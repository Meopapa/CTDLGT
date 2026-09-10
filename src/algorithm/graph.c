#include "algorithm/graph.h"
#include "data_structure/dsa_configs.h"

int GRAPH_Init(Graph *graph, size_t vertex_count)
{
	size_t row;

	if (graph == NULL) return ERROR_NULL_PTR;
	if (vertex_count == 0 || vertex_count > GRAPH_MAX_VERTICES) return ERROR_SIZE;
	graph->vertex_count = vertex_count;
	for (row = 0; row < GRAPH_MAX_VERTICES; row++)
	{
		for (size_t column = 0; column < GRAPH_MAX_VERTICES; column++)
			graph->edges[row][column] = 0;
	}
	return SUCCESS_TRUE;
}

int GRAPH_AddEdge(Graph *graph, size_t from, size_t to, int directed)
{
	if (graph == NULL) return ERROR_NULL_PTR;
	if (from >= graph->vertex_count || to >= graph->vertex_count) return ERROR_INDEX;
	graph->edges[from][to] = 1;
	if (!directed) graph->edges[to][from] = 1;
	return SUCCESS_TRUE;
}

int GRAPH_HasEdge(const Graph *graph, size_t from, size_t to)
{
	if (graph == NULL) return ERROR_NULL_PTR;
	if (from >= graph->vertex_count || to >= graph->vertex_count) return ERROR_INDEX;
	return graph->edges[from][to] ? SUCCESS_TRUE : FAIL_FALSE;
}

int GRAPH_BFS(const Graph *graph, size_t start, size_t *order, size_t order_capacity, size_t *order_size)
{
	size_t queue[GRAPH_MAX_VERTICES];
	size_t visited[GRAPH_MAX_VERTICES] = {0};
	size_t front = 0;
	size_t back = 0;

	if (graph == NULL || order == NULL || order_size == NULL) return ERROR_NULL_PTR;
	if (start >= graph->vertex_count) return ERROR_INDEX;
	if (order_capacity < graph->vertex_count) return ERROR_SIZE;
	queue[back++] = start;
	visited[start] = 1;
	*order_size = 0;
	while (front < back)
	{
		size_t vertex = queue[front++];
		order[(*order_size)++] = vertex;
		for (size_t next = 0; next < graph->vertex_count; next++)
		{
			if (graph->edges[vertex][next] && !visited[next])
			{
				visited[next] = 1;
				queue[back++] = next;
			}
		}
	}
	return SUCCESS_TRUE;
}
