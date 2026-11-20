#include "DacOutput.h"
#include <include/pmc.h>

void DacOutput::init() {
    pmc_enable_periph_clk(ID_DACC); // enable clock for DAC
    DACC->DACC_WPMR = DACC_WPMR_WPKEY(0x444143); // unlock DACC Mode Register for write
    // configure DACC Mode Register
    DACC->DACC_MR = DACC_MR_TRGEN_DIS // free running mode
                    | DACC_MR_WORD_HALF // use half-word
                    | DACC_MR_USER_SEL_CHANNEL0 // use DAC0
                    | DACC_MR_MAXS_MAXIMUM // max speed mode
                    | DACC_MR_STARTUP_8; // wait 8 cycles on startup
    DACC->DACC_CHER = DACC_CHER_CH0; // enable DAC0 channel
}

// expects uint16_t [0, 4095]
// converts 12 bit sample to voltage [1/6*5V, 5/6*5V]
void DacOutput::write(uint16_t sample) {
    DACC->DACC_CDR = sample;
}

// expects float [-1, 1] // probably ((VCO+LFO)*ENV)/2
// converts to 12 bit val centered on 2047
void DacOutput::writeFloat(float fSample) {
    write(uint16_t((fSample + 1.0f) * 2047.0f));
}
