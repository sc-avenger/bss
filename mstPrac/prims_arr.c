#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//min_ind function
int min_ind(int key[], int n, int mst[]){
	int i, index;
	int min = INT_MAX;
	for(i=0; i<n; i++){
		if((mst[i] == 0) && (key[i] < min)){
			min = key[i];
			index = i;
		}
	}
	return index;
}

//prims function
void prims(){
	int i, c, u, j, n;
	scanf("%d", &n);
//	int n = 5;
	int graph[n][n];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &graph[i][j]);
		}
	}
/*	int graph[5][5] = {{0, 2, 0, 6, 0},
			   {2, 0, 3, 8, 5},
			   {0, 3, 0, 0, 7},
			   {6, 8, 0, 0, 9},
			   {0, 5, 7, 9, 0}};
*/
	int key[n];
	int mst[n];
	int parent[n];

	for(i=0; i<n; i++){
		key[i] = INT_MAX;
		mst[i] = 0;
	}		 

	key[0] = 0;
	parent[0] = -1;

	for(c=0; c<n-1; c++){
		u = min_ind(key, n, mst);
		mst[u] = 1;

		for(i=0; i<n; i++){
			if(graph[u][i] && mst[i] == 0 && graph[u][i] < key[i]){
				parent[i] = u;
				key[i] = graph[u][i];	
			}
		}
	}

	//print mst
	printf("Edge\tWeight\n");
	for(i=1; i<n; i++){
		printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
	}
		
}

//main function
int main(){
	prims();
	return 0;
}
