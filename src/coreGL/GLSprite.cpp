/* 
 * File:   GLSprite.cpp
 * Author: ivpusic
 * 
 * Created on January 13, 2014, 1:00 AM
 */

#include <math.h>

#include "GLSprite.h"

void GLSprite::init() {
    posx = 0;
    posy = 0;
    width = 1;
    height = 1;
    angle = 0;
    angleRadians = 0;
    allowTranslate = true;
}

void GLSprite::translate() {
    if (allowTranslate) {
        glLoadIdentity();
        glTranslated(0, posy, 0);
        glTranslated(posx, 0, 0);
        glRotated(angle, 0, 0, 1);
        glTranslated(-getWidth() / 2, -getHeight() / 2, 0);
    }
}

void GLSprite::setWidth(double w) {
    width = w;
}

void GLSprite::setHeight(double h) {
    height = h;
}

double GLSprite::getWidth() {
    return width;
}

double GLSprite::getHeight() {
    return height;
}