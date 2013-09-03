//
//  rectangle.h
//  RectangleTest
//
//  Created by Bobby Fata on 8/27/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
    
public:
    Rectangle();
    
    void update();
    void draw();
    
    void xenoToPoint( float catchX, float catchY);
    
    void interpolateByPct (float myPct);
    
    ofPoint pos;
    ofPoint posa;
    ofPoint posb;
    
    float pct;
    float catchUpSpeed;
    int blueVal;
    int redVal;
    int rectX;
    int rectY;
};

