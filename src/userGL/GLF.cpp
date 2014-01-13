/* 
 * File:   GLF.cpp
 * Author: ivpusic
 * 
 * Created on January 13, 2014, 1:43 AM
 */

#include "GLF.h"

GLF::GLF() {
    init();
    setWidth(1);
    setHeight(1);
}

void GLF::draw() {
    glColor3d(1, 0, 0);
    GLRect *r1 = new GLRect(1, 4);
    GLRect *r2 = new GLRect(1, 1);

    r1->draw();
    glTranslated(0, getWidth(), 0);
    glTranslated(getHeight(), 0, 0);
    r2->draw();
    glTranslated(0, getWidth() * 2, 0);
    r2->draw();
}