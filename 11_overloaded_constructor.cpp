    #include<iostream>
    #define PI 3.14
    using namespace std;
    class Circle
    {
    float radius, circumference;
    public:
    Circle() // Definition of a Default constructor
    {
    radius = 0;
    }
    Circle(int r) // Definiton of a Parameterized constructor
    {
    radius = r;
    }
    Circle(Circle &c) // Defintion of a Copy constructor
    {
    radius = c.radius;
    }
    void compute()
    {
    circumference = 2 * PI * radius;
    }
    void display()
    {
    cout<<"The radius of the circle is: "<<radius<<endl;
    cout<<"The circumference of the circle is: "<<circumference<<endl<<endl;
    }
    };
    int main()
    {
    cout<<"Welcome to DataAce tutorials!"<<endl<<endl;
    Circle c1(3);
    Circle c2(c1);
    Circle c3;
    c1.compute();
    c2.compute();
    c3.compute();
    c1.display();
    c2.display();
    c3.display();
    return 0;
    }
