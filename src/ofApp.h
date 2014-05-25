#pragma once

#include "ofMain.h"
#include "SynapseStreamer.h"
#include "StarController.h"

class ofApp : public ofBaseApp{

    
    /* Kinect Constants */
    const int X_HAND_THRESH = 440;
    const int Y_HAND_THRESH = 380;
    const int SCREEN_WIDTH = ofGetWindowWidth();//1980;
    const int SCREEN_HEIGHT = ofGetWindowHeight();//1280;
    
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        /* Kinect  */
        SynapseStreamer synapseStreamer;
        int handDist;
        double goHomeFactor;
    
        vector<int> leftHandPos;
        vector<int> rightHandPos;
        double handGravity;
        double homeGravity;
    
        /* Graphics */
        StarController mStarController;
};
