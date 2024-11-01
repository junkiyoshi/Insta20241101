#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(200);
	ofNoFill();
	ofSetLineWidth(2);

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	this->frame_number = 0;
}

//--------------------------------------------------------------
void ofApp::update() {

	this->frame_number += 1;
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	for (int k = 0; k < 15; k++) {

		ofRotate(24);

		vector<glm::vec2> vertices;
		for (int i = 0; i < 80; i++) {

			auto radius = ofMap(sin((this->frame_number + i) * DEG_TO_RAD * 1.44), -1, 1, 100, 300);
			auto deg = (this->frame_number + i) * 3;
			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			radius = ofMap(sin((this->frame_number + i + 1) * DEG_TO_RAD * 1.44), -1, 1, 100, 300);
			deg = (this->frame_number + i + 1) * 3;
			auto next = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			ofSetLineWidth(ofMap(i, 0, 80, 0.1, 2.5));
			ofDrawLine(location, next);

		}
	}

	/*
	int start = 300;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}