#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"

#define RESOLUTION_RATIO 0.7

#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080

#define BUTTON_COUNT 100

#define ANIMATION_COUNT 3

/* if dont use ofxgui commentout */
//#define USE_OFXGUI

class Animation {
public:
    virtual void setup(){};
    virtual void init(){};
    virtual void update(){};
    virtual void draw(){};
    float getElapsedTime() {
        return ofGetElapsedTimef() - timeTemp_s;
    }
    
    int turn;
    float time;
    bool isPlaying;    
    float timeTemp_s;
};
