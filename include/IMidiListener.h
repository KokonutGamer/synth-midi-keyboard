// Interface for any object that recieves MIDI input (synthesizer)

#include <cstdint>

class IMidiListener {
    public:
        // Called by MidiInput to notify of new note
        virtual void noteOn(uint8_t note, uint8_t vel);
        virtual void noteOff(uint8_t note, uint8_t vel);
        virtual void cc(uint8_t module, uint8_t val); // control change

        virtual ~IMidiListener() = default;
};