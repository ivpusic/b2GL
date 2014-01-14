/* 
 * File:   GLF.cpp
 * Author: ivpusic
 * 
 * Created on January 13, 2014, 1:43 AM
 */

#include "GLF.h"

GLF::GLF() {
    init();
    setWidth(2);
    setHeight(2);
}

void GLF::draw() {
    glColor3d(1, 0, 0);
    GLRect *r1 = new GLRect(2, 8);
    GLRect *r2 = new GLRect(2, 2);

    r1->draw();
    glTranslated(0, getWidth(), 0);
    glTranslated(getHeight(), 0, 0);
    r2->draw();
    glTranslated(0, getWidth() * 2, 0);
    r2->draw();
}