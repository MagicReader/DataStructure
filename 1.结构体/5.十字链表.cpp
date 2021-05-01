#define MAX_VERTEX_NUM 20
typedef struct ArcBox{//弧结点（tailvex headvex hlink tlink info）
    int tailvex,headvex; //该弧的尾和头顶点的位置
    struct ArcBox *hlink,*tlink;   //分别为弧头相同和弧尾相同的弧的链域
    InfoType *info; //该弧相关信息的指针
};

typedef struct VexNode{ //顶点结点（data，firstin，firstout）
    VertexType data;    //顶点信息
    ArcBox *firstin,*firstout;   //分别指向该顶点第一条入弧和出弧 
}AdjList[MAX_VERTEX_NUM];

typedef struct OLGraph{
    AdjList xlist[MAX_VERTEX_NUM]; //表头向量
    int vexnum,arcnum;  //有向图的当前顶点第一条入弧和出弧
};