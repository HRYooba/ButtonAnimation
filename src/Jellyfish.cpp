#include "Jellyfish.h"

void Jellyfish::setup() {
    button.setup();
}

void Jellyfish::init(float _size, ofVec2f _position, float _rotation, ofColor _color) {
    size = _size;
    position = _position;
    rotation = _rotation;
    color = _color;
    button.init(_size, _position, _rotation, _color);
    seed = ofRandom(0, 180);
}

void Jellyfish::update() {
    speed = abs(sin((ofGetFrameNum() + seed) / 180.0 * PI) * sin((ofGetFrameNum() + seed) / 180.0 * PI) * sin((ofGetFrameNum() + seed) / 180.0 * PI));
    position.x += speed * cos(rotation / 180.0 * PI) * 0.5;
    position.y += speed * sin(rotation / 180.0 * PI) * 0.5;
    button.position = position;
}

void Jellyfish::draw() {
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    ofPushMatrix();
    ofTranslate(position);
    ofRotate(rotation);
    ofSetColor(color);
    float r = size / 30.0;
    for (int i = 0; i < 6; i ++) {
        float x = -i * r * 3 * cos(((1-speed)*0.25) * PI) - size / 2.0;
        float y = r * 3 - r * 2 * cos(((1-speed) * i*0.28) * PI) + size / 10.0 * (1 - speed);
        ofDrawCircle(x, y, r);
    }
    for (int i = 0; i < 4; i ++) {
        float x = -i * r * 3 * cos(((1-speed)*0.25) * PI) - size / 2.0;
        float y = r * 4 - r * 2 * cos(((1-speed) * i*0.28) * PI) + size / 5.0 * (1 - speed);
        ofDrawCircle(x, y, r);
    }
    for (int i = 0; i < 7; i ++) {
        float x = -i * r * 3 * cos(((1-speed)*0.25) * PI) - size / 2.0;
        float y = r - r * 2 * cos(((1-speed) * i*0.28) * PI) + size / 20.0 * (1 - speed);
        ofDrawCircle(x, y, r);
    }
    
    for (int i = 0; i < 6; i ++) {
        float x = -i * r * 3 * cos(((1-speed)*0.25) * PI) - size / 2.0;
        float y = -r * 3 + r * 2 * cos(((1-speed) * i*0.28) * PI) - size / 10.0 * (1 - speed);
        ofDrawCircle(x, y, r);
    }
    for (int i = 0; i < 4; i ++) {
        float x = -i * r * 3 * cos(((1-speed)*0.25) * PI) - size / 2.0;
        float y = -r * 4 + r * 2 * cos(((1-speed) * i*0.28) * PI) - size / 5.0 * (1 - speed);
        ofDrawCircle(x, y, r);
    }
    for (int i = 0; i < 7; i ++) {
        float x = -i * r * 3 * cos(((1-speed)*0.25) * PI) - size / 2.0;
        float y = -r + r * 2 * cos(((1-speed) * i*0.28) * PI) - size / 20.0 * (1 - speed);
        ofDrawCircle(x, y, r);
    }
    ofPopMatrix();
    
    button.draw();
    ofDisableBlendMode();
}
