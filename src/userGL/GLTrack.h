/* 
 * File:   GLTrack.h
 * Author: ivpusic
 *
 * Created on January 14, 2014, 2:36 PM
 */

#ifndef GLTRACK_H
#define	GLTRACK_H

#include <Box2D/Box2D.h>
#include "../b2GL/b2GLRectangle.h"
#include "../coreGL/GLSprite.h"
#include "../b2GL/b2GLTypes.h"
#include "../coreGL/GLSpriteTexture2D.h"

class GLTrack : public GLSprite {
public:
    GLTrack(b2World *world);
    void draw();
    GLSpriteTexture2D *tex;

private:
    b2GLRectangle *track;
    b2World *world;
    double angle;
};

#endif	/* GLTRACK_H */