#include <iostream>
using namespace std;
typedef int ElemType;
// 使用栈，去完成非递归的遍历

// 二叉树的定义
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;


# define MaxSize 50
typedef struct Sqtack{
    BiTree data[MaxSize];
    int top; //栈顶指
}SqStack;
bool StackEmpty(SqStack &s){
    if(s.top==-1){
        return true;
    }
    else{
        return false;
    }
}
//栈初始化
void InitStack(SqStack &s){
    s.top = -1;
}
//进栈
bool Push(SqStack &s,BiTree x){
    // 如果栈满，进栈失败
    if (s.top==MaxSize-1){
        return false;
    }
    s.data[++s.top] = x; // 先把指针+1，再赋值
    return true;
}
// 出栈
bool Pop(SqStack &s,BiTree &x){//使用引用调用的方式，获得出栈的返回值
    if (s.top == -1){
        return false;
    }
    x = s.data[s.top--];  //先把赋值，再把指针-1
    return true;
}



void visit(BiTNode *T){ // 访问树节点
    cout<<T->data<<endl;
}

void PreOrder(BiTNode *T){ //前序遍历
    if (T){
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
    }
}

void InOrder(BiTNode *T){ //中序遍历
    if (T){
    PreOrder(T->lchild);
    visit(T);
    PreOrder(T->rchild);
    }
}
void PostOrder(BiTNode *T){ //后序遍历
    if (T){
    PreOrder(T->lchild);
    PreOrder(T->rchild);
    visit(T);
    }
}

void PreOrder2(BiTNode *T){ //中序遍历
    SqStack S;InitStack(S);
    while(T||StackEmpty(S)){
        if(T){
            Push(S,T);
            T=T->lchild;
        }
        else{
            Pop(S,T);
            visit(T);
            T=T->rchild;
        }
    }
}
void PostOrder2(BiTNode *T){ //后序遍历
    SqStack S;InitStack(S);
    BiTNode *recent; // 最近访问过的节点
    while(T||StackEmpty(S)){
        if (T){
            Push(S,T);
            T=T->lchild;
        }
        else{
            T=S.data[S.top]; // 访问栈顶元素
            if (T->rchild && recent!=T->rchild){ // 右孩子存在并且右孩子没有被访问过
                Push(S,T->rchild);
                T=T->rchild->lchild; //转向左孩子
            }
            else{
                Pop(S,T);
                visit(T);
                T=NULL; //防止再进左孩判断
                recent=T; //记录最近访问的节点
            }
        }
    }
}
