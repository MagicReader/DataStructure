Status TopologicalSort(ALGraph G){
    //有向图G采用邻接表存储结构
    //若G无回路，则输出G的顶点的一个拓扑序列并返回OK，否则返回ERROR
    FindInDegree(G, indegree);  //对各顶点求入度 indegree[0..vernum-1]
    InitStack(S);
    for(i=0; i<G.vernum; ++i)   //建零入度顶点栈S
        if (!indegree[i]) Push(S, i);   //入度为 0者进栈
    count = 0;  //对输出顶点计数
    while (！StackEmpty(S)){
        Pop(S,i);   printf(i, G.vertices[i].data);  ++count;   //输出i号顶点并计数
        for(p=G.vertices[i].firstarc; p; p=p->nextarc){
            k = p->adjvex;  //对i号顶点的每个邻接点的入度减一
            if(!(--indegree[k])) Push(S, k);    //若入度减为 0，则入栈
        }
    }
}
