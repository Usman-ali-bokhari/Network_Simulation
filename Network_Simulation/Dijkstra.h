#pragma once
#include <stdio.h>
#include <limits.h>


int minDistance(int dist[],bool sptSet[], int V)
{

	int min = 9999, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false &&
			dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
int index;
int yes;
void GetPath(int parent[], int j, int*** &arr,int src)
{
	// Base Case : If j is source
	if (parent[j] == -1)
		return;

	GetPath(parent, parent[j], arr,src);



	arr[src][index][yes]=j;
	yes++;
}

void GenPaths(int dist[], int n, int parent[],int x,int*** &arr)
{
	int src = x;
	for (int i = 0; i < 20; i++)
	{
		index = i;
		yes = 0;

		GetPath(parent, i,arr,src);

	}
}

void dijkstra(int** graph, int src,int*** &arr,int V)
{

	int* dist = new int[V];

	bool* sptSet = new bool[V];

	int* parent = new int[V];

	for (int i = 0; i < V; i++)
	{
		parent[i] = -1;
		dist[i] = 9999;
		sptSet[i] = false;
	}

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet,V);
		sptSet[u] = true;

		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	GenPaths(dist, V, parent,src, arr);

}