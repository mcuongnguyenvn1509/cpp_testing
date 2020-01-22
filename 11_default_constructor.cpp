    #include <iostream>
    using namespace std;
    class DataAce
    {
    public:
    int value;
    DataAce() // Definition of the default constructor
    {
    value = 50;
    }
    };
    int main()
    {
    cout<<"Welcome to DataAce tutorials!"<<endl<<endl;
    DataAce d; // The constructor
    cout<<"The value stored in the variable is: " <<d.value<<endl;
    return 0;
    }
