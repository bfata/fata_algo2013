#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    mReceiver.setup( 12345 );
    
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
}

void testApp::checkOsc(){
    
    while (mReceiver.hasWaitingMessages() ) {
        ofxOscMessage  m;
        mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if(addr == "/mouse/pos"){
            
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);
            
            mousePos.set(xPos, yPos);
        }else if(addr == "/ball/pos"){
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);
            
            ballPos.set(xPos, yPos);
            
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofCircle(ballPos, 20);
    
    
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
