#include <iostream>
using namespace std;
typedef int ElemType; //定义ElemType为int类型

// 顺序队列
# define MaxSize 50
typedef struct SqQueue
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

//链队
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
    LinkNode *front,*rear;    
}LinkQueue;

// 链队初始化
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode)); // 初始化头结点
    Q.front->next=NULL; //指定一个就好了，因为此时Q.front 和 Q.rear的地址是相同的。
}
//判队空
bool IsEmpty(LinkQueue &Q){
    if (Q.front==Q.rear){
        return true;
    }else return false;
}
//入队
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode)); // 为s新动态分配内存
    s->data = x;
    s->next=NULL;
    Q.rear->next = s;
    Q.rear = s;
}
// 出队
bool DeQueue(LinkQueue &Q,ElemType &x){
    if (Q.front==Q.rear){
        return false;
    }
    LinkNode *p = Q.front->next; // 因为存在为空的头结点 
    x = p->data; //将引用x返回出去
    Q.front->next = p->next;
    if (p == Q.rear){ //或者Q.front.next = NULL
        // 队列中原先只有一个一个元素,
        Q.rear = Q.front;
    }
    free(p);
    return true;
}


int main(){
    LinkQueue Q;
    InitQueue(Q);
    cout<<Q.front<<endl;
    cout<<Q.rear<<endl;
}