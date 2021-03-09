#include <limits.h> 
#include <stdio.h> 

#define X 5

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < X; v++)
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	return min_index;
}

void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < X; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[X][X], int src)
{
	int dist[X]; 

	bool sptSet[X]; 

	for (int i = 0; i < X; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < X - 1; count++) 
	{
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < X; v++)

			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}

int main()
{
	int graph[X][X] = { {0,3,0,0,5},
		                {0,0,8,5,3},
		                {0,0,0,0,0},
		                {0,0,2,0,0},
		                {0,0,0,4,0} };

	dijkstra(graph, 0);

	return 0;
}
