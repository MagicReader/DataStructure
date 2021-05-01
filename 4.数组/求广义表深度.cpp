int GlistDepth(GList L){ //递归算法
    //采用头尾链表存储结构，求广义表L的深度
    if(!L) return 1;    //空表深度为1
    if(L->tag == ATOM) return 0;    //原子深度为0
    for(max=0,pp=L; pp; pp=pp->ptr.tp){
        dep = GlistDepth(pp->ptr.hp);   //求以pp->ptr.tp为头指针的子表深度
        if(dep>max) max=dep;
    }
    return max+1;   //非空表的深度是各元素的深度最大值+1
}