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
void someMethod(MyClass* m){}

void test() {
   unique_ptr<MyClass> ptr1(new MyClass("obj1"));

   // can use -> (and *) on the unique_ptr just like with a normal pointer
   ptr1->methodA();

   // to get a plain pointer from the unique_ptr, we use the get() method
   someMethod(ptr1.get());

   // use std::move to transfer ownership to ptr2 - ptr1 now holds no pointer
   unique_ptr<MyClass> ptr2(std::move(ptr1));

   // assign a new pointer to ptr1
   ptr1.reset(new MyClass("obj2"));

   // assign a new pointer to ptr2 - "obj1" will now automatically be deleted
   ptr2.reset(new MyClass("obj2"));

   // set ptr1 to contain nothing - "obj2" will now automatically be deleted
   ptr1.reset();

   // "obj3" will automatically deleted at the end of this function, as ptr2 goes out of scope
}

//pass by value
void func_by_value(A a){
}
void func_by_value(B b){
}

int main() {

	A a;
//	A a2 = a;	//cannot do it (private assignment operator)
//	A a1(a);	//cannot do it (private copy constructor)
//	func(a);	//cannot do it (private copy constructor)

	B b;
//	B b2 = b;	//cannot do it, deleted assignment operator (means cannot use it)
//	B b1(b);	//cannot do it, deleted copy constructor, (means cannot use it)
//	func(b);	//cannot do it, deleted copy constructor, (means cannot use it)

}
