#include "Bat.h"
#include <math.h>
//
// Created by Colin Wang on 2022-01-30.
//

Bat::Bat(float startX, float startY, int width, int height) {
    m_position=Vector2f(startX, startY);
    m_Shape.setPosition(m_position);
    m_Shape.setOutlineColor(sf::Color(255, 31, 40));
    m_Shape.setSize(sf::Vector2f(width, height));
}
bool Bat::newBat(float startX, float startY, int width, int height) {
    m_position=Vector2f(startX, startY);
    m_Shape.setPosition(m_position);
    m_Shape.setOutlineColor(sf::Color(255, 31, 40));
    m_Shape.setSize(sf::Vector2f(width, height));
}

Vector2<float> Bat::getPosition() {
    return m_position;
}
RectangleShape Bat::getShape(){
    return m_Shape;
}
void Bat::moveLeft(){
    m_MovingLeft=true;
}
void Bat::moveRight(){
    m_MovingRight=true;
}
void Bat::stopLeft(){
    m_MovingLeft=false;
}
void Bat::stopRight(){
    m_MovingRight=false;
}
void Bat::update(Time dt){
    if(m_MovingRight){
        m_position.x+=m_Speed*dt.asSeconds();
        if(m_position.x>1920-m_Shape.getSize().x){
            m_position.x=1920-m_Shape.getSize().x;
        }
    }
    if(m_MovingLeft){
        m_position.x-=m_Speed*dt.asSeconds();
        if(m_position.x<0){
            m_position.x=0;
        }
    }
    m_Shape.setPosition(m_position);
}