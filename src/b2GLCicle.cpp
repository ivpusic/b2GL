/* 
 * File:   b2GLCicle.cpp
 * Author: ivpusic
 * 
 * Created on January 4, 2014, 6:27 PM
 */

#include "b2GLCicle.h"

b2GLCicle::b2GLCicle(double radius, b2Vec2 position, b2World *world, fixture_properties properties) {
    body_def.type = b2_dynamicBody;
    body_def.position.Set(position.x, position.y);
    body_def.angle = 0;

    body = world->CreateBody(&body_def);

    // define shape
    b2CircleShape cicleShape;
    cicleShape.m_radius = radius;

    // define fixture
    fixture_def.shape = &cicleShape;
    fixture_def.density = properties.density;
    body->CreateFixture(&fixture_def);
}

b2GLCicle::~b2GLCicle() {
}

