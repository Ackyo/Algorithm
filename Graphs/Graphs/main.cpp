//
//  main.cpp
//  Graphs
//
//  Created by xuwenyong on 15/11/23.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
using namespace std;

int main(int argc, const char * argv[])
{
    MGraph g;
    g.vexnum=8;
    
    g.edges[0][1]=1;
    g.edges[1][0]=1;
    g.edges[0][4]=1;
    g.edges[4][0]=1;
    g.edges[1][5]=1;
    g.edges[5][1]=1;
    g.edges[5][2]=1;
    g.edges[2][5]=1;
    g.edges[5][6]=1;
    g.edges[6][5]=1;
    g.edges[2][3]=1;
    g.edges[3][2]=1;
    g.edges[2][6]=1;
    g.edges[6][2]=1;
    g.edges[6][3]=1;
    g.edges[3][6]=1;
    g.edges[6][7]=1;
    g.edges[7][6]=1;
    g.edges[3][7]=1;
    g.edges[7][3]=1;
    puts("DFS Traverse:");
    DFSTraverse(g);
    puts("\nBFS Traverse:");
    BFSTraverse(g);
    puts("\n");
    
    ALGraph alg;
    alg.vexnum=8;
    ArcNode arc1;
    arc1.adjvex=1;
    arc1.nextarc=NULL;
    alg.vertices[0].firstarc=&arc1;
    
    
    return 0;
}
