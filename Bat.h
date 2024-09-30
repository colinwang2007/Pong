#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
    Vector2f m_position;
    // rectangle shape object for the bat itself
    RectangleShape m_Shape;
    float m_Speed = 1000.0f;
    bool m_MovingRight = false;
    bool m_MovingLeft = false;



public:
    Bat(float startX, float startY, int width, int height);
    bool newBat(float startX, float startY, int width, int height);
    // getPosition() returns the four positions that define the rectangle
    Vector2<float> getPosition();
    // getShape() will return the rectangle shape
    RectangleShape getShape();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    // calculate how to move the bat each frame
    void update(Time dt);
};

