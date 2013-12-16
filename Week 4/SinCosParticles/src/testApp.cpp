#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    alphaLevel = 50;
    
    // Set up GUI
    gui = new ofxUICanvas();
    gui ->addLabel("Particle Command Center");
    gui ->addSpacer();
    gui ->addToggle("Splode", false, 40, 40);
    gui ->addSlider("Force", 0, 20, 5);
    gui ->addSlider("Alpha", 0, 255, 50);
    
    gui -> setColorBack(ofColor(255, 0, 0, 100));
    gui -> setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));
    gui -> loadSettings("myGuiSettings.xml");
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
    
    // Initial 'Splosion
    for (int i = 0; i < 1000; i++){
        addParticle();
    }
}

void testApp::exit(){
    gui -> saveSettings("myGuiSettings.xml");
    delete gui;
}

void testApp::onGuiEvent( ofxUIEventArgs &e){
    // Send Message To Log. Where is message coming from?
    cout << "I got a message" << e.getName() << endl;
    
    // Force Slider
    if( e.getName() == "Force"){
        ofxUISlider * ForceSlider = (ofxUISlider*)e.widget;
        
        Force = ForceSlider -> getScaledValue();
    }
    // Alpha Slider
    if( e.getName() == "Alpha"){
        ofxUISlider * AlphaSlider = (ofxUISlider*)e.widget;
        
        alphaLevel = AlphaSlider -> getScaledValue();
    }
    // Splode Button ( Toggle )
    else if ( e.getName() == "Splode"){
        ofxUIToggle *b = (ofxUIToggle*) e.widget;
        b->getValue();
        for (int i = 0; i < particleList.size(); i++){
            //		float vx = ofRandom(-4,4);
            //		float vy = ofRandom(-4,4);
            
            float circVal = ofRandom(TWO_PI);
            
            float vx = cos( circVal ) * cos (circVal/2 * Force)* 5;
            float vy = sin( circVal ) * cos (circVal/4 * (Force * 2));
            
            particleList[i].setParams(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
            
        }
        
    }
    
    
}


//--------------------------------------------------------------
void testApp::update(){
    
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
	for (int i=0; i < particleList.size(); i++){
		particleList[i].resetForces();
        //		particleList[i].addForce( ofVec2f(0,0.04));  // gravity
		particleList[i].addDampingForce();
		particleList[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Particle Colors
    ofSetColor(0,200,100,alphaLevel);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
    }
}

void testApp::addParticle() {
    Particle myParticle;
    
    float vx = (-Force, Force);
    float vy = (-Force,Force);
    myParticle.setParams(300,300,vx, vy);
    
    
    particleList.push_back(myParticle);
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
    //    for (int i = 0; i < particleList.size(); i++){
    //        //		float vx = ofRandom(-4,4);
    //        //		float vy = ofRandom(-4,4);
    //
    //        float circVal = ofRandom(TWO_PI);
    //
    //        float vx = cos( circVal ) * ofRandom(-Force, Force);
    //        float vy = sin( circVal ) * ofRandom(-Force, Force);
    //
    //		particleList[i].setParams(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
    //
    //	}
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