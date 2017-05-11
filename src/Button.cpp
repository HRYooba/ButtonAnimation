#include "Button.h"

void Button::setup() {
    int seed = int(ofRandom(0, 11));
    switch (seed) {
        case 0:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 1:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 2:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 3:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 4:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 5:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 6:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 7:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 8:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 9:
            img.load("button" + ofToString(seed) + ".png");
            break;
        case 10:
            img.load("button" + ofToString(seed) + ".png");
            break;
    }
}

void Button::init(float _size, ofVec2f _position, float _rotation, ofColor _color) {
    size = _size;
    sizeMax = _size;
    color = _color;
    position = _position;
    rotation = _rotation;
}

void Button::draw() {
    ofPushMatrix();
    ofTranslate(position);
    ofRotate(rotation);
    ofSetColor(color);
    img.draw(-size / 2.0, -size / 2.0, size, size);
    ofPopMatrix();
}
