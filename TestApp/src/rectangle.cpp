//
//  rectangle.cpp
//  RectangleTest
//
//  Created by Bobby Fata on 8/27/13.
//
//

#include "rectangle.h"

Rectangle::Rectangle(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    catchUpSpeed = 0.03f;
    blueVal = 0;
    redVal = 0;
    rectX = 20;
    rectY = 20;
}

void Rectangle::update(){
    pos.x = pos.x + ofRandom(-1,1);
    
}

void Rectangle::draw(){
    ofEnableAlphaBlending();
    ofSetColor(redVal,0, blueVal, 255 * 0.4);
    
    ofRect(pos.x , pos.y ,rectX,rectY);
    
}


void Rectangle::xenoToPoint(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}

void Rectangle::interpolateByPct(float myPct){
    pct = myPct;
    
    pct = powf(myPct, 2);
    
    pos.x = (1-pct) * posa.x + pct * posb.x;
    pos.y = (1-pct) * posa.y + pct * posb.y;
}
