#include "def.h"
#include "Jellyfish.h"

class Sea : public Animation{
private:
    Jellyfish jellyfish[BUTTON_COUNT];
    ofxXmlSettings XML;
    
public:
    void setup();
    void init();
    void update();
    void draw();
};
