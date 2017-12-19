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

#include "cytypes.h"

#define MAX_COMMAND_LENGTH 64u

int setup();
int UART_GetInput();
int parse_command(char* cmd, uint8 args);

/* [] END OF FILE */
