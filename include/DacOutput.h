#ifndef DAC_OUTPUT
#define DAC_OUTPUT

#include <cstdint>

class DacOutput {
    public:
        void initDac();
        void write(uint16_t sample);

    private:
        static constexpr uint32_t kMaxCode = 4095;
};

#endif