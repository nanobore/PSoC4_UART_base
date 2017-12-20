/*******************************************************************************
* File Name: TestControlReg_PM.c
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

#include "TestControlReg.h"

/* Check for removal by optimization */
#if !defined(TestControlReg_Sync_ctrl_reg__REMOVED)

static TestControlReg_BACKUP_STRUCT  TestControlReg_backup = {0u};

    
/*******************************************************************************
* Function Name: TestControlReg_SaveConfig
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
void TestControlReg_SaveConfig(void) 
{
    TestControlReg_backup.controlState = TestControlReg_Control;
}


/*******************************************************************************
* Function Name: TestControlReg_RestoreConfig
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
void TestControlReg_RestoreConfig(void) 
{
     TestControlReg_Control = TestControlReg_backup.controlState;
}


/*******************************************************************************
* Function Name: TestControlReg_Sleep
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
void TestControlReg_Sleep(void) 
{
    TestControlReg_SaveConfig();
}


/*******************************************************************************
* Function Name: TestControlReg_Wakeup
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
void TestControlReg_Wakeup(void)  
{
    TestControlReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
