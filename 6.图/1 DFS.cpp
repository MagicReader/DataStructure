Boolean visited[MAX]; //访问标志数组
Status(* VisitFunc)(int v);	//函数变量

void DFSTraverse(Graph G, Status(* Visit)(int v)){ //对图G作深度优先遍历
	VisitFunc = Visit; //使用全局变量VisitFunc,使 DFS不必设函数指针参数
	for(v=0; v<G.vexnum; ++v) visited[v]=FALSE; //访问标志数组初始化
	for(v=0; v<G.vexnum; ++v)
		if(!visited[v]) DFS(G,v);	//对尚未访问的顶点调用DFS	
}

void DFS(Graph G, int v){
	//从第v个顶点出发递归地深度优先遍历图G
	visited[v]=TRUE; VisitFunc(v); //访问第v个顶点
	for(w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w))
		if(!visited[w]) DFS(G,w); //对v的尚未访问的邻接顶点w递归调用DFS	
}