#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;  
}ThreadNode,*ThreadTree;

// 中序遍历构建线索二叉树
void InThread(ThreadTree &p,ThreadTree &pre){
    if (p!=NULL){
        InThread(p->lchild,pre);
        if (p->lchild==NULL){
            p->lchild=pre;
            p->ltag=1;
        }
        if (p->rchild==NULL){
            pre->rchild=p;
            pre->rtag=1;
        }
        pre = p;
        InThread(p->rchild,pre);
    }
}

void CreateInThread(ThreadTree T){
    ThreadTree pre = NULL;
    if (T!=NULL){
        InThread(T,pre);
        pre->rchild=NULL;//处理最后一个节点
        pre->rtag = 1;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
void visit(ThreadNode *P){
    cout<<P->data<<endl;
}
// 中序二叉树的遍历
ThreadNode *FirstNode(ThreadNode *P){
    if (P){
        while(P->ltag==0){
            P=P->lchild;
        }
    }
    return P;
}
void InOrder(ThreadNode *P){
    ThreadNode *first_node = FirstNode(P);
    visit(P);
    while(true){
        if (P->rtag==0){
            P=FirstNode(P->rchild);
        }else if ((P->rtag=1) && P->rchild!=NULL)
        {
            P=P->rchild;
        }else
        {
            break;
        }
        visit(P);
    }
}
struct BiTree
{
    int a;
};
 typedef int KeyType;
struct BSTNode
{
    int b;
};

// 二叉排序树的插入
int BST_Insert(BiTree *T,KeyType k){
    if (T==NULL){
        T = (BiTree*)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild=NULL;
        return 1;
    }
    else if(T->key<k){ //如果T的值比目标k小，向右走
        return BST_Insert(T->rchild);
    }
    else if(T->key>k){
        return BST_Insert(T->lchild);
    }
    else{
        return 0; //返回0，表示插入不成功
    }
}