#define INFINITY INT_MAX //最大值∞
#define MAX_VERTEX_NUM 20   //最大顶点个数
typedef enum {DG,DN,UDG,UDN} GraphKind; //｛有向图，有向网，无向图，无向网｝
typedef struct ArcCell{
    VRType adj; //VRType 是顶点关系类型、对无权图，用1或0表示相邻否；对带权图，则为权值类型
    InfoType *info; //该弧相关信息的指针
}AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct MGraph {
    VertexType vexs[MAX_VERTEX_NUM];    //顶点向量
    AdjMatrix arcs; //邻接矩阵
    int vexnum，arcnum; //图的当前顶点数和弧数
    GraphKind kind; //图的种类标志
};
