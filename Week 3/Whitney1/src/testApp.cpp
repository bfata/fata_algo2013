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
        
    float x = radius * sin(angle * 4.5);
    float y = radius * cos(angle * 3.5);
    
    float otherX = radius/2 * sin(angle * 2.5);
    float otherY = radius/2 * sin(angle * 3.5);
    
    float theOtherX = radius/4 * sin(angle * 7.5);
    float theOtherY = radius/4 * sin(angle * 5.5);
    
    ofPoint tmp;
    tmp.x = x;
    tmp.y = y;
    
    ofPoint otherTmp;
    otherTmp.x = otherX;
    otherTmp.y = otherY;
    
    ofPoint theOtherTmp;
    theOtherTmp.x = theOtherX;
    theOtherTmp.y = theOtherY;
    
    pointList.push_back( tmp);
    if ( pointList.size() > 30) {
        pointList.erase( pointList.begin() );
    }
    
    ofPushMatrix();{
        
        ofTranslate(ofGetWindowSize()/2);
        
//        ofNoFill();
        
//        ofBeginShape();
//        for ( int i=0; i<pointList.size(); i++){
//            ofVertex(pointList[i]);
//        }
//        ofEndShape();
        
        
        ofSetColor(255, 0, 255,255*0.6);
        ofCircle(tmp.x, tmp.y, 30,30);
        ofCircle(-tmp.x, -tmp.y, 30,30);
        ofCircle(tmp.x*.5, tmp.y*.5, 15,15);
        ofCircle(-tmp.x*.5, -tmp.y*.5, 15,15);
        
        ofSetColor(255,255,0,255*.6);
        ofCircle(otherTmp.x, otherTmp.y, 20,20);
        ofCircle(-otherTmp.x, -otherTmp.y, 20,20);
        ofCircle(otherTmp.x*.5, otherTmp.y*.5, 10,10);
        ofCircle(-otherTmp.x*.5, -otherTmp.y*.5, 10,10);
        
        ofSetColor(0,255,255*.6);
        ofCircle(theOtherTmp.x, theOtherTmp.y, 20,20);
        ofCircle(-theOtherTmp.x, -theOtherTmp.y, 20,20);
        ofCircle(theOtherTmp.x*.5, theOtherTmp.y*.5, 10,10);
        ofCircle(-theOtherTmp.x*.5, -theOtherTmp.y*.5, 10,10);


        
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
