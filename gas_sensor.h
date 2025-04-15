#ifndef GAS_SENSOR_H
#define GAS_SENSOR_H

#include "sensor.h"

SensorStatus GasSensor_init(void);
float GasSensor_readCO(void);

#endif // GAS_SENSOR_H
