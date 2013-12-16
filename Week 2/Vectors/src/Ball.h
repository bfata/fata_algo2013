//
//  Ball.h
//  Vectors
//
//  Created by Bobby Fata on 9/3/13.
//
//

#pragma once

#include "ofMain.h"

class Ball {
    public:
    Ball();
    
    void update();
    void draw();
    
    ofVec2f pos;
    float xVelocity;
    float yVelocity;
};
