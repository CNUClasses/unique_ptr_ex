/*
 * A.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: keith
 */

#include "A.h"

A::A():i(new int(0)) {}

A::~A() {
    if(i) {
       delete i;
    }
 }

