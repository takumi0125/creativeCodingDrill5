#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
  
    void drawKochCurve(const ofVec3f &p1, const ofVec3f &p2, int recursion);
		
    ofEasyCam cam;
    int numRecursions;
    float rotX;
    float rotY;
    float needleLengthRatio;
    vector<ofVec3f> points;
};
