//两种存储队列的方式：  1.链式队列  2.循环队列

//1.链式队列
Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e)){
    //首先将根(头指针)入队列
    //此后,若队列不空则取队头元素p
    //如果p不空，则访问之，然后将其左右子树入队列，如此循环直到队列为空
    InitQueue(Q);   p = T;  EnQueue(Q,p);   //根入队列
    while (!QueueEmpty(Q)){ //若队列不空则继续遍历
        DeQueue(Q, p);
        if(p != NULL){  
            if(!visit(p->data)) return ERROR;
            EnQueue(Q, p->lchild);  //左子树入队列
            EnQueue(Q, p->rchild);  //右子树入队列
        }
    }
}

//2.循环队列
Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e)){
    //数组Queue[] +头尾下标front,rear
    //本算法忽略入队列的条件：入队列前判断是否队满 if(front != (rear+1)%MAXSIZE)
    const int MAXSIZE = 1024;
    BinTree Queue[MAXSIZE];
    int front, rear;
    
    front=rear=0;   //队列初始化
    Queue[rear]=bt; rear=(rear+1)%MAXSIZE;  //根结点入队列
    while(front!=rear){ //队列不空则循环
        p=q[front];
        front = (front+1)%MAXSIZE;
        if(p){
            if(!visit(p->data)) return ERROR;
                Queue[rear]=p->lchild; rear=(rear+1)%MAXSIZE;   //左子树入队列
                Queue[rear]=p->rchild; rear=(rear+1)%MAXSIZE;   //右子树入队列
        }
    }
}
