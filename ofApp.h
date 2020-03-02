#pragma once

#include "ofMain.h"
#include "AudioTools.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void mouseMoved(int x, int y );
		void audioOut(float* buffer, int bufferSize, int nChannels);

		int sampleRate;

		Oscillator oscArray[12];
};