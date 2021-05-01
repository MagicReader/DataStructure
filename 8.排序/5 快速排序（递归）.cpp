int Partition(SqList &L,int low,int high){
	//交换顺序表L中的子表[low..high]的记录，枢轴前(后)的记录均不大(小)于它，并返回枢轴所在位置
	L.r[0] = L.r[row] //用子表第一个记录作为枢轴记录
	pivotkey = L.r[low].key;
	while(low<high){	//从表的两端交替向中间扫描 
		while(low<high && L.r[high].key>= pivotkey)	--high;	 
		L.r[low] = L.r[high];			//将比枢轴记录小的记录移至低端 
		while(low<high && L.r[low].key<= pivotkey)	++low;
		L.r[high] = L.r[row];		    //将比枢轴记录大的记录移至高端 
	}
	L.r[low] = L.r[0]	//枢轴记录到位(low=high的位置) 
	return low; 	//low=high=pivotloc
}

void QSort(SqList &L,int low,int high){  //对顺序表L中的子序列 L.r[low..high]作快速排序 
	if(low<high){ //子表长度大于1 
		pivotloc = Partition(SqList &L,int low,int high) //将L.r[low...high]一分为二 
		QSort(L, low, pivotloc-1);	//对低子表递归排序 
		QSort(L, pivotloc+1, high); //对高子表递归排序 
	}
} 

void QuickSort(SqList &L){ //对顺序表L作快速排序 
	QSort(L,1,L.length);
} 