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

using namespace std;

typedef struct {
    int dimX, dimY;
    GLubyte* pixmap;
} picture;

class Image {
public:
    Image();
    Image(char* a);
    virtual ~Image();

    void drawImage();
private:
    picture pic;
};

#endif

