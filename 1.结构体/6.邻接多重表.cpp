#define MAX_VERTEX_NUM 20
typedef enum{unvisited,visited} VisitIf;

typedef struct EBox{//弧结点（mark ivex ilink jvex jlink info）
    VisitIf mark;   //访问标记
    int ivex,jvex;  //该边依附的两个顶点的位置
    struct EBox *ilink,*jlink; //分别指向边依附这两个顶点的下一条边
    InfoType *info; //该弧相关信息的指针
};

typedef struct VexBox{ //顶点结点（data，firstedge）
    VertexType data;    //顶点信息
    ArcBox *firstedge;   //分别指向该顶点第一条入弧和出弧
};

typedef struct AMLGraph{
    AdjList xlist[MAX_VERTEX_NUM]; //表头向量
    int vexnum,arcnum;  //有向图的当前顶点第一条入弧和出弧
};