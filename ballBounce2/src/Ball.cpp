//
//  Ball.cpp
//  ballBounce2
//
//  Created by Bobby Fata on 9/9/13.
//
//

#include "Ball.h"

Ball::Ball (){
    ballVel.x = ofRandom(-5,5);
    ballVel.y = ofRandom(-5,5);
    
    gravity.x = 0;
    gravity.y = 0.8;
    
    pos = ofPoint( (ofGetWindowWidth()/2 ),( ofGetWindowHeight() ));
    
    
}

void Ball::update(){

    ballVel += gravity;
    pos += ballVel;
    
    if (pos.x < 20 || pos.x > ofGetWindowWidth()){
        ballVel.x = ballVel.x *-1;
    }
    
    if (pos.y < 10 || pos.y > ofGetWindowHeight()){
        ballVel.y = ballVel.y *-.9;
        pos.y=ofGetHeight()-11;
    }

    
    
}

void Ball::draw(){
    ofCircle(pos, 20);
}
