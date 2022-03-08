#include <iostream>
using namespace std;
typedef int ElemType;


// 直接插入排序
void InsertSort(ElemType li[],int n){
    int i,j;
    ElemType sentry;
    for (i=1;i<n;i++){ // 迭代每一个要插入的元素
        if (li[i-1]>li[i]){ // 如果前一个元素比后一个元素大，说明失序，需要插入
            sentry = li[i]; // 存储要插入的元素
            for (j=i-1;j>=0&&li[j]>sentry;j--){  //注意j--和--j的区别，
                // 从后往前遍历，当遍历到j的值不再大于i的值的时候说明找到插入位置了
                li[j+1] = li[j]; //往后移动
            }
            li[j+1] = sentry; //插入
        }
    }
}



// 希尔排序
void ShellSort(ElemType li[],int n){
    int step = n/2;
    int num; // 暂存变量
    int j;
    while (step>=1){ //当step为1时，已经基本有序
        for (int i =step;i<n;i++){ //遍历同一个步长上的元素
            if (li[i]<li[i-step]){
                num = li[i]; // 待插入的值
                for (j=i-step;j>0&&li[j]>num;j=j-step){ // 往前找地方插入
                    li[j+step] = li[j]; 
                }
                li[j+step] = num;
            }
        }
        step = step/2;
    }

}
//冒泡排序
void BubbleSort(ElemType li[],int n){
    int num; // 用作交换存储
    for (int i=0;i<n-1;i++){
        bool flag = false;
        // 可以增加一个标志，如果一趟遍历一次交换都没有发生，说明已经有序，就不用在比较了
        for (int j =1;j<n-i;j++){
            if (li[j-1]>li[j]){ //把大的顶上去做交换
                num = li[j-1];
                li[j-1] = li[j];
                li[j] = num;
                flag = true;
            }
        }
        if (!flag){
            return;
        }
    }
}

void aaaa(int A[],int low,int high){
    if (low>=high) return;
    int left = low;
    int right = high;
    int x;
    while (right>left){
        while (right>left&&A[right]>=A[low]){
            right--;
        }
        while (right>left&&A[left]<=A[low]){
            left++;
        }
        if (A[left]>A[right]){
            x = A[left];
            A[left]=A[right];
            A[right]=x;
        }
    }
    x=A[left];
    A[left] = A[low];
    A[low]=x;
    aaaa(A,low,left-1);
    aaaa(A,left+1,high);
}

void QuickSort(ElemType li[],int low,int high){
    if (high-low <=0) return;
    // 划分操作,找到枢轴应该在列表中的位置，默认low为枢轴
    int i = low,j= high;
    ElemType pivot = li[low];
    ElemType num;
    while(i<j){ // 当两个哨兵相遇的时候，说明这个位置就是pivot应该在的位置
        while(i<j&&li[j]>=pivot){ // 右哨兵向左探测，遇到比pivot小的元素停住
            j=j-1; // 一定是右哨兵先动再左哨兵动，因为最后是赋值给low所在的位置
        }
        while(i<j&&li[i]<=pivot){ // 左哨兵向右探测，遇到比pivot大的元素停住
            i=i+1;
        }
        //左右哨兵都停住的时候两元素交换
        num = li[i];li[i]=li[j];li[j]=num;
    }
    // 基数位置交换
    li[low] = li[i];
    li[i] = pivot;
    
    //递归左右进行
    QuickSort(li,low,i-1);
    QuickSort(li,i+1,high);

}

// 简单选择排序
void SelectSort(ElemType li [],int n){
    for (int i=0;i<n-1;i++){ //共进行n-1趟
        int min =i;
        for (int j=i;j<n;j++){
            if (li[j]<li[min]){
                min = j;
            }
        }
        if (min !=i){
            // 交换
            ElemType num = li[i];
            li[i] = li[min];
            li[min] = num;
        }
    }
}

void Merge(ElemType li[],int low,int mid, int high){
    // 列表li[low:mid],li[mid+1:high] 各自有序，将其合并成一个有序列表
    ElemType *NewLi = (ElemType *)malloc((high-low+1)*sizeof(ElemType));
    int i = low,j=mid+1; int cur = 0;
    while (i!=mid+1 && j!=high+1){
        if (li[i]<li[j]){ // 较小的那个先进列表
            NewLi[cur] = li[i];
            i++;
            cur++;
        }
        else{
            NewLi[cur] = li[j];
            j++;
            cur++;
        }
    }
    if (cur<=high-low){
        while(i<mid+1){
            NewLi[cur] = li[i];
            cur++;
            i++;
        }
        while(j<high+1){
            NewLi[cur] = li[j];
            cur++;
            j++;
        }
    }
    for (int k=0;k<cur;k++){
        li[low+k] = NewLi[k];
    }
}

void MergeSort(ElemType li[],int low, int high){
    if (low>=high)return;
    int mid = (low+high)/2;
    MergeSort(li,low,mid);
    MergeSort(li,mid+1,high);
    Merge(li,low,mid,high);
}

void Solution(int R,int n,int p){
    int *A;
    A=(int*)malloc(sizeof(int));
}


int main()
{
    ElemType li [] ={3,56,21,2143,4,31,56};
    // ShellSort(li,7);
    // MergeSort(li,0,6);
    // BubbleSort(li,7);
    aaaa(li,0,6);
    // QuickSort(li,0,6);
    int i;
    for (i = 0;i<7;i++){
        cout<<li[i]<<endl;
    }
    cout<<i<<endl;
    return 0;

}
