Status DeleteBST(BiTree &T, KeyType key){
	//若二叉排序树T中存在关键字等于key的数据元素，则删除该数据元素结点
	//并返回TURE，否则返回FALSE
	if(!T) return FALSE; //根或子树为空, 未找到key，删除失败 
	else {
		if(EQ(key,T->data.key)) return Delete(T); //找到key，进行删除操作 
		else if(LT(key,T->data.key)) return DeleteBST(T->lchild,key); //向右子树查找 
		else return DeleteBST(T->rchild,key); //向左子树查找 
		
	} 
}

Status Delete(BiTree &p){
	//从二叉排序树中删除结点p，并重接它的左子树或右子树
	if(!p->rchild){//右子树空，则只需重接它的左子树 
		q = p; p = p->lchild;free(q);
	} 
	else if(!p->lchild){//左子树空，则只需重接它的右子树 
		q = p; p = p->rchild;free(q);
	}
	else{//左右子树均不空 
		q = p; s = p->lchild;
		while(s->rchild){q=s; s=s->rchild;} //找到p的左子树中最接近p值的s（此时s->rchild==NULL） 
		p->data = s->data; //s的值替换p的值
		if(q!=p) q-rchild = s->lchild; //重接*q的右子树 （p->lchild->rchild！=NULL）
		else q->lchild = s->lchild; //重接*q的左子树 （p->lchild->rchild==NULL） 
	}
	return TRUE; 
}