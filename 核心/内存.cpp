#include <iostream>
using namespace std;
//全局变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

// int main() {

// 	//局部变量
// 	int a = 10;
// 	int b = 10;

// 	//打印地址
// 	cout << "局部变量a地址为： " << (long int)&a << endl;
// 	cout << "局部变量b地址为： " << (long int)&b << endl; // 强制类型转换

// 	cout << "全局变量g_a地址为： " << (long int)&g_a << endl;
// 	cout << "全局变量g_b地址为： " << (long int)&g_b << endl;

// 	//静态变量
// 	static int s_a = 10;
// 	static int s_b = 10;

// 	cout << "静态变量s_a地址为： " << (long int)&s_a << endl;
// 	cout << "静态变量s_b地址为： " << (long int)&s_b << endl;

// 	cout << "字符串常量地址为： " << (long int)&"hello world" << endl;
// 	cout << "字符串常量地址为： " << (long int)&"hello world1" << endl;

// 	cout << "全局常量c_g_a地址为： " << (long int)&c_g_a << endl;
// 	cout << "全局常量c_g_b地址为： " << (long int)&c_g_b << endl;

// 	const int c_l_a = 10;
// 	const int c_l_b = 10;
// 	cout << "局部常量c_l_a地址为： " << (long int)&c_l_a << endl;
// 	cout << "局部常量c_l_b地址为： " << (long int)&c_l_b << endl;
	
// 	// 动态申请堆变量
// 	int * new_a = new int(10);
// 	cout << "动态申请内存new_a地址为： " << (long int)&new_a << endl;
// 	delete new_a;

// 	int * new_arr = new int[10]; // 申请数组
// 	cout << "动态申请内存new_arr地址为： " << (long int)&new_arr << endl;
//     delete [] new_arr; //释放数组 delete 后加 []


    

// 	system("pause");

// 	return 0;
//     // 局部变量a地址为： 0x7ffee68a80a8
//     // 局部变量b地址为： 0x7ffee68a80a4
//     // 全局变量g_a地址为： 0x10935f0c8
//     // 全局变量g_b地址为： 0x10935f0cc
//     // 静态变量s_a地址为： 0x10935f0d0
//     // 静态变量s_b地址为： 0x10935f0d4
//     // 字符串常量地址为： 0x10935aebb
//     // 字符串常量地址为： 0x10935aec7
//     // 全局常量c_g_a地址为： 0x10935af58
//     // 全局常量c_g_b地址为： 0x10935af5c
//     // 局部常量c_l_a地址为： 0x7ffee68a80a0
//     // 局部常量c_l_b地址为： 0x7ffee68a809c
// }


// int main() 
// {

// 	int a = 10;
// 	int b = 20;
// 	//int &c; //错误，引用必须初始化
// 	int &c = a; //一旦初始化后，就不可以更改
// 	// int &c = b; // 报错 内存.cpp:77:7: note: previous definition is here
// 	c = b; //这是赋值操作，不是更改引用

// 	cout << "a = " << a << endl; // 20
// 	cout << "b = " << b << endl; // 20
// 	cout << "c = " << c << endl; // 20

// 	system("pause");

// 	return 0;
// }

//1. 值传递
// void mySwap01(int a, int b) {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }

// //2. 地址传递
// void mySwap02(int* a, int* b) {
// 	int temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// //3. 引用传递
// void mySwap03(int& a, int& b) {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }

// int main() {

// 	int a = 10;
// 	int b = 20;

// 	mySwap01(a, b);
// 	cout << "a:" << a << " b:" << b << endl;

// 	mySwap02(&a, &b);
// 	cout << "a:" << a << " b:" << b << endl;

// 	mySwap03(a, b);
// 	cout << "a:" << a << " b:" << b << endl;

// 	system("pause");

// 	return 0;
// }
//返回局部变量引用
int& test01() {
	int a = 10; //局部变量
	return a;
}

//返回静态变量引用
int& test02() {
	static int a = 20;
	return a;
}

int main() {

	//不能返回局部变量的引用
	// int& ref = test01();
	// cout << "ref = " << ref << endl;
	// cout << "ref = " << ref << endl;

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");

	return 0;
}