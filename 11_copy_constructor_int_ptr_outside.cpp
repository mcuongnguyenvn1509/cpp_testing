#include<iostream>
#include<cstring>
using namespace std;

class B
{

public:
    B();
    B(const B& b);
    ~B();
    void setVal(int val);

private:
    int* m_p;
};

B::B()
{
    //Allocate the memory to hold an int
    m_p = new int;

    *m_p = 0;
}

B::B(const B& b)
{
    //Allocate the memory first
    m_p = new int;

    //Then copy the value from the passed object
    *m_p = *b.m_p;
}

B::~B()
{

    //Release the memory allocated
    delete m_p;
    m_p = NULL;
}

void B::setVal(int val)
{
    *m_p = val;
}

int main(){
B b;
b.setVal(4);

B c=b;
c.setVal(8);


cout << "Address of object B= " << &b << endl;
cout << "Address of object C= " << &c << endl;

return 0;
}
