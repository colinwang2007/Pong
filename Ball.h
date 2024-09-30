//
// Created by Colin Wang on 2022-01-30.
//

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
    Vector2f m_position;
    // rectangle shape object for the bat itself
    CircleShape m_Shape;
    float m_Speed = 1000.0f;
    float xdirection = 0;
    float ydirection = 0;
    float movementspeed = 0;


public:
    Ball(float startX, float startY, float radius, int x, float y,float speed);
    void newBall(float startX, float startY, float radius, int x, float y,float speed);
    // getPosition() returns the four positions that define the rectangle
    Vector2<float> getPosition();
    // getShape() will return the rectangle shape
    CircleShape getShape();
    void setx(float x);
    void sety(float y);
    void hitLeftWall();
    void hitRightWall();
    void hitRoof();
    void hitBat();
    void hitBottom();
    // calculate how to move the bat each frame
    void update(Time dt);
};

