#include "Rainbow.h"

void Rainbow::setup() {
    XML.loadFile("animationSettings.xml");
    turn = XML.getValue("RAINBOW:TURN", -1);
    time = XML.getValue("RAINBOW:TIME", -1.0);
    alphaMax = XML.getValue("RAINBOW:ALPHA_MAX", -1);
    alphaSpeed = XML.getValue("RAINBOW:ALPHA_SPEED", -1);
    sky.load("sky.png");
    
    for (int i = 0; i < BUTTON_COUNT; i++) {
        button[i].setup();
    }
}

void Rainbow::init() {
    timeTemp_s = ofGetElapsedTimef();
    isPlaying = true;
    
    for (int i = 0; i < BUTTON_COUNT; i++) {
        ofColor color;
        float rotation = ofRandom(0, 360);
        float x;
        float y;
        float size;
        
        alphaFlag[i] = false;
        int seed = i;
        
        /* rainbow line divide */
        if (0 <= seed && seed < 20) {
            color.setHsb(ofRandom(150, 200), ofRandom(150, 240), ofRandom(250, 255));
            float theta = seed/19.0 * PI/2.0 - PI;
            x = 1100 * cos(theta) + DISPLAY_WIDTH + ofRandom(-20, 20);
            y = 600 * sin(theta) + DISPLAY_HEIGHT + ofRandom(-20, 20);
            size = ofRandom(100, 200);
            
        } else if (20 <= seed && seed < 40) {
            int n = seed - 20;
            color.setHsb(ofRandom(50, 100), ofRandom(150, 240), ofRandom(250, 255));
            float theta = n/19.0 * PI/2.0 - PI;
            x = 1250 * cos(theta) + DISPLAY_WIDTH + ofRandom(-20, 20);
            y = 700 * sin(theta) + DISPLAY_HEIGHT + ofRandom(-20, 20);
            size = ofRandom(100, 200);
            
        } else if (40 <= seed && seed < 70) {
            int n = seed - 40;
            color.setHsb(ofRandom(30, 40), ofRandom(150, 240), ofRandom(250, 255));
            float theta = n/29.0 * PI/2.0 - PI;
            x = 1400 * cos(theta) + DISPLAY_WIDTH + ofRandom(-20, 20);
            y = 800 * sin(theta) + DISPLAY_HEIGHT + ofRandom(-20, 20);
            size = ofRandom(100, 200);
            
        } else if (70 <= seed && seed < 100) {
            int n = seed - 70;
            color.setHsb(ofRandom(0, 10), ofRandom(150, 240), ofRandom(250, 255));
            float theta = n/29.0 * PI/2.0 - PI;
            x = 1550 * cos(theta) + DISPLAY_WIDTH + ofRandom(-20, 20);
            y = 900 * sin(theta) + DISPLAY_HEIGHT + ofRandom(-20, 20);
            size = ofRandom(100, 200);
        }
        
        button[i].init(size, ofVec2f(x, y), rotation, color);
        button[i].color.a = 0;
    }
    
    alphaFlag[0] = true;
    alphaFlag[20] = true;
    alphaFlag[40] = true;
    alphaFlag[70] = true;
}

void Rainbow::update() {
    if (getElapsedTime() > time) {
        isPlaying = false;
        return;
    }
    
    /* slow show rainbow */
    for (int i = 0; i < 20; i++) {
        if (alphaFlag[i]) {
            float alpha = button[i].color.a;
            button[i].color.a += alphaSpeed;
            if (alpha > alphaMax) {
                alphaFlag[i] = false;
            }
            if (alpha > alphaMax / 3.0) {
                if (i + 1 < 20) {
                    alphaFlag[i + 1] = true;
                }
            }
            if (alpha > alphaMax * 2.0 / 3.0) {
                if (i + 2 < 20) {
                    alphaFlag[i + 2] = true;
                }
            }
        }
    }
    for (int i = 20; i < 40; i++) {
        if (alphaFlag[i]) {
            float alpha = button[i].color.a;
            button[i].color.a += alphaSpeed;
            if (alpha > alphaMax) {
                alphaFlag[i] = false;
            }
            if (alpha > alphaMax / 3.0) {
                if (i + 1 < 40) {
                    alphaFlag[i + 1] = true;
                }
            }
            if (alpha > alphaMax * 2.0 / 3.0) {
                if (i + 2 < 40) {
                    alphaFlag[i + 2] = true;
                }
            }
        }
    }
    for (int i = 40; i < 70; i++) {
        if (alphaFlag[i]) {
            float alpha = button[i].color.a;
            button[i].color.a += alphaSpeed + alphaSpeed/2.0;
            if (alpha > alphaMax) {
                alphaFlag[i] = false;
            }
            if (alpha > alphaMax / 3.0) {
                if (i + 1 < 70) {
                    alphaFlag[i + 1] = true;
                }
            }
            if (alpha > alphaMax * 2.0 / 3.0) {
                if (i + 2 < 70) {
                    alphaFlag[i + 2] = true;
                }
            }
        }
    }
    for (int i = 70; i < 100; i++) {
        if (alphaFlag[i]) {
            float alpha = button[i].color.a;
            button[i].color.a += alphaSpeed + alphaSpeed/2.0;
            if (alpha > alphaMax) {
                alphaFlag[i] = false;
            }
            if (alpha > alphaMax / 3.0) {
                if (i + 1 < 100) {
                    alphaFlag[i + 1] = true;
                }
            }
            if (alpha > alphaMax * 2.0 / 3.0) {
                if (i + 2 < 100) {
                    alphaFlag[i + 2] = true;
                }
            }
        }
    }
    
}

void Rainbow::draw() {
    ofSetColor(255);
    sky.draw(0, 0);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    for (int i = 0; i < BUTTON_COUNT; i++) {
        button[i].draw();
    }
    ofDisableBlendMode();
}
