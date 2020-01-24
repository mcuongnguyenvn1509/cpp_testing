#include <iostream>
using namespace std;
class Base{
        private:
                int _base_val;
        public:
                Base(){
                        cout<<"This is the base constructor"<<endl;
                }
                ~Base(){
                        cout<<"This is the base destructor"<<endl;
                }
                void display(){
                        cout<<"This is the display function of base"<<endl;
                }



};

class Derived: public Base{
        public:
                Derived(){
                        cout<<"This is the derived constructor"<<endl;
                }
                ~Derived(){
                        cout<<"This is the derived destructor"<<endl;
                }
                void display(){
                        cout<<"This is the display function of derived"<<endl;
                }


};
int main(){
        cout<<"Welcome to the DataAce"<<endl;
        Base *p = new Derived;
        p->display();
        delete  p; //cannot call the destructor of the Derived due to lacking of virtual function in ~Base
/*you'll get corrupted program states like memory leaks https://chromium.googlesource.com/external/github.com/google/googletest/+/HEAD/googlemock/docs/for_dummies.md*/
        /*
Welcome to the DataAce
This is the base constructor
This is the derived constructor
This is the display function of base
This is the base destructor

        */
return 0;
}
