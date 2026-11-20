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
#ifndef LFO_H
#define LFO_H

class LFO {
 private:
	/**
	 * Amount of modulation wave cycles per second eg. 5Hz
	 */
	float rate;

	/**
	 * Amount of modulation waveform samples generated per second
	 */
	float sampleRate;

	/**
	 * Fracitional position within a the modulation wavecycle. It ranges from 0-1
	 */
	float phase;

 public:
	/**
	 * Constructs a modulator with the specified sample rate
	 *
	 * @param sampleRate    Number of digital samples per second
	 */
	LFO(float sampleRate);

	/**
	 * Sets the frequency of the modulation wave
	 *
	 * @param newRate    Amount of modulation wave cycles per second
	 */

	void setRate(float newRate);

	/**
	 * Calculates the precise amplitude of the modulation wave at its current
	 * position
	 */
	float nextSample();
};

#endif
