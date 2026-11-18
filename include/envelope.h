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
    enum class Stage {
        Idle,
        Attack,
        Decay,
        Sustain,
        Release
    };

    Stage stage;

    float sampleRate;
    float level;

    float attackTime;
    float decayTime;
    float sustainLevel;
    float releaseTime;
    float releaseStep;

public:
    Envelope(float sampleRate);

    void setADSR(float attack,
                 float decay,
                 float sustain,
                 float release);

   
                 // triggers attack
    void noteOn();
    // triggers release
    void noteOff();

    // tries to get the next point in our current stage
    float nextSample();
};

#endif
