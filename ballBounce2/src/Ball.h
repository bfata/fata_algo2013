//
//  Ball.h
//  ballBounce2
//
//  Created by Bobby Fata on 9/9/13.
//
//

#pragma once

#include "ofMain.h"

class Ball{
    public:
    
    Ball();
    void update();
    void draw();
    
    ofPoint pos;
    ofVec2f ballVel, gravity;
};