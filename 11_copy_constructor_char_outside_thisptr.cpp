#include<iostream>
#include<cstring>
using namespace std;
class CopyConstructor
{
    char *s_copy;
    public:
    //constructor
CopyConstructor (const char *);
CopyConstructor (const CopyConstructor &);
void concatenate(const char *);
    //destructor
~CopyConstructor();
void display();

};
    CopyConstructor::CopyConstructor (const char *str)
    {
        s_copy = new char[16];  //Dynamic memory alocation
        strcpy(s_copy, str);
    }

    CopyConstructor::CopyConstructor (const CopyConstructor &str)
    {
//      this->s_copy = NULL;
        this->s_copy = new char[16]; //Dynamic memory alocation
        if (this->s_copy != NULL){
                strcpy(this->s_copy, str.s_copy);
                //std::memcpy(this->s_copy, str.s_copy (or str.getData), 16(or this->length));
        }
        //strcpy(s_copy, str.s_copy);
    }

    void CopyConstructor::concatenate(const char *str)
    {
        strcat(s_copy, str); //Concatenating two strings
    }

    CopyConstructor::~CopyConstructor()
    {
        delete [] s_copy;
    }

    void CopyConstructor::display()
    {
        cout<<s_copy<<endl;
    }


/* main function */
int main()
{
    CopyConstructor c1("Copy");
    CopyConstructor c2 = c1;    //copy constructor
    c1.display();
    c2.display();
    c1.concatenate("Constructor");    //c1 is invoking concatenate()
    c1.display();
    c2.display();
    return 0;
}
