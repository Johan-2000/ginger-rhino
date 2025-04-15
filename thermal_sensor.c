#include "thermal_sensor.h"
#include <stdio.h>
#include <stdlib.h>

SensorStatus ThermalSensor_init(void) {
    printf("Thermal Sensor initialized.\n");
    return SENSOR_OK;
}

float ThermalSensor_readTemperature(void) {
    // Simulate temperature reading (20.0°C to 70.0°C)
    return 20.0f + ((float)rand() / RAND_MAX) * 50.0f;
}
