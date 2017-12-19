/*******************************************************************************
* File Name: LED_ControlReg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "LED_ControlReg.h"

/* Check for removal by optimization */
#if !defined(LED_ControlReg_Sync_ctrl_reg__REMOVED)

static LED_ControlReg_BACKUP_STRUCT  LED_ControlReg_backup = {0u};

    
/*******************************************************************************
* Function Name: LED_ControlReg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_ControlReg_SaveConfig(void) 
{
    LED_ControlReg_backup.controlState = LED_ControlReg_Control;
}


/*******************************************************************************
* Function Name: LED_ControlReg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void LED_ControlReg_RestoreConfig(void) 
{
     LED_ControlReg_Control = LED_ControlReg_backup.controlState;
}


/*******************************************************************************
* Function Name: LED_ControlReg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_ControlReg_Sleep(void) 
{
    LED_ControlReg_SaveConfig();
}


/*******************************************************************************
* Function Name: LED_ControlReg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_ControlReg_Wakeup(void)  
{
    LED_ControlReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
