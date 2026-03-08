//1.添加联系人
//2.显示联系人
//3.修改联系人
//4.删除联系人
//5.清空联系人
//0.退出通讯录



#include<iostream>
#include<string>
#include<malloc.h>

using namespace std;

//------------------------------------------------------------------------建立单独人物结构体所在区域------------------------------------
typedef struct Person
{
    char name[30];
    char number[30];//使用int会超出，int无法保存11位手机号
}Person;
struct Person arr[100] = {};
//--------------------------------------------------------------------------------------------------------------------------------------



int main()
{

    int size = 0;
    int select = 0;
    char WRONG_NAME[30];
    char TURE_NAME[30];
    char TURE_NUMBER[30];



    while (1)
    {
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "*********************************" << endl;
        cout << "*********************************" << endl;
        cout << "Welcome to Using Contacts Books!" << endl;
        cout << "   Please Enter Follow Number " << endl;
        cout << "*********************************" << endl;
        cout << "*********************************" << endl;
        cout << "-------------------------------" << endl;
        cout << "1.Add Person" << endl;//添加联系人
        cout << "2.Show Contacts" << endl;//显示联系人
        cout << "3.Change Contacts" << endl;//修改联系人
        cout << "4.Delete Contacts" << endl;//删除联系人
        cout << "5.Del_All Contacts" << endl;//清空联系人
        cout << "0.Exit Contactbook" << endl;//退出通讯录
        cout << "-------------------------------" << endl;
        cin >> select;

        switch (select)
        {
        case 1://-----------------------------------------------添加联系人


            cout << "Please Enter name:";
            cin >> arr[size].name;
            cout << "Please Enter Phone Number:";
            cin >> arr[size].number;
            size++;
            cout << "Create Successfully!" << endl;
            break;

        case 2://显示
            cout << "Following are All of Contacts:" << endl;
            cout << "#############################################################" << endl;
            for (int i = 0; i < size; i++)
            {
                // 修复：使用 arr[i] 而不是 arr[size]
                cout << "name:" << arr[i].name << "        number:" << arr[i].number << endl;
            }
            cout << "#############################################################" << endl;

            break;

        case 3://修改

            cout << "Who You Want to Change:" << endl;
            cin >> WRONG_NAME;

            while (1)
            {
                int i = 0;
                if (strcmp(WRONG_NAME, arr[i].name) == 0)
                {
                    cout << "found It!Please Enter Name You Want to Change:";
                    cin >> TURE_NAME;
                    strcpy_s(arr[i].name, 30, TURE_NAME);//将正确的名字放进去
                    cout << "Enter the Right Number:";
                    scanf_s("%s", &TURE_NUMBER);
                    strcpy_s(arr[i].number,30, TURE_NUMBER);
                    cout << "Finished!";

                    break;



                }
                else//未找到错误的联系人名字并且退出
                {
                    if (i < size) i++;
                    else if (i == size)
                    {
                        cout << "No Found!Please Try Again!" << endl;
                        break;
                    }
                }
            }
            break;

        case 4://删除
            cout << "Please Enter Who You Want to Delete:";






            break;

        case 5://清空
        {//---------------------------------大括号
            int flag = 0;//---------------在switch语句中申明定义，需要将包含定义的所有地方用大括号包裹，以保证它的生命周期在这个范围内
            cout << "Are You Sure to Delete All?" << endl;
            cout << "Enter 1 to Delete || Enter 2 to Exit" << endl;
            cin >> flag;
            if (flag == 1)
            {
                arr[100] = { 0 };
                flag = 0;
                break;
            }
            else if (flag == 2)
                break;
        }//--------------------------------------大括号

        case 0:
            cout << "Thanl You for Your Using!" << endl;
            return 0;

        default:
            cout << "Please Enter the Right Number." << endl;
            break;
        }

    }
    //---------------------------------------------------------------------------------------------------
}











/*-------------------------- - 豆包修正版------------------------ -
#include<iostream>
#include<string>
using namespace std;

// 修正结构体：单个联系人只有一个姓名和一个手机号，无需数组
typedef struct Person
{
    string name;    // 姓名（单个string，不是数组）
    string number;  // 手机号（单个string，不是数组）
} Person;

// 通讯录数组，最多存储100个联系人
Person contacts[100] = {};
// 有效联系人数量（核心变量，记录当前有多少个联系人）
int contactCount = 0;

int main()
{
    int select = 0;
    while (true)
    {
        // 清屏（可选，提升体验）
        cout << "\n\n\n\n\n";
        cout << "*********************************" << endl;
        cout << "Welcome to Using Contacts Books!" << endl;
        cout << "   Please Enter Follow Number " << endl;
        cout << "*********************************" << endl;
        cout << "-------------------------------" << endl;
        cout << "1.Add Person       (添加联系人)" << endl;
        cout << "2.Show Contacts    (显示联系人)" << endl;
        cout << "3.Change Contacts  (修改联系人)" << endl;
        cout << "4.Delete Contacts  (删除联系人)" << endl;
        cout << "5.Del_All Contacts (清空联系人)" << endl;
        cout << "0.Exit Contactbook (退出通讯录)" << endl;
        cout << "-------------------------------" << endl;
        cin >> select;

        switch (select)
        {
        case 1: // 添加联系人
            if (contactCount >= 100) // 防止数组越界
            {
                cout << "通讯录已满，无法添加新联系人！" << endl;
                break;
            }
            cout << "Please Enter name: ";
            cin >> contacts[contactCount].name;
            cout << "Please Enter Phone Number: ";
            cin >> contacts[contactCount].number;
            contactCount++; // 有效数量+1
            cout << "Create Successfully!" << endl;
            break;

        case 2: // 显示联系人
            if (contactCount == 0)
            {
                cout << "通讯录为空，暂无联系人！" << endl;
                break;
            }
            cout << "Following are All of Contacts:" << endl;
            cout << "#############################################################" << endl;
            for (int i = 0; i < contactCount; i++)
            {
                cout << "No." << i + 1 << "  name: " << contacts[i].name
                    << "        number: " << contacts[i].number << endl;
            }
            cout << "#############################################################" << endl;
            break;

        case 3: // 修改联系人
        {
            if (contactCount == 0)
            {
                cout << "通讯录为空，无联系人可修改！" << endl;
                break;
            }
            string targetName; // 要修改的联系人姓名
            cout << "Who You Want to Change: ";
            cin >> targetName;

            bool found = false; // 标记是否找到联系人
            for (int i = 0; i < contactCount; i++)
            {
                if (contacts[i].name == targetName) // C++ string直接用==比较
                {
                    found = true;
                    cout << "Found It! Please Enter New Name: ";
                    cin >> contacts[i].name; // 直接赋值string
                    cout << "Enter the New Phone Number: ";
                    cin >> contacts[i].number; // 直接赋值string
                    cout << "Change Finished!" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "No Found This Contact! Please Try Again!" << endl;
            }
            break;
        }

        case 4: // 删除联系人
        {
            if (contactCount == 0)
            {
                cout << "通讯录为空，无联系人可删除！" << endl;
                break;
            }
            string deleteName;
            cout << "Please Enter Who You Want to Delete: ";
            cin >> deleteName;

            bool found = false;
            int deleteIndex = -1;
            // 第一步：找到要删除的联系人下标
            for (int i = 0; i < contactCount; i++)
            {
                if (contacts[i].name == deleteName)
                {
                    found = true;
                    deleteIndex = i;
                    break;
                }
            }
            if (!found)
            {
                cout << "No Found This Contact!" << endl;
                break;
            }
            // 第二步：删除（后面的元素往前移）
            for (int i = deleteIndex; i < contactCount - 1; i++)
            {
                contacts[i] = contacts[i + 1]; // 结构体直接赋值
            }
            contactCount--; // 有效数量-1
            cout << "Delete Successfully!" << endl;
            break;
        }

        case 5: // 清空联系人
        {
            int flag = 0;
            cout << "Are You Sure to Delete All?" << endl;
            cout << "Enter 1 to Delete || Enter 2 to Exit: ";
            cin >> flag;
            if (flag == 1)
            {
                contactCount = 0; // 重置有效数量为0，等同于清空
                cout << "All Contacts Deleted!" << endl;
            }
            break;
        }

        case 0: // 退出
            cout << "Thank You for Your Using!" << endl;
            return 0;

        default: // 输入错误
            cout << "Please Enter the Right Number (0-5)!" << endl;
            break;
        }
    }
    return 0;
}





---------------------------------------------*/