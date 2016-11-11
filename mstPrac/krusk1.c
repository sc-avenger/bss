#include <stdio.h>
#include <stdlib.h>

//defining edge_k structure
typedef struct edge{
	int src;
	int dest;
	int wt;
}edge_k;

//defining subset_k structure
typedef struct subset{
	int rank;
	int parent;
}subset_k;

//find function
int find(subset_k sub[], int a){
	if(sub[a].parent != a){
		sub[a].parent = find(sub, sub[a].parent);
	}
	return sub[a].parent;
}

//make union function
void make_union(subset_k sub[], int x, int y){
	int xpar = find(sub, x);
	int ypar = find(sub, y);

	if(sub[xpar].rank == sub[ypar].rank){
		sub[ypar].parent = xpar;
		sub[xpar].rank++;
	}	
	else if(sub[xpar].rank < sub[ypar].rank){
		sub[xpar].parent = ypar;
	}
	else{
		sub[ypar].parent = xpar;
	}
}

//kruskal_mst function
void kruskal_mst(edge_k taken[], int v){
	int e, i, j, x;
	e = v * v;
	edge_k list[e];
	int mat[v][v];

	//taking the input matrix
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	//setting parent and rank for each node
	subset_k sub[v];
	for(i=0; i<v; i++){
		sub[i].parent = i;
		sub[i].rank = 0;
	}

	//transfering edges in the list array
	x = 0;
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			if(mat[i][j] != 0 && mat[i][j] != 99){
				list[x].src = i;
				list[x].dest = j;
				list[x++].wt = mat[i][j];
				mat[list[x-1].dest][list[x-1].src] = 99;
			}
		}
	}

	//total edges in the graph
	e = x;

	//kruskals algo
	//non decreasing order
	edge_k temp;
	for(i=0; i<(e-1); i++){
		for(j=0; j<(e-i-1); j++){
			if(list[j].wt > list[j+1].wt){
				temp.src = list[j].src;
				temp.dest = list[j].dest;
				temp.wt = list[j].wt;
				list[j].src = list[j+1].src;
				list[j].dest = list[j+1].dest;
				list[j].wt = list[j+1].wt;
				list[j+1].src = temp.src;
				list[j+1].dest = temp.dest;
				list[j+1].wt = temp.wt;
			}
		}
	}
	
	//choose the first edge as it is the smallest and put it in taken
	x = 0;
	i = 0;
	
	taken[x].src = list[i].src;
	taken[x].dest = list[i].dest;
	taken[x].wt = list[i].wt;
	sub[taken[x].dest].parent = taken[x].src;
	sub[taken[x].dest].rank++;
	
	x = x + 1;
	i = i + 1;

	//continuing till v-1 edges
	while(x < (v-1)){
		int xpar = find(sub, list[i].src);
		int ypar = find(sub, list[i].dest);

	// if both parents not same put the edge in taken	
		if(xpar != ypar){
			taken[x].src = list[i].src;
			taken[x].dest = list[i].dest;
			taken[x].wt = list[i].wt;

			make_union(sub, xpar, ypar);
			x++;
		}
		i++; 
	} 
}

//display function
void display(edge_k taken[], int v){
	int i;
	for(i=0; i<(v-1); i++){
		printf("%d-%d | %d\n", taken[i].src, taken[i].dest, taken[i].wt);
	}
	printf("\n");
}

//main function
int main(){
	int v;
	scanf("%d", &v);
	edge_k taken[v-1];
	kruskal_mst(taken, v);
	display(taken, v);
	return 0;
}
