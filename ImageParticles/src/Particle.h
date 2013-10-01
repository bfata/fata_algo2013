//
//  Particle.h
//  ImageParticles
//
//  Created by Bobby Fata on 10/1/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    void update();
    void draw();
    
    void setParams( float px, float py, float vx, float vy );
    void addForce( ofVec2f force );
    void addDampingForce();
    void resetForces();
    
    ofImage particleImage;
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    ofVec2f damping;
};