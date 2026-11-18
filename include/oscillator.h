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
#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator {
 private:
	// This is the amount of wave cyccles per second. eg 440Hz
	float frequency;
	// this is the sample rate per second. eg 44100 Hz
	float sampleRate;

	// This is how we determine when one wave starts and
	// another ends. It is a value between 0 and 1. 
	// we incremented by this value starting from 0 to 1
	// it is calculated by frequency/sampleRate
	float phase;

 public:
	Oscillator(float sampleRate);

	void setFrequency(float newFrequency);

    // calculates the precise next point on our wave
    // after 1/samplerate seconds
	float nextSample();
};

#endif
