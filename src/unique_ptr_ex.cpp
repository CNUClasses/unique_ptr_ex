//============================================================================
// Name        : unique_ptr_ex_class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include "A.h"
#include "B.h"

using namespace std;

//see https://mbevin.wordpress.com/2012/11/18/smart-pointers/
struct MyClass {
   MyClass(const char* s){}
   void methodA(){};
};

//what if we want a plain pointer?
void someMethod(B* m){}

void test() {
   unique_ptr<B> ptr1(new B(1));

   // can use -> (and *) on the unique_ptr just like with a normal pointer
   ptr1->set(2);

   // to get a plain pointer from the unique_ptr, we use the get() method
   someMethod(ptr1.get());
   int j = ptr1.get()->get();

   // use std::move to transfer ownership to ptr2 - ptr1 now holds no pointer
   unique_ptr<B> ptr2 = std::move(ptr1);

//   ptr1->set(3);															//crash already moved
//   unique_ptr<B> ptr3(std::move(ptr1));	//crash already moved

   // assign a new pointer to ptr1
   ptr1.reset(new B(4));

   // assign a new pointer to ptr2 - orig object  will now automatically be deleted
   ptr2.reset(new B(5));

   // set ptr1 to contain nothing - orig object  will now automatically be deleted
   ptr1.reset();

   // all pointers  automatically deleted at the end of this function, as ptr2 goes out of scope
}

//pass by value
void func_by_value(A a){
}
void func_by_value(B b){
}

int main() {
	test();

	A a(2);	//must define destructor that cleans up memory
//	A a2 = a;	//cannot do it (private assignment operator)
//	A a1(a);	//cannot do it (private copy constructor)
//	func_by_value(a);	//cannot do it (private copy constructor)

	B b(1);	//default destructor is fine, B has so much less code than A
//	B b2 = b;	//cannot do it, deleted assignment operator (means cannot use it)
//	B b1(b);	//cannot do it, deleted copy constructor, (means cannot use it)
//	func_by_value(b);	//cannot do it, deleted copy constructor, (means cannot use it)

}
