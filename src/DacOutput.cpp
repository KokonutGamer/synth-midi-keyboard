#include <Arduino.h>
#include "DacOut.h"

class DacOut;

void DacOut::initDac() {
    pmc_enable_periph_clk(ID_DACC);
    DACC->DACC_CR = DACC_CR_SWRST;
    DACC->DACC_MR = DACC_MR_TRGEN_DIS        // free-run, write = convert
                  | DACC_MR_WORD_HALF        // 16-bit write, low 12 used
                  | DACC_MR_USER_SEL_CHANNEL0
                  | DACC_MR_STARTUP_8
                  | DACC_MR_REFRESH(1)
                  | DACC_MR_MAXS;
    DACC->DACC_CHER = DACC_CHER_CH0;         // enable channel 0 (DAC0 pin)
}

void DacOut::write(float sample) {
    if (sample > 1.0f)  sample = 1.0f;
    if (sample < -1.0f) sample = -1.0f;

    uint32_t code = (uint32_t)((sample * 0.5f + 0.5f) * kMaxCode);

    if (DACC->DACC_ISR & DACC_ISR_TXRDY) {   // skip if busy, never block in ISR
        DACC->DACC_CDR = code;
    }
}