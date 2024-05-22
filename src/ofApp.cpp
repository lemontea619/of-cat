#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofBackground(255, 255, 255);
  ofSetCircleResolution(200);
  catRadius = 40;
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 15; x++) {
      ofColor baseColor = x % 2 == 0 ? ofColor(192) : ofColor(0);

      ofColor eyeColor, highlightColor;
      if (x % 3 == 0) {
        eyeColor = ofColor(65, 105, 255);
        highlightColor = ofColor(255);
      } else if (x % 2 == 0) {
        eyeColor = ofColor(0);
        highlightColor = ofColor(255);
      } else {
        eyeColor = ofColor(255);
        highlightColor = ofColor(0);
      }

      bool isWink = x % 2 == 0 && (int)ofGetElapsedTimef() % 2 == 0;

      drawCat(catRadius * (2.5 * x + 1), catRadius * (2.5 * y + 1), catRadius,
              baseColor, eyeColor, highlightColor, isWink);
    }
  }
}

void ofApp::drawCat(int x, int y, int radius, ofColor baseColor,
                    ofColor eyeColor, ofColor highlightColor, bool isWink) {
  // 顔のベース
  ofSetColor(baseColor);
  ofDrawCircle(x, y, radius);

  // 左耳
  ofSetColor(baseColor);
  ofDrawTriangle(x - 3.6 * radius / 8.0, y - 7.2 * radius / 8.0,
                 x - 9.6 * radius / 8.0, y - 9.2 * radius / 8.0,
                 x - 6 * radius / 8.0, y + 2 * radius / 8.0);

  // 右耳
  ofSetColor(baseColor);
  ofDrawTriangle(x + 9.2 * radius / 8.0, y - 9.2 * radius / 8.0,
                 x + 3.6 * radius / 8.0, y - 7.2 * radius / 8.0,
                 x + 7.6 * radius / 8.0, y - 1.6 * radius / 8.0);

  // おでこ
  ofSetColor(255, 255, 255);
  ofDrawEllipse(x, y - 6 * radius / 8.0, 1.2 * radius / 8.0,
                5.2 * radius / 8.0);
  ofDrawEllipse(x - 2 * radius / 8.0, y - 6.4 * radius / 8.0,
                1.2 * radius / 8.0, 5.2 * radius / 8.0);
  ofDrawEllipse(x + 2 * radius / 8.0, y - 6.4 * radius / 8.0,
                1.2 * radius / 8.0, 5.2 * radius / 8.0);

  // 左目
  ofSetColor(eyeColor);
  ofDrawCircle(x - 3.6 * radius / 8.0, y + 2 * radius / 8.0, radius / 8.0);
  ofSetColor(highlightColor);
  ofDrawCircle(x - 3.2 * radius / 8.0, y + 1.6 * radius / 8.0,
               0.4 * radius / 8.0);

  // 右目
  if (isWink) {
    ofSetColor(eyeColor);
    ofSetLineWidth(2);
    ofDrawLine(x + 2 * radius / 8.0, y + 2 * radius / 8.0, x + 4 * radius / 8.0,
               y + 2 * radius / 8.0);
  } else {
    ofSetColor(eyeColor);
    ofDrawCircle(x + 3.2 * radius / 8.0, y + 2 * radius / 8.0, radius / 8.0);
    ofSetColor(highlightColor);
    ofDrawCircle(x + 3.6 * radius / 8.0, y + 1.6 * radius / 8.0,
                 0.4 * radius / 8.0);
  }

  // 鼻
  ofSetColor(0, 0, 0);
  ofDrawTriangle(x - 0.8 * radius / 8.0, y + 4 * radius / 8.0,
                 x + 0.4 * radius / 8.0, y + 4 * radius / 8.0,
                 x - 0.2 * radius / 8.0, y + 4.6 * radius / 8.0);

  // 口
  ofSetColor(0, 0, 0);
  ofSetLineWidth(2);
  ofDrawLine(x - 0.2 * radius / 8.0, y + 4.6 * radius / 8.0,
             x - 0.2 * radius / 8.0, y + 4.72 * radius / 8.0);
  ofDrawLine(x - 0.2 * radius / 8.0, y + 4.72 * radius / 8.0,
             x + 0.4 * radius / 8.0, y + 5 * radius / 8.0);
  ofDrawLine(x - 0.2 * radius / 8.0, y + 4.72 * radius / 8.0,
             x - 0.8 * radius / 8.0, y + 5 * radius / 8.0);
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
