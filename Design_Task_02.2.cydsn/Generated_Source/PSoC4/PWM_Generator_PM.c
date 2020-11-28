/*******************************************************************************
* File Name: PWM_Generator_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_Generator.h"

static PWM_Generator_BACKUP_STRUCT PWM_Generator_backup;


/*******************************************************************************
* Function Name: PWM_Generator_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_Generator_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_Generator_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_Generator_Sleep(void)
{
    if(0u != (PWM_Generator_BLOCK_CONTROL_REG & PWM_Generator_MASK))
    {
        PWM_Generator_backup.enableState = 1u;
    }
    else
    {
        PWM_Generator_backup.enableState = 0u;
    }

    PWM_Generator_Stop();
    PWM_Generator_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Generator_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_Generator_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_Generator_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_Generator_Wakeup(void)
{
    PWM_Generator_RestoreConfig();

    if(0u != PWM_Generator_backup.enableState)
    {
        PWM_Generator_Enable();
    }
}


/* [] END OF FILE */
