//编译器执行的浅拷贝相当于做"="操作,若是有指针也会指向同一块内存
//为了避免在清理内存时出错,需要自己创建一个拷贝函数来进行深拷贝
//深拷贝就是将拷贝过来的指针变量新建一个指针指向另外一块内存空间
// 防止释放内存时出错
// (p和q的指针变量是两个不同的变量但是指向相同的内存)






#include<iostream>
#include<cstring>
using namespace std;

//深拷贝和浅拷贝
class Person
{
public:

	int m_age = 18;//年龄
	int *high = NULL;//身高//堆区//指针只能指向内存//初始化指针




	Person()
	{
		cout << "Person的默认函数调用" << endl;
	}

	Person(int age,int HIGH)//HIGH为临时变量用来传递参数
	{
		high = new int(HIGH);//新建堆区用来存放值
		cout << "Person的有餐构造函数调用" << endl;
	}

	Person(const Person& p)//这里拷贝函数代表的p2复制p1
	{

		cout << "Person拷贝构造函数调用" << endl;

		m_age = p.m_age;//编译器默认执行,使得q.high指向同一块内存区域


		//深拷贝操作
		high = new int(*p.high);//解出指针里面的内容
								//重新开辟一块内存空间
								//任然命名成原本的名字
								//相当于给变量迁了个家
				
		

	}




	~Person()
	{
		//析构代码,将多去开辟的数据做释放操作
		//堆区创造的数据,在这里释放干净

		if (high != NULL)
		{
			delete high;
			high = NULL;
		}



		cout << "Person的析构函数调用" << endl;
	}



};


void test01()
{
	Person p1(18,170);

	cout << "p1的年龄为:" << p1.m_age<<"身高为:"<<*p1.high << endl;

	Person p2(p1);//Person p2 = Person p1;//编译器做了一个临时复制操作
				  //在此处high指针指向的是p1存放数据的内存,p2先执行完毕先退出
				  //在析构的时候将指针内的东西清空了,导致p1析构一块已经析构了的内存
				  //导致因为重复析构造成的报错,同一块内存不能析构两次


	cout << "p2的年龄为:" << p2.m_age << endl;

}







int main()
{
	test01();
	//解决方法:自己创建一个拷贝函数,来规避编译器自己拷贝不好使的问题

}




//总结:如果创建类的时候有使用指针,或者说开辟了了一块新的内存并拷贝
//那么一定一定一定要自己创建一个拷贝函数,并且在其中改变它指针的指向
//以免进行错误的内存清理,即同一块内存被重复清理两次