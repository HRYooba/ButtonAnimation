#include "def.h"
#include "Button.h"

class Jellyfish {
private:
    Button button;
    int seed;
    
public:
    void setup();
    void init(float _size, ofVec2f _position, float _rotation, ofColor _color);
    void update();
    void draw();
    
    ofVec2f position;
    float rotation;
    float speed;
    float size;
    ofColor color;
};
