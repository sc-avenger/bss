#include <stdio.h>
#include <stdlib.h>

//defining structure for tree disjoint
struct disNode{
	int data;
	int rank;
	struct disNode *parent;
};

//make set function
struct disNode *make_set(int data){
	struct disNode *newNode = (struct disNode *)malloc(sizeof(struct disNode));
	newNode->data = data;
	newNode->rank = 0;
	newNode->parent = newNode;
	return newNode;
}

//find parent function
struct disNode *find_par(struct disNode *head[], int n, int x){
	int i;
	struct disNode *node = NULL;

	for(i=0; i<n; i++){
		if(head[i]->data == x){
			node = head[i];
		}
	}

	while(node->parent != node){
		node = node->parent;
	}
	return node;
}

//union set function
void union_set(struct disNode *head[], int n, int x, int y){
	struct disNode *root1 = find_par(head, n, x);
	struct disNode *root2 = find_par(head, n, y);
	
	struct disNode *t1 = root1;
	struct disNode *t2 = root2;

	if(t1->rank == t2->rank){
		t2->parent = t1;
		t1->rank++;
	}
	if(t1->rank > t2->rank){
		t2->parent = t1;
	}
	else{
		t1->parent = t2;
	}	
}

//path compression
void path_comp(struct disNode *head[], int n){
	int i;
	for(i=0; i<n; i++){
		struct disNode *p1 = head[i];		
		struct disNode *p2 = head[i];

		while(p1 != p1->parent){
			p1 = p1->parent;
		}
		p2->parent = p1;
	}
}

//printing representatives of given disjoint set
void print_rep(struct disNode *head[], int n){
	int i, j;
	int x[n]; 
	int y[n];
	struct disNode *temp = NULL;
	
	//storing parent of each node in array x
	for(i=0; i<n; i++){
		temp = find_par(head, n, head[i]->data);
		x[i] = temp->data;
	}
	
	//finding unique elements of array x and printing
	int t = 0;
	for(i=0; i<n; i++){
		for(j=0; j<i; j++){
			if(x[i] == x[j]){
				break;
			}
		}
		if(i == j){
			y[t] = x[i];
			t++;
		}
	}
	
	//printing number of connected components and rep for each component
	printf("Number of connected components: %d\n", t);
	printf("The representatives are: ");
	for(i=0; i<t; i++){
		printf("%d ", y[i]);
	}
}

//display function
void display(struct disNode *head[], int n){
	int i;
	for(i=0; i<n; i++){
		struct disNode *node = head[i];
		printf("Node-> %8d\n", node->data); 
		printf("Parent-> %6d\n", node->parent->data); 
		printf("Rank-> %8d\n", node->rank);
		printf("\n"); 
	}
}


//main function
int main(){
	
	int i, n, data, x, y, nu;
	
	scanf("%d", &n);
	struct disNode *head[n];

	for(i=0; i<n; i++){
		scanf("%d", &data);
		head[i] = make_set(data);
	}

	printf("Enter the number of union operatios to be performed\n");
	scanf("%d", &nu);
	for(i=0; i<nu; i++){
		scanf("%d %d", &x, &y);
		union_set(head, n, x, y);
	}
	
	path_comp(head, n);
	display(head, n);
	print_rep(head, n);	
	printf("\n");	
	
	return 0;
}
