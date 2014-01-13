/* 
 * File:   b2GLMouseClickCallback.cpp
 * Author: ivpusic
 * 
 * Created on January 7, 2014, 12:25 AM
 */

#include "b2GLMouseClickCallback.h"

b2GLMouseClickCallback::b2GLMouseClickCallback() {
    foundFixture = NULL;
}

bool b2GLMouseClickCallback::ReportFixture(b2Fixture* fixture) {
    foundFixture = fixture;
    return false;
}

b2Fixture *b2GLMouseClickCallback::getFoundFixture() {
    return foundFixture;
}