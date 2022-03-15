#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int targetNum = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == targetNum)
                {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
    }
};
// 方法二
class Solution2
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        map<int,int> indexMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (indexMap.count(target-nums[i])>0)
            {
                v.push_back(i);
                v.push_back(indexMap[target-nums[i]]);
                break;
            }
            indexMap[nums[i]]=i;
        }
        return v;
    }
};