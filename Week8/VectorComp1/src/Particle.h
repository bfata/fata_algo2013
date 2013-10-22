//
//  Particle.h
//  VectorComp1
//
//  Created by Bobby Fata on 10/21/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    ofVec2f force;    // vector force
    
    float mass, damping;
    
    void applyForce( ofVec2f force );
    void update();
    void draw();
    void addDamping();
    void resetForces();
    
    void trail(float catchX, float catchY);
    void addRepulsion(float px, float py, float radius, float strength);    
    float xPos, psize, redness;
    
};