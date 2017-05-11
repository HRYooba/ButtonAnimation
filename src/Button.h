#pragma once

#include "def.h"

class Button {
    
private:
    ofImage img;
    
public:
    void setup();
    void init(float _size, ofVec2f _position, float _rotation, ofColor _color);
    void draw();
    
    ofVec2f position;
    float rotation;
    float size;
    float sizeMax;
    float sizeSpeed;
    ofColor color;
};
