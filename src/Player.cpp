/* 
 * File:   Player.cpp
 * Author: ivpusic
 * 
 * Created on January 5, 2014, 1:13 AM
 */

#include "Player.h"

Player::Player(double width, double height, b2Vec2 position, b2World *world) {
    
    mouse_joint = NULL;
    
    body_def.type = b2_dynamicBody;
    body_def.position.Set(position.x, position.y);
    body_def.angle = 0;

    body = world->CreateBody(&body_def);
    b2PolygonShape polygonShape;

    polygonShape.SetAsBox(width, height);
    fixture_def.shape = &polygonShape;
    fixture_def.density = 0.5;
    fixture = body->CreateFixture(&fixture_def);
}

Player::~Player() {
}