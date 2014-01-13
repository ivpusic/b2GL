/* 
 * File:   GLI.cpp
 * Author: ivpusic
 * 
 * Created on January 13, 2014, 2:24 AM
 */

#include "GLI.h"

GLI::GLI() {
    setWidth(1);
    setHeight(4);
}

void GLI::draw() {
    glColor3d(0, 1, 0);
    GLRect *iRect = new GLRect(1, 4);
    iRect->draw();
}