#include "mbed.h"
 
AnalogIn   vrefint(ADC_VREF);

BufferedSerial serial(PA_9, PA_10);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &serial;
}
 
int main() {
    uint16_t    vref_cal;
    vref_cal = *(__IO uint16_t *)((uint32_t)0x1fff75aa);

    while(1) {
        double voltage = (3.f * (double)vref_cal / 4096) / vrefint.read();
        printf("Voltage: %2.4f\r\n", voltage);
        ThisThread::sleep_for(1s);
    }
}
