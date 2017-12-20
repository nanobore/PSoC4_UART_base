/*******************************************************************************
* File Name: main.c
*
* Version: 1.20
*
* Description:
*  This project is a UART tx/rx base for PSoC as a jumping off point for testing
*  other components (ADC, DAC, BLE, etc.).
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

// Global variables
volatile uint8 LED_state = 0u;
volatile uint16 ADC_result = 0u;

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

int main()
{
    setup();

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
    
    ups("\r\n");   
    ups("************************************************\r\n");
    ups("* Simple serial communication UART base system *\r\n");
    ups("************************************************\r\n");
    ups("\r\n");
    
    return 0;
}

/* [] END OF FILE */
