#include <iostream>
using namespace std;


// 结构体综合

// 学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下

// 设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

// 学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

// 最终打印出老师数据以及老师所带的学生数据。
struct student
{
    string studenName;
    int score;
};
struct teacher
{
    string teacherName;
    student students[5];
};
int case1()
{
    teacher teachers[3];
    string teacherName = "教师";
    string studentName = "学生";
    string seed = "ABCDE";
    for (int i = 0; i < 3; i++)
    {
        teachers[i].teacherName = teacherName + seed[i];
        for (int j = 0; j < 5; j++)
        {
            teachers[i].students[j].score = rand() % 61 + 40;
            teachers[i].students[j].studenName = studentName + seed[j];
        }
    }

    // 打印数据
    for (int i = 0; i < 3; i++)
    {
        cout << teachers[i].teacherName << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t姓名：" << teachers[i].students[j].studenName << " 分数：" << teachers[i].students[j].score << endl;
        }
    }

    return 0;
}

/*

结构体案例2

设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。

*/

struct hero
{
    string name;
    string sex;
    int age;
};
hero* makeHeros(hero heros[]){ //注意这里要加*，因为是返回英雄数组
    string heroName[5] = {"张飞", "关羽", "刘备", "曹操", "孙权"};
    for (int i = 0; i < 5; i++)
    {
        heros[i].name=heroName[i];
        heros[i].sex="男";
        heros[i].age=rand()%101;
    }
    //rand() % 101; //如果你要产生0~99这100个整数中的一个随机整数，可以表达为：int num = rand()% 100;
    return heros;
}

void bubbleSort(hero * heroArr)
{
    int len = 5;
    for (int i=0;i<len;i++){
        bool flag=false;
        for (int j=i+1;j<len;j++){
            if (heroArr[i].age>heroArr[j].age){
                hero tmp = heroArr[i];
                heroArr[i] = heroArr[j];
                heroArr[j] = tmp;
                flag=true;
            }
        }
        if (not flag){
            break;
        }
    }
}

void printHero(hero * heroArr){
    int len = 5;
    for (int i = 0; i < len; i++){
        cout<<"hero: "<<heroArr[i].name<<", age: "<<heroArr[i].age<<endl;
    }

}

int case2()
{
    hero heros[5];
    makeHeros(heros);
    bubbleSort(heros);
    printHero(heros);
    return 1;
}

int main()
{
    // case1();
    case2();
    return 1;
}