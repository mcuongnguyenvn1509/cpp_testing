#include <boost/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>
//#include <iostream>
using namespace std;
namespace
{

// Let's create these inheritance relationship:
//
//    base   base2
//      |     |
//      derived
//         |
//  derived_derived
//

class Base
{
   public:
   virtual ~Base(){}
   int filler [5];
   void run(){
      std::cout << "This is the Base" <<std::endl; 
   }
};

class Base2
{
public:

    virtual ~Base2(){}
    int filler [5];
   void run(){
      std::cout << "This is the Base 2" <<std::endl;
   }

};

class Derived
   : public Base, public Base2 
{
public:
    int filler [5];
   void run(){
      std::cout << "This is the Derived" <<std::endl;
   }

};

class Derived_derived
   : public Derived
{
public:
    int filler [5];
   void run(){
      std::cout << "This is the Derived_derived" <<std::endl;
   }

};

// And now some simple check functions

template <class BasePtr>
bool check_dynamic_pointer_cast(const BasePtr &ptr)
{
   //Check that dynamic_pointer_cast versus dynamic_cast
   return
   //Correct cast with dynamic_pointer_cast
   boost::get_pointer(boost::dynamic_pointer_cast<Derived>(ptr)) ==
      //Correct cast with dynamic_cast
      dynamic_cast<Derived*>(boost::get_pointer(ptr)) 
   &&
   //Incorrect cast with dynamic_pointer_cast
   boost::get_pointer(boost::dynamic_pointer_cast<Derived_derived>(ptr)) ==
      //Incorrect cast with dynamic_cast
      dynamic_cast<Derived_derived*>(boost::get_pointer(ptr));
}


}

int main()
{
    {
        // Try casts with shared_ptr

        boost::shared_ptr<Derived> ptr(new Derived);
        //boost::shared_ptr<Base> ptr1(new Base);
        boost::shared_ptr<Base> ptr1(new Derived_derived);
        boost::shared_ptr<Derived_derived> ptr2(new Derived_derived);
        ptr1-> run();
        ptr-> run();
        ptr2-> run();
        boost::shared_ptr<Derived_derived> ptr3 = boost::dynamic_pointer_cast<Derived_derived>(ptr1);
        ptr3-> run(); 
        BOOST_TEST( check_dynamic_pointer_cast( ptr ) );
        BOOST_TEST( check_dynamic_pointer_cast( ptr1 ) );

    }

    
    return boost::report_errors();
}
