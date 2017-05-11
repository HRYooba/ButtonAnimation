#include "Sea.h"

void Sea::setup() {
    XML.loadFile("animationSettings.xml");
    turn = XML.getValue("SEA:TURN", -1);
    time = XML.getValue("SEA:TIME", -1.0);
    
    for (int i = 0; i < BUTTON_COUNT; i++) {
        jellyfish[i].setup();
    }
}

void Sea::init() {
    timeTemp_s = ofGetElapsedTimef();
    isPlaying = true;
    
    for (int i = 0; i < BUTTON_COUNT; i++) {
        float size = ofRandom(40, 100);
        float rotation = ofRandom(0, 360);
        ofColor color;
        color.setHsb(ofRandom(180, 150), ofRandom(100, 150), ofRandom(250, 255));
        color.a = 200;
        jellyfish[i].init(size, ofVec2f(ofRandom(DISPLAY_WIDTH), ofRandom(DISPLAY_HEIGHT)), rotation, color);
    }
}

void Sea::update() {
    if (getElapsedTime() > time) {
        isPlaying = false;
        return;
    }
    
    for (int i = 0; i < BUTTON_COUNT; i++) {
        jellyfish[i].update();
    }
}

void Sea::draw() {
    for (int i = 0; i < BUTTON_COUNT; i++) {
        jellyfish[i].draw();
    }
}
