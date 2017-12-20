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
#include <stdio.h>

#define MAX_COMMAND_LENGTH 64u

void ups(const char8 string[]);
void upl(const char8 string[]);
int UART_GetInput();
int parse_command(char* cmd, uint8 args);

/* [] END OF FILE */
