//
//  Particle.cpp
//  multiParticles
//
//  Created by Bobby Fata on 11/5/13.
//
//

#include "Particle.h"

void Particle::setup( ofVec2f rVel ){
    particleImage.loadImage("particle2.png");
    vel = rVel;
    age = 0;
    particleColor = ofColor(ofRandom(100,255), ofRandom(100,255), ofRandom(100,255));
    lifespan = ofRandom(100, 250);
    alphaVal = ofRandom(100, 250);
    
    pos = ofGetWindowSize() / 2.0;
    bIsDead = false;
};

void Particle::update(){
    
    // Generate some noise based on where we are with x and y.  The particle slows down due to our multiplying the
    // velocity by 0.97, but we still want a lot of noise motion.  for this reason we pass in something we know will keep moving.  Time!
    // This is 3D noise.
    
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.3) * 15.0;
    
    // How close is our particle to dying.  0.0 = newborn, 1.0 = death
    float agePct = 1.0 - ((float)age / (float)lifespan);
    
    // use sin and cos to give us some sweepy circular motion.  The closer we are to death, the more noise we add.
    pos += ofVec2f( cos(noise), sin(noise) ) * (1.0-agePct);
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
    //    ofSetColor(particleColor);
    
    //    ofCircle( pos, 4.0 * agePct  );
    
    // Make the background clear!
    
    float particleAlpha = ofRandom(100, 255);
    float redness = ofRandom(150,255);
    
    particleImage.draw(pos, 30*agePct, 30*agePct);
    // The older our particle is, the smaller it gets.
};

