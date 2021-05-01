//1.稀疏矩阵的三元组顺序表存储表示
#define MAXSIZE 12500   //假设非零元个数的最大值为12500
typedef struct{
    int i,j;    //该非零元的行下标和列下标
    ElemType e;
}Triple;
typedef struct TSMatrix{    //非零元三元组表，data[0]未用
    Triple data[MAXSIZE+1];  //非零元三元组表
    int mu,nu,tu;   //矩阵的行数、列数、非零元个数
};


//2.行逻辑连接的顺序表（便于随机存取任意一行的非零元）
typedef struct RLSMatrix{
    Triple data[MAXSIZE+1];  //非零元三元组表
    int rpos[MAXRC+1];  //各行第一个非零元的位置数
    int mu,nu,tu;   //矩阵的行数、列数、非零元个数
};

//3.稀疏矩阵的十字链表存储表示
typedef struct OLNode{
    int i,j; //非零元的行和列下标
    ElemType   e;
    struct OLNode   *right,*down; //该非零元所在行表和列表的后继链域 
}*OLink;

typedef struct CrossList{
    Olink   *rhead,*chead;  //行（rhead）和列（chead）链表表头指针向量
    int mu,nu,tu;   //稀疏矩阵的行数、列数、非零元个数
};
//行和列链表表头指针向量基址由CreateSMatrix分配
//M.rhead = (OLink*) malloc ((m+1)*sizeof(OLink))
//M.chead = (OLink*) malloc ((n+1)*sizeof(OLink))
//M.rhead[]=M.chead[]=NULL; //初始化为空链表