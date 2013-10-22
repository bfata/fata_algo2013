#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    alphaLevel = 80;
    
    //GUI//
    gui = new ofxUICanvas();
    gui ->addLabel("Particle Command Center");
    gui ->addSpacer();
    gui ->addSlider("Mass", 1, 5, 2);
    gui ->addSlider("Field", 0, TWO_PI, PI);
    gui ->addSlider("Alpha", 0, 255, 80);

    
    gui -> setColorBack(ofColor(255, 0, 0, 100));
    gui -> setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));
    gui -> loadSettings("myGuiSettings.xml");
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
    // END GUI //
    
    drawVec = false;
    
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    myField.flowScale = PI;
    
    particleList.clear();
    
    // Set Up Initial Amount of Particles
    for( int i=0; i<8000; i++ ){
        addParticle();
    }
    
    ofBackground(0);
}

void testApp::addParticle() {
    Particle part;
    part.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    part.mass = mass;
//    part.psize = ofRandom(3,5);
    
    particleList.push_back( part );
}
//--------------------------------------------------------------

void testApp::exit(){
    gui -> saveSettings("myGuiSettings.xml");
    delete gui;
}

//--------------------------------------------------------------

void testApp::onGuiEvent( ofxUIEventArgs &e){
    // Send Message To Log. Where is message coming from?
    cout << "I got a message" << e.getName() << endl;
    
    // Force Slider
    if( e.getName() == "Mass"){
        ofxUISlider * ForceSlider = (ofxUISlider*)e.widget;
        
        mass = ForceSlider -> getScaledValue();
    }
    if( e.getName() == "Alpha"){
        ofxUISlider * ForceSlider = (ofxUISlider*)e.widget;
        
        alphaLevel = ForceSlider -> getScaledValue();
    }
    // Alpha Slider
    if( e.getName() == "Field"){
        ofxUISlider * AlphaSlider = (ofxUISlider*)e.widget;
        
       fieldForce = AlphaSlider -> getScaledValue();
    }
}
//--------------------------------------------------------------
void testApp::update(){
    myField.update();
    myField.flowScale = fieldForce;
    
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].applyForce( myField.getForceAtPosition(particleList[i].pos ) * 0.005 );
        particleList[i].mass = mass;
        particleList[i].update();
        particleList[i].resetForces();
        particleList[i].addDamping();
      
        // Yo, Don't go off Screen! Weird quantum teleporting happening here
        if (particleList[i].pos.x > ofGetScreenWidth() || particleList[i].pos.x < 0){
            particleList[i].pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
        }
        if (particleList[i].pos.y > ofGetScreenHeight() || particleList[i].pos.y < 0){
            particleList[i].pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255,255,255,alphaLevel);
//    float redness = ofMap(particleList.pos, 0, 1024, 0, 255);

 
//    myField.draw();
    
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom( 20.0 );
    }else if( key == '2' ){
        myField.setPerlin();
    }
    else if ( key == 'd'){
        drawVec = true;
    }else if( key == 'r' ){
        for( int i=0; i<particleList.size(); i++ ){
            particleList[i].pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
//    for (int i = 0; i < particleList.size(); i++){
//        particleList[i].resetForces();
//        particleList[i].addRepulsion(x, y, 20, 20);
//        particleList[i].addDamping();
//        particleList[i].update();
//    }
//    
//    if( button == OF_MOUSE_BUTTON_1 ){
//        //        myField.addRepelForce(x, y, 100, 2.0);
//        myField.addCircularForce(x, y, 300, 2.0);
//    }else{
//        myField.addAttractForce(x, y, 100, 2.0);
//    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
//    for (int i = 0; i < particleList.size(); i++){
//        particleList[i].resetForces();
//        particleList[i].addRepulsion(x, y, 50, 80);
//        particleList[i].addDamping();
//        particleList[i].update();
//    }
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