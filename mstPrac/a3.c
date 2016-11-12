#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//defining edge structure
typedef struct edge{
	int src, dest, wt;	
}edge_m;

//defining subset structure
typedef struct subset{
	int rank, parent;
}sub_m;

//find function
int find(sub_m sub[], int a){
	if(sub[a].parent != a){
		sub[a].parent = find(sub, sub[a].parent);
	}
	return sub[a].parent;
}

//make union function
void make_union(sub_m sub[], int x, int y){
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

//kruskal function
void kruskal(edge_m taken[], int v){
	int i, j, e, x, mat[v][v];
	int flag = 0;
	e = v * v;
	edge_m list[e]; //creating a list array of type edge
	sub_m sub[v];	//creating a sub array of type subset

	//inputing the matrix
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	//setting the subset rank and parent for every node
	for(i=0; i<v; i++){
		sub[i].rank = 0;
		sub[i].parent = i;
	}

	//putting all the edges in the list array
	x = 0;
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			if(mat[i][j] != 0 && mat[i][j] != INT_MAX){
				list[x].src = i;
				list[x].dest = j;
				list[x++].wt = mat[i][j];
				mat[list[x-1].dest][list[x-1].src] = INT_MAX;
			}
		}
	}
	
	e = x;
	edge_m temp;
	//non decreasing order of list
	for(i=0; i<(e-1); i++){
		for(j=0; j<(e-1-i); j++){
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

	x = 0;
	i = 0;

	//putting the smallest edge in taken array
	taken[x].src = list[i].src;
	taken[x].dest = list[x].dest;
	taken[x].wt = list[x].wt;
	sub[taken[x].dest].parent = taken[x].src;
	sub[taken[x].src].rank++;

	x++;
	i++;

	//selecting the next smallest edge and putting in taken array
	while(x < (v-1)){
		
		//finding parents of src and dest node
		int xpar = find(sub, list[i].src);
		int ypar = find(sub, list[i].dest);

		//checking if there is a cycle
		if(xpar == ypar){
			printf("There is a cycle.\n");
		}	

		//putting the edge in taken if no cycle
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
/*
//display function
void display(edge_m taken[], int v){
	int i;
	printf("Edge\tWeight\n");
	for(i=0; i<(v-1); i++){
		printf("%d-%d\t%d\n", taken[i].src, taken[i].dest, taken[i].wt);
	}
}
*/
//main function
int main(){
	int n;
	scanf("%d", &n);
	
	edge_m taken[n];
	
	kruskal(taken, n);
//	display(taken, n);

	return 0;
}
