//
//  Graph.h
//  Graphs
//
//  Created by xuwenyong on 15/12/1.
//  Copyright © 2015年 Ack. All rights reserved.
//

#ifndef Graph_h
#define Graph_h


#endif /* Graph_h */



#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

#define MAX_VERTEX_NUM 100
typedef char VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM];
    EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum,arcnum;
}MGraph;

typedef struct ArcNode
{
    int adjvex;
    ArcNode* nextarc;
    //InfoType info;
}ArcNode;

typedef struct
{
    VertexType data;
    ArcNode* firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;


void Visit(int i);

void BFS(MGraph G, int i, bool* visited);
void BFSTraverse(MGraph G);
void DFS(MGraph G, int i, bool* visited);
void DFSTraverse(MGraph G);


