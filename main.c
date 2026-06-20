#include "sdk_project_config.h"

status_t ADC_St;
uint16_t ADC_RawValue;

int main(void)
{
    CLOCK_DRV_Init(&clockMan1_InitConfig0);
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    ADC_St = ADC_Init(&adc_pal_1_instance, &adc_pal_1_config);
    if (ADC_St != STATUS_SUCCESS) {
        while (1);
    }

    while (1) {
        ADC_StartGroupConversion(&adc_pal_1_instance, 0U);
        ADC_RawValue = adc_pal_1_results0[0];

        if (ADC_RawValue > 150) {
            PINS_DRV_ClearPins(PTD, 1 << 0);
        } else {
            PINS_DRV_SetPins(PTD, 1 << 0);
        }
    }
}
