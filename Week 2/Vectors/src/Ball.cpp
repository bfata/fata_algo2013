//
//  Ball.cpp
//  Vectors
//
//  Created by Bobby Fata on 9/3/13.
//
//

#include "Ball.h"

Ball::Ball(){
    ofSeedRandom();
    
    xVelocity = ofRandom(0.0, 1.0);
    yVelocity = ofRandom(0.0, 1.0);
    
    pos.x = ofGetWindowWidth() / 2;
    pos.y = ofGetWindowHeight() / 2;
    
    ofSetRectMode(OF_RECTMODE_CENTER);
}

void Ball::update(){
    pos.x += xVelocity * 10;
    pos.y += yVelocity * 10;
    
    if ( pos.x < 0 || pos.x > ofGetWindowWidth()){
        xVelocity *= -1;
    }
    
    if ( pos.y < 0 || pos.y > ofGetWindowHeight() ){
        yVelocity *= -1;
    }
}

void Ball::draw(){
    ofSetColor(0, 0, 255);
    ofCircle(pos.x, pos.y, 20);
}