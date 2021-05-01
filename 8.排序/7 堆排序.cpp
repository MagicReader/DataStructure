typedef SqList HeapType; //采用顺序表存储表示 堆 

void HeapAdjust(SqList &H,int s,int m){
	//已知H.r[s...m]中记录的关键字除H.r[s].key之外均满足堆的定义
	//本函数调整H.r[s]的关键字，使H.r[s...m]成为一个大顶堆（对其中记录的关键字而言）
	rc = H.r[s];
	for(j=2*s; j<=m; j*=2){	//沿key较大的孩子结点向下筛选 
		if(j<m && LT(H.r[j].key, H.r[j+1].key)) ++j; //左右子结点间比较大小，j为key较大的记录的下标 
		if(!LT(rc.key, H.r[j].key)) break;	//父节点>=左右子结点，则rc应插入在当前位置s上 
		H.r[s] = H.r[j];	 //父节点<左右子结点之一，结点上移 
		s = j;	//向下继续调整 
	}
	H.r[s] = rc;
} 

void HeapSort(HeapType &H){
	//对顺序表H进行堆排序（大顶堆->升序, 小顶堆->降序） 
	for(i=H.length/2; i>0; --j)		//把H.r[1..H.length]建成大顶堆  O(n) 
		HeapAdjust(H,i,H.length);
	for(i=H.length; i>1; --j){
		swap(H.r[1], H.r[i]);  //将堆顶记录和当前未经排序的子序列H.r[1..i]中最后一个记录互换
		HeapAdjust(H, 1, i-1);  //将H.r[1.i-1]重新调整为大顶堆 
	}
} 