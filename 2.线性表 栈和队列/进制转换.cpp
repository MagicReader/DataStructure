//原理 ： N = (N div d) * d + N mod d   （N从10进制转为d进制
void conversion(int d){
    InitStack(S);
    scanf("%d",N);
    while(N){
        Push(S, N%d);
        N = N/d;
    }
    while(!StackEmpty(S)){
        Pop(S,e);
        printf("%d",e);
    }
}