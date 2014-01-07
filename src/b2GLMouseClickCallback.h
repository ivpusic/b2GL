/* 
 * File:   b2GLMouseClickCallback.h
 * Author: ivpusic
 *
 * Created on January 7, 2014, 12:25 AM
 */

#ifndef B2GLMOUSECLICKCALLBACK_H
#define	B2GLMOUSECLICKCALLBACK_H

#include <Box2D/Box2D.h>

class b2GLMouseClickCallback : public b2QueryCallback {
public:
    b2GLMouseClickCallback();
    bool ReportFixture(b2Fixture* fixture);
    b2Fixture *getFoundFixture();
    
private:
    b2Fixture *foundFixture;
private:

};

#endif	/* B2GLMOUSECLICKCALLBACK_H */

