import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import os

# Create a figure with three subplots
fig, axs = plt.subplots(3, 1, figsize=(10, 12), sharex=True)
plt.subplots_adjust(hspace=0.5)

def animate(i):
    if not os.path.exists('sensor_data.csv'):
        return

    try:
        # Load the sensor data from the CSV file
        data = pd.read_csv('sensor_data.csv')

        # Convert 'Timestamp' to datetime
        data['Timestamp'] = pd.to_datetime(data['Timestamp'])

        # Limit to the last 100 data points for performance
        data = data.tail(100)

        # Clear previous plots
        for ax in axs:
            ax.clear()

        # Plot Flame Intensity over Time
        axs[0].plot(data['Timestamp'], data['Flame_Intensity'], marker='o', color='orange')
        axs[0].set_title('Flame Intensity Over Time')
        axs[0].set_ylabel('Intensity')
        axs[0].grid(True)

        # Plot Temperature and CO Level over Time
        axs[1].plot(data['Timestamp'], data['Temperature'], marker='s', color='blue', label='Temperature (°C)')
        axs[1].plot(data['Timestamp'], data['CO_Level'], marker='^', color='green', label='CO Level (ppm)')
        axs[1].set_title('Temperature and CO Level Over Time')
        axs[1].set_ylabel('Value')
        axs[1].legend()
        axs[1].grid(True)

        # Plot Motion Detection over Time
        axs[2].step(data['Timestamp'], data['Motion_Detected'], where='mid', color='red')
        axs[2].set_title('Motion Detection Over Time')
        axs[2].set_xlabel('Timestamp')
        axs[2].set_ylabel('Motion Detected')
        axs[2].set_yticks([0, 1])
        axs[2].set_yticklabels(['No', 'Yes'])
        axs[2].grid(True)

    except Exception as e:
        print(f"Error reading or plotting data: {e}")

# Set up the animation
ani = animation.FuncAnimation(fig, animate, interval=1000)

# Display the plots
plt.show()
