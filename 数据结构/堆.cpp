#include <iostream>
using namespace std;
typedef int ElemType;

struct HeapStruct{
    int Capacity;
    int Size;
    ElemType *Elements;
};
typedef HeapStruct *PriorityQueue;
// 堆的初始化
PriorityQueue Initialize(int MaxElements){
    PriorityQueue H = (PriorityQueue)malloc(sizeof(HeapStruct));
    if (H==NULL){
        throw("Out of Space!");
    }
    H->Elements = (ElemType*)malloc(sizeof(MaxElements));
    if (H->Elements==NULL){
        throw("Out of Space!");
    }
    return H;
}

// 堆的插入 H->Elements[0]为哨兵
void HeapInsert(ElemType x,PriorityQueue H){
    int i;
    for (i=H->Size;H->Elements[i/2]>x;i=i/2){
        H->Elements[i] = H->Elements[i/2]; // 将父元素换下来
    }
    H->Elements[i] = x;
}

//堆的删除
ElemType DeleteMin(PriorityQueue H){
    int i ,child;
    ElemType MinElement = H->Elements[1];
    ElemType LastElement = H->Elements[H->Size--];
    for (i=1;i*2<=H->Size;i=child){
        // 找到最小的孩子
        child = i*2;
        if (child!=H->Size&&H->Elements[child+1]<H->Elements[child]) 
        // 不是没有右孩子的情况
            child++;
        if (LastElement > H->Elements[child]){
            // 下去
            H->Elements[i]=H->Elements[child];
        }else{
            break;
        }
    }
    H->Elements[i]=LastElement;
    return MinElement;

}