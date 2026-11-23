#include <Arduino.h>
#include <MIDI.h>

#include "synthesizer.h"

/*
 * Globals
 */
MIDI_CREATE_DEFAULT_INSTANCE()

static Synthesizer synth;  // default constructed

/**
 * Triggers when the default MIDI instance receives a NoteOn event.
 *
 * @param channel 	Channel the message came from.
 * @param pitch		Pitch of the note to play.
 * @param velocity	Velocity of the note to play.
 */
void handleNoteOn(byte channel, byte pitch, byte velocity) {
	synth.noteOn(pitch, velocity);  // TODO modify synth with velocity
}
/**
 * Triggers when the default MIDI instance receives a NoteOff event.
 *
 * @param channel 	Channel the message came from.
 * @param pitch		Pitch of the note to stop.
 * @param velocity	Velocity of the note to stop.
 */

void handleNoteOff(byte channel, byte pitch, byte velocity) {
	synth.noteOff(pitch, velocity);  // TODO modify synth with velocity
}

/*
 * Arduino
 */
void setup() {
	Serial.begin(115200);
	MIDI.begin(MIDI_CHANNEL_OMNI);
	MIDI.setHandleNoteOn(handleNoteOn);
	MIDI.setHandleNoteOff(handleNoteOff);
}

void loop() {
	MIDI.read();  // polls the MIDI serial line for data; triggers appropriate
	              // callbacks
}

/*
 * ISR
 */
void TC0_Handler() {
	TC_GetStatus(TC0, 0);  // read interrupt register to clear status flag
	synth.renderSample();
}