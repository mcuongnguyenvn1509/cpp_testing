#ifndef GTEST_01_CONSTRUCTOR_H_
#define GTEST_01_CONSTRUCTOR_H_

#include <cstddef>
#include <iostream>
#include <cstring>
using namespace std;

class Constructor{

private:
        char* _s_copy;

public:
        Constructor();
        Constructor(const char* str);
        ~Constructor();
        Constructor(const Constructor& str);
        Constructor& operator=(const Constructor& str);

};

#endif
