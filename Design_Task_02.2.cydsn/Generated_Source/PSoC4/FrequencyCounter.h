/*******************************************************************************
* File Name: FrequencyCounter.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the FrequencyCounter
*  component.
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

#if !defined(CY_TCPWM_FrequencyCounter_H)
#define CY_TCPWM_FrequencyCounter_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} FrequencyCounter_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  FrequencyCounter_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define FrequencyCounter_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define FrequencyCounter_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define FrequencyCounter_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define FrequencyCounter_QUAD_ENCODING_MODES            (0lu)
#define FrequencyCounter_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define FrequencyCounter_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define FrequencyCounter_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define FrequencyCounter_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define FrequencyCounter_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define FrequencyCounter_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define FrequencyCounter_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define FrequencyCounter_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define FrequencyCounter_TC_RUN_MODE                    (0lu)
#define FrequencyCounter_TC_COUNTER_MODE                (0lu)
#define FrequencyCounter_TC_COMP_CAP_MODE               (2lu)
#define FrequencyCounter_TC_PRESCALER                   (0lu)

/* Signal modes */
#define FrequencyCounter_TC_RELOAD_SIGNAL_MODE          (0lu)
#define FrequencyCounter_TC_COUNT_SIGNAL_MODE           (0lu)
#define FrequencyCounter_TC_START_SIGNAL_MODE           (0lu)
#define FrequencyCounter_TC_STOP_SIGNAL_MODE            (0lu)
#define FrequencyCounter_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define FrequencyCounter_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define FrequencyCounter_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define FrequencyCounter_TC_START_SIGNAL_PRESENT        (0lu)
#define FrequencyCounter_TC_STOP_SIGNAL_PRESENT         (0lu)
#define FrequencyCounter_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define FrequencyCounter_TC_INTERRUPT_MASK              (3lu)

/* PWM Mode */
/* Parameters */
#define FrequencyCounter_PWM_KILL_EVENT                 (0lu)
#define FrequencyCounter_PWM_STOP_EVENT                 (0lu)
#define FrequencyCounter_PWM_MODE                       (4lu)
#define FrequencyCounter_PWM_OUT_N_INVERT               (0lu)
#define FrequencyCounter_PWM_OUT_INVERT                 (0lu)
#define FrequencyCounter_PWM_ALIGN                      (0lu)
#define FrequencyCounter_PWM_RUN_MODE                   (0lu)
#define FrequencyCounter_PWM_DEAD_TIME_CYCLE            (0lu)
#define FrequencyCounter_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define FrequencyCounter_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define FrequencyCounter_PWM_COUNT_SIGNAL_MODE          (3lu)
#define FrequencyCounter_PWM_START_SIGNAL_MODE          (0lu)
#define FrequencyCounter_PWM_STOP_SIGNAL_MODE           (0lu)
#define FrequencyCounter_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define FrequencyCounter_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define FrequencyCounter_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define FrequencyCounter_PWM_START_SIGNAL_PRESENT       (0lu)
#define FrequencyCounter_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define FrequencyCounter_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define FrequencyCounter_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define FrequencyCounter_TC_PERIOD_VALUE                (65535lu)
#define FrequencyCounter_TC_COMPARE_VALUE               (65535lu)
#define FrequencyCounter_TC_COMPARE_BUF_VALUE           (65535lu)
#define FrequencyCounter_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define FrequencyCounter_PWM_PERIOD_VALUE               (65535lu)
#define FrequencyCounter_PWM_PERIOD_BUF_VALUE           (65535lu)
#define FrequencyCounter_PWM_PERIOD_SWAP                (0lu)
#define FrequencyCounter_PWM_COMPARE_VALUE              (65535lu)
#define FrequencyCounter_PWM_COMPARE_BUF_VALUE          (65535lu)
#define FrequencyCounter_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define FrequencyCounter__LEFT 0
#define FrequencyCounter__RIGHT 1
#define FrequencyCounter__CENTER 2
#define FrequencyCounter__ASYMMETRIC 3

#define FrequencyCounter__X1 0
#define FrequencyCounter__X2 1
#define FrequencyCounter__X4 2

#define FrequencyCounter__PWM 4
#define FrequencyCounter__PWM_DT 5
#define FrequencyCounter__PWM_PR 6

#define FrequencyCounter__INVERSE 1
#define FrequencyCounter__DIRECT 0

#define FrequencyCounter__CAPTURE 2
#define FrequencyCounter__COMPARE 0

#define FrequencyCounter__TRIG_LEVEL 3
#define FrequencyCounter__TRIG_RISING 0
#define FrequencyCounter__TRIG_FALLING 1
#define FrequencyCounter__TRIG_BOTH 2

#define FrequencyCounter__INTR_MASK_TC 1
#define FrequencyCounter__INTR_MASK_CC_MATCH 2
#define FrequencyCounter__INTR_MASK_NONE 0
#define FrequencyCounter__INTR_MASK_TC_CC 3

#define FrequencyCounter__UNCONFIG 8
#define FrequencyCounter__TIMER 1
#define FrequencyCounter__QUAD 3
#define FrequencyCounter__PWM_SEL 7

#define FrequencyCounter__COUNT_UP 0
#define FrequencyCounter__COUNT_DOWN 1
#define FrequencyCounter__COUNT_UPDOWN0 2
#define FrequencyCounter__COUNT_UPDOWN1 3


/* Prescaler */
#define FrequencyCounter_PRESCALE_DIVBY1                ((uint32)(0u << FrequencyCounter_PRESCALER_SHIFT))
#define FrequencyCounter_PRESCALE_DIVBY2                ((uint32)(1u << FrequencyCounter_PRESCALER_SHIFT))
#define FrequencyCounter_PRESCALE_DIVBY4                ((uint32)(2u << FrequencyCounter_PRESCALER_SHIFT))
#define FrequencyCounter_PRESCALE_DIVBY8                ((uint32)(3u << FrequencyCounter_PRESCALER_SHIFT))
#define FrequencyCounter_PRESCALE_DIVBY16               ((uint32)(4u << FrequencyCounter_PRESCALER_SHIFT))
#define FrequencyCounter_PRESCALE_DIVBY32               ((uint32)(5u << FrequencyCounter_PRESCALER_SHIFT))
#define FrequencyCounter_PRESCALE_DIVBY64               ((uint32)(6u << FrequencyCounter_PRESCALER_SHIFT))
#define FrequencyCounter_PRESCALE_DIVBY128              ((uint32)(7u << FrequencyCounter_PRESCALER_SHIFT))

/* TCPWM set modes */
#define FrequencyCounter_MODE_TIMER_COMPARE             ((uint32)(FrequencyCounter__COMPARE         <<  \
                                                                  FrequencyCounter_MODE_SHIFT))
#define FrequencyCounter_MODE_TIMER_CAPTURE             ((uint32)(FrequencyCounter__CAPTURE         <<  \
                                                                  FrequencyCounter_MODE_SHIFT))
#define FrequencyCounter_MODE_QUAD                      ((uint32)(FrequencyCounter__QUAD            <<  \
                                                                  FrequencyCounter_MODE_SHIFT))
#define FrequencyCounter_MODE_PWM                       ((uint32)(FrequencyCounter__PWM             <<  \
                                                                  FrequencyCounter_MODE_SHIFT))
#define FrequencyCounter_MODE_PWM_DT                    ((uint32)(FrequencyCounter__PWM_DT          <<  \
                                                                  FrequencyCounter_MODE_SHIFT))
#define FrequencyCounter_MODE_PWM_PR                    ((uint32)(FrequencyCounter__PWM_PR          <<  \
                                                                  FrequencyCounter_MODE_SHIFT))

/* Quad Modes */
#define FrequencyCounter_MODE_X1                        ((uint32)(FrequencyCounter__X1              <<  \
                                                                  FrequencyCounter_QUAD_MODE_SHIFT))
#define FrequencyCounter_MODE_X2                        ((uint32)(FrequencyCounter__X2              <<  \
                                                                  FrequencyCounter_QUAD_MODE_SHIFT))
#define FrequencyCounter_MODE_X4                        ((uint32)(FrequencyCounter__X4              <<  \
                                                                  FrequencyCounter_QUAD_MODE_SHIFT))

/* Counter modes */
#define FrequencyCounter_COUNT_UP                       ((uint32)(FrequencyCounter__COUNT_UP        <<  \
                                                                  FrequencyCounter_UPDOWN_SHIFT))
#define FrequencyCounter_COUNT_DOWN                     ((uint32)(FrequencyCounter__COUNT_DOWN      <<  \
                                                                  FrequencyCounter_UPDOWN_SHIFT))
#define FrequencyCounter_COUNT_UPDOWN0                  ((uint32)(FrequencyCounter__COUNT_UPDOWN0   <<  \
                                                                  FrequencyCounter_UPDOWN_SHIFT))
#define FrequencyCounter_COUNT_UPDOWN1                  ((uint32)(FrequencyCounter__COUNT_UPDOWN1   <<  \
                                                                  FrequencyCounter_UPDOWN_SHIFT))

/* PWM output invert */
#define FrequencyCounter_INVERT_LINE                    ((uint32)(FrequencyCounter__INVERSE         <<  \
                                                                  FrequencyCounter_INV_OUT_SHIFT))
#define FrequencyCounter_INVERT_LINE_N                  ((uint32)(FrequencyCounter__INVERSE         <<  \
                                                                  FrequencyCounter_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define FrequencyCounter_TRIG_RISING                    ((uint32)FrequencyCounter__TRIG_RISING)
#define FrequencyCounter_TRIG_FALLING                   ((uint32)FrequencyCounter__TRIG_FALLING)
#define FrequencyCounter_TRIG_BOTH                      ((uint32)FrequencyCounter__TRIG_BOTH)
#define FrequencyCounter_TRIG_LEVEL                     ((uint32)FrequencyCounter__TRIG_LEVEL)

/* Interrupt mask */
#define FrequencyCounter_INTR_MASK_TC                   ((uint32)FrequencyCounter__INTR_MASK_TC)
#define FrequencyCounter_INTR_MASK_CC_MATCH             ((uint32)FrequencyCounter__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define FrequencyCounter_CC_MATCH_SET                   (0x00u)
#define FrequencyCounter_CC_MATCH_CLEAR                 (0x01u)
#define FrequencyCounter_CC_MATCH_INVERT                (0x02u)
#define FrequencyCounter_CC_MATCH_NO_CHANGE             (0x03u)
#define FrequencyCounter_OVERLOW_SET                    (0x00u)
#define FrequencyCounter_OVERLOW_CLEAR                  (0x04u)
#define FrequencyCounter_OVERLOW_INVERT                 (0x08u)
#define FrequencyCounter_OVERLOW_NO_CHANGE              (0x0Cu)
#define FrequencyCounter_UNDERFLOW_SET                  (0x00u)
#define FrequencyCounter_UNDERFLOW_CLEAR                (0x10u)
#define FrequencyCounter_UNDERFLOW_INVERT               (0x20u)
#define FrequencyCounter_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define FrequencyCounter_PWM_MODE_LEFT                  (FrequencyCounter_CC_MATCH_CLEAR        |   \
                                                         FrequencyCounter_OVERLOW_SET           |   \
                                                         FrequencyCounter_UNDERFLOW_NO_CHANGE)
#define FrequencyCounter_PWM_MODE_RIGHT                 (FrequencyCounter_CC_MATCH_SET          |   \
                                                         FrequencyCounter_OVERLOW_NO_CHANGE     |   \
                                                         FrequencyCounter_UNDERFLOW_CLEAR)
#define FrequencyCounter_PWM_MODE_ASYM                  (FrequencyCounter_CC_MATCH_INVERT       |   \
                                                         FrequencyCounter_OVERLOW_SET           |   \
                                                         FrequencyCounter_UNDERFLOW_CLEAR)

#if (FrequencyCounter_CY_TCPWM_V2)
    #if(FrequencyCounter_CY_TCPWM_4000)
        #define FrequencyCounter_PWM_MODE_CENTER                (FrequencyCounter_CC_MATCH_INVERT       |   \
                                                                 FrequencyCounter_OVERLOW_NO_CHANGE     |   \
                                                                 FrequencyCounter_UNDERFLOW_CLEAR)
    #else
        #define FrequencyCounter_PWM_MODE_CENTER                (FrequencyCounter_CC_MATCH_INVERT       |   \
                                                                 FrequencyCounter_OVERLOW_SET           |   \
                                                                 FrequencyCounter_UNDERFLOW_CLEAR)
    #endif /* (FrequencyCounter_CY_TCPWM_4000) */
#else
    #define FrequencyCounter_PWM_MODE_CENTER                (FrequencyCounter_CC_MATCH_INVERT       |   \
                                                             FrequencyCounter_OVERLOW_NO_CHANGE     |   \
                                                             FrequencyCounter_UNDERFLOW_CLEAR)
#endif /* (FrequencyCounter_CY_TCPWM_NEW) */

/* Command operations without condition */
#define FrequencyCounter_CMD_CAPTURE                    (0u)
#define FrequencyCounter_CMD_RELOAD                     (8u)
#define FrequencyCounter_CMD_STOP                       (16u)
#define FrequencyCounter_CMD_START                      (24u)

/* Status */
#define FrequencyCounter_STATUS_DOWN                    (1u)
#define FrequencyCounter_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   FrequencyCounter_Init(void);
void   FrequencyCounter_Enable(void);
void   FrequencyCounter_Start(void);
void   FrequencyCounter_Stop(void);

void   FrequencyCounter_SetMode(uint32 mode);
void   FrequencyCounter_SetCounterMode(uint32 counterMode);
void   FrequencyCounter_SetPWMMode(uint32 modeMask);
void   FrequencyCounter_SetQDMode(uint32 qdMode);

void   FrequencyCounter_SetPrescaler(uint32 prescaler);
void   FrequencyCounter_TriggerCommand(uint32 mask, uint32 command);
void   FrequencyCounter_SetOneShot(uint32 oneShotEnable);
uint32 FrequencyCounter_ReadStatus(void);

void   FrequencyCounter_SetPWMSyncKill(uint32 syncKillEnable);
void   FrequencyCounter_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   FrequencyCounter_SetPWMDeadTime(uint32 deadTime);
void   FrequencyCounter_SetPWMInvert(uint32 mask);

void   FrequencyCounter_SetInterruptMode(uint32 interruptMask);
uint32 FrequencyCounter_GetInterruptSourceMasked(void);
uint32 FrequencyCounter_GetInterruptSource(void);
void   FrequencyCounter_ClearInterrupt(uint32 interruptMask);
void   FrequencyCounter_SetInterrupt(uint32 interruptMask);

void   FrequencyCounter_WriteCounter(uint32 count);
uint32 FrequencyCounter_ReadCounter(void);

uint32 FrequencyCounter_ReadCapture(void);
uint32 FrequencyCounter_ReadCaptureBuf(void);

void   FrequencyCounter_WritePeriod(uint32 period);
uint32 FrequencyCounter_ReadPeriod(void);
void   FrequencyCounter_WritePeriodBuf(uint32 periodBuf);
uint32 FrequencyCounter_ReadPeriodBuf(void);

void   FrequencyCounter_WriteCompare(uint32 compare);
uint32 FrequencyCounter_ReadCompare(void);
void   FrequencyCounter_WriteCompareBuf(uint32 compareBuf);
uint32 FrequencyCounter_ReadCompareBuf(void);

void   FrequencyCounter_SetPeriodSwap(uint32 swapEnable);
void   FrequencyCounter_SetCompareSwap(uint32 swapEnable);

void   FrequencyCounter_SetCaptureMode(uint32 triggerMode);
void   FrequencyCounter_SetReloadMode(uint32 triggerMode);
void   FrequencyCounter_SetStartMode(uint32 triggerMode);
void   FrequencyCounter_SetStopMode(uint32 triggerMode);
void   FrequencyCounter_SetCountMode(uint32 triggerMode);

void   FrequencyCounter_SaveConfig(void);
void   FrequencyCounter_RestoreConfig(void);
void   FrequencyCounter_Sleep(void);
void   FrequencyCounter_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define FrequencyCounter_BLOCK_CONTROL_REG              (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define FrequencyCounter_BLOCK_CONTROL_PTR              ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define FrequencyCounter_COMMAND_REG                    (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define FrequencyCounter_COMMAND_PTR                    ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define FrequencyCounter_INTRRUPT_CAUSE_REG             (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define FrequencyCounter_INTRRUPT_CAUSE_PTR             ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define FrequencyCounter_CONTROL_REG                    (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__CTRL )
#define FrequencyCounter_CONTROL_PTR                    ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__CTRL )
#define FrequencyCounter_STATUS_REG                     (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__STATUS )
#define FrequencyCounter_STATUS_PTR                     ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__STATUS )
#define FrequencyCounter_COUNTER_REG                    (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__COUNTER )
#define FrequencyCounter_COUNTER_PTR                    ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__COUNTER )
#define FrequencyCounter_COMP_CAP_REG                   (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__CC )
#define FrequencyCounter_COMP_CAP_PTR                   ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__CC )
#define FrequencyCounter_COMP_CAP_BUF_REG               (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__CC_BUFF )
#define FrequencyCounter_COMP_CAP_BUF_PTR               ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__CC_BUFF )
#define FrequencyCounter_PERIOD_REG                     (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__PERIOD )
#define FrequencyCounter_PERIOD_PTR                     ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__PERIOD )
#define FrequencyCounter_PERIOD_BUF_REG                 (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define FrequencyCounter_PERIOD_BUF_PTR                 ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define FrequencyCounter_TRIG_CONTROL0_REG              (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define FrequencyCounter_TRIG_CONTROL0_PTR              ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define FrequencyCounter_TRIG_CONTROL1_REG              (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define FrequencyCounter_TRIG_CONTROL1_PTR              ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define FrequencyCounter_TRIG_CONTROL2_REG              (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define FrequencyCounter_TRIG_CONTROL2_PTR              ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define FrequencyCounter_INTERRUPT_REQ_REG              (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__INTR )
#define FrequencyCounter_INTERRUPT_REQ_PTR              ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__INTR )
#define FrequencyCounter_INTERRUPT_SET_REG              (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__INTR_SET )
#define FrequencyCounter_INTERRUPT_SET_PTR              ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__INTR_SET )
#define FrequencyCounter_INTERRUPT_MASK_REG             (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__INTR_MASK )
#define FrequencyCounter_INTERRUPT_MASK_PTR             ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__INTR_MASK )
#define FrequencyCounter_INTERRUPT_MASKED_REG           (*(reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__INTR_MASKED )
#define FrequencyCounter_INTERRUPT_MASKED_PTR           ( (reg32 *) FrequencyCounter_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define FrequencyCounter_MASK                           ((uint32)FrequencyCounter_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define FrequencyCounter_RELOAD_CC_SHIFT                (0u)
#define FrequencyCounter_RELOAD_PERIOD_SHIFT            (1u)
#define FrequencyCounter_PWM_SYNC_KILL_SHIFT            (2u)
#define FrequencyCounter_PWM_STOP_KILL_SHIFT            (3u)
#define FrequencyCounter_PRESCALER_SHIFT                (8u)
#define FrequencyCounter_UPDOWN_SHIFT                   (16u)
#define FrequencyCounter_ONESHOT_SHIFT                  (18u)
#define FrequencyCounter_QUAD_MODE_SHIFT                (20u)
#define FrequencyCounter_INV_OUT_SHIFT                  (20u)
#define FrequencyCounter_INV_COMPL_OUT_SHIFT            (21u)
#define FrequencyCounter_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define FrequencyCounter_RELOAD_CC_MASK                 ((uint32)(FrequencyCounter_1BIT_MASK        <<  \
                                                                            FrequencyCounter_RELOAD_CC_SHIFT))
#define FrequencyCounter_RELOAD_PERIOD_MASK             ((uint32)(FrequencyCounter_1BIT_MASK        <<  \
                                                                            FrequencyCounter_RELOAD_PERIOD_SHIFT))
#define FrequencyCounter_PWM_SYNC_KILL_MASK             ((uint32)(FrequencyCounter_1BIT_MASK        <<  \
                                                                            FrequencyCounter_PWM_SYNC_KILL_SHIFT))
#define FrequencyCounter_PWM_STOP_KILL_MASK             ((uint32)(FrequencyCounter_1BIT_MASK        <<  \
                                                                            FrequencyCounter_PWM_STOP_KILL_SHIFT))
#define FrequencyCounter_PRESCALER_MASK                 ((uint32)(FrequencyCounter_8BIT_MASK        <<  \
                                                                            FrequencyCounter_PRESCALER_SHIFT))
#define FrequencyCounter_UPDOWN_MASK                    ((uint32)(FrequencyCounter_2BIT_MASK        <<  \
                                                                            FrequencyCounter_UPDOWN_SHIFT))
#define FrequencyCounter_ONESHOT_MASK                   ((uint32)(FrequencyCounter_1BIT_MASK        <<  \
                                                                            FrequencyCounter_ONESHOT_SHIFT))
#define FrequencyCounter_QUAD_MODE_MASK                 ((uint32)(FrequencyCounter_3BIT_MASK        <<  \
                                                                            FrequencyCounter_QUAD_MODE_SHIFT))
#define FrequencyCounter_INV_OUT_MASK                   ((uint32)(FrequencyCounter_2BIT_MASK        <<  \
                                                                            FrequencyCounter_INV_OUT_SHIFT))
#define FrequencyCounter_MODE_MASK                      ((uint32)(FrequencyCounter_3BIT_MASK        <<  \
                                                                            FrequencyCounter_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define FrequencyCounter_CAPTURE_SHIFT                  (0u)
#define FrequencyCounter_COUNT_SHIFT                    (2u)
#define FrequencyCounter_RELOAD_SHIFT                   (4u)
#define FrequencyCounter_STOP_SHIFT                     (6u)
#define FrequencyCounter_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define FrequencyCounter_CAPTURE_MASK                   ((uint32)(FrequencyCounter_2BIT_MASK        <<  \
                                                                  FrequencyCounter_CAPTURE_SHIFT))
#define FrequencyCounter_COUNT_MASK                     ((uint32)(FrequencyCounter_2BIT_MASK        <<  \
                                                                  FrequencyCounter_COUNT_SHIFT))
#define FrequencyCounter_RELOAD_MASK                    ((uint32)(FrequencyCounter_2BIT_MASK        <<  \
                                                                  FrequencyCounter_RELOAD_SHIFT))
#define FrequencyCounter_STOP_MASK                      ((uint32)(FrequencyCounter_2BIT_MASK        <<  \
                                                                  FrequencyCounter_STOP_SHIFT))
#define FrequencyCounter_START_MASK                     ((uint32)(FrequencyCounter_2BIT_MASK        <<  \
                                                                  FrequencyCounter_START_SHIFT))

/* MASK */
#define FrequencyCounter_1BIT_MASK                      ((uint32)0x01u)
#define FrequencyCounter_2BIT_MASK                      ((uint32)0x03u)
#define FrequencyCounter_3BIT_MASK                      ((uint32)0x07u)
#define FrequencyCounter_6BIT_MASK                      ((uint32)0x3Fu)
#define FrequencyCounter_8BIT_MASK                      ((uint32)0xFFu)
#define FrequencyCounter_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define FrequencyCounter_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define FrequencyCounter_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(FrequencyCounter_QUAD_ENCODING_MODES     << FrequencyCounter_QUAD_MODE_SHIFT))       |\
         ((uint32)(FrequencyCounter_CONFIG                  << FrequencyCounter_MODE_SHIFT)))

#define FrequencyCounter_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(FrequencyCounter_PWM_STOP_EVENT          << FrequencyCounter_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(FrequencyCounter_PWM_OUT_INVERT          << FrequencyCounter_INV_OUT_SHIFT))         |\
         ((uint32)(FrequencyCounter_PWM_OUT_N_INVERT        << FrequencyCounter_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(FrequencyCounter_PWM_MODE                << FrequencyCounter_MODE_SHIFT)))

#define FrequencyCounter_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(FrequencyCounter_PWM_RUN_MODE         << FrequencyCounter_ONESHOT_SHIFT))
            
#define FrequencyCounter_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(FrequencyCounter_PWM_ALIGN            << FrequencyCounter_UPDOWN_SHIFT))

#define FrequencyCounter_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(FrequencyCounter_PWM_KILL_EVENT      << FrequencyCounter_PWM_SYNC_KILL_SHIFT))

#define FrequencyCounter_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(FrequencyCounter_PWM_DEAD_TIME_CYCLE  << FrequencyCounter_PRESCALER_SHIFT))

#define FrequencyCounter_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(FrequencyCounter_PWM_PRESCALER        << FrequencyCounter_PRESCALER_SHIFT))

#define FrequencyCounter_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(FrequencyCounter_TC_PRESCALER            << FrequencyCounter_PRESCALER_SHIFT))       |\
         ((uint32)(FrequencyCounter_TC_COUNTER_MODE         << FrequencyCounter_UPDOWN_SHIFT))          |\
         ((uint32)(FrequencyCounter_TC_RUN_MODE             << FrequencyCounter_ONESHOT_SHIFT))         |\
         ((uint32)(FrequencyCounter_TC_COMP_CAP_MODE        << FrequencyCounter_MODE_SHIFT)))
        
#define FrequencyCounter_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(FrequencyCounter_QUAD_PHIA_SIGNAL_MODE   << FrequencyCounter_COUNT_SHIFT))           |\
         ((uint32)(FrequencyCounter_QUAD_INDEX_SIGNAL_MODE  << FrequencyCounter_RELOAD_SHIFT))          |\
         ((uint32)(FrequencyCounter_QUAD_STOP_SIGNAL_MODE   << FrequencyCounter_STOP_SHIFT))            |\
         ((uint32)(FrequencyCounter_QUAD_PHIB_SIGNAL_MODE   << FrequencyCounter_START_SHIFT)))

#define FrequencyCounter_PWM_SIGNALS_MODES                                                              \
        (((uint32)(FrequencyCounter_PWM_SWITCH_SIGNAL_MODE  << FrequencyCounter_CAPTURE_SHIFT))         |\
         ((uint32)(FrequencyCounter_PWM_COUNT_SIGNAL_MODE   << FrequencyCounter_COUNT_SHIFT))           |\
         ((uint32)(FrequencyCounter_PWM_RELOAD_SIGNAL_MODE  << FrequencyCounter_RELOAD_SHIFT))          |\
         ((uint32)(FrequencyCounter_PWM_STOP_SIGNAL_MODE    << FrequencyCounter_STOP_SHIFT))            |\
         ((uint32)(FrequencyCounter_PWM_START_SIGNAL_MODE   << FrequencyCounter_START_SHIFT)))

#define FrequencyCounter_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(FrequencyCounter_TC_CAPTURE_SIGNAL_MODE  << FrequencyCounter_CAPTURE_SHIFT))         |\
         ((uint32)(FrequencyCounter_TC_COUNT_SIGNAL_MODE    << FrequencyCounter_COUNT_SHIFT))           |\
         ((uint32)(FrequencyCounter_TC_RELOAD_SIGNAL_MODE   << FrequencyCounter_RELOAD_SHIFT))          |\
         ((uint32)(FrequencyCounter_TC_STOP_SIGNAL_MODE     << FrequencyCounter_STOP_SHIFT))            |\
         ((uint32)(FrequencyCounter_TC_START_SIGNAL_MODE    << FrequencyCounter_START_SHIFT)))
        
#define FrequencyCounter_TIMER_UPDOWN_CNT_USED                                                          \
                ((FrequencyCounter__COUNT_UPDOWN0 == FrequencyCounter_TC_COUNTER_MODE)                  ||\
                 (FrequencyCounter__COUNT_UPDOWN1 == FrequencyCounter_TC_COUNTER_MODE))

#define FrequencyCounter_PWM_UPDOWN_CNT_USED                                                            \
                ((FrequencyCounter__CENTER == FrequencyCounter_PWM_ALIGN)                               ||\
                 (FrequencyCounter__ASYMMETRIC == FrequencyCounter_PWM_ALIGN))               
        
#define FrequencyCounter_PWM_PR_INIT_VALUE              (1u)
#define FrequencyCounter_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_FrequencyCounter_H */

/* [] END OF FILE */
