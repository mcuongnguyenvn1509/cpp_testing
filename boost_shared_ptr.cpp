//source from https://www.boost.org/doc/libs/1_34_0/libs/smart_ptr/test/pointer_cast_test.cpp
#include <boost/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>
namespace
{

// Let's create these inheritance relationship:
//
//    Base   Base2
//      |     |
//      Derived
//         |
//  Derived_derived
//

class Base
{
   public:
   virtual ~Base(){}
   int filler [5];
};

class Base2
{
public:

    virtual ~Base2(){}
    int filler [5];
};

class Derived
   : public Base, public Base2
{
    int filler [5];
};

class Derived_derived
   : public Derived
{
    int filler [5];
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

        boost::shared_ptr<Base> ptr(new Derived);

        BOOST_TEST( check_dynamic_pointer_cast( ptr ) );

    }


    return boost::report_errors();
}
