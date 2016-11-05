#include <stdio.h>
#include <stdlib.h>

//defining structure for disjoint sets
struct disNode{
	int data;
	struct disNode *next;
	struct disNode *rep;
};

//make set function
struct disNode *make_set(int data){
	struct disNode *newNode = (struct disNode *)malloc(sizeof(struct disNode));
	newNode->data = data;
	newNode->next = NULL;
	newNode->rep = newNode;
	return newNode;	
}

//finding the rep for a given data function
struct disNode *find_rep(struct disNode *head[], int n, int data){
	int i;
	for(i=0; i<n; i++){
		struct disNode *temp = head[i];
		while(temp){
			if(temp->data == data){
				return temp->rep;
			}
			temp = temp->next;
		}
	}
}

//get index function
int get_index(struct disNode *head[], int n, int data){
	int i;
	for(i=0; i<n; i++){
		struct disNode *temp = head[i];
		while(temp){
			if(temp->data == data){
				return i;	
			}
			temp = temp->next;
		}
	}
}

//length function
int length(struct disNode *root){
	int c = 0;
	while(root){
		c++;
		root = root->next;
	}
	return c;
}
//union set function
void union_set(struct disNode *head[], int x, int y, int n){
	struct disNode *rep1 = NULL;
	struct disNode *rep2 = NULL;
	struct disNode *t1, *t2;

	int index1, index2;	

	rep1 = find_rep(head, n, x);
	rep2 = find_rep(head, n, y);

	t1 = rep1;
	t2 = rep2; 

	index1 = get_index(head, n, x);
	index2 = get_index(head, n, y);

	if(length(rep1) > length(rep2)){
		while(t1->next){
			t1 = t1->next;
		}
		t1->next = rep2;

		while(t2){
			t2->rep = rep1->rep;
			t2 = t2->next;
		}

		head[index2] = NULL;
	}
	else{
		while(t2->next){
			t2 = t2->next;
		}
		t2->next = rep1;

		while(t1){
			t1->rep = rep2->rep;
			t1 = t1->next;
		}

		head[index1] = NULL;
	}	
}

//display function
void display(struct disNode *head[], int n){
	int i;
	for(i=0; i<n; i++){
		struct disNode *node = head[i];
		printf("{");
		while(node){
			printf("%d", node->data);
			if(node->next){
				printf(",");
			}
			node = node->next;
		}	
		printf("}\n");
	}
}

//main function
int main(){
	int i, n, u, data, x, y;

	scanf("%d", &n);
	struct disNode *head[n];

	for(i=0; i<n; i++){
		scanf("%d", &data);
		head[i] = make_set(data);
	}

	printf("\n");
	display(head, n);	
	printf("\n");

	printf("No of union operations\n");
	scanf("%d", &u);

	for(i=0; i<u; i++){
		scanf("%d %d", &x, &y);
		union_set(head, x, y, n);
		display(head, n);
	}

	return 0;
}

