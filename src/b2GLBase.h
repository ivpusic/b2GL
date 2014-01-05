/* 
 * File:   b2GLBase.h
 * Author: ivpusic
 *
 * Created on January 4, 2014, 4:39 PM
 */

#ifndef B2GLBASE_H
#define	B2GLBASE_H

#include <Box2D/Box2D.h>

class b2GLBase {
protected:
    b2Body *body;
    b2BodyDef body_def;
    b2Fixture *fixture;
    b2FixtureDef fixture_def;
    b2MouseJoint *mouse_joint;

public:
    b2Body *get_body();
    b2Fixture *get_fixture();
    b2MouseJoint *get_mouse_joint();
    void set_mouse_joint(b2MouseJoint *joint);
};

#endif	/* B2GLBASE_H */