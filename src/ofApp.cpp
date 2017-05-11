#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetVerticalSync(false);
    ofSetFrameRate(60);
    ofBackground(255);
    
    ac.setup();
    
    img.load("background.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    ac.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofScale(RESOLUTION_RATIO, RESOLUTION_RATIO);
    ofSetColor(255);
    img.draw(0, 0);
    ac.draw();
    ofSetColor(255, 0, 0);
    ofDrawBitmapString("Frame Rate : " + ofToString(ofGetFrameRate()), 10, 30);
    ofDrawBitmapString("Time : " + ofToString(ac.getElapsedTime()), 10, 60);
    ofDrawBitmapString("Turn : " + ofToString(ac.getAnimationTurn()), 10, 90);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        ac.setAnimation(0);
    }
    if (key == '2') {
        ac.setAnimation(1);
    }
    if (key == '3') {
        ac.setAnimation(2);
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
