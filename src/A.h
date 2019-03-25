/*
 * A.h
 *
 *  Created on: Mar 25, 2019
 *      Author: keith
 */

#ifndef A_H_
#define A_H_
class A {
public:
   A();
   ~A();

private:
   int* i;
    // we need to explicitly disable value-copying, as it's not safe!
    A(const A&);
    A& operator=(const A&);
};

#endif /* A_H_ */
