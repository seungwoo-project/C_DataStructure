#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

struct Edge {
	int start, end, weight;
};
typedef struct GraphType {
	int n; // 간선의 개수
	int nvertex; // 정점의 개수
	struct Edge edges[2 * MAX_VERTICES];
} GraphType;
int compare(const void* a, const void* b) {
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return(x->weight - y->weight);
}
void set_init(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
}
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1)
		curr = parent[curr];
	return curr;
}
void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}
void graph_init(GraphType* g)
{
	g->n = g->nvertex = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}
void kruskal(GraphType* g)
{
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;
	set_init(g->nvertex);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);
	int i = 0;
	while (edge_accepted < (g->nvertex - 1))
	{
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset) {
			printf("%d %d %d\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}
}
int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);
	int nvertex, start, end, weight;
	scanf("%d", &nvertex);
	g->nvertex = nvertex;
	while (scanf("%d %d %d", &start, &end, &weight) != EOF) {
		insert_edge(g, start, end, weight);
	}
	kruskal(g);
	free(g);
	return 0;
}