Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e)){
    //采用二叉链表存储结构
    //指针p从根开始，首先沿着左子树向下移动，访问结点,同时入栈保存
    //左子树为空且栈非空时,退栈，然后移动到右子树上
    InitStack(S); p = T;
    while (p || !StackEmpty(S)){
        if(p){  //  遍历左子树
            if(!visit(p->data)) return ERROR;
            Push(S,p);
            p = p->lchild;
        }else{   //左子树空，退栈，再遍历右子树
            Pop(S,p);
            p = p->rchild;
        }      
    }
    return OK;
}

//另一个版本(红果研上)：由于访问过的结点可以弃之不用，只要访问其左右子树即可，得到如下算法
Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e)){
    InitStack(S); p = T;
    Push(S, p);
    while (!StackEmpty(S)){
        Pop(S,p);
        if(p){  //  遍历左子树
            if(!visit(p->data)) return ERROR;
            Push(S,p->p->rchild);   //先进栈，后访问，所以先让右子树进栈
            Push(S,p->p->lchild);
        }       
    }
    return OK;
}