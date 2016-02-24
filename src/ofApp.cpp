#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  
  float a = 100;
  
  ofVec3f p1 = ofVec3f(-a, a, a);
  ofVec3f p2 = ofVec3f(-a, a, -a);
  ofVec3f p3 = ofVec3f(a, a, -a);
  ofVec3f p4 = ofVec3f(a, a, a);

  points.push_back(p1);
  points.push_back(p2);
  points.push_back(p3);
  points.push_back(p4);
  
  ofVec3f p5 = ofVec3f(-a, -a, a);
  ofVec3f p6 = ofVec3f(-a, -a, -a);
  ofVec3f p7 = ofVec3f(a, -a, -a);
  ofVec3f p8 = ofVec3f(a, -a, a);
  
  points.push_back(p5);
  points.push_back(p6);
  points.push_back(p7);
  points.push_back(p8);

  numRecursions = 0;
  rotX = rotY = 0;
  needleLengthRatio = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  
  ofPushMatrix();
  rotX += 0.5;
  rotY += 0.5;
  ofRotateX(rotX);
  ofRotateY(rotY);
  
  ofSetColor(255, 255, 255);
  
  drawKochCurve(points[0], points[1], numRecursions);
  drawKochCurve(points[1], points[2], numRecursions);
  drawKochCurve(points[2], points[3], numRecursions);
  drawKochCurve(points[3], points[0], numRecursions);
  
  drawKochCurve(points[4], points[5], numRecursions);
  drawKochCurve(points[5], points[6], numRecursions);
  drawKochCurve(points[6], points[7], numRecursions);
  drawKochCurve(points[7], points[4], numRecursions);
  
  drawKochCurve(points[0], points[4], numRecursions);
  drawKochCurve(points[1], points[5], numRecursions);
  drawKochCurve(points[2], points[6], numRecursions);
  drawKochCurve(points[3], points[7], numRecursions);
  
  ofPopMatrix();

  cam.end();
}

void ofApp::drawKochCurve(const ofVec3f &p1, const ofVec3f &p2, int recursion) {
  ofVec3f v1 = (2 * p1 + p2) / 3;
  ofVec3f v2 = (p1 + 2 * p2) / 3;
  ofVec3f v3 = (p1 + p2) / 2;
  
  ofVec3f center(0, 0, 0);
  ofVec3f axis = (p1 - center).getCrossed(p2 - center).getNormalized();
  
  ofVec3f p3 = (v3 - p1).getRotated(90, -axis) * needleLengthRatio + v3;
  
  if(--recursion == 0) {
    ofDrawLine(p1, v1);
    ofDrawLine(v2, p2);
    ofDrawLine(v1, p3);
    ofDrawLine(v2, p3);
    return;
  } else if(recursion < 0) {
    ofDrawLine(p1, p2);
    return;
  }
  
  drawKochCurve(p1, v1, recursion);
  drawKochCurve(v2, p2, recursion);
  drawKochCurve(v1, p3, recursion);
  drawKochCurve(v2, p3, recursion);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  numRecursions = ofMap(x, 0, ofGetWidth(), 0, 6, true);
  needleLengthRatio = ofMap(y, 0, ofGetHeight(), -3, 3);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
