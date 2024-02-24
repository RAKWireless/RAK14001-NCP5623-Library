#include <Wire.h>

#include "Arduino.h"
#include "NCP5623.h"


NCP5623::NCP5623() {
    _addr = NCP5623_DEFAULT_ADDR;
    _red = 2;
    _green = 1;
    _blue = 0;
}

bool NCP5623::begin(TwoWire &wirePort) {
    _i2cPort = &wirePort;
    _addr = NCP5623_DEFAULT_ADDR;

    // Checking if sensor exists on the I2C line
    _i2cPort->beginTransmission(_addr);
	_i2cPort->write((uint8_t)0x00);
	if (_i2cPort->endTransmission())
		return false;

    setColor(0,0,0);

    return true;
}

void NCP5623::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    setRed(red);
    setGreen(green);
    setBlue(blue);
}

void NCP5623::setRed(uint8_t value) {
	if(value != 0 && value < 8) 
		value = 8;
    setChannel(_red,(value>>3));
}

void NCP5623::setGreen(uint8_t value) {
	if(value != 0 && value < 8) 
		value = 8;
    setChannel(_green,(value>>3));
}

void NCP5623::setBlue(uint8_t value) {
	if(value != 0 && value < 8) 
		value = 8;

    setChannel(_blue,(value>>3));
}

void NCP5623::setChannel(uint8_t channel, uint8_t value) {
    writeReg(NCP5623_REG_CHANNEL_BASE+channel, value);
}

void NCP5623:: setGradualDimming(uint32_t setpMs) {
	if(setpMs != 0 && setpMs < 8)
		setpMs = 8;
	setpMs = (setpMs>248) ? 248 : setpMs;

    writeReg(7, (setpMs>>3));
}

void NCP5623:: setGradualDimmingUpEnd(uint8_t value) {// 0-31
    writeReg(5, value);
}

void NCP5623:: setGradualDimmingDownEnd(uint8_t value) {// 0-31
    writeReg(6, value);
}

void NCP5623::writeReg(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(_addr);
    Wire.write(((reg&0x7)<<5)|(value&0x1f)); // rrrvvvvv
    Wire.endTransmission();
}

void NCP5623::setCurrent(uint8_t iled) {
    iled = (iled>30)?30:iled;

    writeReg(NCP5623_REG_ILED, iled);
}

void NCP5623::mapColors(uint8_t red, uint8_t green, uint8_t blue) {
    _red = red;
    _green = green;
    _blue = blue;
}

void NCP5623::shutDown(void) {
	writeReg(0, 0);
}
