#pragma once

#include "def.h"
#include "CherryBlossoms.h"
#include "Rainbow.h"
#include "Sea.h"

class AnimationController {
private:  
    int animationTurn;
    list <shared_ptr<Animation>> animation;
    
public:
    void setup();
    void update();
    void draw();
    void setAnimation(int _animationTurn);
    float getElapsedTime();
    int getAnimationTurn();
};
