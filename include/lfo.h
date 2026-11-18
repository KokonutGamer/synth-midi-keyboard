#ifndef LFO_H
#define LFO_H

class LFO {
private:
    float rate;
    float sampleRate;
    float phase;

public:
    LFO(float sampleRate);

    void setRate(float newRate);

    float nextSample();
};

#endif
