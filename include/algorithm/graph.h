#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>

#define GRAPH_MAX_VERTICES 32

typedef struct {
    size_t vertex_count;
    unsigned char edges[GRAPH_MAX_VERTICES][GRAPH_MAX_VERTICES];
} Graph;

int GRAPH_Init(Graph *graph, size_t vertex_count);
int GRAPH_AddEdge(Graph *graph, size_t from, size_t to, int directed);
int GRAPH_HasEdge(const Graph *graph, size_t from, size_t to);
int GRAPH_BFS(const Graph *graph, size_t start, size_t *order, size_t order_capacity, size_t *order_size);

#endif
