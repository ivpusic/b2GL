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
    double density;
    double friction;
    b2BodyType bodyType;
};


#endif	/* B2GLTYPES_H */