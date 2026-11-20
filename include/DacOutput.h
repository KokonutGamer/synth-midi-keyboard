#ifndef DAC_OUTPUT
#define DAC_OUTPUT

#include <cstdint>

class DacOutput {
    public:
        void init();
        void write(uint16_t sample);
        void writeFloat(float fSample);
};

#endif