#ifndef AUDIO_OUT
#define AUDIO_OUT

#include <cstdint>

class DacOutput {
    public:
        void initDac();
        void write(float sample);

    private:
        static constexpr uint32_t kMaxCode = 4095;
};

#endif