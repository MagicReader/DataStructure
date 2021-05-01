void ShortestPath_Dijkstra(MGraph G, int v0, PathMatrix &P, DistanceMatrix &D){
    //用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径P[v][w]及带权长度D[v]
    //若P[v][w]为TRUE,则w是从v0到v当前求得最短路径上的顶点
    //final[v]为TRUE 当且仅当 v∈S，即已经求得从v0到v的最短路径
    for(v=0; v<G.vexnum; ++v){  //初始化
        final[v] = FALSE; D[v] = G.arcs[v0][v];
        for(w=0; w<G.vexnum; ++w)   P[v][w] = FALSE; //vo->v设空路径
        if(D[v] <INFINITY){P[v][v0] = TRUE; P[v][v]=TRUE;}
    }
    D[v0] = 0;  final[v0] = TRUE;   //初始化，v0顶点属于S集
    //开始主循环，每次求得v0到某个顶点的最短路径，并加v到S集
    for(i=1;i<G.vexnum;++i){    //除v0外其余G.vexnum-1个顶点
        min = INFINITY;   //当前所知离v0顶点最近距离 
        for(w=0; w<G.vexnum; ++w)   //此循环简写为{v,min}=MIN(D) {离v0最近且未加入到S集的点v，当前v0到v的距离}
            if(!final[w])
                if(D[w]<min) {v=w; min=D[w];}    //w顶点离v0顶点更近
        final[v]=TRUE;  //离v0顶点最近的v加入S集
        for(w=0; w<G.vexnum; ++w)   //更新当前最短路径及距离
            if(!final[w] && (min+G.arcs[v][w] < D[w])){ //若无有向边<v,w>，则G.arcs[v][w]=INFINITY
                D[w] = min + G.arcs[v][w];
                P[w] = P[v]; P[w][w] = TRUE;    //最短路径v0->w：{v0..w} = {v0..v} + w
            }
    }
}//(较长路径v0..s..w中间经过顶点的具体走向 由较短路径例如v0..s确定)[递归查询]