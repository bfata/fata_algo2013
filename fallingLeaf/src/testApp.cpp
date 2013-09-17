#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
    ofBackground(0);
    ofEnableAntiAliasing();

}

//--------------------------------------------------------------
void testApp::update(){
    leafY += ofRandom(.8, 1.8);
    float leafRad = 120;
    
    if (leafY > ofGetWindowHeight()+ leafRad) {
        leafY = 0 - leafRad;
    }

    

}

//--------------------------------------------------------------
void testApp::draw(){
    float fallRate = ofGetElapsedTimef() *.8;
    float leafNumber = 30;
    
    float leafRad = 30;
    float fallRad = 10;
    
    // why /3?
    ofTranslate(ofGetScreenWidth()/4, 0);
    float x = fallRad * sin(fallRate * 3.5);
    
    ofSetColor(30,220,0);
    for (int i = 0; i<leafNumber; i++) {
        ofCircle(x, leafY, leafRad);
        x+=40;
    }
//    ofCircle(x, leafY, leafRad);
    }

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
