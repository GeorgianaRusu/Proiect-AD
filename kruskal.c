#include<stdio.h>
#include "headers.h"

int graph[MAX][MAX],n;
void sort() //Sort the edge list according to their weights in ascending order.
{
    int i,j;
    edge aux;

    for(i=1;i<elist.n;i++)
        for(j=0;j<elist.n-1;j++)
            if(elist.data[j].w>elist.data[j+1].w)
            {
                aux=elist.data[j];
                elist.data[j]=elist.data[j+1];
                elist.data[j+1]=aux;
            }
}
int find(int belongs[],int no_of_vertex)
{
    return(belongs[no_of_vertex]);
}

void union1(int belongs[],int c1,int c2)//Connect the vertices with given edge.
{
    int i;

    for(i=0;i<n;i++)
        if(belongs[i]==c2)
            belongs[i]=c1;
}


void print()//Print the span list of given graph, with their weights.
{
    int i,cost=0;
   printf("\nedge1 \tedge2 \tvertices");
    for(i=0;i<spanlist.n;i++)
    {
        printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
        cost=cost+spanlist.data[i].w;
    }

    printf("\n\nCost of the spanning tree=%d",cost);
    printf("\n");
}


void kruskal()
{
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        {
            if(graph[i][j]!=0)
            {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=graph[i][j];
                elist.n++;
            }
        }

    sort();

    for(i=0;i<n;i++)
        belongs[i]=i;

    spanlist.n=0;

    for(i=0;i<elist.n;i++)
    {
        cno1=find(belongs,elist.data[i].u);
        cno2=find(belongs,elist.data[i].v);
        //Connect the vertices in the skeleton with given edge. If by connecting the vertices, a cycle is created, then discard this edge.

        if(cno1!=cno2)
        {
            spanlist.data[spanlist.n]=elist.data[i];
            spanlist.n=spanlist.n+1;
            union1(belongs,cno1,cno2);
        }

    }
    //Repeat steps, until n-1 edges are added or list of edges is over.
}

