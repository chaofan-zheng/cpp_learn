// https://leetcode-cn.com/problems/search-insert-position/
// 二分查找
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left < right)
        {
            mid = (right +left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        if (nums[left] < target)  //退出的时候一定是重合的。。
        {
            return left + 1;
        }
        else
        {
            return left;
        }
    }
};

int main()
{
    int mid;
    mid = (1 + 2) / 2;
    cout << mid << endl;
    return 0;
}
