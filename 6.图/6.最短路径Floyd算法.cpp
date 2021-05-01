void ShortestPath_FLOYD(MGraph G,PathMatrix &P, DistanceMatrix &D){
    //用Floyd算法求有向图G对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w]
    //若P[v][w][u]为TRUE，则 u是v到w当前求得最短路径上的顶点
    for(v=0; v<G.vexnum; ++v)   //初始化 各对结点之间已知路径及距离
        for(w=0; w<G.vexnum; ++w){
            D[v][w] = G.arcs[v][w];
            for(u=0; u<G.vexnum; ++u) P[v][w][u]=FALSE;
            if(D[v][w]<INFINITY){   //从v到w有直接路径
                P[v][w][v] = TRUE;  P[v][w][w] = TRUE;
            }
        }
    
    for(u=0; u<G.vexnum; ++u)   //总共G.vexnum轮调整
        for(v=0; v<G.vexnum; ++v)
            for(w=0; w<G.vexnum; ++w)
                if(D[v][u]+D[u][w] < D[v][w]){  //从v经u到w的一条路径更短
                    D[v][w] = D[v][u]+D[u][w];
                    for(i=0; i<G.vexnum; ++i)
                        P[v][w][i] = P[v][u][i] || P[u][w][i]; //更新当前最短路径v到w经过的点
                }
}//(较长路径v..s..q...w中间经过顶点的具体走向由较短路径例如v..s、s..q、q...w确定)[递归查询]