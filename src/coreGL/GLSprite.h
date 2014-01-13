/* 
 * File:   GLSprite.h
 * Author: ivpusic
 *
 * Created on January 13, 2014, 1:00 AM
 */

#ifndef GLSPRITE_H
#define	GLSPRITE_H

#include <GL/freeglut.h>

class GLSprite {
public:
    // virtual methods
    virtual void draw() = 0;

    // regular methods
    void init();
    void translate();
    void setWidth(double w);
    void setHeight(double h);
    double getWidth();
    double getHeight();

    // members
    double posx;
    double posy;
    double angle;
    double angleRadians;

private:
    double width;
    double height;
    
protected:
    bool allowTranslate;
};

#endif	/* GLSPRITE_H */