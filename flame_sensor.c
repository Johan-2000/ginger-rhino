#include "flame_sensor.h"
#include <stdio.h>
#include <stdlib.h>

SensorStatus FlameSensor_init(void) {
    printf("Flame Sensor initialized.\n");
    return SENSOR_OK;
}

float FlameSensor_readIntensity(void) {
    // Simulate flame intensity (0.0 to 100.0)
    return ((float)rand() / RAND_MAX) * 100.0f;
}
