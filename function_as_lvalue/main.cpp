#include <iostream>

using namespace std;
int &func(void)
{
    static int a;
    return a;
}
int *func1(void)
{
    static int a;
    return &a;
}
int main()
{
    cout << "Hello World!" << endl;
    //cout << "函数返回引用,可以直接当左值!" <<endl;
    func() = 100;
    cout << func() << endl;
    func() = 120;
    cout << func() << endl;
    //cout << "函数返回指针,可以直接当左值!" <<endl;
    *(func1()) = 100;
    cout << *(func1()) << endl;
    *(func1()) = 120;
    cout << *(func1()) << endl;
    return 0;
}

