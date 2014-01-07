/* 
 * File:   Player.cpp
 * Author: ivpusic
 * 
 * Created on January 5, 2014, 1:13 AM
 */

#include "Player.h"

Player::Player(double width, double height, b2Vec2 position, b2World *world) {
    
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.angle = 0;

    body = world->CreateBody(&bodyDef);
    b2PolygonShape polygonShape;

    polygonShape.SetAsBox(width, height);
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = 0.5;
    fixture = body->CreateFixture(&fixtureDef);
}

Player::~Player() {
}