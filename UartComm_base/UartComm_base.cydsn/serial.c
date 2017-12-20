/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <serial.h>

extern uint16 ADC_result;

// Wrapper function for UART_UartPutString because that is long and rather tedious to type repeatedly
// but I also don't want to mess with the generated source code too much u(art) p(ut) s(tring)
void ups(const char8 string[])
{
    UART_UartPutString(string);
}

// Wrapper function that appends a return + newline
// u(art) p(ut) l(line)
void upl(const char8 string[])
{
    ups(string);
    ups("\r\n");
}

/* Gets an input from a user over UART. Returns when a CR is received. */
int UART_GetInput() {

    uint32 ch;
    uint8 done = 0u;
    uint8 args = 1;
    
    char cmd[MAX_COMMAND_LENGTH];
    
    uint32 ch_received = 0;
    
    ups(": ");
    
    while (done != 1u || ch_received == MAX_COMMAND_LENGTH) 
    {
        ch = UART_UartGetChar();
        
        if (ch != 0u)
        {
            UART_UartPutChar(ch);
            
            if (ch == ' ')
                args++;
            
            if (ch == '\r') 
            {
                done = 1u;
                cmd[ch_received] = '\0';
            } else 
            {
                cmd[ch_received] = (char) ch;
            }
            
            ch_received++;
        }
    }
    
    ups("\r\nOK, thanks!\r\n");
    ups("Your command: ");
    ups(cmd);
    ups("\r\n");
    
    parse_command(cmd, args);

    return 0;
}

/* Parse arguments. For now, only "LED on" and "LED off" are supported but eventually will 
   include support for parsing multiple args for "set value" operations */
int parse_command(char* cmd, uint8 args)
{
    char buf[30];
    
    if (strcmp(cmd, "LED on") == 0)
    {
        LED_ControlReg_Write(1u);
        TestControlReg_Write(1u);
    }
    else if (strcmp(cmd, "LED off") == 0) 
    {
        LED_ControlReg_Write(0u);
        TestControlReg_Write(0u);
    }
    else if (strcmp(cmd, "r") == 0)
    {
        sprintf(buf, "%d", ADC_result);
        ups("ADC value:");
        ups(buf);
        ups("\r\n");
    }
    else
        ups("I don't understand that command!\r\n");      
    return args;
}

/* [] END OF FILE */
