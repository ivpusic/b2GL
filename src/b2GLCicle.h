/* 
 * File:   b2GLCicle.h
 * Author: ivpusic
 *
 * Created on January 4, 2014, 6:27 PM
 */

#ifndef B2GLCICLE_H
#define	B2GLCICLE_H

#include "b2GLBase.h"
#include "b2GLTypes.h"

class b2GLCicle : b2GLBase {
public:
    b2GLCicle(double radius, b2Vec2 position, b2World *world, fixture_properties properties);
    virtual ~b2GLCicle();
private:

};

#endif	/* B2GLCICLE_H */