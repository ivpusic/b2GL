/* 
 * File:   GLBullet.h
 * Author: ivpusic
 *
 * Created on January 14, 2014, 8:13 PM
 */

#ifndef GLBULLET_H
#define	GLBULLET_H

#include "../b2GL/b2GLRectangle.h"
#include "../coreGL/GLSprite.h"
#include "../coreGL/GLSpriteTexture2D.h"

class GLBullet : public GLSprite {
public:
    // methods
    GLBullet(b2World *world, double power, double angle);
    void draw();
    virtual ~GLBullet();
    
    // members
    GLSpriteTexture2D *tex;
    b2GLRectangle *bullet;
    double power;
};

#endif	/* GLBULLET_H */