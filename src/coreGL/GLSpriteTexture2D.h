/* 
 * File:   Image.h
 * Author: ivpusic
 *
 * Created on December 23, 2013, 6:00 PM
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <SOIL/SOIL.h>
#include <iostream>
#include "../b2GL/globals.h"
#include "GLSprite.h"

using namespace std;

typedef struct {
    int dimX, dimY;
    GLubyte* pixmap;
} picture;

class GLSpriteTexture2D : public GLSprite {
public:
    GLSpriteTexture2D();
    GLSpriteTexture2D(char* a);

    void draw();
    void translate();
    GLint texture;
};

#endif