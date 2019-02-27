#include <iostream>
/*
    如何理解下边的一句话:
    子类无法重载父类的函数，父类同名函数将被名称覆盖
    看下边的代码我们误以为,child类获得了add()和add(int int)两个方法
    这不是可以重载吗?而且编译的时候并没有发生错误.但是重载是在编译时候就将函数签名给写死了.
    我们调用child成员函数add(int a, int b)没有问题
    在直接调用继承父类的add()时候,不可以,编译的时候就报错了.
    不对啊.这个函数不是继承的时候父类给我的吗?
    父类的add1()子类就可以调用啊.
    没错add()可以调用,但是child类已经有add函数名的函数了.编译器在发现这种情况的时候会将函数签名.
    所以child就没有办法直接调用,只能加上域名控制了.
    这时候理解子类无法重载父类的同名函数了吧.
*/
using namespace std;
class parent {
private:
public:
    void add() {}
    void add1() {}
};
class child : public parent {
private:
public:
    void add(int a, int b) {}
};
int main()
{
    cout << "Hello World!" << endl;
    child *c = new child();
    c->add(3, 4);
    //c->add();  //编译出现错误,说找不到对应的函数.
    c->add1();
    c->parent::add();
    return 0;
}

