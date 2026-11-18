// Synthesizer header, takes midi input, coordinates voices
// and returns samples for output

// #include "Voice.h"
#include "IMidiListener.h"
#include <cstdint>

class Synthesizer : public IMidiListener {
    private:
        // Voice voice;

    public:
        void noteOn(uint8_t note, uint8_t vel);
        void noteOff(uint8_t note, uint8_t vel);
        void cc(uint8_t module, uint8_t val); // control change

        uint16_t renderSample(); // prompts modules and returns sample to be written to DAC

};