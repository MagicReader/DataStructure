int BinarySearch(DataType a[], int low,int high,DataType x){
	if(low>high)
		return -1; //未找到 
	mid = (low+high)/2;
	if(a[mid] == x)
		return x; //找到 
	else if(x<a[mid])
		return BinarySearch(a,low,mid-1,x); //低半区[low,mid-1] 
	else
		return BinarySearch(a,mid+1,high,x); //高半区[mid+1,high]
} 

main(){
	index_x = BinarySearch(a,0,a.length,x);
}