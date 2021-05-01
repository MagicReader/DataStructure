Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e)){
    //采用二叉链表存储结构
    //指针p从根开始，首先沿着左子树向下移动，同时入栈保存
    //左子树为空且栈非空时,退栈访问结点，然后移动到右子树上
    InitStack(S); p = T;
    while (p || !StackEmpty(S)){
        if(p){  //  遍历左子树
            Push(S,p);
            p = p->lchild;
        }else{   //左子树空，退栈访问结点，再遍历右子树
            Pop(S,p);
            if(!visit(p->data)) return ERROR;
            p = p->rchild;
        }      
    }
    return OK;
}

//书上另一种写法
Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e)){
    //采用二叉链表存储结构
    InitStack(S); Push(S,T);    //根指针进栈
    while (!StackEmpty(S)){
        while (GetTop(S, p) && p)   Push(S,p->lchild);  //向左走到尽头
        Pop(S,p);   //空的左子树退栈
        if(!StackEmpty(S)){ //访问结点，转向右子树
            Pop(S, p);
            if(!visit(p->data)) return ERROR;
            Push(S,p->rchild);
        }  
    }
    return OK;
}