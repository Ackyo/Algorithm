//
//  Traverse.cpp
//  Graphs
//
//  Created by xuwenyong on 15/12/1.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Graph.h"
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

void BFS(MGraph G, int i, bool* visited)
{
    Visit(i);
    visited[i]=true;
    queue<int> que;
    que.push(i);
    while (que.empty()==false)
    {
        i=que.front();
        que.pop();
        for (int j=0; j<G.vexnum; ++j)
        {
            if (G.edges[i][j] && visited[j]==false)
            {
                Visit(j);
                visited[j]=true;
                que.push(j);
                
            }
        }
    }
}

void BFSTraverse(MGraph G)
{
    bool *visited=new bool[G.vexnum];
    for (int i=0; i<G.vexnum; ++i)
    {
        visited[i]=false;
    }
    
    for (int i=0; i<G.vexnum; ++i)
    {
        if (visited[i]==false)
        {
            BFS(G,i,visited);
        }
    }
    delete[] visited;
}

void DFS(MGraph G, int i, bool* visited)
{
    Visit(i);
    visited[i]=true;
    stack<int> dfsStack;
    dfsStack.push(i);
    while (dfsStack.empty()==false)
    {
        i=dfsStack.top();
        dfsStack.pop();
        for (int j=0; j<G.vexnum; ++j)
        {
            if (G.edges[i][j] && visited[j]==false)
            {
                Visit(j);
                visited[j]=true;
                dfsStack.push(j);
                break;
            }
        }
    }
}

void DFSTraverse(MGraph G)
{
    bool *visited=new bool[G.vexnum];
    for (int i=0; i<G.vexnum; ++i)
    {
        visited[i]=false;
    }
    
    for (int i=0; i<G.vexnum; ++i)
    {
        if (visited[i]==false)
        {
            DFS(G,i,visited);
        }
    }
    delete[] visited;
}
