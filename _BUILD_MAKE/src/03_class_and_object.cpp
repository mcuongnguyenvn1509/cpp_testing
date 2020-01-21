#include <iostream>
using namespace std;

class DataAce
{

public:
string line;
void display(){
cout <<"The message is: " << line <<endl;
}

};

int main(){
DataAce object;

object.line="Welcome to DataAce tutorials!";
object.display();
return 0;

}
