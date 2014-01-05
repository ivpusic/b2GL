/* 
 * File:   b2GLRectangle.h
 * Author: ivpusic
 *
 * Created on January 4, 2014, 3:51 PM
 */

#include <Box2D/Box2D.h>

#include "b2GLBase.h"
#include "b2GLTypes.h"

#ifndef B2GLRECTANGLE_H
#define	B2GLRECTANGLE_H

class b2GLRectangle : b2GLBase {
public:
    b2GLRectangle(double width, double height, b2Vec2 position, b2World *world, fixture_properties properties);
    b2Body* getBody();
};

#endif	/* B2GLRECTANGLE_H */

