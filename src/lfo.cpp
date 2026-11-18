#include "lfo.h"
#include <cmath>

constexpr float PI = 3.14159265358979323846f;

LFO::LFO(float sampleRate)
    : rate(0.0f),
      sampleRate(sampleRate),
      phase(0.0f) {
}

void LFO::setRate(float newRate) {
    if (newRate >= 0.0f &&
        newRate < sampleRate / 2.0f) {
        rate = newRate;
    }
}

float LFO::nextSample() {
    float sample = sinf(2.0f * PI * phase);

    phase += rate / sampleRate;

    if (phase >= 1.0f) {
        phase -= 1.0f;
    }

    return sample;
}
