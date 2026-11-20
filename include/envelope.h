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
#ifndef ENVELOPE_H
#define ENVELOPE_H

class Envelope {
 private:
	enum class Stage { Idle, Attack, Decay, Sustain, Release };

	Stage currentStage;

	float sampleRate;
	float level;

	float attackTime;
	float decayTime;
	float sustainLevel;
	float releaseTime;
	float releaseStep;

 public:
	Envelope(float sampleRate);

	/**
	 * Sets the duration of each stage of the ADSR envelope.
	 *
	 * @param attack    The duration of the attack stage in milliseconds.
	 * @param decay     The duration of the decay stage in milliseconds.
	 * @param sustain   The duration of the sustain stage in milliseconds.
	 * @param release   The duration of the release stage in milliseconds.
	 */
	void setADSR(float attack, float decay, float sustain, float release);

	/**
	 * Triggers the attack stage
	 */
	void noteOn();

	/**
	 * Triggers the release stage
	 */
	void noteOff();

	/**
	 * Calculates the next amplitude level based on its current stage
	 */
	float nextSample();
};

#endif
