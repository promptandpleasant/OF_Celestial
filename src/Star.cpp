//
//  Star.cpp
//  OF_Celestial_Graphics
//
//  Created by C. A. Stavridis on 5/24/14.
//
//

#include "Star.h"
#include "ofGraphics.h"

int Star::sleftHandPosX = 0;
int Star::sleftHandPosY = 0;
int Star::srightHandPosX = 0;
int Star::srightHandPosY = 0;
double Star::shomeGravity = 0;
double Star::shandGravity = 0;

Star::Star(vector<double> start, bool is_quote) {
//    mLoc = start;
    mLoc.push_back(0);
    mLoc.push_back(0);
    mStart.push_back(0);
    mStart.push_back(0);
    mLoc[0] = mStart[0] = start[0];
    mLoc[1] = mStart[1] = start[1];
//    mDir.push_back(ofRandom(10.0f)-5);
//    mDir.push_back(ofRandom(10.0f)-5);
    mVel = ofRandom(3.5f)-0.1;

    mStar_color.set(235, 165, 113);
    mQuote_color.set(255, 176, 118);
    mTwinkle_color.set(255,222,202);
    mIs_quote = is_quote;
    mRadius = mIs_quote ? 2.25f : ofRandom(1.25f) + 0.5f;
}

void Star::update_kinect_vars(vector<int>lftHndPs, vector<int>rghtHndPs, double hndGrvty, double hmGrvty) {
    Star::sleftHandPosX = lftHndPs[0];
    Star::sleftHandPosY = lftHndPs[1];
    Star::srightHandPosX = rghtHndPs[0];
    Star::srightHandPosY = rghtHndPs[1];
    Star::shomeGravity = hmGrvty;
    Star::shandGravity = hndGrvty;
    
//    std::cout << lftHndPs[0] << rghtHndPs[0] << hmGrvty << hndGrvty;
}

void Star::update() {
    
    
    //calculate lefthand vector
    double  lx      = mLoc[0] - sleftHandPosX,
            ly      = mLoc[1] - sleftHandPosY,
            l_mag   = sqrt(lx*lx + ly*ly),
            l_scl   = (l_mag == 0) ? 0 : (-7500 * mVel * shandGravity) / (l_mag * l_mag * l_mag);
    
            lx      *= l_scl,
            ly      *= l_scl;
    
    
    //calculate righthand vector
    double  rx      = mLoc[0] - srightHandPosX,
            ry      = mLoc[1] - srightHandPosY,
            r_mag   = sqrt(rx*rx + ry*ry),
            r_scl   = (r_mag == 0) ? 0 : (-7500 * mVel * shandGravity) / (r_mag * r_mag * r_mag);
    
            rx      *= r_scl,
            ry      *= r_scl;
    
    //calculate home vector
    double  hx      = mLoc[0] - mStart[0],
            hy      = mLoc[1] - mStart[1],
            h_mag   = sqrtl(hx*hx + hy*hy),
            h_scl   = (h_mag == 0) ? 0 : (-8 * abs(mVel) * shomeGravity)/(h_mag);

            hx      *= h_scl,
            hy      *= h_scl;

    
    //add vectors together
    mLoc[0] += lx + rx + hx;
    mLoc[1] += ly + ry + hy;
    
    //std::cout << lx << ' ' << ly << '\n';
    
    //mLoc = star's location <--- we are setting mLoc
    //mDir = where the star wants to go <--- defined on creation
    //mVel = star's velocity <--- defined on creation
    
//    if (mIs_quote) {
//        if ((ofGetElapsedTimef() < 5)) {
//            mLoc[0] += mDir[0] * mVel;
//            mLoc[1] += mDir[1] * mVel;
//        } else {
//            if (mLoc[0] != mStart[0]) {
//                 mLoc[0] -= mDir[0] * mVel;
//            }
//            if (mLoc[1] != mStart[1]) {
//                 mLoc[1] -= mDir[1] * mVel;
//            }
//        }
//    }
}

void Star::draw() {
    ofSetColor(mIs_quote ? mQuote_color : mStar_color);
    ofCircle(mLoc[0], mLoc[1], mIs_quote ? mRadius : mRadius * (sin(ofGetElapsedTimef() * (mLoc[0] + mLoc[1]))));
    
    if (mIs_quote) {
        ofSetColor(mTwinkle_color);
        ofCircle(mLoc[0], mLoc[1], mRadius * (0.25f + 0.75f * (sin(ofGetElapsedTimef()+144 * ofRandom(0.05f)))));
    } else {
        
    }
}