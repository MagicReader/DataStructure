void BinaryInsertSort(SqList &L){
	for(i=2;i<=L.length;++i){
		L.r[0] = L.r[i];  
		low = 1;	high = i-1;
		while(low<=high){
			mid = (low+high)/2;
			if(LT(L.r[0].key, L.r[mid].key)) high = m-1;
			else low = m+1;								   
		}
		for(j=i-1;j>=high+1;--j) L.r[j+1] = L.r[j]	
		L.r[high+1] = L.r[0] 	//low=high+1 为待插入点与待插入值最接近的偏大点
		//例子：113452->112345 low/high=1/5、1/2、2/2、3/2
		//例子：122342*->1222*34 low/high=1/5、4/5、4/3
	}
}
