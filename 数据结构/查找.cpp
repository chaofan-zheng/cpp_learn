#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct SeqList
{
    ElemType elem[100];
    int Length;
}SeqList;

//折半查找
int BinarySearch(SeqList l,ElemType key){
    int low=0,high=l.Length-1,mid;
    while (low<=high){
        mid=(low+high)/2;
        if (l.elem[mid]==key){
            return mid;
        }
        else if (l.elem[mid]<key){
            low=mid-1; // 加一减一别忘了
        }
        else{
            high=mid+1;
        }
    }
    return -1; // 找不着也别忘了
}
