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
#include "oscillator.h"
#include <cmath>

constexpr float PI = 3.14159265358979323846f;

Oscillator::Oscillator(float sampleRate)
    : frequency(440.0f),
      sampleRate(sampleRate),
      phase(0.0f) {
}

void Oscillator::setFrequency(float newFrequency) {
    if (newFrequency >= 0.0f &&
        newFrequency < sampleRate / 2.0f) {
        frequency = newFrequency;
    }
}

float Oscillator::nextSample() {
    // Generate the current waveform sample.
    float sample = sinf(2.0f * PI  * phase);

    // Advance phase by one sample.
    phase += frequency / sampleRate;

    // Wrap phase back into the range [0, 1).
    if (phase >= 1.0f) {
        phase -= 1.0f;
    }

    return sample;
}
