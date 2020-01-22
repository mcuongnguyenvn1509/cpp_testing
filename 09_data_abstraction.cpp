    #include <iostream> 
    using namespace std; 
    class Abstraction 
    {
    // Private by default 
    int number1, number2; 
    public: 
    // Function to access private members
    void input(int n1, int n2) 
    { 
    number1 = n1;
    number2 = n2;
    } 
    void sum() 
    { 
    cout<<"Their sum is:" << number1+number2 << endl; 
    } 
    }; 
    int main() 
    {
    cout<<"Welcome to DataAce tutorials!"<<endl;
    Abstraction a; 
    a.input(17, 3); 
    a.sum(); 
    return 0; 
    }
