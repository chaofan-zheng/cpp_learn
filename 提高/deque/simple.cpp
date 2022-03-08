#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}
void test01()
{
    // 构造
    deque<int> d1;
    for (int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    
}

int main()
{
    return 1;
}