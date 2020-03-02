#ifndef AudioTools_h
#define AudioTools_h

#include "ofMain.h"


class Oscillator {

public:
	void setup(float _frequency, double _phase, float _amplitude, int _sampleRate);

	float getSample();

	void setFrequency(float _freq);
	void setAmplitude(float _amp);

private:
	float frequency;
	double phase;
	double phaseInc;
	float amplitude;
	float currentSample;
	int sampleRate;
};


#endif