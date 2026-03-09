#include<iostream>
#include<cstring>
using namespace std;


//拷贝构造函数的调用时机

//1.使用一个已经创建完毕的对象来初始化一个新对象

//2.值传递的方式给函数参数传值

//3.值方式返回局部对象



class Person
{


public:

	int m_age = 0;




	Person()//默认构造（无参）
	{
		cout << "Person的默认构造函数的调用" << endl;
	}

	Person(int age)//含参构造//age用于临时传递值//m_age是需要改变的变量
	{
		m_age = age;
		cout << "Person的含参构造函数调用" << endl;
	}

	Person(const Person &p)//p是Person类的一个临时成员用于传递值来拷贝
	{
		m_age = p.m_age;
		cout << "Person的拷贝构造函数调用" << endl;
	}





	~Person()//析构调用
	{
		cout << "Person的析构函数的调用" << endl;
	}


private:

};





//测试用例
//1.使用一个已经创建完毕的对象来初始化一个新的对象
void test01()
{
	Person p1(20);//相当于一个参数是20的构造函数p1
	Person p2(p1);//相当于p2 = p1构造函数,那么同样是参数为20的构造函数

	cout << "p1的年龄是：" << p1.m_age << endl;
	cout << "p2的年龄是：" << p2.m_age << endl;
}




//测试用例
//2.值传递的方式给函数参数传值
void doWork(Person p)
{

}

void test02()
{
	Person p;
	doWork(p);//值传递会临时拷贝一个副本出来，可以供函数调用
}




//测试用例
//3.值方式返回局部对象
Person doWork2()
{
	Person p1;//在这里创建了一个新的变量
	p1.m_age = 3;
	return p1;
	//在返回后会清空掉p1，所以编译器为了防止这种事情发生
	//会在外面创建一个临时变量，并且在后面给他命名为p1
	//相当于以这种方式让这个类不会消失，反而能够完整的传递出去
}



void test03()
{
	Person p1 = doWork2();//在这里使用了doWork是当前测试用例有了p1
	                      //需要一个同样的变量来接收
	//doWork中的p1生命周期只在doWork，在当前函数已经结束了
	//所以在test03中创建相同的名称p1到头来还是两个不一样的东西

	cout << "Person p1在doWork2中创建的m_age是：" << p1.m_age << endl;


}




int main()
{
	test01();
	test02();
	test03();  







}