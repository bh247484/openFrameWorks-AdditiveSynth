#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	sampleRate = 48000;

	for (int i = 0; i < 12; i++) {
		oscArray[i].setup(200 * (i + 1), 0, 1/(float)(i + 1), sampleRate);
	}
	

	ofSoundStreamSetup(2, 0, sampleRate, 256, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::audioOut(float* buffer, int bufferSize, int nChannels){

	for (int i = 0; i < bufferSize; i++) {

		float currentSample = 0;

		for (int j = 0; j < 12; j++) {
			currentSample += oscArray[j].getSample();
		}

		currentSample *= 0.1;

		buffer[i*nChannels + 0] = currentSample;
		buffer[i*nChannels + 1] = currentSample;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	float newFreq = ofMap(x, 0, ofGetWidth(), 40, 2000);

	for (int i = 0; i < 12; i++) {
		oscArray[i].setFrequency(newFreq * (i + 1));
	}

	float newAmp = ofMap(y, 0, ofGetHeight(), 1.0, 0.0);

	for (int i = 0; i < 12; i++) {
		oscArray[i].setAmplitude(newAmp * (1/(float)(i+1)));
	}
}

//--------------------------------------------------------------
void ofApp::exit() {
	ofSoundStreamClose();
}
