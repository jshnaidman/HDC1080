#ifndef HDC1080JS_h
#define HDC1080JS_h

#include "Arduino.h"

#define ADDR 0x40

//Can use up to 400khz Clockspeed

class HDC1080JS{
	public:
		HDC1080JS();
		void config();
		void readTempHumid();

		float getTemp();
		float getRelativeHumidity();
		float* getTempHumid(float* tempHumid);

	private:
		uint16_t temperatureRaw;
		uint16_t humidityRaw;

		void writeRegister(uint8_t address, uint16_t value);
};
#endif
