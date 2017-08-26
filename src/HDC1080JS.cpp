#include "Wire.h"
#include "HDC1080JS.h"

HDC1080JS::HDC1080JS(){

}

void HDC1080JS::config(){

	temperatureRaw=0;
	humidityRaw=0;

	//config the temp sensor to read temp then humidity in one transaction
	//config the resolution to 14 bits for temp & humidity

	writeRegister(0x02,0x10);

}

void HDC1080JS::writeRegister(uint8_t address, uint16_t value){
	Wire.beginTransmission(ADDR);
	Wire.write(address);
	Wire.write(value);
	Wire.endTransmission();
}



void HDC1080JS::readTempHumid(){
	//set pointer register
	Wire.beginTransmission(ADDR);
	Wire.write(0x00);
	Wire.endTransmission();
	delay(15);
	Wire.requestFrom(ADDR, 4);
	temperatureRaw = temperatureRaw << 8 | Wire.read();
	temperatureRaw = temperatureRaw << 8 | Wire.read();
	humidityRaw = humidityRaw << 8 | Wire.read();
	humidityRaw = humidityRaw << 8 | Wire.read();

}

//returns temp in celcius
float HDC1080JS::getTemp(){

	// (rawTemp/2^16)*165 - 40
	return ( (float)temperatureRaw )*165/65536 - 40;

}

float HDC1080JS::getRelativeHumidity(){

	//(rawHumidity/2^16)*100
	return ( (float)humidityRaw )*100/65536;
}

float* HDC1080JS::getTempHumid(float* tempHumid){

	*tempHumid = getTemp();
	*(tempHumid+1) = getRelativeHumidity();
	return tempHumid;

}
