#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include "sensor.h"

SensorStatus FlameSensor_init(void);
float FlameSensor_readIntensity(void);

#endif // FLAME_SENSOR_H
