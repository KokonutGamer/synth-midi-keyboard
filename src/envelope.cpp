
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
#include "envelope.h"

static constexpr float DEFAULT_ATK = 0.1f;
static constexpr float DEFAULT_DCY = 0.2f;
static constexpr float DEFAULT_SUS = 0.7f;
static constexpr float DEFAULT_REL_TIME = 0.3f;
static constexpr float DEFAULT_REL_STEP = 0.0f;

Envelope::Envelope(float sampleRate)
    : currentStage(Stage::Idle),
      sampleRate(sampleRate),
      level(0.0f),
      attackTime(DEFAULT_ATK),
      decayTime(DEFAULT_DCY),
      sustainLevel(DEFAULT_SUS),
      releaseTime(DEFAULT_REL_TIME),
      releaseStep(DEFAULT_REL_STEP) {}

/**
 * Sets the duration of each stage of the ADSR envelope.
 *
 * @param attack    The duration of the attack stage in milliseconds.
 * @param decay     The duration of the decay stage in milliseconds.
 * @param sustain   The duration of the sustain stage in milliseconds.
 * @param release   The duration of the release stage in milliseconds.
 */
void Envelope::setADSR(float attack, float decay, float sustain,
                       float release) {
	attackTime = attack >= 0.0f ? attack : 0.0f;
	decayTime = decay >= 0.0f ? decay : 0.0f;

	sustainLevel = sustain;
	if (sustainLevel < 0.0f) sustainLevel = 0.0f;
	if (sustainLevel > 1.0f) sustainLevel = 1.0f;

	releaseTime = release >= 0.0f ? release : 0.0f;
}

/**
 * Triggers the attack stage
 */
void Envelope::noteOn() {
	level = 0.0f;
	currentStage = Stage::Attack;
}

/**
 * Triggers the release stage
 */
void Envelope::noteOff() {
	if (currentStage == Stage::Idle) {
		return;
	}

	if (releaseTime <= 0.0f || sampleRate <= 0.0f) {
		level = 0.0f;
		currentStage = Stage::Idle;
	} else {
		releaseStep = level / (releaseTime * sampleRate);
		currentStage = Stage::Release;
	}
}

/**
 * Calculates the next amplitude level based on its current stage
 */
float Envelope::nextSample() {
	switch (currentStage) {
		case Stage::Idle:
			level = 0.0f;
			break;

		case Stage::Attack:
			if (attackTime <= 0.0f || sampleRate <= 0.0f) {
				level = 1.0f;
			} else {
				level += 1.0f / (attackTime * sampleRate);
			}

			if (level >= 1.0f) {
				level = 1.0f;
				currentStage = Stage::Decay;
			}
			break;

		case Stage::Decay:
			if (decayTime <= 0.0f || sampleRate <= 0.0f) {
				level = sustainLevel;
			} else {
				level -= (1.0f - sustainLevel) / (decayTime * sampleRate);
			}

			if (level <= sustainLevel) {
				level = sustainLevel;
				currentStage = Stage::Sustain;
			}
			break;

		case Stage::Sustain:
			level = sustainLevel;
			break;

		case Stage::Release:
			level -= releaseStep;

			if (level <= 0.0f) {
				level = 0.0f;
				currentStage = Stage::Idle;
			}
			break;
	}

	return level;
}
