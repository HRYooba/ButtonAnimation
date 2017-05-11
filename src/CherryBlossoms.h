#include "def.h"
#include "Button.h"

class CherryBlossoms : public Animation{
private:
    Button button[BUTTON_COUNT];
    ofImage tree;
    ofxXmlSettings XML;
    float sizeMin;
    float sizeMax;
    
public:
    void setup();
    void init();
    void update();
    void draw();};
