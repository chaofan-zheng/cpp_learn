#include <iostream>
using namespace std;

typedef struct{
    int * data;
    int MaxSize,length;
}Seqlist;
void InitSeqList(int MaxSize){
    Seqlist l;
    l.data = (int*)malloc(sizeof(int)*MaxSize);
    if (l.data==NULL){
        throw("Out of Space!");
    }
    l.MaxSize =MaxSize;
    l.length=0;

}

bool ListInsert(Seqlist &L, int i, int e){ // 在线性表的第i个位置插入数据
    if (i<1||i>L.length+1) //判断插入的数据是否合法
        return false;
    if (L.length>=L.MaxSize)
        return false;
    for (int j=L.length;j>=i;j--) // 从后往前，i之后的所有指针全部往后移一个。从L的length开始
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}

//-----------------链表---------------------------------

typedef int ElemType; //定义ElemType为int类型
typedef struct LNode{
    ElemType data; // 标准的变量定义，数据域
    struct LNode *next; // 指针域
}LNode; 
// 声明一个或多个结构变量，这是可选的。 LNode 是 LNode类型的变量，LinkList是指向LNode类型的指针

// 头插法把数组转为链表
LNode* InitLinkList(int *A,int n){
    LNode* Head;
    Head=(LNode*)malloc(sizeof(int));
    if (Head==NULL) throw("Out of Space!");
    Head->next=NULL;
    for (int i=n-1;i>=0;i--){
        LNode *s = (LNode*)malloc(sizeof(int));
        if (s==NULL)throw("Out of Space!");
        s->data=A[i];
        s->next=Head;
        Head=s;
    }
    return Head;
}

bool LinkListInsert(LNode *Head,int i,int e){
    LNode* node= Head;
    int j=0;
    while(node && j<i){
        node=node->next;
        j++;
    }//j=i-1
    if (!node)return false;


    return true;
}
#define MaxSize 50
typedef struct Sqtack{
    ElemType data[MaxSize];
    int top; //栈顶指
}SqStack;

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

//初始化
void InitStack(SqStack &s){
    s.top = -1;
}

int Fib(int n){
    SqStack Stack;
    int b,a,x;
    Stack.top=-1;
    Push(Stack,0);
    Push(Stack,1);
    for (int i=1;i<n;i++){
        Pop(Stack,a);
        Pop(Stack,b);
        Push(Stack,a);
        Push(Stack,a+b);
    }
    Pop(Stack,x);
    return x;
}
int main(){
    int n=5;
    int x=Fib(n);
    cout<<x;
}