#include <iostream>
using namespace std;
class Object
{
private:
protected:
public:
    Object(char * s){cout<<"class Object:"<<s<<endl;};
    void print(){cout << "Object::print" <<endl;}
};
class Parent:public Object
{
private:
protected:
public:
    Parent(char * s):Object("i am object"){cout<<"class Parent:"<<s<<endl;};
    void print(int a){cout << "Object::print" <<endl;}
};
class Child:public Parent
{
private:
//    Object o;
    Parent p;   //必须要显示调用父亲有参的构造函数
protected:
public:
    Child(char *s):
        Parent("i am Parent"),
        p("I am parent")
    {cout<<"class CHild:"<<s<<endl;};
};
class Test
{

public :
    void La(){cout << "lalalala"<<endl;};
    Test(){cout << "Test Constructor"<<endl;};
    static Test t;
};
Test Test::t;   //static成员必须在类外显示的初始化.
int main()
{
    Child c("i am Child");
    cout << "Hello World!" << endl;
    Test t1;

    Test::t.La();
    //Test &t = a Test::t;
    return 0;
}

