/* 
 * File:   b2GLMain.h
 * Author: ivpusic
 *
 * Created on January 5, 2014, 12:18 AM
 */

#ifndef B2GLMAIN_H
#define	B2GLMAIN_H

#include <GL/freeglut.h>
#include <Box2D/Box2D.h>
#include "b2GLRectangle.h"
#include "b2GLCicle.h"
#include "Player.h"

class b2GLMain {
public:
    double XMIN;
    double XMAX;
    double YMIN;
    double YMAX;

    b2World *world;
    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;
    bool leftMouseClick;

    b2GLMain *box2dGLMain;
    b2Body *groundBody;
    Player *player;

    b2GLMain(b2World *world);
    void scale(int w, int h);
    void on_mouse_button(int button, int state, int x, int y);
    void on_mouse_move(int x, int y);
    void on_key_down(unsigned char c, int x, int y);
    void display();
    b2Vec2 gl_to_box2d_vec2(double x, double y);
    virtual ~b2GLMain();

private:
    b2GLRectangle *drawF();
    b2GLCicle *drawO();
    b2GLRectangle *drawI();
    void drawBox(double x, double y, int width, int height);
    void drawBounds();

    b2GLRectangle *rect;
    b2GLRectangle *rect1;
    b2GLRectangle *rect2;
    b2GLRectangle *rect3;
    b2GLRectangle *rect4;
    b2GLRectangle *rect5;
};

#endif	/* B2GLMAIN_H */

