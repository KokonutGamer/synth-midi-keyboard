#include <Arduino.h>
#include "Synthesizer.h"

void setup() {
	Serial.begin(115200);
	Serial.println("Hello, World!");

	Synthesizer Synth; // init synth object
	Synth.initSampleTimer(); // start sample timer
}

void loop() {
	// TODO
}


// ISR
void TC0_Handler()
{
   TC_GetStatus(TC0, 0); // read interrupt register to clear status flag
}