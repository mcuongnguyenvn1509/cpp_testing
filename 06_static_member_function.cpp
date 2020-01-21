#include <iostream>
using namespace std;

class Store
{
// private by default
int item_ID;
string item_name;
static int count;
public:
void read(int ID, string item)
{
item_ID = ID;
item_name = item;
count++;
}

void display(){
cout<<"The item ID is: "<<item_ID<<endl;
cout<<"The item name is: "<<item_name<<endl;

}

// Static member function
static void item_count()
{
cout<<"The number of items are: "<<count<<endl;
}
};

int Store:: count =0; // Static data member invoked through class name
int main()
{
cout<<"Welcome to DataAce tutorials!"<<endl<<endl;
Store s1, s2;
s1.read(1001,"Bucket");;
s2.read(1005,"Mug");
Store :: item_count();
s1.display();
s2.display();
return 0;
}
