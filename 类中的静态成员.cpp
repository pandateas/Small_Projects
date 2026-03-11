//静态成员变量
//所有对象共享同一份数据，若数据更改，那么其他对象调用的数据也会更改
//静态成员会在编译阶段就分配内存
//静态成员必须要在类内声明，在类外进行初始化操作





#include<iostream>
#include<cstring>
using namespace std;


class Person
{
private:
	static int m_B;





public:
	static int m_A;//所有对象都共享同一份数据
					//在编译阶段就分配了内存
					//类内声明，类外初始化(必要操作)


};







int Person :: m_A = 100;//告诉编译器m_A变量是在Person作用域下的
						//而Person中的是静态的
						//这就完成了类内声明，类外初始化的操作

int Person::m_B = 1;





void test01()
{


	Person p;
	cout <<"m_A现在的值是："<< p.m_A << endl;


	Person p2;
	p2.m_A = 200;//通过别的成员改变了原本的初始值
	cout <<"m_A现在的值是："<< p2.m_A << endl;

}

void test02()
{
	//静态的成员变量不只属于某一个对象，所有对象共享
	//因此访问金泰成员变量有两种访问方式

	//1.通过对象进行访问
	Person p;
	cout << p.m_A << endl;



	//2.通过类名进行访问
	cout << Person::m_A << endl;
	//tips:双冒号是作用域解析运算符
	//作用是明确告诉编译器要解析那个作用域下的东西
	//像是在这里就是告诉编译器要解析Person下面的m_A这个成员变量



	//静态成员也有访问权限
	//如果在private中，出了类也不可以访问,如下
	//cout << Person::m_B << endl;



}

int main()
{
	test01();







}