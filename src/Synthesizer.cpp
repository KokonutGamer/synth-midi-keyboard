#include "Synthesizer.h"
#include <include/pmc.h>
// TODO: #include "noteTable.h"

Synthesizer::Synthesizer(uint32_t sampleRate) : m_SampleRate(sampleRate) {
    initSampleTimer();
}

uint32_t Synthesizer::getSampleRate() {
    return m_SampleRate;
}

// Timer triggers ISR: void TC0_Handler() {}
void Synthesizer::initSampleTimer() {
    pmc_set_writeprotect(false); // allow writing to PCM (clock) registers
    pmc_enable_periph_clk(ID_TC0); // enable peripheral clock 0

    // configure TC0, channel 0, waveform mode | count up and reset on RC | use clock 1 (Master clock/2)
    TC_Configure(TC0, 0, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK1);

    uint32_t compareValue = 84000000/2/m_SampleRate; // MCK/divisor/SampleRate
    TC_SetRC(TC0, 0, compareValue);

    // attach interrupt to RC compare value
    TC0->TC_CHANNEL[0].TC_IER =  TC_IER_CPCS;
    TC0->TC_CHANNEL[0].TC_IDR = ~TC_IER_CPCS;

    TC_Start(TC0, 0); // start timer
    NVIC_EnableIRQ(TC0_IRQn); // enable interrupt in interrupt controller
}


// TODO: Module management
void Synthesizer::noteOn(uint8_t note) {
}

void Synthesizer::noteOff(uint8_t note) {
}

void Synthesizer::cc(uint8_t module, uint8_t val) {
}

uint16_t Synthesizer::renderSample() {
    float sample = ((vco.nextSample()+lfo.nextSample())/2.0f)*env.nextSample();
    return static_cast<uint16_t>(sample);
}