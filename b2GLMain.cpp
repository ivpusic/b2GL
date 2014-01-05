/* 
 * File:   b2GLMain.cpp
 * Author: ivpusic
 * 
 * Created on January 5, 2014, 12:18 AM
 */

#include <stdio.h>

#include "b2GLMain.h"
#define PTM_RATIO 32

b2GLRectangle *b2GLMain::drawF() {

    b2WeldJointDef wjd;
    fixture_properties properties;
    properties.density = 5.0;

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
    b2GLCicle *cicle = new b2GLCicle(3, b2Vec2(18, 0), world, properties);

    return cicle;
}

b2GLRectangle *b2GLMain::drawI() {
    fixture_properties properties;
    properties.density = 1.0;
    b2GLRectangle *i = new b2GLRectangle(1, 4, b2Vec2(22, 1), world, properties);

    return i;
}

b2GLMain::b2GLMain(b2World *world) {
    this->world = world;

    timeStep = 1.0f / 60.f;
    velocityIterations = 10;
    positionIterations = 10;
    leftMouseClick = false;
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
        b2Vec2 curPos = b->GetPosition();
    }

    world->DrawDebugData();
    //image->drawImage();
    glutSwapBuffers();
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

    player = new Player(2, 2, b2Vec2(128 / PTM_RATIO, 128 / PTM_RATIO), world);
    drawF();
    drawO();
    drawI();
    drawBounds();
}

b2Vec2 b2GLMain::gl_to_box2d_vec2(double x, double y) {
    return b2Vec2(x, YMAX - y);
}

void b2GLMain::on_mouse_button(int button, int state, int x, int y) {
    b2MouseJointDef md;

    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_UP && player->get_mouse_joint() != NULL) {
                world->DestroyJoint(player->get_mouse_joint());
                player->set_mouse_joint(NULL);
                leftMouseClick = false;
            }

            if (state == GLUT_DOWN) {
                if (player->get_mouse_joint() != NULL) return;
                if (player->get_fixture()->TestPoint(gl_to_box2d_vec2(x / PTM_RATIO, y / PTM_RATIO))) {
                    md.bodyA = groundBody;
                    md.bodyB = player->get_body();
                    md.target = player->get_body()->GetPosition();
                    md.collideConnected = true;
                    md.maxForce = 1000.0f * player->get_body()->GetMass();

                    player->set_mouse_joint((b2MouseJoint*) world->CreateJoint(&md));
                    player->get_body()->SetAwake(true);
                    player->get_mouse_joint()->SetTarget(b2Vec2(x / PTM_RATIO, (glutGet(GLUT_WINDOW_HEIGHT) - y) / PTM_RATIO));
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
    if (c == 'q') exit(0);
}

void b2GLMain::on_mouse_move(int x, int y) {
    if (leftMouseClick) {
        if (player->get_mouse_joint() == NULL) return;
        player->get_mouse_joint()->SetTarget(b2Vec2(x / PTM_RATIO, (glutGet(GLUT_WINDOW_HEIGHT) - y) / PTM_RATIO));
    }
}

b2GLMain::~b2GLMain() {
    free(rect);
    free(rect1);
    free(rect2);
    free(rect3);
    free(rect4);
    free(rect5);
}