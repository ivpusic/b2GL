#include "b2GLBase.h"

b2Body *b2GLBase::getBody() {
    return body;
}

b2Fixture *b2GLBase::getFixture() {
    return fixture;
}

void b2GLBase::setData(void* data) {
    fixture->SetUserData(data);
}

