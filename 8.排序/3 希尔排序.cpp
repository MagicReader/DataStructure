void ShellInsertSqList(&L, int dk){ //一趟希尔插入排序 
	for(i=dk+1;i<=L.length;++i)	//统筹兼顾，使[dk+1..L.length]每个元素单例化为一次插入排序
		if(LT(L.r[i].key, L.r[i-dk].key)){ //"<"，需将L.r[i]插入到有序增量子表 
			L.r[0] = L.r[i]; //r[0]只是暂存单元，不是哨兵（区别与直接插入排序） 
			for(j=i-dk; j>0&&LT(L.r[0].key, L.r[j].key); j-=dk)
				L.r[j+dk] = L.r[j];	//记录后移 
			L.r[j+dk] = L.r[0];	//插入正确位置 
		}
}

void ShellSort(SqList &L, int dlta[], int t){ //按增量序列dlta[0...t-1]对顺序表L作希尔排序
	for(k=0;k<t;++k)	//排序趟数：t=log2(n+1)向下取整 
		ShellInsertSqList(L, dlta[k]);  
} 