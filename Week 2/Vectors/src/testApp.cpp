#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(100);

}

//--------------------------------------------------------------
void testApp::update(){
    bouncingBall.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    ofVec2f result;
    
    ofPushMatrix();{
        ofTranslate(ofGetWindowSize()/2);
        
        ofVec2f mousePos( mouseX, mouseY);
        ofVec2f center = ofGetWindowSize() / 2;
        
        ofVec2f result = mousePos - center;
        
        ofLine( ofVec2f(0,0), result);
        
    }ofPopMatrix();
    
    float mag = result.length();
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
