#include "b2GLBase.h"

b2Body *b2GLBase::get_body() {
    return body;
}

b2Fixture *b2GLBase::get_fixture() {
    return fixture;
}

b2MouseJoint *b2GLBase::get_mouse_joint() {
    return mouse_joint;
}

void b2GLBase::set_mouse_joint(b2MouseJoint* joint) {
    mouse_joint = joint;
}