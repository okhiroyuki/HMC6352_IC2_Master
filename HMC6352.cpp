#include <Arduino.h>
#include <Wire.h>
#include <HMC6352.h>

// void constructor
HMC6352::HMC6352()
{
	address_ = 0x21;
};	

// user-specified address
HMC6352::HMC6352(int address)
{
	address_ = address;
};

float HMC6352::getHeading()
{
	Wire.beginTransmission(address_);
	Wire.write(c_getDataStandby_);	
	Wire.endTransmission();

	delay(7);

	Wire.requestFrom(address_, 2);

	byte highByte	= Wire.read();
	byte lowByte	= Wire.read();

	return((highByte*256+lowByte)/10.0);
}