Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e)){
    //采用二叉链表存储结构
    //后序遍历时，分别从左子树和右子树共两次返回根结点，只有从右子树返回时才访问根结点
    //因此 增加一个栈用于标记到达结点的次序
    InitStack(S); InitStack(Tag);
    p = T;
    while (p || !StackEmpty(S)){
        if(p){  //  遍历左子树
            Push(S,p);
            Push(Tag, 1); //第一次入栈
            p = p->lchild;
        }   
        else{   //左子树空，退栈，查看标记栈顶的值  t=1:再遍历右子树 / t=2:访问当前结点,继续退栈
            Pop(S,p);   Pop(Tag, t);
            if(t == 1){ //从左子树返回，二次入栈，然后p转向右子树
                Push(S, p);
                Push(Tag, 2);
                p = p->rchild;
            }else{//从右子树返回，二次出栈, 访问结点，移动到父结点
                if(!visit(p->data)) return ERROR;
                p = NULL;   //必要操作，使下一步继续退栈，从而移动到父结点
            }
        }      
    }
    return OK;
}