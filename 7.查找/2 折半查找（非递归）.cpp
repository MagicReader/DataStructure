int BinarySearch(DataType a[],int n,DataType x){
	low = 0;high = n-1;
	while(low <= high){
		mid = (low+high)/2;
		if(a[mid] == x)
			return mid; //找到x,返回位置 
		else if(x < a[mid])
			high = mid-1; //低半区[low,mid-1] 
		else
			low = mid+1; //高半区[mid+1,high]
	}
	return -1; //未找到，返回-1 
} 