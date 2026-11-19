// Coordinates modules and returns samples for output.

#include <cstdint>

class Synthesizer {
    private:
        static constexpr uint32_t sampleRate = 44100;

    public:
        uint32_t getSampleRate();
        void initSampleTimer();

        void noteOn(uint8_t note);
        void noteOff(uint8_t note);
        void cc(uint8_t module, uint8_t val); // control change

        uint16_t renderSample(); // prompts modules and returns sample to be written to DAC

};