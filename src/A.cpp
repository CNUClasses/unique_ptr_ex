/*
 * A.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: keith
 */

#include "A.h"

A::A(int i):i(new int(i)) {}

void A::clear() {
	if (i)
		delete i;
	i=0;
}

A::~A() {
	clear();
 }

void A::set(int i){
	clear();
	this->i= new int(i);
}

