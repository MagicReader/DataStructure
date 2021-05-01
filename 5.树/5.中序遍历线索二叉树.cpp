Status InOrderTraverse_Thr(BiThrTree T, Status(*visit)(TElemType e)){
    //采用线索链表BiThrTree（lchild，Ltag，data，Rtag，rchild）存储结构
    //中序遍历序列中第一个结点的lchild和最后一个结点的rchild指向头结点
    //头结点的左链lchild指向根结点，右链rchild指向中序遍历时访问的最后一个结点
    p = T->lchild;  //p指向根结点，T指向头结点
    while (p != T){ //空树或遍历结束时，p==T
            while (p->Ltag==Link)
                p = p->lchild;
            if(!visit(p->data)) return ERROR;   //访问其左子树为空(p-Ltag==Thread)的结点
            while(p->Rtag==Thread && p->rchild!=T){
               p = p->rchild;
               if(!visit(p->data)) return ERROR;
            }
            p = p->rchild;  //结点的后继是遍历其右子树时访问的第一个结点（右子树中最左下的结点）
    }
    return OK;
}