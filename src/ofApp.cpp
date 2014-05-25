#include "ofApp.h"
#include <cmath>

//--------------------------------------------------------------
void ofApp::setup(){
    
    /* Kinect */
    
    leftHandPos.push_back(0);
    leftHandPos.push_back(0);
    rightHandPos.push_back(0);
    rightHandPos.push_back(0);
    homeGravity = 0;
    handGravity = 0;
    
    //Synapse
    synapseStreamer.openSynapseConnection();
    synapseStreamer.trackAllJoints(false);
    synapseStreamer.trackLeftHand(true);
    synapseStreamer.trackRightHand(true);
    
    
    /* Graphics */
    
    // Smooth edges
    ofEnableSmoothing();
    
    // Fixed framerate
    ofSetFrameRate(75);
    
    mStarController.addStars(5000   );
}

//--------------------------------------------------------------
void ofApp::update(){
    synapseStreamer.parseIncomingMessages();
    
    if (synapseStreamer.getNewMessage()) {
        
        //the first time moving after settling should be responsive
        //if (goHomeFactor == 0) goHomeFactor = 8000;
//        goHomeFactor = 8000;
        
        vector <double> newleftHand = synapseStreamer.getLeftHandJoint();
        //while we have both the
        //goHomeFactor += (leftHandPos[0]-rightHandPos[0]) * (leftHandPos[0]-rightHandPos[0]) +
        //                     (leftHandPos[1]-rightHandPos[1]) * (leftHandPos[1]-rightHandPos[1]) / 30;
        
        leftHandPos[0] = -newleftHand[0] + X_HAND_THRESH * SCREEN_WIDTH / (2 * X_HAND_THRESH);
        leftHandPos[1] = -newleftHand[1] + Y_HAND_THRESH * SCREEN_HEIGHT / (2 * Y_HAND_THRESH);
        
        vector <double> newrightHand = synapseStreamer.getRightHandJoint();
        //goHomeFactor += abs(rightHandPos[0] - newrightHand[0])/30.0;
        rightHandPos[0] = newrightHand[0] + X_HAND_THRESH * SCREEN_WIDTH / (2 * X_HAND_THRESH);
        rightHandPos[1] = -newrightHand[1] + Y_HAND_THRESH * SCREEN_HEIGHT / (2 * Y_HAND_THRESH);
        
        handDist = sqrt( (leftHandPos[0]-rightHandPos[0]) * (leftHandPos[0]-rightHandPos[0]) +
                         (leftHandPos[1]-rightHandPos[1]) * (leftHandPos[1]-rightHandPos[1]) ) - 100;
        if (handDist < 0) handDist = 0;
        handGravity = handDist * (-40.0 / (9.0 * SCREEN_HEIGHT)) + 11 / 9;
        
        //debug print left hand coordinates
        //for( std::vector<double>::const_iterator i = leftHand.begin(); i != leftHand.end(); ++i)
        //    std::cout << *i << ' ';
        //std::cout << '\n';
        //goHomeFactor = (goHomeFactor > 2) ? goHomeFactor - 2 : 0;
    }
    
    //As time goes by, the stars want to go home.
//    goHomeFactor = (goHomeFactor > 64.2) ? goHomeFactor - 64.2 : 0;
//    if(goHomeFactor > 8000) goHomeFactor = 8000;
//    homeGravity = 1 - (goHomeFactor / 8000);
//    if (homeGravity < 0) homeGravity = 0;
//    if (homeGravity > 1) homeGravity = 1;
    
//    std::cout << "{homegravity=" << homeGravity << ", goHomeFactor=" << goHomeFactor << ", handGravity=" << handGravity << ", handDist=" << handDist << "}\n";
    
    if (handGravity < -6) {
        handGravity = 0;
        homeGravity += 0.05f;
        std::cout << "Collapsing. " << homeGravity << '\n';
    } else {
        if (handGravity < -1) handGravity = -1;
        if (handGravity > 1) handGravity = 1;
        homeGravity -= 0.03f;
    }
    
    if (homeGravity < 0) homeGravity = 0;
    if (homeGravity > 1) homeGravity = 1;
    
    //starController.moveStars(leftHandPos, rightHandPos, handGravity, homeGravity);
    //Update starController with texture
    mStarController.update(leftHandPos, rightHandPos, handGravity, homeGravity);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Setup Gradient Background
    ofColor start_color;
    ofColor end_color;
    
    start_color.set(65, 34, 59);
    end_color.set(7, 37, 49);
    ofBackgroundGradient(start_color, end_color, OF_GRADIENT_LINEAR);
    
    //Draw starController
    mStarController.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
