//
//  StarController.h
//  OF_Celestial_Graphics
//
//  Created by C. A. Stavridis on 5/24/14.
//
//

#ifndef __OF_Celestial_Graphics__StarController__
#define __OF_Celestial_Graphics__StarController__

#include <iostream>

#endif /* defined(__OF_Celestial_Graphics__StarController__) */

#pragma once
#include "Star.h"
#include "ofImage.h"
#include <list>

class StarController {
public:
    StarController();
    
    void update(vector<int> leftHandPos, vector<int> rightHandPos, double handGravity, double homeGravity);
    void draw();
    void addStars(int amt);
    void removeStars(int amt);
    
    ofImage mQuote;
    
    double mHomeGravity;
    double mHandGravity;
    vector <int> mRightHandPos;
    vector <int> mLeftHandPos;
    
    std::list<Star> mStars;
};