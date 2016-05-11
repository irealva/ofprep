#include "ofApp.h"

GLfloat lightOnePosition[] = {0, 0, 0, 1000};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    
    ofEnableDepthTest();
    glShadeModel (GL_SMOOTH);
    
    //Lighting
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);

    glEnable (GL_LIGHTING);
    
    model.loadModel("ny.obj");

    model.setRotation(0, 90, 1, 0, 0);
    model.setScale(6, 6, 6);
    model.setPosition(ofGetWidth()/2, (float)ofGetHeight() * 0.75 , 0);
    
    //Timeline setup
    timeline.setup(); //registers events
    timeline.setDurationInSeconds(60); //sets time
    timeline.setLoopType(OF_LOOP_NORMAL); //turns the timeline to loop
    timeline.addCurves("MyCircleRadius", ofRange(0, 200));
    //End timeline setup

    
}

//--------------------------------------------------------------
void ofApp::update(){
    model.setRotation(1, 10 + ofGetElapsedTimef() * 2, 0, 1, 0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin() ;
    glPushMatrix();
    
    ofSetColor(180, 180, 180, 180);
    model.drawFaces();
    
    glPopMatrix();
    cam.end() ;
    
    ofSetHexColor(0xf8f8ff);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 140);
    
    //Timeline
    float changingRadius = timeline.getValue("MyCircleRadius");
    ofCircle(mouseX, mouseY, changingRadius);
    timeline.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
