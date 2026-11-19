// Coordinates voices and returns samples for output.

#include "Voice.h"

class Synthesizer {
    private:

    public:
        void noteOn(uint8_t note);
        void noteOff(uint8_t note);
        void cc(uint8_t module, uint8_t val); // control change

        uint16_t renderSample(); // prompts modules and returns sample to be written to DAC

};