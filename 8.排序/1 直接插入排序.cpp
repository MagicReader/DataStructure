void InsertSort(SqList &L){
	for(i=2;i<=L.length;++i){
		if(LT(L.r[i].key, L.r[i-1].key)){  //"<"，需将L.r[i]插入有序子表 
			L.r[0] = L.r[i];			   //复制为哨兵 
			L.r[i] = L.r[i-1]; 			   //已在if中比较，先单独拿出交换 
			for(j=i-2;LT(L.r[0].key, L.r[j].key);--j)
				L.r[j+1] = L.r[j];		//记录后移 
			L.r[j+1] = L.r[0];			//插入到正确位置 
		}
	} 
}