#include "Synthesizer.h"

void Synthesizer::noteOn(uint8_t note, uint8_t vel) {
    voice.noteOn(note, vel);
}

void Synthesizer::noteOff(uint8_t note, uint8_t vel) {
    voice.noteOff(note, vel);
}

void Synthesizer::cc(uint8_t module, uint8_t val) { // control change
    voice.cc(module, val);
}

uint16_t Synthesizer::renderSample() { // prompts modules and returns sample to be written to DAC
    voice.renderSample();
}