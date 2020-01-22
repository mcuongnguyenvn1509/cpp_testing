#include <iostream>
using namespace std;

class Base
{
public:
virtual void display(){
	cout << "This is Base class" << endl;

}

};

class Derived : public Base
{
public:
void display(){
	cout << "This is Derived class "<< endl;

}

};

int main(){

	cout << "Welcome to DataAce turorial" << endl;
	Base *p = new Derived;
       	p->display();
	return 0;
}
