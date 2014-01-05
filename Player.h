/* 
 * File:   Player.h
 * Author: ivpusic
 *
 * Created on January 5, 2014, 1:13 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <Box2D/Box2D.h>

#include "b2GLBase.h"

class Player : public b2GLBase {
public:
    Player(double width, double height, b2Vec2 position, b2World *world);
    virtual ~Player();
private:

};

#endif	/* PLAYER_H */

