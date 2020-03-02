#include "AudioTools.h"

void Oscillator::setup(float _frequency, double _phase, float _amplitude, int _sampleRate) {
	frequency = _frequency;
	phase = _phase;
	amplitude = _amplitude;
	sampleRate = _sampleRate;
	phaseInc = (TWO_PI * frequency) / (double)sampleRate;
	currentSample = 0;
}

float Oscillator::getSample() {
	currentSample = sin(phase) * amplitude;
	phase += phaseInc;
	return currentSample;
}

void Oscillator::setFrequency(float _freq) {
	frequency = _freq;
	phaseInc = (TWO_PI * frequency) / (double)sampleRate;
}

void Oscillator::setAmplitude(float _amp) {
	amplitude = _amp;
}