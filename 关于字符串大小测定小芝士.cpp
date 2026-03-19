//测定字符串的大小在C和C++中的语句是不同的,下面会详细介绍


/*C语言中字符串的大小测定
1.sizeof(字符串数组名);---返回的是字符串所占字节数的大小,会包含 "\0"终止符
2.strlen(字符串数组名);---返回的是字符串有效字符的大小,不包含终止符,但是要包含头文件#include<string>

*/

/*C++中字符串大小的测定
1.使用 strname.size() --- 数组名.size()
2.使用strname.length()--- 数组名.length()
注意:以上两种返回的都是字符串实际的字符数,不包含终止符
*/






#include<iostream>
#include<cstring>
using namespace std;









int main()
{







}