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

/**
 * Constructs a modulator with the specified sample rate
 *
 * @param sampleRate    Number of digital samples per second
 */
LFO::LFO(float sampleRate) : rate(0.0f), sampleRate(sampleRate), phase(0.0f) {}

/**
 * Sets the frequency of the modulation wave
 *
 * @param newRate    Amount of modulation wave cycles per second
 */
void LFO::setRate(float newRate) {
	if (newRate >= 0.0f && newRate < sampleRate / 2.0f) {
		rate = newRate;
	}
}

/**
 * Calculates the precise amplitude of the modulation wave at its current
 * position
 */
float LFO::nextSample() {
	float sample = sinf(2.0f * PI * phase);

	phase += rate / sampleRate;

	if (phase >= 1.0f) {
		phase -= 1.0f;
	}

	return sample;
}
