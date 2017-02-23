//============================================================================
// Name        : Cpp_Training_ConstructionExplicit.cpp
// Author      : Nico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct A{
	A() {cout << " // A::A() default constructor" << endl;}
	A(int) {cout << " // A::A(int) converting constructor" << endl;}
	A(int, int) {cout << " // A::A(int,int) converting constructor C++ 11" << endl;}
	operator bool() const {
		cout << " // A: overloaded bool operator" << endl;
		return true;
	}
};

struct B{
	B() {cout << " // B::B() default constructor" << endl;}
	explicit B(int) {cout << " // B::B(int) converting constructor" << endl;}
	explicit B(int, int) {cout << " // B::B(int,int) converting constructor C++ 11" << endl;}
	explicit operator bool() const {
		cout << " // B: overloaded bool operator" << endl;
		return true;
	}
};

int main() {
	cout << "::: Examples without \"explicit\" keyword in construction" << endl;

	cout << "A a1;";
	A a1;
	cout << "A a2(2);";			// direct initialization
	A a2(2);
	cout << "A a3 = 3;";		// copy initialization
	A a3 = 3;
	cout << "A a4(4,444);";		// direct list initialization
	A a4(4,444);
	cout << "A a5{5,55};";		// direct list initialization
	A a5{5,55};
	cout << "A a6 = (6,66);";	// Why is A::A(int) called?
	A a6 = (6,66);
	cout << "A a7 = {7,77};";	// copy list initialization
	A a7 = {7,77};
	cout << "A a8 = (A)8;";		// explicit cast of an int value to an A object performs a static_cast
	A a8 = (A)8;
	cout << "if (a1);";
	if (a1);					// check if overloaded bool operator works
	cout << "bool new_a1 = a1;";
	bool new_a1 = a1;			// copy initialization after reading via overloaded bool operator
	cout << "bool new_a2 = static_cast<bool>a2;";
	bool new_a2 = static_cast<bool>(a2);	// direct initialization after reading via overloaded bool operator works
											// (static_cast performs direct initialization)
	cout << endl;
	cout << "::: Examples with \"explicit\" keyword in construction" << endl;
	cout << "B b1;";			// default constructor
	B b1;
	cout << "B b2(2);";			// direct initialization works with B::B(int)
	B b2(2);
	//	B b2 = 2;				// error: copy initialization doesn't consider B::B(int)
	cout << "B b3(3,3);";		// direct list initialization works with B::B(int,int)
	B b3(3,3);
	cout << "B b4{4,4};";		// direct list initialization works with B::B(int,int)
	B b4{4,4};
	//	B b4 = (4,4);			// error: copy list initialization doesn't work with B::B(int,int)
	//	B b4 = {4,4};			// error: copy list initialization doesn't work with B::B(int,int)
	cout << "B b5 = (B)5;";		// direct list initialization works with B::B(int,int)
	B b5 = (B)5;				// explicit cast of an int value to an B object performs a static cast
	cout << "if (b1);";			// check if overloaded bool operator works
	if (b1);
	// bool new_b1 = b1;		// error: copy initialization doesn't consider overloaded bool operator
	cout << "bool new_b1 = static_cast<bool>(b1);";
	bool new_b1 = static_cast<bool>(b1);	// direct initialization after reading via overloaded bool operator works
											// (static_cast performs direct initialization)
	return 0;
}
