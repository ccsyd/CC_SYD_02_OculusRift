#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // OF init
    ofEnableDepthTest();
    ofSetVerticalSync( false );
    
    oculusRift.baseCamera = &cam;
    oculusRift.setup();
    oculusRift.fullscreenOnRift();
    
    reloadShader();
    
    // rect textures are fine by default in GL3, we can just use GL_TEXTURE_2D.
    // disabling allows simpler normalized texture coordinates, not pixel coords
    ofDisableArbTex();
    
    panoLeft.loadImage("well_L.jpg");
    panoRight.loadImage("well_R.jpg");
    
    cam.setAutoDistance(false);
}

void ofApp::reloadShader() {
    panoshader.load("Shaders/pano.vert", "Shaders/pano.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

void ofApp::drawScene(int eye) {
    
    panoshader.begin();
    
    if (eye == 0)
        panoshader.setUniformTexture("pano", panoRight.getTextureReference(), 1);
    else if (eye == 1)
        panoshader.setUniformTexture("pano", panoLeft.getTextureReference(), 1);
    
    ofDrawSphere(1000.0);
    
    panoshader.end();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(oculusRift.isSetup()){
        oculusRift.beginLeftEye();
        drawScene(0);
        oculusRift.endLeftEye();
        
        oculusRift.beginRightEye();
        drawScene(1);
        oculusRift.endRightEye();
        
        oculusRift.draw();
    }
    else{
        cam.begin();
        drawScene(0);
        cam.end();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // dismiss safety warning on any key
    oculusRift.dismissSafetyWarning();
    
    if( key == 'f' )
    {
        //gotta toggle full screen for it to be right
        ofToggleFullscreen();
    }
    if(key == 's'){
        reloadShader();
    }
    if(key == 'v'){
        oculusRift.setNoVsync( !oculusRift.getNoVsync() );
    }
    if(key == 'z'){
        cout << "FPS: " << ofGetFrameRate() << endl;
    }
    
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
