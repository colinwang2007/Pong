#include "Ball.h"
#include "Bat.h"
#include <math.h>
//
// Created by Colin Wang on 2022-01-30.
//

Ball::Ball(float startX, float startY, float radius, int x,float y,float speed) {
    movementspeed=speed;
    ydirection=y/100.0;
    if(x==2) {
        xdirection = -(sqrt(1-(ydirection*ydirection)));
    }
    else{
        xdirection = (sqrt(1-(ydirection*ydirection)));
    }

    m_position=Vector2f(startX, startY);
    m_Shape.setPosition(m_position);
    m_Shape.setFillColor(sf::Color(255, 31, 40));
    m_Shape.setRadius(radius);
}
void Ball::newBall(float startX, float startY, float radius, int x,float y,float speed) {
    movementspeed=speed;
    ydirection=y/100.0;
    if(x==2) {
        xdirection = -(sqrt(1-(ydirection*ydirection)));
    }
    else{
        xdirection = (sqrt(1-(ydirection*ydirection)));
    }

    m_position=Vector2f(startX, startY);
    m_Shape.setPosition(m_position);
    m_Shape.setFillColor(sf::Color(255, 31, 40));
    m_Shape.setRadius(radius);
}

Vector2<float> Ball::getPosition() {
    return m_position;
}
CircleShape Ball::getShape(){
    return m_Shape;
}
void Ball::setx(float x){
    m_position.x=x;
}
void Ball::sety(float y){
    m_position.y=y;
}
void Ball::hitLeftWall(){
    xdirection=-xdirection;
    setx(0);
}

void Ball::hitRightWall(){
    xdirection=-xdirection;
    setx(1920-(m_Shape.getRadius()*2));
}
void Ball::hitRoof() {
    ydirection=-ydirection;
    sety(0);
}
void Ball::hitBat() {
    ydirection=-ydirection;
    //Add more stuff later?
}
void Ball::hitBottom(){
}
void Ball::update(Time dt){
    m_position.x+=m_Speed*dt.asSeconds()*xdirection;
    m_position.y-=m_Speed*dt.asSeconds()*ydirection*movementspeed;
    if(m_position.x>1920-(m_Shape.getRadius()*2)){
        hitRightWall();
    }
    if(m_position.x<0){
        hitLeftWall();
    }
    if(m_position.y<0){
        hitRoof();
    }
    m_Shape.setPosition(m_position);
}