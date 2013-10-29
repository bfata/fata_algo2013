//
//  Particle.h
//  loop1
//
//  Created by Bobby Fata on 10/27/13.
//
//

#include "ofMain.h"

class Particle{
public:
    void setup();
    void draw();
    void update();
    void addDamping();
    void resetForces();
    void applyForce( ofVec2f force );
    
    ofVec2f pos, accel, vel, force;
    
    float mass, damping;
    
};

