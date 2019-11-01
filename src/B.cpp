/*
 * B.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: keith
 */

#include "B.h"

B::B(int i):i(new int(i)) {}

void B::set(int i){
	this->i.reset(new int(i));
}

int B::get(){
	return *i;
}

