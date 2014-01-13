/* 
 * File:   b2GLMain.cpp
 * Author: ivpusic
 * 
 * Created on January 5, 2014, 12:18 AM
 */

#include <stdio.h>
#include "b2GLMain.h"

b2GLMain::b2GLMain(b2World *world, int WIN_ID) {

    XMIN = 0;
    YMIN = 0;

    mouseJoint = NULL;

    this->world = world;
    timeStep = 1.0f / 60.f;
    velocityIterations = 10;
    positionIterations = 10;
    leftMouseClick = false;
    this->WIN_ID = WIN_ID;
}

b2GLRectangle *b2GLMain::drawF() {

    b2WeldJointDef wjd;
    fixture_properties properties;
    properties.density = 5.0;
    properties.bodyType = b2_dynamicBody;

    rect = new b2GLRectangle(1, 1, b2Vec2(10, 10), world, properties);
    rect1 = new b2GLRectangle(1, 1, b2Vec2(10, 12), world, properties);
    wjd.Initialize(rect->getBody(), rect1->getBody(), b2Vec2(10, 10));
    world->CreateJoint(&wjd);

    rect2 = new b2GLRectangle(1, 1, b2Vec2(10, 14), world, properties);
    wjd.Initialize(rect1->getBody(), rect2->getBody(), b2Vec2(10, 10));
    world->CreateJoint(&wjd);

    rect3 = new b2GLRectangle(1, 1, b2Vec2(10, 16), world, properties);
    wjd.Initialize(rect2->getBody(), rect3->getBody(), b2Vec2(10, 16));
    world->CreateJoint(&wjd);

    properties.density = 1.0;
    rect4 = new b2GLRectangle(1, 1, b2Vec2(12, 16), world, properties);
    wjd.Initialize(rect1->getBody(), rect4->getBody(), b2Vec2(10, 16));
    world->CreateJoint(&wjd);

    rect5 = new b2GLRectangle(1, 1, b2Vec2(12, 12), world, properties);
    wjd.Initialize(rect3->getBody(), rect5->getBody(), b2Vec2(10, 12));
    world->CreateJoint(&wjd);

    return rect;
}

b2GLCicle *b2GLMain::drawO() {
    fixture_properties properties;
    properties.density = 1.0;
    properties.bodyType = b2_dynamicBody;

    b2GLCicle *cicle = new b2GLCicle(3, b2Vec2(18, 0), world, properties);

    return cicle;
}

b2GLRectangle *b2GLMain::drawI() {
    fixture_properties properties;
    properties.density = 1.0;
    properties.bodyType = b2_dynamicBody;

    b2GLRectangle *i = new b2GLRectangle(1, 4, b2Vec2(22, 1), world, properties);

    return i;
}

void b2GLMain::drawStands() {
    fixture_properties properties;
    properties.density = 1.0;
    properties.bodyType = b2_staticBody;

    fStand = new b2GLRectangle(5, 0.5, b2Vec2(20, 40), world, properties);
    fStandSprite = new GLSpriteTexture2D((char*) "src/assets/stand.png");
    fStandSprite->posx = 20;
    fStandSprite->posy = 40;
    sprites.push_back(fStandSprite);
    fStand->getBody()->SetUserData((void*) fStandSprite);

    oStand = new b2GLRectangle(6, 0.5, b2Vec2(35, 30), world, properties);
    oStandSprite = new GLSpriteTexture2D((char*) "src/assets/stand.png");
    oStandSprite->posx = 35;
    oStandSprite->posy = 30;
    sprites.push_back(oStandSprite);
    oStand->getBody()->SetUserData((void*) oStandSprite);

    iStand = new b2GLRectangle(6, 0.5, b2Vec2(50, 20), world, properties);
    iStandSprite = new GLSpriteTexture2D((char*) "src/assets/stand.png");
    iStandSprite->posx = 50;
    iStandSprite->posy = 20;
    sprites.push_back(iStandSprite);
    iStand->getBody()->SetUserData((void*) iStandSprite);
}

void b2GLMain::drawBounds() {
    b2Fixture *groundFixture;
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    groundBody = world->CreateBody(&groundBodyDef);

    b2EdgeShape groundBox;
    b2FixtureDef groundBoxDef;
    groundBoxDef.shape = &groundBox;

    groundBox.Set(b2Vec2(XMIN, YMIN), b2Vec2(XMAX, YMIN));
    groundFixture = groundBody->CreateFixture(&groundBoxDef);

    groundBox.Set(b2Vec2(XMAX, YMIN), b2Vec2(XMAX, YMAX));
    groundFixture = groundBody->CreateFixture(&groundBoxDef);

    groundBox.Set(b2Vec2(XMIN, YMIN), b2Vec2(XMIN, YMAX));
    groundFixture = groundBody->CreateFixture(&groundBoxDef);

    groundBox.Set(b2Vec2(XMIN, YMAX), b2Vec2(XMAX, YMAX));
    groundFixture = groundBody->CreateFixture(&groundBoxDef);
}

void b2GLMain::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    world->Step(timeStep, velocityIterations, positionIterations);
    world->ClearForces();

    for (b2Body *b = world->GetBodyList(); b; b = b->GetNext()) {
        if (b->GetUserData() != NULL) {
            if (b->GetType() == b2_dynamicBody) {
                sprite = (GLSprite*) b->GetUserData();
                sprite->posx = b->GetPosition().x;
                sprite->posy = b->GetPosition().y;
                float angle = RADIANS_TO_DEGREES(b->GetAngle());
                sprite->angle = angle;
                sprite->angleRadians = b->GetAngle();
            }
        }
    }

    if (DRAW_BOX2D) {
        world->DrawDebugData();
    }

    // draw sprites
    if (DRAW_GL) {
        for (spriteIterator = sprites.begin(); spriteIterator != sprites.end(); ++spriteIterator) {
            (*spriteIterator)->translate();
            (*spriteIterator)->draw();
        }
    }

    glutSwapBuffers();
}

void b2GLMain::init() {
    background = new GLSpriteTexture2D((char*) "src/assets/wood.png");
    rectGL = new GLRect(1, 1);
    glF = new GLF();
    glO = new GLO(3);
    glI = new GLI();

    sprites.push_back(background);
    sprites.push_back(glF);
    sprites.push_back(glI);
    sprites.push_back(glO);
}

void b2GLMain::onScaled() {
    b2Body *f = drawF()->getBody();
    b2Body *o = drawO()->getBody();
    b2Body *i = drawI()->getBody();

    f->SetUserData((void*) glF);
    o->SetUserData((void*) glO);
    i->SetUserData((void*) glI);

    double jointDistance = 15;

    b2RopeJointDef djd;
    djd.bodyA = f;
    djd.bodyB = o;
    djd.collideConnected = true;
    djd.maxLength = jointDistance;
    world->CreateJoint(&djd);

    djd.bodyA = o;
    djd.bodyB = i;
    djd.maxLength = jointDistance;
    world->CreateJoint(&djd);

    drawStands();
    drawBounds();
}

void b2GLMain::scale(int w, int h) {
    XMAX = glutGet(GLUT_WINDOW_WIDTH) / PTM_RATIO;
    double xrange = XMAX - XMIN;
    double yrange = h * xrange / w;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    YMAX = yrange;
    gluOrtho2D(XMIN, XMAX, YMIN, YMAX);
    onScaled();
}

b2Vec2 b2GLMain::gl_to_box2d_vec2(b2Vec2 pos) {
    return b2Vec2(pos.x, YMAX - pos.y);
}

void b2GLMain::on_mouse_button(int button, int state, int x, int y) {
    b2MouseJointDef md;

    switch (button) {
        case GLUT_LEFT_BUTTON:
            // mouse down
            if (state == GLUT_UP && mouseJoint != NULL) {
                world->DestroyJoint(mouseJoint);
                mouseJoint = NULL;
                leftMouseClick = false;
            }

            if (state == GLUT_DOWN) {
                // mouse up
                b2GLMouseClickCallback queryCallback;
                b2AABB aabb;
                aabb.lowerBound = gl_to_box2d_vec2(b2Vec2((x + 0.001) / PTM_RATIO, (y + 0.001) / PTM_RATIO));
                aabb.upperBound = gl_to_box2d_vec2(b2Vec2((x - 0.001) / PTM_RATIO, (y - 0.001) / PTM_RATIO));
                world->QueryAABB(&queryCallback, aabb);

                b2Fixture *fixture = queryCallback.getFoundFixture();
                if (fixture != NULL) {
                    if (mouseJoint != NULL) return;
                    md.bodyA = groundBody;
                    md.bodyB = fixture->GetBody();
                    md.target = fixture->GetBody()->GetPosition();
                    md.collideConnected = true;
                    md.maxForce = 1000.0f * fixture->GetBody()->GetMass();

                    mouseJoint = (b2MouseJoint*) world->CreateJoint(&md);
                    queryCallback.getFoundFixture()->GetBody()->SetAwake(true);
                    mouseJoint->SetTarget(b2Vec2(x / PTM_RATIO, (glutGet(GLUT_WINDOW_HEIGHT) - y) / PTM_RATIO));
                    leftMouseClick = true;
                }
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            break;
    }
    glutPostRedisplay();
}

void b2GLMain::on_key_down(unsigned char c, int x, int y) {
    if (c == 'q') {
        glutDestroyWindow(WIN_ID);
        this->~b2GLMain();
        exit(0);
    }
    if (c == 'g') DRAW_GL = 0;
    if (c == 'G') DRAW_GL = 1;
    if (c == 'b') DRAW_BOX2D = 0;
    if (c == 'B') DRAW_BOX2D = 1;
}

void b2GLMain::on_mouse_move(int x, int y) {
    if (leftMouseClick) {
        if (mouseJoint == NULL) return;
        mouseJoint->SetTarget(b2Vec2(x / PTM_RATIO, (glutGet(GLUT_WINDOW_HEIGHT) - y) / PTM_RATIO));
    }
}

b2GLMain::~b2GLMain() {
    free(rect);
    free(rect1);
    free(rect2);
    free(rect3);
    free(rect4);
    free(rect5);

    free(glF);
    free(glO);
    free(glI);

    free(fStand);
    free(oStand);
    free(iStand);

    free(fStandSprite);
    free(oStandSprite);
    free(iStandSprite);

    free(background);
    for (b2Body *b = world->GetBodyList(); b; b = b->GetNext()) {
        world->DestroyBody(b);
    }
    free(world);
    printf("Dealloc finished! \n");
}