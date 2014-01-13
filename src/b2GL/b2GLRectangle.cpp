/* 
 * File:   b2GLRectangle.cpp
 * Author: ivpusic
 * 
 * Created on January 4, 2014, 3:51 PM
 */

#include "b2GLRectangle.h"

b2GLRectangle::b2GLRectangle(double width, double height, b2Vec2 position, b2World *world, fixture_properties properties) {

    bodyDef.type = properties.bodyType;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.angle = 0;

    body = world->CreateBody(&bodyDef);

    // define shape
    b2PolygonShape rectangleShape;
    rectangleShape.SetAsBox(width, height);

    // define fixture
    fixtureDef.shape = &rectangleShape;
    fixtureDef.density = properties.density;
    body->CreateFixture(&fixtureDef);
}