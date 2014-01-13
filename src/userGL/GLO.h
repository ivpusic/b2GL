/* 
 * File:   GLO.h
 * Author: ivpusic
 *
 * Created on January 13, 2014, 12:36 PM
 */

#ifndef GLO_H
#define	GLO_H

#include <iostream>
#include <math.h>
#include <SOIL/SOIL.h>
#include "../coreGL/GLSprite.h"
#include "../coreGL/GLSpriteTexture2D.h"
#include "../b2GL/globals.h"

using namespace std;

class GLO : public GLSprite {
public:
    GLO(double r);
    void draw();
    GLSpriteTexture2D *letterTex;

private:
    double r;
    GLSpriteTexture2D *tex;
};

#endif	/* GLO_H */