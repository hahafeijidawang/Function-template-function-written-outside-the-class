/*
场景2

所有的函数写在类的外部。

*/

#include <iostream>

using namespace std;

template<typename T>
class Complex;//类的前置声明(只为了MySub函数)

template<typename T>
Complex<T> MySub(Complex<T> &c1,Complex<T> &c2);


template<typename T>

class Complex{

public:
    //所有的函数写到类里面。这种写法只针对<<和>>
  // friend ostream & operator<< <T> (ostream &out,const Complex<T> &c3);//编译通不过。
    //其他类型的友元函数外放 说明 需要加前置说明。
  // friend Complex MySub<T> (Complex &c1,Complex &c2);

   friend  Complex<T> MySub<T>(Complex<T> &c1,Complex<T> &c2);

   Complex( T a,T b );

   Complex operator +(Complex &c2);

   void printCom();

private:
  T a;
  T b;

};

//成员函数
template <typename T>
Complex<T>::Complex( T a,T b ){

    this->a = a;

    this->b = b;

}

template <typename T>
void Complex<T>::printCom(){

    cout<<"a:"<<a<<"b:"<<b<<endl;
}

template <typename T>
Complex<T> Complex<T>:: operator +(Complex<T> &c2){

    return Complex(a+c2.a,b+c2.b);
}

//友元函数 实现运算符重载。
template <typename T>
//编译报错 模板机制是两次编译
/*ostream& operator <<(ostream &out,Complex<T> &c3){

    out<<"a:"<<c3.a<<"b:"<<c3.b<<endl;

    return out;
}*/

template<T>
Complex<T> MySub(Complex<T> &c1,Complex<T> &c2){

    Complex tmp(c1.a-c2.a,c1.b-c2.b);

    return tmp;

}




int main()
{




    Complex<int> c1(10,30);

    Complex<int> c2(2,3);

    Complex<int> c3=c1+c2;

    c3.printCom();


    return 0;
}

