#include "Synthesizer.h"

void Synthesizer::noteOn(uint8_t note) {
    voice.noteOn(note);
}

void Synthesizer::noteOff(uint8_t note) {
    voice.noteOff(note);
}

void Synthesizer::cc(uint8_t module, uint8_t val) {
    voice.cc(module, val);
}

uint16_t Synthesizer::renderSample() { // prompts modules and returns sample to be written to DAC
    return voice.renderSample();
}