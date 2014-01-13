/* 
 * File:   b2GLMain.h
 * Author: ivpusic
 *
 * Created on January 5, 2014, 12:18 AM
 */

#ifndef B2GLMAIN_H
#define	B2GLMAIN_H

#include <list>
#include <GL/freeglut.h>
#include <Box2D/Box2D.h>
#include "b2GLRectangle.h"
#include "b2GLCicle.h"
#include "b2GLMouseClickCallback.h"
#include "../coreGL/GLSpriteTexture2D.h"

#include "../coreGL/GLRect.h"
#include "../coreGL/GLSprite.h"
#include "../userGL/GLF.h"
#include "../userGL/GLI.h"
#include "../userGL/GLO.h"
#include "../b2GL/globals.h"

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

    b2Body *groundBody;

    b2GLMain(b2World *world, int WIN_ID);
    void scale(int w, int h);
    void on_mouse_button(int button, int state, int x, int y);
    void on_mouse_move(int x, int y);
    void on_key_down(unsigned char c, int x, int y);
    void display();
    void init();
    b2Vec2 gl_to_box2d_vec2(b2Vec2 pos);
    virtual ~b2GLMain();

private:
    // methods
    b2GLRectangle *drawF();
    b2GLCicle *drawO();
    b2GLRectangle *drawI();
    void drawStands();
    void drawBox(double x, double y, int width, int height);
    void drawBounds();
    void onScaled();

    // members
    int WIN_ID;

    std::list<GLSprite*> sprites;
    std::list<GLSprite*>::iterator spriteIterator;

    b2GLRectangle *rect;
    b2GLRectangle *rect1;
    b2GLRectangle *rect2;
    b2GLRectangle *rect3;
    b2GLRectangle *rect4;
    b2GLRectangle *rect5;

    GLRect *rectGL;
    GLSprite *sprite;
    GLF *glF;
    GLI *glI;
    GLO *glO;

    GLSpriteTexture2D *background;
    b2MouseJoint *mouseJoint;

    b2GLRectangle *fStand;
    b2GLRectangle *oStand;
    b2GLRectangle *iStand;

    GLSpriteTexture2D *fStandSprite;
    GLSpriteTexture2D *oStandSprite;
    GLSpriteTexture2D *iStandSprite;
};

#endif	/* B2GLMAIN_H */