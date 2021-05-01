Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T){
    //采用三元组顺序表存储，求稀疏矩阵M的转置矩阵T
    T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
    if(T.tu){
        for(col=1;col<=M.nu;++col)  num[col]=0;
        for(t=1;t<=M.tu;++t) ++num[M.data[t].j];    //num[col]表示M中第col列含非零元个数
        //copt指示M中第col列的第一个非零元在T.data中的恰当位置
        cpot[1]=1;
        for(col=2;col<=M.nu;++col)  cpot[col]=cpot[col-1]+num[col-1]; 
        for(p=1;p<=M.tu;++p){
            col=M.data[p].j; q=copt[col];  //q为M.data[p]在新三元组的对应下标
            T.data[q].i = M.data[p].j;  T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e; 
            ++cpot[col];
        }
    }
}