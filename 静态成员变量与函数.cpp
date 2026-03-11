#include<iostream>
#include<cstring>
using namespace std;

//静态成员函数
//所有的成员共享同一个函数
//静态成员函数只能访问静态成员变量

class Person
{
public:

	//静态成员函数
	static void func()
	{
		m_A = 100;  //静态的成员函数可以访问静态的成员变量
	    //m_B = 200;//静态的成员函数不可以访问非静态的成员
					//编译器也不知道这到底是哪个对象的属性	
					//但是m_A是共享的所以编译器不需要知道谁调用它
					//静态函数和静态成员是在编译阶段就分配了内存的
					//非静态成员要在运行的时候才会分配内存



		cout << "static void func调用" << endl;
	}

	static int m_A;//静态成员特点：类内声明，类外初始化
	int m_B;
	//静态成员函数也是有访问权限的
private:
	static void func2()
	{
		cout << "static void func2()调用" << endl;
	}



};

int Person::m_A = 0;

void test01()
{
	//1.通过对象来进行访问
	Person p;
	p.func();

	//2.通过类名进行访问
	Person::func();

	//Person::func2();
	//不能够访问在private域中的静态成员

}




int main()
{











}