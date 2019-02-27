#include <iostream>

using namespace std;
class Base
{
public:
    int base_a;
    void print(int &a)
    {
        cout << "a value:" << a << endl;
        cout << "var a address:" << &a<<endl;
    }
};
class BaseChild1 : public Base
{
public:

};
class BaseChild2: public Base
{
public:

};
class BaseChild3: public Base
{
public:

};
class BaseChild4: public Base
{
public:
int base_a;
};
class BaseChild5: public BaseChild4
{
public:
//int base_a;
};
class GrandChild:public BaseChild1,public BaseChild2
{
public:
 //int base_a;
    void print(int &a)
    {
        cout << "a value:" << a << endl;
        cout << "var a address:" << &a<<endl;
    }
};

void main_mutliple_inheritance()
{
    GrandChild gc;
    //gc.base_a = 2;       //compile error,issue:ambiguous
    //gc.Base::base_a = 3;
    //gc.print(gc.Base::base_a);
    gc.BaseChild1::base_a = 4;
    gc.print(gc.BaseChild1::base_a);
    gc.BaseChild2::base_a = 5;
    gc.print(gc.BaseChild2::base_a);
}
void main_single_inheritance()
{
    BaseChild3 bc;
    bc.BaseChild3::base_a = 1;
    bc.print(bc.base_a);
    bc.print(bc.Base::base_a);
    bc.base_a = 1;
    bc.print(bc.base_a);
    bc.print(bc.Base::base_a);
    bc.Base::base_a = 2;
    bc.print(bc.base_a);
    bc.print(bc.Base::base_a);

    BaseChild4 bc4;
    bc4.base_a = 1;
    bc4.print(bc4.base_a);
    bc4.print(bc4.Base::base_a);
    bc4.BaseChild4::base_a = 3;
    bc4.print(bc4.base_a);
    bc4.print(bc4.Base::base_a);
    bc4.Base::base_a = 2;
    bc4.print(bc4.base_a);
    bc4.print(bc4.Base::base_a);

}
int main()
{
    //main_single_inheritance();
    main_mutliple_inheritance();
    BaseChild5 bc5;
    //基类的成员会完全继承过来
    bc5.print(bc5.base_a);
    bc5.print(bc5.BaseChild4::base_a);
    bc5.print(bc5.Base::base_a);
    cout << sizeof(bc5) <<endl;
    cout << "Hello World!" << endl;
    return 0;
}
