#include "gas_sensor.h"
#include <stdio.h>
#include <stdlib.h>

SensorStatus GasSensor_init(void) {
    printf("Gas Sensor initialized.\n");
    return SENSOR_OK;
}

float GasSensor_readCO(void) {
    // Simulate CO level (0 to 200 ppm)
    return ((float)rand() / RAND_MAX) * 200.0f;
}
