#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // OF init
    ofEnableDepthTest();
    ofSetVerticalSync( false );
    ofEnableNormalizedTexCoords();
    
    oculusRift.baseCamera = &cam;
    oculusRift.setup();
    oculusRift.fullscreenOnRift();
    
    // Add a simple box to look at
    box = ofBoxPrimitive();
    box.enableTextures();
    box.set(0.2);
    
    // position camera just slightly away from the box
    cam.setAutoDistance(false);
    cam.setGlobalPosition(0, 0.3, 0.5);
    
    // load the OF logo from disk ready to texture with
    ofLogo.loadImage("of.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::drawScene() {
    
    ofLogo.getTextureReference().bind();
    box.draw();
    ofLogo.getTextureReference().unbind();
    
}

void ofApp::draw(){
    
    oculusRift.beginLeftEye();
    drawScene();
    oculusRift.endLeftEye();
    
    oculusRift.beginRightEye();
    drawScene();
    oculusRift.endRightEye();
    
    oculusRift.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    // dismiss safety warning on any key
    oculusRift.dismissSafetyWarning();
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
