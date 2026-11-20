// Coordinates modules and returns samples for output.

// TODO: #include VCO
// TODO: #include LFO
// TODO: #include EG

#include <cstdint>

class Synthesizer {
    private:
        uint32_t m_SampleRate = 44100;

        /**
         * Start sampling
         */
        void initSampleTimer();

        // TODO: hold modules

    public:
        /**
         * Constructor
         */
        Synthesizer(uint32_t sampleRate) : m_SampleRate(sampleRate) {
            // TODO: instantiate modules
            initSampleTimer();
        }

        /**
         * Returns sample rate
         */
        uint32_t getSampleRate();

        /**
         * Play a note with the given frequency.
         *
         * @param note  The frequency of the note to play.
         */
        void noteOn(uint8_t note);

        /**
         * Stop playing a note with the given frequency.
         *
         * @param note  The frequency of the note to play.
         */
        void noteOff(uint8_t note);

        /**
         * Edit a module control value.
         *
         * @param module    The module to edit.
         * @param val       The updated value.
         */
        void cc(uint8_t module, uint8_t val); // control change

        /**
         * Prompt modules for values, combine values into sample, write sample to DAC.
         */
        uint16_t renderSample();
};