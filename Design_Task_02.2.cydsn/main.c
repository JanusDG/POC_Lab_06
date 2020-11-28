#include "project.h"
#include "stdio.h"

#define MAXCOUNT    (65536u)
#define STR_LEN     (20u)

volatile uint8_t dataReady = 0;
volatile uint32_t overflowCounter = 0;

CY_ISR_PROTO(CC_TC_InterruptHandler);

int main(void)
{
    uint32 capturedValue;
    uint32 measuredFreq;
    char str[STR_LEN];
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Initialization/startup code */
    FrequencyCounter_Start();
    PWM_1sWindow_Start();
    isr_Counter_StartEx(CC_TC_InterruptHandler);
    UART_Start();
    UART_UartPutString("Init stage is done \r\n");
    
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_StartConvert();
    UART_UartPutString("  PWM_Generator started \r\n");
    
    for(;;)
    {
        static uint32 capturedPrevious = 0;
        if(0 != dataReady)
        {
            /* Calculate frequency and send measurement result */
            capturedValue = FrequencyCounter_ReadCapture();
            
            measuredFreq = overflowCounter * MAXCOUNT + capturedValue - capturedPrevious;
            
            capturedPrevious = capturedValue;
            overflowCounter = 0;
            dataReady = 0;
            
            /* Send result frequency through UART */
            sprintf(str, "F = %lu Hz \r\n", measuredFreq);
            UART_UartPutString(str);
        }
    }
}

CY_ISR(CC_TC_InterruptHandler)
{
    uint32 interruptSource;
    interruptSource = FrequencyCounter_GetInterruptSource();
    
    /* CC_MATCH interrupt is triggered when 1s time window is gone */
    if(0 != (interruptSource & FrequencyCounter_INTR_MASK_CC_MATCH))
    {
        FrequencyCounter_ClearInterrupt(FrequencyCounter_INTR_MASK_CC_MATCH);
        dataReady++;
    }
       
    /* TC interrupt is triggered when overflow is happened */
    if(0 != (interruptSource & FrequencyCounter_INTR_MASK_TC))
    {
        FrequencyCounter_ClearInterrupt(FrequencyCounter_INTR_MASK_TC);
        overflowCounter++;
    }
    
}

/* [] END OF FILE */
