/*******************************************************************************
* File Name: FrequencyCounter_PM.c
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

#include "FrequencyCounter.h"

static FrequencyCounter_BACKUP_STRUCT FrequencyCounter_backup;


/*******************************************************************************
* Function Name: FrequencyCounter_SaveConfig
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
void FrequencyCounter_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: FrequencyCounter_Sleep
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
void FrequencyCounter_Sleep(void)
{
    if(0u != (FrequencyCounter_BLOCK_CONTROL_REG & FrequencyCounter_MASK))
    {
        FrequencyCounter_backup.enableState = 1u;
    }
    else
    {
        FrequencyCounter_backup.enableState = 0u;
    }

    FrequencyCounter_Stop();
    FrequencyCounter_SaveConfig();
}


/*******************************************************************************
* Function Name: FrequencyCounter_RestoreConfig
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
void FrequencyCounter_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: FrequencyCounter_Wakeup
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
void FrequencyCounter_Wakeup(void)
{
    FrequencyCounter_RestoreConfig();

    if(0u != FrequencyCounter_backup.enableState)
    {
        FrequencyCounter_Enable();
    }
}


/* [] END OF FILE */
