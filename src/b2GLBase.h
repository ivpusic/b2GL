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
    b2BodyDef bodyDef;
    b2Fixture *fixture;
    b2FixtureDef fixtureDef;

public:
    b2Body *getBody();
    b2Fixture *getFixture();
};

#endif	/* B2GLBASE_H */