/* 
 * File:   b2GLCicle.cpp
 * Author: ivpusic
 * 
 * Created on January 4, 2014, 6:27 PM
 */

#include "b2GLCicle.h"

b2GLCicle::b2GLCicle(double radius, b2Vec2 position, b2World *world, fixture_properties properties) {
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.angle = 0;

    body = world->CreateBody(&bodyDef);

    // define shape
    b2CircleShape cicleShape;
    cicleShape.m_radius = radius;

    // define fixture
    fixtureDef.shape = &cicleShape;
    fixtureDef.density = properties.density;
    body->CreateFixture(&fixtureDef);
}

b2GLCicle::~b2GLCicle() {
}