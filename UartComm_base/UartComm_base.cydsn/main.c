/*******************************************************************************
* File Name: main.c
*
* Version: 1.20
*
* Description:
*  This example project demonstrates the basic operation of the SCB component
*  in the UART mode. The polling method is used to wait for received character.
*  As soon as character is received it is transmitted back. The serial terminal
*  can be used on the PC to send characters and get them back.
*  The example will echo every received character.
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include "main.h"
#include <project.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

uint8 LED_state = 0u;

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  The main function performs the following actions:
*   1. Sets up UART component.
*   2. UART sends text header into the serial terminal.
*   3. UART waits for the characters to send them back to the serial terminal.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/

uint16 ADC_result = 0;

int main()
{
    setup();
    
    UART_UartPutString("\r\n");   
    UART_UartPutString("************************************************\r\n");
    UART_UartPutString("* Simple serial communication UART base system *\r\n");
    UART_UartPutString("************************************************\r\n");
    UART_UartPutString("\r\n");

    
    
    for (;;)
    {   ADC_result = ADC_GetResult16(0);
        UART_GetInput();
    }
}

/* Setup */
int setup()
{
    /* Start SCB (UART mode) operation */
    UART_Start();
    
    /* Start the ADC in free-running mode */
    ADC_Start();
    ADC_StartConvert();
    
    return 0;
}

/* Gets an input from a user over UART. Returns when a CR is received. */
int UART_GetInput() {

    uint32 ch;
    uint8 done = 0u;
    uint8 args = 1;
    
    char cmd[MAX_COMMAND_LENGTH];
    
    uint32 ch_received = 0;
    
    UART_UartPutString(": ");
    
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
    
    UART_UartPutString("\r\nOK, thanks!\r\n");
    UART_UartPutString("Your command: ");
    UART_UartPutString(cmd);
    UART_UartPutString("\r\n");
    
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
        UART_UartPutString("ADC value:");
        UART_UartPutString(buf);
        UART_UartPutString("\r\n");
    }
    else
        UART_UartPutString("I don't understand that command!\r\n");      
    return args;
}


/* [] END OF FILE */
