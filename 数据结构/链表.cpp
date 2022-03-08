#include <iostream>
using namespace std;
typedef int ElemType; //定义ElemType为int类型
typedef struct LNode{
    ElemType data; // 标准的变量定义，数据域
    struct 
    {
        LNode *next; // 指针域
    };
}LNode,*LinkList; 
// 声明一个或多个结构变量，这是可选的。 LNode 是 LNode类型的变量，LinkList是指向LNode类型的指针

// 头插法*逆向*建立单链表
LinkList List_HeadInsert(LinkList &L){
    LNode *s;int x;
    L = (LinkList)malloc(sizeof(LNode)); //创建头结点 (有头结点的版本)
    // L = new LinkList;
    L->next=NULL; // -> 访问结构指针对应结构成员
    scanf("%d",&x); //用引用的方式去拿到节点的值
    while (x!=9999){
        s=(LNode*)malloc(sizeof(LNode)); //创建新结点
        s->data = x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
// 尾插法*正向*建立单链表
LinkList List_TailInsert(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode)); //创建头结点 (有头结点的版本) L是头结点的地址
    //     cout<<L;
    LNode *s; //指向节点的指针
    LNode *cur = L; // 
    // cout<<cur;//得到的结果跟L是一样的，内存地址
    int x; //插入元素的数据类型
    scanf("%d",&x);
    while (x!=9999) //用9999标志结束插入
    {
        s = (LNode*)malloc(sizeof(LNode));
        // cout<<s; // 是一个地址
        s->data = x;
        s->next = NULL; //下一个节点指针置空
        cur->next=s;
        cur = s;
    }
    return L;
}

// 按序号查找结点值
//在单链表中，从第一个结点出发，顺指针next逐个往下搜索，直到找到第i个节点位置，否则返回最后一个节点的指针域NULL
LNode *Get_By_Index(LinkList &L,int i){ // *表示返回类型是指针
    int count =1;
    LNode *s = L->next;
    if (i==0){
        return L;
    }
    if (i<0){
        return NULL;
    }
    while(s&&count<i){
        count++;
        s=s->next;
    }
    return s;   
}
// 按照值查找节点
LNode *Get_By_Value(LinkList &L,ElemType e){ // *表示返回类型是指针
    LNode *s = L->next;
    while(s->data!=e&&s){
        s=s->next;
    }
    return s;   
}
// 插入节点
bool ListNode_Insert(LinkList &L,ElemType e, int i){ // 在第i个节点，插入元素e(即在i-1的节点之后插入一个新节点)
    LNode *s = L->next;
    int j = 1; // 表示这个是第几个循环
    while (s&&j<i-1){
        j++;
        s=s->next;
    }
    if (!s){
        return false;
    }
    LNode *new_node;
    new_node->data=e;
    new_node->next=s->next;
    s->next=new_node;
    return true;
}

int main(){
    LinkList L;
    List_TailInsert(L);
}

// 声明双链表
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next; //前驱指针和后继指针。
}DNode,*DLinkList;

// 静态链表结构定义
# define MaxSize 50
typedef struct StaticLinkList{
    ElemType data[MaxSize];
    int next; // 下一个元素的数组下标
}StaticLinkList;
