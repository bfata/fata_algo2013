#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
    myRect.pos.x = ofGetWindowWidth() / 2;
    myRect.pos.y = ofGetHeight() / 2;
    
    myRect.posa.x = 10;
    myRect.posa.y = 100;
    
    myRect.posb.x = 500;
    myRect.posb.y = 140;
    
    myRect.interpolateByPct(0.0f);
    myRect.rectX = 30;
    myRect.rectY = 30;
    
    myOtherRect.catchUpSpeed = .15f;
    myOtherRect.rectX = 20;
    myOtherRect.rectY = 20;
    
    myOtherOtherRect.catchUpSpeed = .075f;
    myOtherOtherRect.rectX = 25;
    myOtherOtherRect.rectY = 25;
    pct = 0;
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    //    pct += 0.001f;
    //    if( pct > 1) {
    //        pct = 0;
    //    }
    
    myRect.xenoToPoint(mouseX, mouseY);
    myOtherRect.xenoToPoint(mouseX, mouseY);
    myOtherOtherRect.xenoToPoint(mouseX, mouseY);
    
    myOtherRect.blueVal = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    myOtherRect.redVal = ofMap(mouseY, 0, ofGetWidth(), 0, 255);
    
    myOtherOtherRect.blueVal = ofMap(mouseY, 0, ofGetHeight(), 0, 255);
    myOtherOtherRect.redVal = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    myRect.draw();
    myOtherRect.draw();
    myOtherOtherRect.draw();
    
    ofSetColor(255);
    
    ofDrawBitmapString(ofToString(pct), ofPoint(10, 10));
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    pct = (float)y / (float)ofGetWindowHeight();
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    myRect.pos.x = ofRandom(0, 1024);
    myRect.pos.y = ofRandom(0, 768);
    
    myOtherRect.pos.x = ofRandom(0, 1024);
    myOtherRect.pos.y = ofRandom(0, 768);
    
    myOtherOtherRect.pos.x = ofRandom(0, 1024);
    myOtherOtherRect.pos.y = ofRandom(0, 768);
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
