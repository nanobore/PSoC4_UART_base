/*******************************************************************************
* File Name: ADC_minus.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ADC_minus.h"

static ADC_minus_BACKUP_STRUCT  ADC_minus_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: ADC_minus_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet ADC_minus_SUT.c usage_ADC_minus_Sleep_Wakeup
*******************************************************************************/
void ADC_minus_Sleep(void)
{
    #if defined(ADC_minus__PC)
        ADC_minus_backup.pcState = ADC_minus_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            ADC_minus_backup.usbState = ADC_minus_CR1_REG;
            ADC_minus_USB_POWER_REG |= ADC_minus_USBIO_ENTER_SLEEP;
            ADC_minus_CR1_REG &= ADC_minus_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ADC_minus__SIO)
        ADC_minus_backup.sioState = ADC_minus_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        ADC_minus_SIO_REG &= (uint32)(~ADC_minus_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: ADC_minus_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to ADC_minus_Sleep() for an example usage.
*******************************************************************************/
void ADC_minus_Wakeup(void)
{
    #if defined(ADC_minus__PC)
        ADC_minus_PC = ADC_minus_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            ADC_minus_USB_POWER_REG &= ADC_minus_USBIO_EXIT_SLEEP_PH1;
            ADC_minus_CR1_REG = ADC_minus_backup.usbState;
            ADC_minus_USB_POWER_REG &= ADC_minus_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ADC_minus__SIO)
        ADC_minus_SIO_REG = ADC_minus_backup.sioState;
    #endif
}


/* [] END OF FILE */
