/* 
 * File:   GLO.cpp
 * Author: ivpusic
 * 
 * Created on January 13, 2014, 12:36 PM
 */
#include "GLO.h"

GLO::GLO(double r) {
    init();
    this->r = r;
    setWidth(r);
    setHeight(r);
    tex = new GLSpriteTexture2D((char*) "src/assets/o_letter.png");
}

void GLO::draw() {
    tex->draw();
}