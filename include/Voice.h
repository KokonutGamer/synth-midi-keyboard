// Voice holds modules to make a sound

#include <cstdint>

class Voice {
    private:
        // Modules
        // VCO vco;
        // LFO lfo;
        // EG eg;

    public:
        void noteOn(uint8_t note, uint8_t vel);
        void noteOff(uint8_t note, uint8_t vel);
        void cc(uint8_t module, uint8_t val); // control change

        uint16_t renderSample();
};