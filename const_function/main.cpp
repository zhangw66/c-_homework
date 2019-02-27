#include <iostream>

using namespace std;
typedef struct {
    int a;
    int b;
} data;
class Test {
private:
data a;
int c,d;
public:

    Test(int a, int b);
    ~Test();
    data& getAll();
    data getAll()const;   //可以构成重载,只需要知道const修饰的是形参中的this指针,所以参数还是有区别.
    void la()  {cout << "la!!"<<endl;};
protected:
};
Test::Test(int a1, int b1):
    c(3),
    d(2),
    a({5, 6})
{
 //结构体赋值的方法1
//    this->a.a = a1;
//    this->a.b = b1;
//    //结构体赋值的方法2
//    this->a = {3, 4};
    cout << "Test constructor!!"<<endl;
}
Test::~Test()
{
    cout << "Test disstructor!!"<<endl;
}
data Test::getAll()const
{
    cout << "data Test::getAll()const"<<endl;
    return this->a;
}
data& Test::getAll()
{
    cout << "data& Test::getAll()"<<endl;
    return a;
}
void print(data& d)
{
    cout<<"a="<<d.a<<endl;
    cout<<"a="<<d.b<<endl;
}
int main()
{
    Test *p = new Test(12, 24);
    data &d1 = p->getAll();
    data d2 =  p->getAll();
    print(d2);
    delete p;
    const Test t(22, 33);
    //t.la();   //compile error
    t.getAll();   //我们发现const对象只能调用const类型的成员.
//    d.a = 5;
//    print(d);
//    cout << "Hello World!" << endl;
    return 0;
}

