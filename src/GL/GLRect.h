/* 
 * File:   GLRect.h
 * Author: ivpusic
 *
 * Created on January 13, 2014, 12:21 AM
 */

#ifndef GLRECT_H
#define	GLRECT_H

#include <GL/freeglut.h>
#include "GLSprite.h"

class GLRect : public GLSprite {
public:
    GLRect(double w, double h);
    void draw();
    void transform();

private:

};

#endif	/* GLRECT_H */