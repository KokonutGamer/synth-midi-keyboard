#include <Arduino.h>

#include "DacOutput.h"

static DacOutput dac;

void setup() {
	Serial.begin(115200);
	Serial.println("==================== Running DAC Test ====================");
}

void loop() {
	dac.write(4095U);
	delayMicroseconds(1136);
	dac.write(0U);
	delayMicroseconds(1136);
}
