#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <GL/glut.h>

#include "b2GL/b2GLDraw.h"
#include "b2GL/b2GLRectangle.h"
#include "b2GL/b2GLCicle.h"
#include "b2GL/b2GLMain.h"

b2GLMain *box2dGLMain;
b2World *world;

void display(void) {
    box2dGLMain->display();
}

void scale(int w, int h) {
    box2dGLMain->scale(w, h);
}

void on_key(unsigned char c, int x, int y) {
    box2dGLMain->on_key_down(c, x, y);
}

void on_mouse_button(int button, int state, int x, int y) {
    box2dGLMain->on_mouse_button(button, state, x, y);
}

void on_mouse_move(int x, int y) {
    box2dGLMain->on_mouse_move(x, y);
}

void rotate(void) {
    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowPosition(60, 30);
    glutInitWindowSize(800, 800);
    int WIN_ID = glutCreateWindow("box2d");

    glClearColor(0.0, 0.0, 0.0, 0.0);

    b2Vec2 gravity(0, -9.8);
    world = new b2World(gravity);

    // setup debugDraw
    b2GLDraw debug;
    world->SetDebugDraw(&debug);
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
    debug.SetFlags(flags);

    box2dGLMain = new b2GLMain(world, WIN_ID);
    box2dGLMain->init();

    glutReshapeFunc(scale);
    glutDisplayFunc(display);
    glutKeyboardFunc(on_key);
    glutMouseFunc(on_mouse_button);
    glutMotionFunc(on_mouse_move);
    glutIdleFunc(rotate);
    glutMainLoop();
    free(box2dGLMain);
    return 0;
} // main