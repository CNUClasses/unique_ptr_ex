/*
 * A.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: keith
 */

#include "A.h"

A::A(int i):i(new int(i)) {}

A::~A() {
    if(i)
       delete i;
 }

