#include <iostream>
using namespace std;
typedef int ElemType; //定义ElemType为int类型

# define MaxSize 50
typedef struct Sqtack{
    ElemType data[MaxSize];
    int top; //栈顶指
}SqStack;

//初始化
void InitStack(SqStack &s){
    s.top = -1;
}
//判栈空
bool StackEmpty(SqStack &s){
    if(s.top==-1){
        return true;
    }
    else{
        return false;
    }
}
//进栈
bool Push(SqStack &s,ElemType x){
    // 如果栈满，进栈失败
    if (s.top==MaxSize-1){
        return false;
    }
    s.data[++s.top] = x; // 先把指针+1，再赋值
    return true;
}
// 出栈
bool Pop(SqStack &s,ElemType &x){//使用引用调用的方式，获得出栈的返回值
    if (s.top == -1){
        return false;
    }
    x = s.data[s.top--];  //先把赋值，再把指针-1
    return true;
}
// 读栈顶元素
bool GetTop(SqStack &s,ElemType &x){
    if (s.top==-1){
        return false;
    }
    x = s.data[s.top];
    return true;
}
//链栈
typedef struct LinkNode
{
    ElemType data;
    struct 
    {
        LinkNode *next;
    };
    
}*LiStack;

// 用栈实现拓扑排序
bool ToPologicalSort(Graph G){
    InitStack(S);
    for (int i=0;i<G.vexnum;i++){
        if (indegree[i]==0){
            Push(S,i); //将所有入度为0的顶点进栈
        }
    }
    int count = 0;
    while(!IsEmpty(S)){
        Pop(S,i);
        print[count++]=; // 输出顶点i
        for (p=G.vertices[i].firstarc;p;p=p->nextarc){
            // 将所有指向i的顶点的入度-1，并将入度为0的顶点入栈
            v = p->adjvex;
            if (!(--indegree[v])){
                Push(S,v);
            }
        }
    }
    if (count<G.vexnum){
        return false;
    }else{
        return true;
    }
}