#ifndef THERMAL_SENSOR_H
#define THERMAL_SENSOR_H

#include "sensor.h"

SensorStatus ThermalSensor_init(void);
float ThermalSensor_readTemperature(void);

#endif // THERMAL_SENSOR_H
