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
