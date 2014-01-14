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

    this->bulletSpeed = 350;
    this->bulletAngle = 70;
    mouseJoint = NULL;
    this->world = world;
    timeStep = 1.0f / 60.f;
    velocityIterations = 8;
    positionIterations = 3;
    leftMouseClick = false;
    this->WIN_ID = WIN_ID;
}

b2GLRectangle *b2GLMain::drawF() {

    b2WeldJointDef wjd;
    fixture_properties properties;
    properties.density = 5.0;
    properties.bodyType = b2_dynamicBody;

    double x = 20;

    // botton square -> GL origin for F letter
    rect = new b2GLRectangle(1, 1, b2Vec2(x, 40), world, properties);

    rect1 = new b2GLRectangle(1, 1, b2Vec2(x, 42), world, properties);
    wjd.Initialize(rect->getBody(), rect1->getBody(), b2Vec2(x, 40));
    world->CreateJoint(&wjd);

    rect2 = new b2GLRectangle(1, 1, b2Vec2(x, 44), world, properties);
    wjd.Initialize(rect1->getBody(), rect2->getBody(), b2Vec2(x, 42));
    world->CreateJoint(&wjd);

    rect3 = new b2GLRectangle(1, 1, b2Vec2(x, 46), world, properties);
    wjd.Initialize(rect2->getBody(), rect3->getBody(), b2Vec2(x, 44));
    world->CreateJoint(&wjd);

    properties.density = 1.0;
    rect4 = new b2GLRectangle(1, 1, b2Vec2(x + 2, 42), world, properties);
    wjd.Initialize(rect1->getBody(), rect4->getBody(), b2Vec2(x, 42));
    world->CreateJoint(&wjd);

    rect5 = new b2GLRectangle(1, 1, b2Vec2(x + 2, 46), world, properties);
    wjd.Initialize(rect3->getBody(), rect5->getBody(), b2Vec2(x, 46));
    world->CreateJoint(&wjd);

    return rect;
}

b2GLCicle *b2GLMain::drawO() {
    double r = 3;
    fixture_properties properties;
    properties.density = 1.0;
    properties.restitution = 0.1f;
    
    b2GLCicle *cicle = new b2GLCicle(3, b2Vec2(35 + r, 30 + r), world, properties);

    return cicle;
}

b2GLRectangle *b2GLMain::drawI() {
    fixture_properties properties;
    properties.density = 1.0;
    properties.bodyType = b2_dynamicBody;
    b2GLRectangle *i = new b2GLRectangle(1, 4, b2Vec2(50, 20), world, properties);
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
    phBodies.push_back(fStand);

    oStand = new b2GLRectangle(6, 0.5, b2Vec2(38, 30), world, properties);
    oStandSprite = new GLSpriteTexture2D((char*) "src/assets/stand.png");
    oStandSprite->posx = 35;
    oStandSprite->posy = 30;
    sprites.push_back(oStandSprite);
    oStand->getBody()->SetUserData((void*) oStandSprite);
    phBodies.push_back(oStand);

    iStand = new b2GLRectangle(6, 0.5, b2Vec2(50, 20), world, properties);
    iStandSprite = new GLSpriteTexture2D((char*) "src/assets/stand.png");
    iStandSprite->posx = 50;
    iStandSprite->posy = 20;
    sprites.push_back(iStandSprite);
    iStand->getBody()->SetUserData((void*) iStandSprite);
    phBodies.push_back(iStand);
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
            sprite->angle = angle;
            sprite->angleRadians = b->GetAngle();
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
    glO = new GLO(6);
    glI = new GLI();
    track = new GLTrack(world);

    sprites.push_back(background);
    sprites.push_back(glF);
    sprites.push_back(glI);
    sprites.push_back(glO);
    sprites.push_back(track->tex);
}

void b2GLMain::onScaled() {
    b2Body *f = drawF()->getBody();
    b2Body *o = drawO()->getBody();
    b2Body *i = drawI()->getBody();

    f->SetUserData((void*) glF);
    o->SetUserData((void*) glO);
    i->SetUserData((void*) glI);

    double jointDistance = 25;

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

b2Vec2 b2GLMain::glToBox2DVec2(b2Vec2 pos) {
    return b2Vec2(pos.x, YMAX - pos.y);
}

void b2GLMain::onMouseButton(int button, int state, int x, int y) {
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
                aabb.lowerBound = glToBox2DVec2(b2Vec2((x + 0.001) / PTM_RATIO, (y + 0.001) / PTM_RATIO));
                aabb.upperBound = glToBox2DVec2(b2Vec2((x - 0.001) / PTM_RATIO, (y - 0.001) / PTM_RATIO));
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
            if (state == GLUT_DOWN) {
                fixture_properties prop;
                prop.density = 1.0f;
                prop.restitution = 0.8f;
                prop.bodyType = b2_dynamicBody;
                GLO *o = new GLO(6);
                b2GLCicle *c = new b2GLCicle(3, b2Vec2(70, 73), world, prop);
                c->getBody()->SetUserData((void*) o);
                sprites.push_back(o);
            }

            break;
    }
    glutPostRedisplay();
}

void b2GLMain::onSpecialKeyDown(int c, int x, int y) {


    if (c == GLUT_KEY_LEFT) {
        if (bulletAngle < 90) {
            bulletAngle++;
        }
    }

    if (c == GLUT_KEY_RIGHT) {
        if (bulletAngle > 0) {
            bulletAngle--;
        }
    }

    if (c == GLUT_KEY_DOWN) {
        bulletSpeed -= 5;
    }

    if (c == GLUT_KEY_UP) {
        bulletSpeed += 5;
    }
}

void b2GLMain::onKeyDown(unsigned char c, int x, int y) {

    if (c == 'q') {
        glutDestroyWindow(WIN_ID);
        this->~b2GLMain();
        exit(0);
    }
    if (c == 'g') DRAW_GL = 0;
    if (c == 'G') DRAW_GL = 1;
    if (c == 'b') DRAW_BOX2D = 0;
    if (c == 'B') DRAW_BOX2D = 1;
    if (c == 's') {
        GLBullet *bullet = new GLBullet(world, bulletSpeed, DEGREES_TO_RADIANS(bulletAngle));
        sprites.push_back(bullet->tex);
    }
}

void b2GLMain::onMouseMove(int x, int y) {
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

    for (phBodiesIterator = phBodies.begin(); phBodiesIterator != phBodies.end(); ++phBodiesIterator) {
        free((*phBodiesIterator));
    }

    free(background);
    for (b2Body *b = world->GetBodyList(); b; b = b->GetNext()) {
        world->DestroyBody(b);
    }
    free(world);

    for (spriteIterator = sprites.begin(); spriteIterator != sprites.end(); ++spriteIterator) {
        free((*spriteIterator));
    }

    printf("Dealloc finished! \n");
}