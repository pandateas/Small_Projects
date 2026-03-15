#include<iostream>
#include<cstring>


using namespace std;


class Person
{
public:

	int m_Age = 18;

	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		//cout << "age = " << this->m_Age<<endl;
		//报错原因是传入了指针是NULL,变量前面默认都会有个this指针
		//但是在这里this指针指向的是空,所以编译器懵了

		if (this == NULL)
		{

			//如果传入的指针是空的,那么直接退出程序
			//这样做可以提升代码的健壮性,不容易出错
			return;
		}



		cout << "age = " << m_Age << endl;



	}




};





void test01()
{
	Person* p = NULL;

	p->showClassName();

	p->showPersonAge();



}



int main()
{
	test01();




}



//总结:空指针可以访问成员函数,但是无法访问成员变量
//因为编译器不知道要访问哪个成员,就会出现报错
//遇到这种情况,但是有需要调用this指针,可以在函数输出前
//加一个判断调用成员对象的this指针,如果this指针为空,那么退出
//在调用变量成员的时候前面都会默认加一个this指针来访问成员
//所以加入一个判断this指针是否为空可以提升代码健壮性


//运行代码可以发现m_Age不会显示,就是应为判断this指针起了作用
//防止输入一些莫名其妙的东西👍