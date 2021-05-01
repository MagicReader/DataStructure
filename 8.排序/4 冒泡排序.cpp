void Bubble(int a[],int len){//升序排序
    int i,j,temp;
    for(i = 0;i < len - 1;i++){
        for(j = len - 1;j > i;j--)
            if (a[j] < a[j - 1]){
                temp = a[j - 1];
                a[j -1] = a[j];
                a[j] = temp;
            }
    }
}

int main()
{
    int i;
    int a[] = {11,55,82,10,9,47,56,2,4,85};
    int length;
    length = sizeof(a)/sizeof(a[0]);

    Bubble(a,length);

    for(i = 0;i<length;i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");

    return 0;
}

执行结果：
        2  4  9  10  11  47  55  56  82  85
