#include <iostream>
using namespace std;
#include <string>
void test()
{
    string s1; // string s1; //创建空字符串，调用无参构造函数
    cout << "str1 = " << s1 << endl;
    const char *str01 = "hello world";
    string s2(str01); //把把c_stricng转换成了string
    cout << "str2 = " << s2 << endl;
    string s3(s2); //调用拷贝构造函数
    cout << "str3 = " << s3 << endl;
    string s4(10, 'a');
    cout << "str3 = " << s3 << endl;
}
//赋值
void test01()
{
    string str1;
    str1 = "hello world";
    cout << "str1 = " << str1 << endl; // hello world

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl; // hello world

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl; // a

    string str4;
    str4.assign("hello c++");
    cout << "str4 = " << str4 << endl; // hello c++

    string str5;
    str5.assign("hello c++", 5); // 前5位赋值给str5
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(5, 'x'); // x赋值五次给str7
    cout << "str7 = " << str7 << endl;

    str7.append("y");
    cout << "str7 = " << str7 << endl;

    str7.replace(1, 3, "aa"); //替换从pos开始n个字符为字符串str
    cout << "str7 = " << str7 << endl;
}
// 拼接
void test02()
{
    string str1 = "abc";
	str1+="efg";
    str1.append("hijk");
	cout << "str1 = " << str1 << endl;
}
// 查找和替换
void test03()
{
    string str1 = "abcabc";
    int pos;
    pos=str1.find("a");
    cout<<pos<<endl;
    pos=str1.rfind("a");
    cout<<pos<<endl;
    str1.replace(1,3,"--"); // "a--bc"
    cout<<str1<<endl;
}
// 取单个字符
void test04()
{
    string i;
    string str1="abcd";
    str1[1]='e'; // c++中 双引号代表的是字符串类型，单引号代表字符。
    i = str1[2];
    cout<<i<<endl;
    cout<<str1<<endl;

}

int main()
{
    // test();
    // test01();
    test04();
    return 0;
}
