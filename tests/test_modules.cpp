/*
 * AI Assistance Disclosure
 *
 * AI Tool: OpenAI ChatGPT (GPT-6)
 *
 * This code was generated with assistance from ChatGPT.
 * I reviewed the implementation and studied its logic, including
 * the functions, variables, calculations, and control flow.
 * I understand how the code works and can explain its functionality.
 *
 * Verification: I reviewed the code line by line and checked
 * its logic against the intended module behavior.
 *
 * Author: Matiyas Dawit
 */
#include "oscillator.h"
#include "lfo.h"
#include <cmath>
#include <cassert>
#include <iostream>


/**
 * Test to see if the oscillator (VCO) generates the correct samples
 * We test it against values that were calculated beforehand.
 */
void testOscillator() {
    Oscillator vco(8.0f);
    vco.setFrequency(2.0f);

    float expected[] = {0, 1, 0, -1, 0};

    for (int i = 0; i < 5; i++) {
        float actual = vco.nextSample();
        assert(std::fabs(actual - expected[i]) < 0.0001f);
    }

    std::cout << "VCO test passed\n";
}

/**
 * Test to see if the LFO generates the correct samples
 * We test it against values that were calculated before hand.
 */
void testLFO() {
    LFO lfo(8.0f);
    lfo.setRate(2.0f);

    float expected[] = {0, 1, 0, -1, 0};

    for (int i = 0; i < 5; i++) {
        float actual = lfo.nextSample();
        assert(std::fabs(actual - expected[i]) < 0.0001f);
    }

    std::cout << "LFO test passed\n";
}

int main() {
    testOscillator();
    testLFO();
    return 0;
}