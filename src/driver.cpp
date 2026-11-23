#include <Arduino.h>
#include "Synthesizer.h"
#include "DacOutput.h"

/*
 * Globals
 */
static constexpr uint32_t SAMPLE_RATE = 44100;

Synthesizer synth = Synthesizer(static_cast<uint32_t>(SAMPLE_RATE));
static DacOutput dac;
volatile bool doRender = false;

/*
 * Arduino
 */
void setup() {
	Serial.begin(115200);
	Serial.println("Hello, World!");
}

void loop() {
	if (doRender) {
		dac.writeFloat(synth.renderSample());
		doRender = false;
	}
}

/*
 * ISR
 */
void TC0_Handler() {
   TC_GetStatus(TC0, 0); // read interrupt register to clear status flag
   doRender = true;
}