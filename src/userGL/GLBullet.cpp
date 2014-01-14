/* 
 * File:   GLBullet.cpp
 * Author: ivpusic
 * 
 * Created on January 14, 2014, 8:13 PM
 */

#include "GLBullet.h"

GLBullet::GLBullet(b2World *world, double power, double angle) {
    init();
    tex = new GLSpriteTexture2D((char*) "src/assets/bullet.png");
    tex->posx = 20;
    tex->posy = 20;

    fixture_properties props;
    props.density = 1;
    props.bodyType = b2_dynamicBody;
    bullet = new b2GLRectangle(1, 0.5, b2Vec2(1, 1), world, props);
    b2Body *b = bullet->getBody();
    b->SetTransform(b2Vec2(1, 1), angle);
    b->ApplyLinearImpulse(b2Vec2(power * cos(angle), power * sin(angle)), b->GetWorldCenter(), true);
    b->SetUserData((void*)tex);
}

GLBullet::~GLBullet() {
}

void GLBullet::draw() {
    tex->draw();
}