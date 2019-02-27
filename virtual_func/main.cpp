#include <iostream>
#include <stdio.h>
using namespace std;
typedef void(*v_v)();
/*
    结论:
    1_虚函数会按照在类中声明的顺序存放在虚函数表里.
    2_虚函数表的地址是一个指针,在类的对象的首地址处存储.
*/
class Base
{
public:
    void g(){cout << "class Base::void g()"<<endl;};
    virtual void b(){cout << "class Base::virtual void b()"<<endl;};
    virtual void a(){cout << "class Base::virtual void a()"<<endl;};

    virtual void c(){cout << "class Base::virtual void c()"<<endl;};
};
class Child:public Base
{
public:
    void g(){cout << "class Child::void g()"<<endl;};
    virtual void b(){cout << "class Child::virtual void b1()"<<endl;};
    virtual void a1(){cout << "class CHild::virtual void a1()"<<endl;};

    virtual void c1(){cout << "class CHild::virtual void c1()"<<endl;};
};
int main()
{
    Base b;
    b.g();
    b.a();
    b.b();
    b.c();  //验证此处的地址.
    //get pointer
    Base *pb = NULL;
    pb = &b;  //是对象中的第一个成员.

    /*
     * 1.
     * 对象中的第一个成员是指向虚函数表的指针.
     * 指向第一个成员:(int *)pb
     * 拿到该成员的值:*(int *)pb
     * 该值的含义是:一个指向虚函数表的指针.
    */
    //printf("the virtual func table addr:%#x\n", pb);
    printf("the virtual func table addr:%#x\n", *(int *)pb);
    v_v pf =  NULL;
    printf("the virtual func  addr:%#x\n", (*((int*)*(int*)(&b))));
    /*
     * 1.
     * 虚函数表中存放的都是函数指针,指向vitrual函数.
     * 我们拿到第一个成员,首先要指向第一个成员:(int *)(*(int *)pb)
     * 这其实再取值就可以当做一个函数来使用:(*((int *)(*(int *)pb))) 或者 ((int *)(*(int *)pb))[0]
    */
    pf = (v_v)(*((int *)(*(int *)pb)));
    pf();
   // (*pf)();  //这种写法使用函数指针也是可以的.
    //依次调用a,b,c三个成员函数.
    pf = (v_v)(((int *)(*(int *)pb))[1]);
    pf();
    pf = (v_v)(((int *)(*(int *)pb))[2]);
    pf();
    //对继承的时候,虚函数表验证
    Child c, *pc;
    pc = &c;  //父类指针指向子类对象.
    c.g();
    c.a();
    c.a1();
    //开始验证子类对象的虚函数表,未发生虚函数覆盖.
    cout <<"验证子类的虚函数表的函数存储顺序"<<endl;
    for (int i = 0; i < 5; i++) {
    pf = (v_v)(((int *)(*(int *)pc))[i]);
    pf();
    }
    /*
     结果: class Base::virtual void b()
        class Base::virtual void a()
        class Base::virtual void c()
        class Child::virtual void b1()
        class CHild::virtual void a1()
        class CHild::virtual void c1()
    */

    //开始验证函数虚函数覆盖,多态.将基类和派生类的一个函数改为同名即可看到现象.子类覆盖父类的.
    return 0;
}

