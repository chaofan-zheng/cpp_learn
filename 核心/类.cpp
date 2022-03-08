#include<iostream>
using namespace std;

const float PI = 3.14;
class Circle
{
public:
    int m_r; // 半径
    double CalZC()
    {
        return 2 * m_r * PI;
    }
};

struct Struct1
{
    int a;
};
class Class1
{
public:
    void SetA(int num)
    {
        a=num;
    };
private:
    int a;
};

// 练习案例1：设计立方体类

// 设计立方体类(Cube)

// 求出立方体的面积和体积

// 分别用全局函数和成员函数判断两个立方体是否相等。

class Cube
{
public:
    int length;
    int width;
    int height;
    void CalVolume()
    {
        cout<<"The volume of cube is"<<length*width*height<<endl;
    };
    bool IsSameCube(Cube cube)
    {
        if (cube.length==length&&cube.width==width&&cube.height==height)
            return true;
        else return false;
    }
};
bool IsSameCube(Cube cube1,Cube cube2)
{
    if (cube1.length==cube2.length&&cube1.width==cube2.width&&cube1.height==cube2.height)
        return true;
    else return false;
}

int main()
{
    Circle circle; // 实例化对象
    circle.m_r=10;
    cout<<"圆的周长是"<<circle.CalZC()<<endl;

    Struct1 s1;
    s1.a=10;
    Class1 c1;
    // c1.a=10; 
    c1.SetA(10); // 默认都是私有成员，都不可以访问

    Cube cub1,cub2;
    cub1.length=1;cub1.width=2;cub1.height=3;
    cub1.CalVolume();
    cub2.length=2;cub2.width=2;cub2.height=3;
    cout<<cub2.IsSameCube(cub1)<<endl; //0
    cout<<IsSameCube(cub1,cub1)<<endl; //1
    return 0;
}