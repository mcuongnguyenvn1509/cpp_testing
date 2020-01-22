    #include<iostream>
    using namespace std;
    class Average
    {
    // private by default
    float min, max, result;
    public:
    Average(float m1, float m2 = 100); // Default argument
    void compute();
    };
    Average :: Average(float m1, float m2)
    {
    max = m1;
    min = m2;
    }
    void Average :: compute()
    {
    cout<<"The minimum value is: "<<min<<endl;
    cout<<"The maximum value is: "<<max<<endl;
    result = (min + max) / 2;
    cout<<"The average of the two values is: "<<result<<endl<<endl;
    }
    int main()
    {
    cout<<"Welcome to DataAce tutorials!"<<endl<<endl;
    Average a1(58,85.5);
    Average a2(60, 95.25);
    Average a3(80,100);
    Average a4(20);
    a1.compute();
    a2.compute();
    a3.compute();
    a4.compute();
    return 0;
    }
