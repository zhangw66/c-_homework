
#include <iostream>

using namespace std;
template <class T1, class T2, class T3>
class Complex {
private:
    T1 i;
    T2 c;
    T3 f;
protected:
public:
    friend ostream& operator <<(ostream& c, Complex &c1);
    //friend ostream& operator <<(ostream& c, Complex<T1, T2, T3> &c1);
    Complex operator +(Complex &c1);
    void printAll();
    Complex(T1 i = 0, T2 c = 'c', T3 f = 3.14);
    ~Complex();
};
template <class T1, class T2, class T3>
ostream& operator <<(ostream& c, Complex<int, char, float> &c1)
{
    c << "i="<<c1.i<<endl;
    c << "c="<<c1.c<<endl;
    c << "f="<<c1.f<<endl;
    return c;
}
template <class T1, class T2, class T3>
Complex<T1,T2,T3> Complex<T1,T2,T3>::operator +(Complex &c1)
{
    Complex tmp;
    tmp.i = this->i + c1.i;
    tmp.c = this->c + c1.c;
    tmp.f = this->f + c1.f;
    return tmp;
}
template <class T1, class T2, class T3>
void Complex<T1,T2,T3>::printAll()
{
    cout<<"a="<<i<<endl;
    cout<<"c="<<c<<endl;
    cout<<"f="<<f<<endl;
}
template <class T1, class T2, class T3>
Complex<T1,T2,T3>::Complex(T1 i, T2 c, T3 f):
    i(i),
    c(c),
    f(f)
{
    //cout<<"Complex::Complex"<<endl;
}
template <class T1, class T2, class T3>
Complex<T1,T2,T3>::~Complex()
{
  // cout<<"Complex::~Complex"<<endl;
}

int main()
{
    Complex<int, char, float> c1;
    Complex<int, char, float> c2;
    Complex<int, char, float> c3;
    c2 = c2 + c1;
    c3 = c2 + c1;
//    c1.printAll();
//    c2.printAll();
//    cout << c1 <<endl;

    return 0;
}

