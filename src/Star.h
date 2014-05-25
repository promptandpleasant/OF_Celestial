//
//  Star.h
//  OF_Celestial_Graphics
//
//  Created by C. A. Stavridis on 5/24/14.
//
//

#ifndef __OF_Celestial_Graphics__Star__
#define __OF_Celestial_Graphics__Star__

#include <iostream>

#endif /* defined(__OF_Celestial_Graphics__Star__) */

#pragma once
//#include "StarController.h"
#include "ofColor.h"
#include <list>

class Star {
public:
    Star(vector<double> start, bool is_quote);
    
    static void update_kinect_vars(vector<int>lftHndPs, vector<int>rghtHndPs, double hndGrvty, double hmGrvty);
    static int sleftHandPosX;
    static int sleftHandPosY;
    static int srightHandPosX;
    static int srightHandPosY;
    static double shandGravity;
    static double shomeGravity;
    
    void update();
    void draw();
    
    vector<double> mLoc;
    vector<double> mStart;
//    vector<double> mDir;
    
    double mVel;
    float mRadius;
    
    bool mIs_quote;
    
    ofColor mStar_color;
    ofColor mQuote_color;
    ofColor mTwinkle_color;
    
//    StarController * mStarController;
};