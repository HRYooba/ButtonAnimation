#include "def.h"
#include "Button.h"

class Rainbow : public Animation{
private:
    Button button[BUTTON_COUNT];
    ofxXmlSettings XML;
    ofImage sky;
    bool alphaFlag[BUTTON_COUNT];
    int alphaMax;
    float alphaSpeed;
    
public:
    void setup();
    void init();
    void update();
    void draw();
};
