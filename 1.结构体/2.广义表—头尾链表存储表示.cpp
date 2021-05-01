//----广义表的头尾链表表示----
typedef enum{ATOM, LIST}ElemTag;    //ATOM=0：原子，LIST=1：子表
typedef struct GLNode{
    ElemTag tag;    //公共部分，用于区分原子结点和表结点
    union {
        AtomType atom;  //atom是原子结点的值域，AtomType由用户定义（int、char...）
        struct {struct GLNode *hp,*tp;}ptr; //ptr是表结点的指针域，ptr.hp和ptr.tp分别指向表头和表尾
    };
}*GList;        //广义表类型
