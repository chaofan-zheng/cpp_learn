// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
#include<iostream>
#include<vector>
#include <cassert>

using namespace std;

void printVector(vector<int>& v) {

	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<2)
        {
            return nums.size();
        }

        vector<int>::const_iterator pre = nums.end();
        for (vector<int>::reverse_iterator iter = nums.rbegin()+1;iter!=nums.rend();iter++) // 正向遍历是不行的
        {
            if (*pre == *iter)
            {
                nums.erase(pre);
            }
            pre = iter; 
        }

        return nums.size();
    }
};


int main()
{
    int nums[] = {1,1}; // 输入数组
    int expectedNums[] = {1}; // 长度正确的期望答案
    int lenofExpectedNums = sizeof(expectedNums)/sizeof(int);
    Solution s;
    vector<int> v1(nums,nums+sizeof(nums)/sizeof(int)); //数组 转换成 vector
    printVector(v1);
    int k = s.removeDuplicates(v1); // 调用
    printVector(v1);
    assert (k == lenofExpectedNums);
    for (int i = 0; i < k; i++) {
        assert (v1[i] == expectedNums[i]);
    }


    return 0;
}
