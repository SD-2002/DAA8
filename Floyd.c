// C Program for Floyd Warshall Algorithm
#include <stdio.h>

// Number of vertices in the graph
#define V 4

/*Infinte Value*/
#define INF 99999

void printSolution(int dist[][V]);


void floydWarshall(int dist[][V])
{
	int i, j, k;

	for (k = 0; k < V; k++) {
        //source vertices
		for (i = 0; i < V; i++) {
			//destination vertices of picked source
			for (j = 0; j < V; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	printf(
		"The following matrix shows the shortest distances"
		" between every pair of vertices \n");
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

// driver's code
int main()
{
	int graph[V][V] = { { 0, 8, INF, 1 },
						{ INF, 0, 1, INF },
						{ 4, INF, 0, INF },
						{ INF, 2, 9, 0 } };

	floydWarshall(graph);
	return 0;
}
