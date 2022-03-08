#include <iostream>
using namespace std;

void defPointer()
{
    // 1、指针的定义
    int a = 10; //定义整型变量a

    //指针定义语法： 数据类型 * 变量名 ;
    int *p;

    //指针变量赋值
    p = &a;             //指针指向变量a的地址
    cout << &a << endl; //打印数据a的地址 0x7ffee1b200a8
    cout << p << endl;  //打印指针变量p 0x7ffee1b200a8

    // 2、指针的使用
    //通过*操作指针变量指向的内存
    cout << "*p = " << *p << endl; // *p = 10
}

void SizeofPointer()
{
    // 2. 指针的大小
    int a = 10;
    int *p = &a;
    cout << "size of a " << sizeof(a)<<endl;
    cout << "size of pointer p " << sizeof(p)<<endl;
}

void emptyPointer()
{
    // 3. 空指针和野指针
    
    // 空指针：初始化指针变量
    //指针变量p指向内存地址编号为0的空间
	int * p = NULL;

	//访问空指针报错 
	//内存编号0 ~255为系统占用内存，不允许用户访问
	cout << *p << endl;

    // 野指针
    //指针变量p指向内存地址编号为0x1100的空间
	int * p = (int *)0x1100;

	//访问野指针报错 
	cout << *p << endl;
}

void constPoinet()
{
    // 指针常量与常量指针
    int a = 10;
	int b = 10;

	//const修饰的是指针，指针指向可以改，指针指向的值不可以更改
	const int * p1 = &a;  // 可以理解为 * p1 是常量
	p1 = &b; //正确
	//*p1 = 100;  报错
	

	//const修饰的是常量，指针指向不可以改，指针指向的值可以更改
	int * const p2 = &a;  // 理解为 p 地址为常量
	//p2 = &b; //错误
	*p2 = 100; //正确

    //const既修饰指针又修饰常量
	const int * const p3 = &a;
	//p3 = &b; //错误
	//*p3 = 100; //错误


}
void arrayPoint()
{
    // 数组与指针
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	int * p = arr;  //指向数组的指针

	cout << "第一个元素： " << arr[0] << endl;
	cout << "指针访问第一个元素： " << *p << endl;

	for (int i = 0; i < 10; i++)
	{
		//利用指针遍历数组
		cout << *p << endl;
		p++;
	}
}

//值传递
void swap1(int a ,int b)
{
	int temp = a;
	a = b; 
	b = temp;
}
//地址传递
void swap2(int * p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void functionPointer()
{
    //指针与函数
    int a = 10;
	int b = 20;
	swap1(a, b); // 值传递不会改变实参

	swap2(&a, &b); //地址传递会改变实参

	cout << "a = " << a << endl;

	cout << "b = " << b << endl;
}

int main()
{
    defPointer();
    SizeofPointer();
    emptyPointer();
    return 0;
}