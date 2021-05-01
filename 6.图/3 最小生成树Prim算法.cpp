struct｛	//记录从顶点集U到 V-U的代价最小的边的辅助数组定义
	VertexType adjvex;
	VRType lowcost;
｝closedge[MAX_VERTEX_NUM];

void MinSpanTree_PRIM(MGraph G, VertexType u){
	//用普利姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边
	k = LocateVex(G,u);		//k为 u在图中的位置
	for(j=0; j<G.vexnum; ++j)	//辅助数组初始化
		if(j!=k) closedge[j] = {u, G.arcs[k][j].adj}; //{adjvex, lowcost}
	closedge[k].lowcost = 0; //初始，U = {u}
	for(i=1; i<G.vexnum; ++i){	//选择其余G.vexnum-1个结点
		k = minimum(closedge);	//求出T的下一个结点：第k结点
		//此时closedge[k].lowcost = MIN{closedge[vi].lowcost | closedge[vi].lowcost>0, vi∈V-U}
		printf(closedge[k].adjvex, G.vexs[k]);	//输出生成树的边
		closedge[k].lowcost = 0;	//第k顶点并入U集
		for(j=0; j<G.vexnum; ++j)
			if(G.arcs[k][j].adj < closedge[j].lowcost)	//新顶点并入U后重新选择最小边
				closedge[j] = {G.vexs[k], G.arcs[k][j].adj};
	}
}