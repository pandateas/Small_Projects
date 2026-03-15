//当程序中某些变量或者函数前面加上了const后
//就变成了常变量和常函数
//常函数内不能修改成员属性
//成员属性声明是加上关键词mutable后,在常函数中依然可以修改
//声明对象前加const称该对象为常对象
//长对象只能调用常函数





#include<iostream>
#include<cstring>


using namespace std;


class Person
{

public:

	int m_A;
	mutable int m_B = 10;//特殊变量,即使在长函数中也可以修改他的值

	
	void showPerson()//const//在这里加上const
					//除了mutable的值其他都不能够被修改
	{
				  //在调用变量的时候前面会默认有一个this指针
				  //this指针的本质是一个指针常量
				  //指针的指向是不可修改的
				  //可以将this看做成 Person *const this;
				  //如果要限定指针指向的值,需要在函数声明末尾加上const
				  //但是指针指向的地址存放的东西是可以被修改的
		m_A = 100;//如过在声明处加上const,那么就不能被修改

		int m_B = 666;



	}


	void func()
	{

	}


	void address() const
	{

	}






};










void test01()
{
	Person p;
	p.showPerson();

}


void test02()
{
	const Person p;//在对象前加const,变为常对象
	//p.m_A = 100;//被限定无法修改
	p.m_B = 100;//加了mutable就可以更改


	//常对象只能调用常函数
	Person q;
	q.showPerson();
	q.address();



}




int main()
{






}


