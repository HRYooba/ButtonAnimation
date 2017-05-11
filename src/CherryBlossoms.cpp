#include "CherryBlossoms.h"

void CherryBlossoms::setup() {
    
    XML.loadFile("animationSettings.xml");
    turn = XML.getValue("CHERRYBLOSSOMS:TURN", -1);
    time = XML.getValue("CHERRYBLOSSOMS:TIME", -1.0);
    sizeMin = XML.getValue("CHERRYBLOSSOMS:BUTTON_SIZE_MIN", -1.0);
    sizeMax = XML.getValue("CHERRYBLOSSOMS:BUTTON_SIZE_MAX", -1.0);
    
    tree.load("tree.png");
    
    for (int i = 0; i < BUTTON_COUNT; i++) {
        button[i].setup();
    }
}

void CherryBlossoms::init() {
    
    timeTemp_s = ofGetElapsedTimef();
    isPlaying = true;
    
    for (int i = 0; i < BUTTON_COUNT; i++) {
        
        ofColor color;
        color.setHsb(ofRandom(210, 230), ofRandom(180), ofRandom(250, 255));
        color.a = 250;
        float theta = ofRandom(PI * 2);
        float size = ofRandom(sizeMin, sizeMax);
        float rotation = ofRandom(0, 360);
        
        int seed = int(ofRandom(10));
        button[i].sizeSpeed = ofRandom(1, 2);
        bool check = false;
        int escapeCount = 0;
        
        while(!check) {
            escapeCount ++;
            
            switch (seed) {
                case 0:
                    button[i].init(size, ofVec2f(1000 + ofRandom(300) * cos(theta), 920 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 1:
                    button[i].init(size, ofVec2f(638 + ofRandom(300) * cos(theta), 893 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 2:
                    button[i].init(size, ofVec2f(700 + ofRandom(300) * cos(theta), 670 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 3:
                    button[i].init(size, ofVec2f(440 + ofRandom(300) * cos(theta), 600 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 4:
                    button[i].init(size, ofVec2f(400 + ofRandom(300) * cos(theta), 500 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 5:
                    button[i].init(size, ofVec2f(350 + ofRandom(300) * cos(theta), 140 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 6:
                    button[i].init(size, ofVec2f(480 + ofRandom(300) * cos(theta), 130 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 7:
                    button[i].init(size, ofVec2f(1060 + ofRandom(300) * cos(theta), 290 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 8:
                    button[i].init(size, ofVec2f(1080 + ofRandom(300) * cos(theta), 135 + ofRandom(100) * sin(theta)), rotation, color);
                    break;
                case 9:
                    button[i].init(size, ofVec2f(1338 + ofRandom(300) * cos(theta), 72 + ofRandom(40) * sin(theta)), rotation, color);
                    break;
            }
            
            check = true;
            
            for (int j = 0; j < i; j++) {
                float dist = ofDist(button[i].position.x, button[i].position.y, button[j].position.x, button[j].position.y);
                if (i != j && dist < button[i].sizeMax + button[j].sizeMax) {
                    if (escapeCount < 500) {
                        check = false;
                    } else {
                        //                        cout << "button rides on the button:" << i << endl;
                    }
                }
            }
        }
        button[i].size = 0;
    }
}

void CherryBlossoms::update() {
    if (getElapsedTime() > time) {
        isPlaying = false;
        return;
    }
    
    for (int i = 0; i < BUTTON_COUNT; i++) {
        float theta = getElapsedTime() / 20.0 * button[i].sizeSpeed * PI;
        if (theta < PI / 2) {
            button[i].size = button[i].sizeMax * abs(sin(theta));
        }
    }
}

void CherryBlossoms::draw() {
    ofSetColor(255);
    tree.draw(0, 0);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    for (int i = 0; i < BUTTON_COUNT; i++) {
        button[i].draw();
    }
    ofDisableBlendMode();
}
