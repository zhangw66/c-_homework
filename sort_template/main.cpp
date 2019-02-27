#include <iostream>
/*
    对基本类型的数据进行排序(冒泡)
*/
using namespace std;
#define size(a) (sizeof(a)/sizeof(a[0]))
void sort(int *pa, int size)
{

    for (int i = 0; i < size; i++)
    {
           for (int j = i + 1; j < size; j++)
           {
               if (pa[i] > pa[j])
               {
                   int tmp;
                   tmp = pa[i];
                   pa[i] = pa[j];
                   pa[j] = tmp;
                  // swap(&str[i], &str[j]);
               }
           }
       }
}
template <typename T>
void sort1(T *pa, int size)
{

    for (int i = 0; i < size; i++)
    {
           for (int j = i + 1; j < size; j++)
           {
               if (pa[i] > pa[j])
               {
                   T tmp;
                   tmp = pa[i];
                   pa[i] = pa[j];
                   pa[j] = tmp;
                  // swap(&str[i], &str[j]);
               }
           }
       }
}
template <typename T>
void print(T* pt, int size)
{
    for (int i = 0; i < size; i++)
        cout << "["<<i<<"]="<<pt[i]<<endl;
}
int main()
{
    int a[] = {56, 2, 23, 32};
    float f[] = {3.2, 22.1, 0.56, -3.2};
//    cout << "before sort..."<<endl;

//    sort1<int>(a, size(a));
    sort1(a, size(a));
    print<int>(a, size(a));
    sort1<float>(f, size(f));
    print<float>(f, size(f));
    cout << "Hello World!" << endl;
    return 0;
}

