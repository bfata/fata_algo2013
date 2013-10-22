//
//  Particle.cpp
//  VectorComp1
//
//  Created by Bobby Fata on 10/21/13.
//
//

#include "Particle.h"
#include "ofMain.h"

Particle::Particle() {
    mass = 2.0;
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::update(){
    vel += accel;
    pos += vel;

    vel*= 0.95;
    
    accel.set(0);
    
//    if (pos.x > 1024)  {
//        pos.x = 0;
//    }
}

void Particle::draw() {
    psize = 5;
    ofCircle( pos, psize);
}

void Particle::addRepulsion( float px, float py, float radius, float strength ){
    
    ofVec2f posOfForce;             // vector position of force
    posOfForce.set(px,py);          // initialize
    
    ofVec2f diff = pos - posOfForce;    // difference
    
    if (diff.length() < radius){
        float percent = 1 - (diff.length() / radius );
        diff.normalize();
        pos.x += diff.x * percent * strength;
        pos.y += diff.y * percent * strength;
    }
}

void Particle::addDamping(){
    accel.x = accel.x - vel.x * damping;
    accel.y = accel.y - vel.y * damping;
}

void Particle::resetForces(){
        accel.set(0,0);
    }

void Particle::trail(float catchX, float catchY){
    
    float catchUpSpeed = 0.5f;
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}