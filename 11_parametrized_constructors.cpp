    #include <iostream>
    using namespace std;
    class Coordinates
    {
    private:
    int x, y, z;
    public:
    Coordinates(int x1, int y1, int z1) // Definition of the parameterized constructor to access the private members of the class
    {
    x = x1;
    y = y1;
    z = z1;
    }
    int displayX()
    {
    return x;
    }
    int displayY()
    {
    return y;
    }
    int displayZ()
    {
    return z;
    }
    };
    int main()
    {
    cout<<"Welcome to DataAce tutorials!"<<endl<<endl;
    Coordinates p(2, 4, 7); // Calling the constructor
    // Accessing values using the constructor
    cout<<"The x coordinate is: " <<p.displayX()<<endl;
    cout<<"The y coordinate is: "<<p.displayY()<<endl;
    cout<<"The z coordinate is: "<<p.displayZ()<<endl;
    return 0;
    }
