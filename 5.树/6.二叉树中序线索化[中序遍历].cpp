Status InOrderThreading(BiThrTree &Thrt, BiThrTree T){
    //采用线索链表BiThrTree（lchild，Ltag，data，Rtag，rchild）存储结构
    //线索化的过程：在遍历的过程中修改空指针，使其指向前驱后继
    //附设全局变量pre指针：始终指向刚刚访问过的结点（若p指向当前访问结点，则pre指向它的前驱）
    if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
    Thrt->LTag=Link; Thrt->RTag=Thread; //建立头结点
    Thrt->rchild = Thrt;    //右指针回指
    if(!T) Thrt->lchild = Thrt; //若二叉树为空，则左指针回指
    else{
        Thrt->lchild = T; pre = Thrt;
        InThreading(T); //中序遍历进行中序线索化
        pre->rchild = Thrt; pre->Rtag = Thread; //最后一个结点线索化
        Thrt->rchild = pre;
    }
    return OK;
}

void InThreading(BiThrTree p){ //类似递归中序遍历二叉树
    if(p){
        InThreading(p->lchild); //左子树线索化
        if(!p->lchild){p->Ltag = Thread;  p->lchild=pre;}   //前驱线索
        if(!pre->rchild){pre->Rtag = Thread;  pre->rchild=p;}   //后继线索
        pre=p;  //保持pre指向p的前驱
        InThreading(p->rchild); //右子树线索化
    }
}