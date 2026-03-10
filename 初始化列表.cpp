#include<iostream>
#include<cstring>
using namespace std;


//初始化列表
class Person
{
public:


    int m_A;
    int m_B;
    int m_C;

    //传统的初始化操作
    Person(int a, int b, int c)
    {
        m_A = a;
        m_B = b;
        m_C = c;
    }

    //初始化列表属性
    Person():m_A(10),m_B(20),m_C(30)
    {
        //在调用函数的时候直接初始化其值
    }




    //自定义初始化列表属性
    Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
    {
        //通过外部调用时往内部给值，值会传递到m_A,m_B,m_C
        //是一种能够自定义初始值的方式，非常的灵活
    }
       

        








};













void test01()
{
    Person p(10, 20, 30);
    cout << "m_A = " << p.m_A << endl;
    cout << "m_B = " << p.m_B << endl;
    cout << "m_C = " << p.m_C << endl;





}


int main()
{
    test01();










}