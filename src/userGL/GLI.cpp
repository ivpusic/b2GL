/* 
 * File:   GLI.cpp
 * Author: ivpusic
 * 
 * Created on January 13, 2014, 2:24 AM
 */

#include "GLI.h"

GLI::GLI() {
    init();
    setWidth(2);
    setHeight(8);
}

void GLI::draw() {
    GLRect *iRect = new GLRect(2, 8);
    iRect->draw();
}