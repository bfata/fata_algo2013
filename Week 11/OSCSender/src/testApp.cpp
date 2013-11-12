#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    mSender.setup("localhost", 12345);
    ofBackground(0);
    
    ballPos = ofGetWindowSize() / 2;
    vel = ofVec2f(10,0);

}

//--------------------------------------------------------------
void testApp::update(){
    ballPos+=vel;
    
    if (ballPos.x < 0 || ballPos.x > ofGetWindowWidth() * 4 ) {
        vel.x*=-1;
    }
    
    if (ballPos.y < 0 || ballPos.y > ofGetWindowHeight() ) {
        vel.y*=-1;
    }
    
    ofxOscMessage m2;
    m2.setAddress("/ball/pos");
    m2.addIntArg(ballPos.x);
    m2.addIntArg(ballPos.y);
    
    mSender.sendMessage( m2 );


}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
    ofTranslate(-ofGetWindowWidth(), 0);
    
    ofCircle(ballPos, 20);
    
    ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mousePos.set(x, y);
    
    ofxOscMessage m;
    m.setAddress("/mouse/pos");
    m.addIntArg(mousePos.x);
    m.addIntArg(mousePos.y);
    
    mSender.sendMessage( m );
    
    ofxOscMessage m2;
    m.setAddress("/ball/pos");
    m.addIntArg(ballPos.x);
    m.addIntArg(ballPos.y);
    
    mSender.sendMessage( m2 );

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
