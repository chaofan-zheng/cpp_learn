#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void test()
{
    vector<int> v;
    for (int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    for (vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }

}
int main()
{
    test();
}