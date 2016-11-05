#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//creating new node in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//insert function
void insert(struct bstNode **root, int data){
	if((*root) == NULL){
		(*root) = getNewNode(data);
		return;
	}
	else if(data < (*root)->data){
		insert(&(*root)->left, data);
	}
	else{
		insert(&(*root)->right, data);
	}
}

//preorder function
void preorder(struct bstNode *root, int *a){
	if(root != NULL ){
		*a = root->data;
		if(root->left != NULL){
			a++;
			preorder(root->left, a);
		}
		if(root->right != NULL){
			a++;
			preorder(root->right, a);
		}
	}
}

//inorder function
void inorder(struct bstNode *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

//main function
int main(){

	
	int m=0, n, i, a, t;
	scanf("%d", &t);
	scanf("%d", &n);
	int b[t];

	while(m<t){
		
		struct bstNode *root0 = NULL;
		struct bstNode *root1 = NULL;
			
		int x[n], y[n];
		for(i=0; i<n; i++){
			x[i] = 0;
			y[i] = 0;
		}	
	
		b[m] = 0;

		for(i=0; i<(2*n); i++){
			if(i<n){
				scanf("%d", &a);
				insert(&root0, a);
			}
			else{
				scanf("%d", &a);
				insert(&root1, a);
			}				
		}

		/*
		inorder(root0);
		inorder(root1);
		*/		

		preorder(root0, x);
		preorder(root1, y);	
		
		/*
		for(i=0; i<n; i++){
				
			printf("%d \t %d\n", x[i], y[i]);
		}
		*/

		for(i=0; i<n; i++){
			if(x[i] != y[i]){
				b[m] = 1;
				break;	
			}
		}
	
		m++;
	}

	for(i=0; i<t; i++){
		if(b[i] == 0){
			printf("y\n");
		}
		else{
			printf("n\n");
		}
	}

	return 0;
}
