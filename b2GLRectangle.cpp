/* 
 * File:   b2GLRectangle.cpp
 * Author: ivpusic
 * 
 * Created on January 4, 2014, 3:51 PM
 */

#include "b2GLRectangle.h"

b2GLRectangle::b2GLRectangle(double width, double height, b2Vec2 position, b2World *world, fixture_properties properties) {

    body_def.type = b2_dynamicBody;
    body_def.position.Set(position.x, position.y);
    body_def.angle = 0;

    body = world->CreateBody(&body_def);

    // define shape
    b2PolygonShape rectangleShape;
    rectangleShape.SetAsBox(width, height);

    // define fixture
    fixture_def.shape = &rectangleShape;
    fixture_def.density = properties.density;
    body->CreateFixture(&fixture_def);
}

b2Body* b2GLRectangle::getBody() {
    return body;
}