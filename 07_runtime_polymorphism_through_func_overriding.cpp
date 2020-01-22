#include <iostream>
using namespace std;

class Base
{
public:
void display(){
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
	Base b;
       	b.display();

	Derived d;
	d.display();	

	return 0;
}
