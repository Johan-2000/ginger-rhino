#include "afir_sensor.h"
#include <stdio.h>
#include <stdlib.h>

SensorStatus AFIRSensor_init(void) {
    printf("AFIR Sensor initialized.\n");
    return SENSOR_OK;
}

int AFIRSensor_detectMotion(void) {
    // Simulate motion detection (0 or 1)
    return rand() % 2;
}
