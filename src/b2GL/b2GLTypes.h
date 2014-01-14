/* 
 * File:   b2GLTypes.h
 * Author: ivpusic
 *
 * Created on January 4, 2014, 6:11 PM
 */

#ifndef B2GLTYPES_H
#define	B2GLTYPES_H

#include <Box2D/Box2D.h>

struct fixture_properties {
    fixture_properties() : density(0.0f), friction(0.0f), restitution(0.0f), bodyType(b2_dynamicBody) {}
    float density;
    float friction;
    float restitution;
    b2BodyType bodyType;
};


#endif	/* B2GLTYPES_H */