#include <iostream>
using namespace std;

class Store
{
string item_name;
public: //notice
void getName(string item){
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
