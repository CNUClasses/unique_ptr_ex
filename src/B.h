/*
 * B.h
 *
 *  Created on: Mar 25, 2019
 *      Author: keith
 */

#ifndef B_H_
#define B_H_
#include <memory>

//notice how much less code needed when using unique pointers
class B {
public:
	B(int i);
	~B(){}
	 void set(int i);	//rubbish getters and setters for demo purposes
	 int get();
private:
	std::unique_ptr<int> i;
};

#endif /* B_H_ */
