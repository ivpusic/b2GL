/* 
 * File:   GLRect.cpp
 * Author: ivpusic
 * 
 * Created on January 13, 2014, 12:21 AM
 */

#include "GLRect.h"

GLRect::GLRect(double w, double h) {
    setWidth(w);
    setHeight(h);
}

void GLRect::draw() {
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(0, 0);
    glVertex2d(getWidth(), 0);
    glVertex2d(getWidth(), getHeight());
    glVertex2d(0, getHeight());
    glVertex2d(0, 0);
    glEnd();
}