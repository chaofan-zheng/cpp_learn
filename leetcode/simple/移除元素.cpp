// https://leetcode-cn.com/problems/remove-element/
#include <iostream>
#include <vector>

using namespace std;

/*
双指针，
如果v[i]!=val -> j++,i++; 如果不是同一个位置，交换
如果v[i]==val ->i++

*/
class MySolution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i=0, j = 0;
        int tmp;
        while (i < nums.size())
        {
            if (nums[i] == val)
            {
                i++;
            }
            else
            {
                if (i != j)
                {
                    tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
                i++;
                j++;
            }
        }
        return j;
    }
};
//答案：
/*
思路：
我们可以把输出的数组直接写在输入数组上。可以使用双指针：右指针 right 指向当前将要处理的元素，左指针 left 指向下一个将要赋值的位置。

如果右指针指向的元素不等于val，它一定是输出数组的一个元素，我们就将右指针指向的元素复制到左指针位置，然后将左右指针同时右移；

如果右指针指向的元素等于val，它不能在输出数组里，此时左指针不动，右指针右移一位。
当左右指针遍历完输入数组以后，\textit{left}left 的值就是输出数组的长度。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/remove-element/solution/yi-chu-yuan-su-by-leetcode-solution-svxi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};


int main()
{
    Solution s;
    vector<int> nums;
    int a[] = {0, 1, 2, 2, 3, 0, 4, 2};
    nums.assign(a, a + sizeof(a) / sizeof(int));
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    int res = s.removeElement(nums, 2);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << res << endl;
    return -1;
}