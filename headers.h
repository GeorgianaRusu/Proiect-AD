

#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#define infinity 9999
#define MAX 20
int graph[MAX][MAX],spanning[MAX][MAX],n;

//Create the edge list of given graph, with their weights.
typedef struct edge
{
    int u,v,w;
}edge;

typedef struct edgelist
{
    edge data[MAX];
    int n;
}edgelist;
edgelist elist;
edgelist spanlist;

void kruskal();
int find(int belongs[],int no_of_vertex);
void union1(int belongs[],int c1,int c2);
void sort();
void print();

int prims();
#endif
