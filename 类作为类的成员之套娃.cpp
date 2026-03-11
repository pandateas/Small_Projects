#include<iostream>
#include<cstring>
using namespace std;

//手机类
class Phone
{
public:
	
	string Phone_Brand;//手机品牌

	Phone(string pName)//调用构造函数来给手机品牌传值
	{
		Phone_Brand = pName;
		cout << "Phone的构造函数调用" << endl;
	}
	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}
};



//人类
class Person
{
public:


	//不使用编译器默认的构造函数，新建构造函数来初始化传进来的默认值
	Person(string name, string pName):m_Name(name),m_Phone(pName)

		//上面其实就是类中调用类的操作，只不过是隐性的（隐式转换法）
		//类也可以在类中初始化其变量默认值，但是使用列表能够从外部初始化
		// 使得初始化的值能够随意更改
		//赋值操作中调用的变量实际上来源于Phone但是能够被Person调用
		//是应为编译器做了 Phone p.m_Phone = pName;操作

	{
		//初始化列表操作，在：后面的括号内进行复制操作
		//括号内的赋值给括号外的
		//这样进行初始化赋值的效率更高
		cout << "Person的构造函数调用" << endl;
	}


	//姓名
	string m_Name;
	//手机
	Phone m_Phone;//这是在Person类中的Phone类
				  //使用m_Phone进行了Person类的初始化赋值

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}



};


//测试样例
void test01()
{
	Person p("张三", "苹果");
	cout << p.m_Name << "拿着" << p.m_Phone.Phone_Brand <<"手机" << endl;

}



int main()
{
	test01();





}



//总结：若当类中包含类时，现加载被包含的，在加载外层的
//越小越优先,先调用的后出，后调用的先出