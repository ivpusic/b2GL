/* 
 * File:   GLSprite.cpp
 * Author: ivpusic
 * 
 * Created on January 13, 2014, 1:00 AM
 */

#include "GLSprite.h"

void GLSprite::translate() {
    glLoadIdentity();
    glTranslated(0, posy, 0);
    glTranslated(posx, 0, 0);
    glRotated(angle, 0, 0, 1);
    glTranslated(-getWidth() / 2, -getHeight() / 2, 0);
}

void GLSprite::setWidth(double w) {
    width = w * 2;
}

void GLSprite::setHeight(double h) {
    height = h * 2;
}

double GLSprite::getWidth() {
    return width;
}

double GLSprite::getHeight() {
    return height;
}