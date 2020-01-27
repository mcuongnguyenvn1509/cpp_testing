#ifndef GTEST_01_CONSTRUCTOR_H_
#define GTEST_01_CONSTRUCTOR_H_

#include <cstddef>
#include <iostream>
#include <cstring>
using namespace std;

class Constructor{

private:
        char* _s_copy;
	char _sId;
	int _sLength;

public:
        Constructor(); //constructor 1
	Constructor(char sId, int sLength); //constructor 2
        Constructor(const char* str); //constructor 3
	//the parameter passed cannot be changed within the function https://stackoverflow.com/a/15999237
	Constructor(char* str, int sLength); //constructor 4
        Constructor(const Constructor& str); //copy constructor
        Constructor& operator=(const Constructor& str); //assignment operator
        ~Constructor();
 	char* getString() const; //The implicit "this" pointer is const-qualified! // *this is const(can not be changed) // https://stackoverflow.com/a/15999170
	char getId() const;
	int getLength() const;
	
};

#endif
