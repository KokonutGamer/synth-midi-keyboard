#include <Arduino.h>
#include "Synthesizer.h"

void setup() {
	Serial.begin(115200);
	Serial.println("Hello, World!");

	// Synth timer test
	Synthesizer Synth;
	Synth.initSampleTimer();
	pinMode(13,OUTPUT);
}

void loop() {
	// TODO
}


// ISR

volatile boolean pinOn;

void TC0_Handler()
{
   TC_GetStatus(TC0, 0);
   digitalWrite(13, pinOn = !pinOn);
}