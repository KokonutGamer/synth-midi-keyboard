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
	/**
	 * Amount of wave cycles per second eg 440Hz
	 */
	float frequency;

	/**
	 * Amount of audio waveform samples generated per second
	 */
	float sampleRate;

	/**
	 * Fracitional position within a wavecycle. It ranges from 0-1
	 */
	float phase;

 public:
	/**
	 * Constructs an oscillator with the specified sample rate
	 *
	 * @param sampleRate    Number of digital samples per second
	 */
	Oscillator(float sampleRate);

	/**
	 * Sets the frequency of the sine wave
	 *
	 * @param newFrequency    Amount of wave cycles per second
	 */
	void setFrequency(float newFrequency);

	/**
	 * Calculates the precise amplitude of the wave at its current position
	 */
	float nextSample();
};

#endif
