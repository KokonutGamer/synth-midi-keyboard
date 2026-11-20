#include <Arduino.h>
#include "Synthesizer.h"

/*
 * Globals
 */
Synthesizer synth;

/*
 * Arduino
 */
void setup() {
	Serial.begin(115200);
	Serial.println("Hello, World!");

	Synthesizer synth = Synthesizer(static_cast<uint32_t>(44100)); // init synth object
}

void loop() {
	// TODO
}

/*
 * ISR
 */
void TC0_Handler()
{
   TC_GetStatus(TC0, 0); // read interrupt register to clear status flag
   synth.renderSample();
}