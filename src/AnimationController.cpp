#include "AnimationController.h"


void AnimationController::setup() {
    
    /* create animation list */
    animation.push_back(make_shared<CherryBlossoms>());
    animation.push_back(make_shared<Rainbow>());
    animation.push_back(make_shared<Sea>());
    for (auto a : animation) {
        a->setup();
    }
    /* error log */
    if (animation.size() < ANIMATION_COUNT) {
        cout << "[Error] animation.size() < ANIMATION_COUNT : Please add some animation." << endl;
    } else if (animation.size() > ANIMATION_COUNT) {
        cout << "[Error] animation.size() > ANIMATION_COUNT : Please edit ANIMATION_COUNT(def.h)." << endl;
    }
    
    /* set first animation */
    animationTurn = 0;
    setAnimation(0);
}

void AnimationController::update() {
    for (auto a : animation) {
        if (a->turn == animationTurn) {
            /* animation loop */
            if (!a->isPlaying) {
                animationTurn ++;
                if (animationTurn > ANIMATION_COUNT - 1) {
                    animationTurn = 0;
                }
                setAnimation(animationTurn);
            }
            a->update();
        }
    }
}

void AnimationController::draw() {
    for (auto a : animation) {
        if (a->turn == animationTurn) {
            a->draw();
        }
    }
}

void AnimationController::setAnimation(int _animationTurn) {
    animationTurn = _animationTurn;
    
    for (auto a : animation) {
        if (a->turn == animationTurn) {
            a->init();
        }
    }
}

float AnimationController::getElapsedTime() {
    float time = -1.0;
    for (auto a : animation) {
        if (a->turn == animationTurn) {
            time = a->getElapsedTime();
        }
    }
    if (time == -1.0) {
        cout << "[Error] time == -1.0 : This animation[" + ofToString(animationTurn) + "] does not exist. Please add animation." << endl;
        setAnimation(0);
    }
    return time;
}

int AnimationController::getAnimationTurn() {
    return animationTurn;
}
