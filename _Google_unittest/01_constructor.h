#ifndef GTEST_01_CONSTRUCTOR_H_
#define GTEST_01_CONSTRUCTOR_H_

class Constructor{

private:
        const char* _s_copy;

public:
        Constructor();
        Constructor(char* str);
        ~Constructor();
        Constructor(const Constructor& str);
        Constructor& operator=(const Constructor& str);

};
