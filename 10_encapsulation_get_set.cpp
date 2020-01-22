    #include<iostream> 
    using namespace std; 
    class Encapsulation 
    { 
    // Private by default // Data inaccessible to the outside world
    long int ID; 
    public:
    void set_value(int value) 
    { 
    ID = value;
    } 
    int get_value() 
    { 
    return ID; 
    } 
    }; 
    // main function 
    int main() 
    { 
    cout<<"Welcome to DataAce tutorials!"<<endl<<endl;
    Encapsulation e; 
    e.set_value(209718); 
    cout<<"The ID is: "<<e.get_value()<<endl;
    return 0; 
    }
