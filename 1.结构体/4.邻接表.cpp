#define MAX_VERTEX_NUM 20
typedef struct ArcNode{//表结点
    int adjvex; //该弧所指向的顶点的位置
    struct ArcNode *nextarc;   //指向下一条弧的指针
    InfoType *info; //该弧相关信息的指针
    
};

typedef struct VNode{//头结点
    VertexType data; //顶点信息
    ArcNode *firstarc;   //指向第一条依附于该顶点的弧的指针 
}AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{
    AdjList vertices; //顶点信息
    int vexnum,arcnum;  //图的当前节点数、弧数
    int kind;   //图的种类标志
};