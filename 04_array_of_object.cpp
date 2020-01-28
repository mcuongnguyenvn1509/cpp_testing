#include <iostream>
using namespace std;

class Store
{
string item_name;
public: //notice
void getName(string item){ //it should be &string if you want to change the string or reduce the perfomance of copying arguments into function parameters
//https://www.learncpp.com/cpp-tutorial/73-passing-arguments-by-reference/
//with reference: reduce effort of the copy, change the arguments itself, not via return value
//with passing arguments by value: just return the value back to the caller via return value
        item_name= item;
}

void display(){
        cout << "This item is: " << item_name << endl;
}

};
const int size = 10;
Store order[size];

int main(){
        string ITEM;
        cout << "Welcome to DataAce" << endl;
        for (int i =0; i< size; i++){
                cout << "Store number " << i << ":" << endl;
                cin >> ITEM;
                order[i].getName(ITEM);
        }
        for (int i =0; i < size; i++){
                cout << "Item " << i << ":" << endl;
                order[i].display();

        }
        return 0;
}
