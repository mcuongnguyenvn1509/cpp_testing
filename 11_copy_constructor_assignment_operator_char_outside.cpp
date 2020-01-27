#include<iostream>
#include<cstring>
using namespace std;
class CopyConstructor
{
    char *_s_copy; // need const //https://stackoverflow.com/questions/1175646/c-when-should-i-use-a-pointer-member-in-a-class
    // points to heap storage
    public:
    //constructor
CopyConstructor();
CopyConstructor (const char *);
CopyConstructor (const CopyConstructor &);
CopyConstructor& operator=(const CopyConstructor &str);
void concatenate(const char *);
    //destructor
~CopyConstructor();
void display();

};
    CopyConstructor::CopyConstructor() //or :_s_copy(NULL)
    {
	_s_copy=NULL;
    }
    CopyConstructor::CopyConstructor (const char *str) //constructor
    {
/*	if(_s_copy != NULL){
	 ERROR;
	}
//should have throw exception https://bytes.com/topic/c/answers/528061-constructor-pointer-parameter
*/

//	if(_s_copy == NULL){ //Do we need to have this
        _s_copy = new char[16];  //Dynamic memory alocation
//	}
        strcpy(_s_copy, str);
    }

    CopyConstructor::CopyConstructor (const CopyConstructor &str) //copy constructor
    {
	this->_s_copy = NULL;
	if(str._s_copy != NULL){
        _s_copy = new char[16]; //Dynamic memory alocation
        strcpy(_s_copy, str._s_copy);
        }
    }
    CopyConstructor& CopyConstructor::operator=(const CopyConstructor &str){ //assignment operator
	if( this == &str){ //http://pages.cs.wisc.edu/~hasti/cs368/CppTutorial/NOTES/CLASSES-PTRS.html
		return *this;
	}
	else{
	char* tmp_s_copy = new char[16];
/*This is one of the way to handle exception from new expression*/
/*https://wiki.sei.cmu.edu/confluence/display/cplusplus/OOP54-CPP.+Gracefully+handle+self-copy+assignment*/
/*https://www.codeguru.com/cpp/cpp/algorithms/general/article.php/c9585/Copy-Constructors-and-Assignment-Operators.htm*/
/*
      try {
        _s_copy = new char[16];
      } catch (std::bad_alloc &) {
        _s_copy = nullptr; // For basic exception guarantees
        throw;
      }

*/
	delete [] _s_copy; //must have, The assignment operator deletes the contents of the existing string before assigning the new string , https://www.codeguru.com/cpp/cpp/algorithms/general/article.php/c9585/Copy-Constructors-and-Assignment-Operators.htm
	_s_copy = tmp_s_copy;
	strcpy(_s_copy, str._s_copy);
	}
	return *this;

    }
//or another way of copy constructor
/*   CopyConstructor::CopyConstructor (const CopyConstructor &str):_s_copy(NULL){
	if(str._s_copy != NULL){
		_s_copy = new char[16];  //Dynamic memory alocation
		memcpy(_s_copy, str._s_copy, strlen(str._s_copy)+1);
		
	}

}*/
    /*Should not use the operator like this:*/
#if 0
    CopyConstructor& operator=( const CopyConstructor &str){
	if (this != &str){
	delete [] _s_copy;
	_s_copy = new char[16];
	strcpy(_s_copy, str._s_copy);
	}
	return *this
    }
#endif
    /*The problem with this code is that if the new operator throws an exception, the object will be left in a bad state because the name field would have already been freed by the previous instruction. By performing all the operations that could fail first and then replacing the fields once there's no chance of an exception from occurring, the code is exception safe.*/
    /*https://www.codeguru.com/cpp/cpp/algorithms/general/article.php/c9585/Copy-Constructors-and-Assignment-Operators.htm*/
    void CopyConstructor::concatenate(const char *str)
    {
        strcat(_s_copy, str); //Concatenating two strings
    }

    CopyConstructor::~CopyConstructor()
    {
        delete [] _s_copy; // or if(_s_copy != NULL) delete [] _s_copy;
    }

    void CopyConstructor::display()
    {
        cout<<_s_copy<<endl;
    }


int main()
{
    CopyConstructor c1("Copy");
    CopyConstructor c2 = c1;    //copy constructor
    c1.display();
    c2.display();
    c1.concatenate("Constructor");    //c1 is invoking concatenate()
    c1.display();
    c2.display();
    CopyConstructor c3;
//    CopyConstructor c3("copy3");
    c3=c2;
    c3.display();
    return 0;
}
