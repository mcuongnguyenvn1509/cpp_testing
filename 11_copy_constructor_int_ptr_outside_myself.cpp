#include <iostream>
using namespace std;

class Base{
	private:
		int *_val;
	public:
		Base(int val);
		Base(const Base &val);
		~Base();
		int getVal() const;
		void setVal(int val);
};

Base::Base(int val){
	_val= new int;
	*_val = val; 
}
Base::Base( const Base &base){
	_val=new int;
	//*_val=*base.getVal();
	*_val=*base._val;

}
Base::~Base(){
	delete _val;
	_val = NULL;
}

int Base::getVal() const{
	return *_val;
}
void Base::setVal(int val){
	*_val=val;
}
int main(){
	Base b1(5);
	Base b2 = b1;
	cout << "value of b2 = " << b2.getVal()<< endl;
	b1.setVal(3);
	b2.setVal(3);
	cout << "value of b1 = " << b1.getVal()<< endl;
	cout << "value of b2 = " << b2.getVal()<< endl;
return 0;
}
