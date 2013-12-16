//
//  Rectangle.cpp
//  MultipleXeno
//
//  Created by Bobby Fata on 9/3/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    catchUpSpeed = .03;
    
}

void Rectangle:: xenoToPoint(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}

void Rectangle:: vecXenoToPoint(ofVec2f){
    vecPos = catchUpSpeed * (1-catchUpSpeed) * vecPos;
    
}
void Rectangle::draw(){
    
    ofSetColor( 255 * (pos.y / ofGetWindowHeight()), 255 * (pos.y / ofGetWindowWidth()), ofRandom(20,50));
    ofCircle(pos.x, pos.y, ofRandom(20,40),20);
}