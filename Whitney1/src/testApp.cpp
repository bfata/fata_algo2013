#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground( 0 );
    ofEnableAlphaBlending();
//    ofSetBackgroundAuto(false);
    
    boxRadius = 100;
    mBox = ofBoxPrimitive(boxRadius *2, boxRadius *2, boxRadius*2);
    

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    float angle = ofGetElapsedTimef() * .3;
    
    float leafNumber = 100;
    float radius = 400;
        
    float x = radius * sin(angle * 3.5);
    float y = radius * cos(angle * 3.5);
    
    ofPoint tmp;
    tmp.x = x;
    tmp.y = y;
    
    pointList.push_back( tmp);
    if ( pointList.size() > 400) {
        pointList.erase( pointList.begin() );
    }
    
    ofPushMatrix();{
        
        ofTranslate(ofGetWindowSize()/2);
        
        ofNoFill();
        
        ofBeginShape();
        for ( int i=0; i<pointList.size(); i++){
            ofVertex(pointList[i]);
        }
        ofEndShape();
        ofSetColor(255, 255, 255,255*0.2);
        ofCircle(tmp.x, tmp.y, 20,20);
        
//        ofSetColor(255,0,255);
//        mBox.getMesh().drawWireframe();
    
    }ofPopMatrix();
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
