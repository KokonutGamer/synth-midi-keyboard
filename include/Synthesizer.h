// Coordinates modules and returns samples for output.

// TODO: #include VCO
// TODO: #include LFO
// TODO: #include EG

#include <cstdint>

class Synthesizer {
 private:
	uint32_t m_SampleRate;

	/**
	 * Start sampling
	 */
	void initSampleTimer();

	// TODO: hold modules

 public:
	/**
	 * Constructor
	 */
	Synthesizer(uint32_t sampleRate = 44100U);

	/**
	 * Returns sample rate
	 */
	uint32_t getSampleRate();

	/**
	 * Play a note with the given frequency.
	 *
	 * @param note  	The frequency of the note to play.
	 * @param velocity	The velocity of the note to play.
	 */
	void noteOn(uint8_t note, uint8_t velocity);

	/**
	 * Stop playing a note with the given frequency.
	 *
	 * @param note  	The frequency of the note to stop.
	 * @param velocity	The velocity of the note to stop.
	 */
	void noteOff(uint8_t note, uint8_t velocity);

	/**
	 * Edit a module control value.
	 *
	 * @param module    The module to edit.
	 * @param val       The updated value.
	 */
	void cc(uint8_t module, uint8_t val);  // control change

	/**
	 * Prompt modules for values, combine values into sample, write sample to DAC.
	 */
	uint16_t renderSample();
};