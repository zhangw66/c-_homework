#include <iostream>

using namespace std;

class Base
{
private:

protected:
    public:
    static int getA();
 static int a;
};
//int Base::a = 9;
int Base::getA()
{
    return 0;//Base::a;
}
int main()
{
    Base b;
    Base::a = 9;
    cout << Base::getA() <<endl;
    cout << "Hello World!" << endl;
    return 0;
}

