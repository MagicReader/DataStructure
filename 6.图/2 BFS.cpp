Boolean visited[MAX]; //访问标志数组

void BFSTrvaverse(Graph G, Status(* Visit)(int v)){
    for(v=0; v<G.vexnum; ++v) visited[v]=FALSE;
    InitQueue(Q);   //置空的辅助队列Q
    for(v=0; v<G.vexnum; ++v) 
        if(!visited[v]){    //对尚未访问的顶点进行访问
            visited[v]=TRUE; Visit(v);
            EnQueue(Q, v); //v入队列
            while (!QueueEmpty(Q)){
                DeQueue(Q, u);  //从队头元素出队并置为 u
                for(w=FirstAdjVex(G,u); w>=0; w=NextAdjVex(G,u,w))
                    if (!visited[w]){   //w为 u的尚未访问的邻接顶点
                        visited[w]=TRUE; Visit(w);
                        EnQueue(Q,w);
                    }
            }
        }
}