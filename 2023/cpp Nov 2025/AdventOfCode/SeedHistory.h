#pragma once
class SeedHistory
{
	private: 
		long long seed; 
		long long soil; 
		long long fertilizer;
		long long water; 
		long long light; 
		long long temperature; 
		long long humidity; 
		long long location; 
	public:
		SeedHistory(long long seed);

		// Setters
		void setSoil(long long value) noexcept { soil = value; }
		void setFertilizer(long long value) noexcept { fertilizer = value; }
		void setWater(long long value) noexcept { water = value; }
		void setLight(long long value) noexcept { light = value; }
		void setTemperature(long long value) noexcept { temperature = value; }
		void setHumidity(long long value) noexcept { humidity = value; }
		void setLocation(long long value) noexcept { location = value; }

		// Getters
		long long getSeed() const noexcept { return seed; }
		long long getSoil() const noexcept { return soil; }
		long long getFertilizer() const noexcept { return fertilizer; }
		long long getWater() const noexcept { return water; }
		long long getLight() const noexcept { return light; }
		long long getTemperature() const noexcept { return temperature; }
		long long getHumidity() const noexcept { return humidity; }
		long long getLocation() const noexcept { return location; }
};

