#include "project.h"
#include "stdio.h"

#define STR_LEN     (80u)
#define CHANNEL_0   (0u)

void out7seg(uint16);

uint16 indyk[4]         = {0x10FF,0x20FF,0x40FF,0x80FF};
const uint8 KOD7[10]    = {0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x09};

void out7seg(uint16 data);
CY_ISR_PROTO(isr_100Hz);

uint16 temperature;


uint16_t My_CountsTo_mVolts(int channel, uint16 adcResult){
    uint16 adcResult_mV = adcResult;
    adcResult_mV = adcResult - ADC_SAR_Seq_offset[channel];
    adcResult_mV = adcResult_mV * (ADC_SAR_Seq_10MV_COUNTS/ADC_SAR_Seq_countsPer10Volt[channel]);
    
    return adcResult_mV;
}

int main(void)
{
    char str[STR_LEN];
    uint16 adcResult;
    float adcResult_V;
    int16 adcResult_mV;
    int32 adcResult_uV;
    uint16 my_adcResult_mV;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    SPIM_Start();
    isr_100Hz_StartEx(isr_100Hz);
    
    ADC_SAR_Seq_Start();
    UART_Start();
    UART_UartPutString("Init stage is done \r\n");

    UART_UartPutString("Starting ADC (FreeRunning mode only) \r\n"); 
    ADC_SAR_Seq_StartConvert();
    
    for(;;)
    {
        CyDelay(1000u);
        ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_WAIT_FOR_RESULT);
        
        adcResult = ADC_SAR_Seq_GetResult16(CHANNEL_0);
        adcResult_V = ADC_SAR_Seq_CountsTo_Volts(CHANNEL_0, adcResult);
        adcResult_mV = ADC_SAR_Seq_CountsTo_mVolts(CHANNEL_0, adcResult);
        adcResult_uV = ADC_SAR_Seq_CountsTo_uVolts(CHANNEL_0, adcResult);
        
        temperature = adcResult_mV / 10; // 10 mV per C
        out7seg(temperature);
        
        CyDelay(1000u);
        my_adcResult_mV = My_CountsTo_mVolts(CHANNEL_0, adcResult);
        temperature = adcResult_mV / 10; // 10 mV per C
        out7seg(temperature);
        
        /* Send data through UART
        sprintf(str, "n = 0x%04x; V = %dmV  T = %d C  \r\n", (unsigned short)adcResult, adcResult_mV, temperature);
        UART_UartPutString(str); */
    }
}


void out7seg(uint16 data)
{
    uint8 i;
    
    for (i = 0; i < 4; i++)
    {
        indyk[i] &= 0xFF00;
        indyk[i] |= (uint16)KOD7[data % 10];
        data /= 10;
        if (data == 0) break;
    }
    
    for (i++; i < 4; i++)
    {
        indyk[i] |= 0x00FF;
    }
}

CY_ISR(isr_100Hz)
{
    static uint8 N_indyk = 0u;
    
    SPIM_WriteTxData(indyk[N_indyk]);
    
    N_indyk++;
    N_indyk &= 3;    
}

/* [] END OF FILE */
