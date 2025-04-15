#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define SLEEP(ms) usleep((ms) * 1000)
#endif

#include "flame_sensor.h"
#include "thermal_sensor.h"
#include "afir_sensor.h"
#include "gas_sensor.h"

int main(void) {
    srand((unsigned int)time(NULL));

    // Open the CSV file for writing sensor data
    FILE *fp = fopen("sensor_data.csv", "w");
    if (fp == NULL) {
        perror("Failed to open sensor_data.csv for writing");
        return -1;
    }

    // Write CSV header line
    fprintf(fp, "Timestamp,Flame_Intensity,Temperature,Motion_Detected,CO_Level\n");
    fflush(fp); // Ensure header is written immediately

    // Initialize sensors
    if (FlameSensor_init() != SENSOR_OK) {
        fprintf(stderr, "Failed to initialize Flame Sensor!\n");
        fclose(fp);
        return -1;
    }
    if (ThermalSensor_init() != SENSOR_OK) {
        fprintf(stderr, "Failed to initialize Thermal Sensor!\n");
        fclose(fp);
        return -1;
    }
    if (AFIRSensor_init() != SENSOR_OK) {
        fprintf(stderr, "Failed to initialize AFIR Sensor!\n");
        fclose(fp);
        return -1;
    }
    if (GasSensor_init() != SENSOR_OK) {
        fprintf(stderr, "Failed to initialize Gas Sensor!\n");
        fclose(fp);
        return -1;
    }

    while (1) {
        float flameIntensity = FlameSensor_readIntensity();
        float temperature = ThermalSensor_readTemperature();
        int motionDetected = AFIRSensor_detectMotion();
        float coLevel = GasSensor_readCO();

        // Get current timestamp
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

        // Print readings to console
        printf("Timestamp: %s\n", timestamp);
        printf("  Flame Intensity: %.2f\n", flameIntensity);
        printf("  Temperature: %.2f °C\n", temperature);
        printf("  Motion Detected: %s\n", motionDetected ? "Yes" : "No");
        printf("  CO Level: %.2f ppm\n", coLevel);
        printf("--------------------------\n");

        // Write sensor readings to CSV file
        fprintf(fp, "%s,%.2f,%.2f,%d,%.2f\n", timestamp, flameIntensity, temperature, motionDetected, coLevel);
        fflush(fp); // Ensure data is written immediately

        // Delay for 1 second
        SLEEP(1000);
    }

    fclose(fp);
    return 0;
}
