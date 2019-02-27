#include <iostream>
#include <stdio.h>
using namespace std;
class Other {

    friend class Test;
public:
    //Other();
    static Other &getIns();
protected:
    void setA(){cout<<"void setA()"<<endl;};
private:
    int a, b;
    Other();
};
Other &Other::getIns()
{

    cout<<"Other &Other::getIns()"<<endl;
}
Other::Other():a(22), b(33)
{
    cout<<"Private Other constructor!!"<<endl;
}
class Test {
    friend class Other;
    friend void friend_modify(Test *const pTest);
private:
    int a,b;
    Other o;    //可以构造
    void modifyOther();
protected:
public:
    Test():a(2), b(3){};
    void printAll(){printf("a = %d, b = %d\n", a, b);};
};
void Test::modifyOther()
{
    o.setA();
    o.a = 1;
    cout<<"void Test::modifyOther"<<endl;
}

void friend_modify(Test *const pTest)
{
    //这样做其实会破坏类的封装.
    pTest->a = 12;
    pTest->b = 21;
    pTest->modifyOther();
    Other::getIns();
}
int main()
{
    Test t;
   // Other o;  //compile error
    t.printAll();
    friend_modify(&t);
    t.printAll();
    cout << "Hello World!" << endl;
    return 0;
}

