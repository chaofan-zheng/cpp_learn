// https://leetcode-cn.com/problems/implement-strstr/
// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = 0;
        if (needle.size()<1){
            return 0;
        }
        for (int i =0; i+needle.size()<=haystack.size(); i++) // 防止越界，内存溢出
        {
            if (haystack[i]==needle[0])  
            {
                bool flag = true;
                for (int j =0; j<needle.size();j++)
                {
                    if (haystack[i+j] != needle[j]){
                        flag = false;
                        break; 
                    }
                }
                if (flag){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    string haystack = "hello", needle = "ll";
    Solution s;
    int res = s.strStr(haystack,needle);
    cout<<res<<endl;
}