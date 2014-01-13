/* 
 * File:   b2GLMain.cpp
 * Author: ivpusic
 * 
 * Created on January 5, 2014, 12:18 AM
 */

#include <stdio.h>
#include "b2GLMain.h"

b2GLMain::b2GLMain(b2World *world) {

    XMIN = 0;
    YMIN = 0;

    mouseJoint = NULL;

    this->world = world;
    timeStep = 1.0f / 60.f;
    velocityIterations = 10;
    positionIterations = 10;
    leftMouseClick = false;
}

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
            sprite = (GLSprite*) b->GetUserData();
            sprite->posx = b->GetPosition().x;
            sprite->posy = b->GetPosition().y;
            float angle = RADIANS_TO_DEGREES(b->GetAngle());
            while (angle <= 0) {
                angle += 360;
            }
            while (angle > 360) {
                angle -= 360;
            }
            sprite->angle = angle;
        }
        b2Vec2 curPos = b->GetPosition();
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
    rectGL = new GLRect(1, 1);
    glF = new GLF();
    glI = new GLI();

    sprites.push_back(glF);
    sprites.push_back(glI);
}

void b2GLMain::onScaled() {
    player = new Player(2, 2, b2Vec2(128 / PTM_RATIO, 128 / PTM_RATIO), world);
    b2Body *f = drawF()->getBody();
    b2Body *o = drawO()->getBody();
    b2Body *i = drawI()->getBody();

    f->SetUserData((void*) glF);
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
    if (c == 'q') exit(0);
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
}