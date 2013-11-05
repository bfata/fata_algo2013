//
//  Particle.h
//  multiParticles
//
//  Created by Bobby Fata on 11/5/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle(){};
    void setup( ofVec2f rVel );
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    ofColor particleColor;
    ofImage particleImage;
    int age, lifespan, alphaVal;
    bool bIsDead;
};
