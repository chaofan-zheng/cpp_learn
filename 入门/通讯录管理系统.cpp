#include <iostream>
using namespace std;
#include <string>

// 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
// 显示联系人：显示通讯录中所有联系人信息
// 删除联系人：按照姓名进行删除指定联系人
// 查找联系人：按照姓名查看指定联系人信息
// 修改联系人：按照姓名重新修改指定联系人
// 清空联系人：清空通讯录中所有信息
// 退出通讯录：退出当前使用的通讯录

// 显示菜单
void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

struct Person
{
    string m_Name;  //姓名
    int m_Sex;      //性别：1男 2女
    int m_Age;      //年龄
    string m_Phone; //电话
    string m_Addr;  //住址
};                  // struct 结构体后面得需要有分号

#define Max 1000
struct Addressbooks
{
    struct Person personArray[Max];
    int m_Size;
};

void addPerson(Addressbooks *abs)
{
    if (abs->m_Size == Max)
    {
        cout << "通讯录满了" << endl;
    }
    string name;
    cout << "请输入姓名" << endl;
    cin >> name;
    abs->personArray[abs->m_Size].m_Name = name;

    int sex;
    while (true)
    {
        cout << "请输入性别" << endl;
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            abs->personArray[abs->m_Size].m_Sex = sex;
            break;
        }
        else
        {
            cout << "必须输入0或者1" << endl;
        }
    }
    //年龄
    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    abs->personArray[abs->m_Size].m_Age = age;

    //联系电话
    cout << "请输入联系电话：" << endl;
    string phone = "";
    cin >> phone;
    abs->personArray[abs->m_Size].m_Phone = phone;

    //家庭住址
    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    abs->personArray[abs->m_Size].m_Addr = address;

    //更新通讯录人数
    abs->m_Size++;

    cout << "添加成功" << endl;
    system("pause");
    system("cls");
}

int main()
{
    // 初始化通讯录
    Addressbooks abs;
    abs.m_Size = 0;

    int select = 0;
    while (true)
    {
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1: // 添加联系人
            addPerson(&abs);
            break;
        case 2: // 显示联系人
            break;
        case 3: // 删除联系人
            break;
        case 4: //查找联系人
            break;
        case 5: //修改联系人
            break;
        case 6: //清空联系人
            break;
        case 0: //退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
