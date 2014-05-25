//
//  StarController.cpp
//  OF_Celestial_Graphics
//
//  Created by C. A. Stavridis on 5/24/14.
//
//

#include "StarController.h"
#include "ofMain.h"

using std::list;

StarController::StarController() {
    mQuote.loadImage("quote.jpg");
    mQuote.resize(ofGetWindowWidth(), ofGetWindowHeight());
}

void StarController::update(vector<int> leftHandPos, vector<int> rightHandPos, double handGravity, double homeGravity) {
    
    Star::update_kinect_vars(leftHandPos, rightHandPos, handGravity, homeGravity);
    
    for( list<Star>::iterator p = mStars.begin(); p != mStars.end(); ++p ){
		p->update();
	}
}

void StarController::draw(){
    for( list<Star>::iterator p = mStars.begin(); p != mStars.end(); ++p ){
		p->draw();
	}
}

void StarController::addStars(int amt) {
    int i=0;
    while(i<amt)
	{
        float x = ofRandom(ofGetWindowWidth());
        float y = ofRandom(ofGetWindowHeight());
        
        //Check if color is white
        ofColor check = mQuote.getColor(x,y);
        vector <double> vec;
        vec.push_back(x);
        vec.push_back(y);
        if (check[0] > 180) {
            if (ofRandom(1.0f) > 0.25) {
                mStars.push_back(Star(vec, true));
                i++;
            }
        } else {
            if (ofRandom(1.0f) < 0.05) {
                mStars.push_back(Star(vec, false));
                i++;
            }
        }
	}
}

void StarController::removeStars(int amt) {
    for( int i=0; i<amt; i++ )
	{
		mStars.pop_back();
	}
}

