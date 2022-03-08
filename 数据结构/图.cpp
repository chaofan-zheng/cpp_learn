#include <iostream>
using namespace std;

//邻接矩阵法
#define MaxVertexNum 100
typedef char VertexType; //定义节点的数据类型
typedef int EdgeType;  //定义边，表示权重
typedef struct MGraph
{
    VertexType Vex[MaxVertexNum]; // 顶点表，通过坐标对应到顶点值
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵，边表
    int vexnum,arcnum; // 图的顶点数和边数
}MGraph;
