#ifndef DAC_OUTPUT
#define DAC_OUTPUT

#include <cstdint>

class DacOutput {
 public:
	/**
	 * Constructor
	 */
	DacOutput();

	/**
	 * Initializes DAC0 pin for analog writing
	 */
	void init();

	/**
	 * Writes 12 bit value to DAC
	 *
	 * @param sample    Rendered sample as uint16_t [0, 4095].
	 */
	void write(uint16_t sample);

	/**
	 * Converts to 12 bit val centered on 2047 then writes to DAC
	 *
	 * @param fSample   Rendered sample as float [-1, 1].
	 */
	void writeFloat(float fSample);
};

#endif