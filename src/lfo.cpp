/*
 * AI Assistance Disclosure
 *
 * AI Tool: OpenAI ChatGPT (GPT-6)
 *
 * This code was generated with assistance from ChatGPT.
 * I reviewed the implementation and studied its logic, including
 * the functions, variables, calculations, and control flow.
 * I understand how the code works and can explain its functionality.
 *
 * Verification: I reviewed the code line by line and checked
 * its logic against the intended module behavior.
 *
 * Author: Matiyas Dawit
 */
#include "lfo.h"
#include <cmath>

constexpr float PI = 3.14159265358979323846f;

LFO::LFO(float sampleRate)
    : rate(0.0f),
      sampleRate(sampleRate),
      phase(0.0f) {
}

void LFO::setRate(float newRate) {
    if (newRate >= 0.0f &&
        newRate < sampleRate / 2.0f) {
        rate = newRate;
    }
}

float LFO::nextSample() {
    float sample = sinf(2.0f * PI * phase);

    phase += rate / sampleRate;

    if (phase >= 1.0f) {
        phase -= 1.0f;
    }

    return sample;
}
