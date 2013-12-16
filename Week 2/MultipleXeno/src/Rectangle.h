//
//  Rectangle.h
//  MultipleXeno
//
//  Created by Bobby Fata on 9/3/13.
//
//

#pragma once   

#include "ofMain.h"

class Rectangle {
    public:
    Rectangle();
    
    void xenoToPoint (float catchX, float catchY);
    void draw();
    
    void vecXenoToPoint (ofVec2f vecCatch);
    
    ofPoint pos;
//    ofPoint targetPos;
    
    ofVec2f vecPos;
    
    float catchUpSpeed;
};
