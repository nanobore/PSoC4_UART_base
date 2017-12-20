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

#include <cytypes.h>
#include <project.h>
#include <serial.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int setup();
int UART_GetInput();
int parse_command(char* cmd, uint8 args);

/* [] END OF FILE */
