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
