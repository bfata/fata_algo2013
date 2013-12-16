//
//  Particle.cpp
//  NoiseParticles
//
//  Created by Charlie Whitney on 9/18/13.
//
//

#include "Particle.h"

void Particle::setup( ofVec2f rVel ){
    vel = rVel;
    age = 0;
    lifespan = ofRandom(450, 650);
    
    pos = ofGetWindowSize() / 2.0;
    pos.x = ofRandom(ofGetWindowWidth());
    pos.y = ofRandom(0,10);
    bIsDead = false;
};

void Particle::update(){
    
    // Generate some noise based on where we are with x and y.  The particle slows down due to our multiplying the
    // velocity by 0.97, but we still want a lot of noise motion.  for this reason we pass in something we know will keep moving.  Time!
    // This is 3D noise.
    float noise = ofNoise(pos.x, pos.y*0.005, ofGetElapsedTimef() * 0.9) * 15.0;
    
    // How close is our particle to dying.  0.0 = newborn, 1.0 = death
    float agePct = 1.0 - ((float)age / (float)lifespan);
    
    // use sin and cos to give us some sweepy circular motion.  The closer we are to death, the more noise we add.
    pos += ofVec2f( cos(noise), 3 ) * (1.0-agePct);
    pos += vel;
    vel *= 0.9;
    
    
    age++;
    
    if( age > lifespan ) {
        bIsDead = true;         // we've had a good life.
    }
};
void Particle::draw(){
    if( bIsDead ){
        return;
    }
    
    float agePct = 1.0 - ((float)age / (float)lifespan);
    ofSetColor(255, 255, 255, 80);

    ofCircle( pos, 5.0 * agePct  );         // The older our particle is, the smaller it gets.
};

