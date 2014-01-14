/* 
 * File:   GLTrack.cpp
 * Author: ivpusic
 * 
 * Created on January 14, 2014, 2:36 PM
 */

#include "GLTrack.h"

GLTrack::GLTrack(b2World *world) {
    init();
    angle = 25;
    setWidth(30);
    setHeight(0.5);
    fixture_properties props;
    props.bodyType = b2_staticBody;
    track = new b2GLRectangle(30, 0.5, b2Vec2(70, 70), world, props);
    track->getBody()->SetTransform(track->getBody()->GetPosition(), DEGREES_TO_RADIANS(angle));
    tex = new GLSpriteTexture2D((char*) "src/assets/track.png");
    tex->posx = 70;
    tex->posy = 70;
    tex->angle = angle;
}

void GLTrack::draw() {
    GLSprite *s = (GLSprite*)tex;
    s->translate();
    tex->draw();
}