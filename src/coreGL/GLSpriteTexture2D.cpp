/* 
 * File:   Image.cpp
 * Author: ivpusic
 * 
 * Created on December 23, 2013, 6:00 PM
 */

#include "GLSpriteTexture2D.h"

GLSpriteTexture2D::GLSpriteTexture2D() {

}

GLSpriteTexture2D::GLSpriteTexture2D(char *path) {
    init();
    texture = SOIL_load_OGL_texture
            (
            path,
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
            );
    if (texture == 0)
        cerr << "SOIL loading error: '" << SOIL_last_result() << "' (" << path << ")" << endl;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    float w, h;
    glGetTexLevelParameterfv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
    glGetTexLevelParameterfv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);

    setWidth(w / PTM_RATIO);
    setHeight(h / PTM_RATIO);
}

void GLSpriteTexture2D::draw() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, texture);
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2i(0, 0);
    glVertex2i(0, 0);
    glTexCoord2i(1, 0);
    glVertex2i(getWidth(), 0);
    glTexCoord2i(1, 1);
    glVertex2i(getWidth(), getHeight());
    glTexCoord2i(0, 1);
    glVertex2i(0, getHeight());
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}

// overrides default implementation
void GLSpriteTexture2D::translate() {
}