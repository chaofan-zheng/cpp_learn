#include <iostream>
using namespace std;

// 快速排序
int sort(int li[],int start, int end,int n){
    int pivot,num;
    int left = start,right = end;
    pivot = li[start];
    while (left<right)
    {
        while(left<right&& pivot<=li[right]) // 先移动右边哨兵
            right--;
        while(left<right&& pivot>=li[left])
            left++;
        if(left>right){
            num = li[left];li[left]=li[right];li[right]=num;
        }
    }
    li[start]=li[left];
    li[left]=pivot;
    if (left == n/2) return left;
    else if (left<n/2) sort(li,left+1,end,n);
    else sort(li,start,left-1,n);

}