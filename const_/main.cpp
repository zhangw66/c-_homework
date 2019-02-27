#include <iostream>
#include <stdio.h>
using namespace std;
/*
    为何a的值还是10呢?
    我们可以理解为这是c++中的符号表机制所为,由于const修饰其实在c
    语言中是无用的,因为无法将内存变成只读的,我们一旦知道了只读变量的地址
    我们可以轻易的通过内存去修改变量的值,但是c++中维护了一个符号表,以key-value的
    形式存储着const,所以你只要用这个常量的名字,就可以从符号表中找到对应的value.
*/
int main01()
{
    const int a = 10;
    int *pa = (int *)&a;
    const int &a1 = a;
    pa[0] = 22;
    printf("a[%p], pa[%p] al[%p]\r\n", &a, pa, &a1);
    printf("a = %d, *pa = %d, a1 = %d\r\n", a, *pa, a1);
    cout << "Hello World!" << endl;
    return 0;
}
//常引用指向字面值的时候,是会分配内存空间的.
int main02()
{
    /*常引用指向字面值*/
    //int &a = 10; //compile err
    const int& a1 = 10; //这句话会分配一个内存空间.
    cout << a1 << endl;
    int *pa1 = (int *)&a1;
    *pa1 = 20;
    cout << a1 << endl;
    printf("%p\r\n", &a1);
    return 0;
}
int main()
{
    return main02();
}
/*
output:
a[0061fe94], pa[0061fe94] al[0061fe94]
a = 10, *pa = 22, a1 = 22
Hello World!
*/

