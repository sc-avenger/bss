#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//function to create new node in bst
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
	else if(data <= (*root)->data){
		insert(&(*root)->left, data);
	}
	else{
		insert(&(*root)->right, data);
	}
}

//function to print array
void printArr(int b[], int len){
	int i;
	for(i=0; i<len; i++){
		printf("%d ", b[i]);
	}
	printf("\n");
}

//rec function to print every root to leaf path
void printPathRec(struct bstNode *root, int a[], int pLen){
	if(root == NULL){
		return;
	}
	
	a[pLen] = root->data;
	pLen++;

	if(root->left == NULL && root->right == NULL){
		printArr(a, pLen);
	}	
	else{
		printPathRec(root->left, a, pLen);
		printPathRec(root->right, a, pLen);
	}
}

//print path function
void printPath(struct bstNode *root){
	int a[1000];
	printPathRec(root, a, 0);	
}

//main function
int main(){

struct bstNode *root = NULL;

insert(&root, 12);
insert(&root, 5);
insert(&root, 15);
insert(&root, 3);
insert(&root, 7);
insert(&root, 13);
insert(&root, 17);
insert(&root, 1);
insert(&root, 9);

printPath(root);

return 0;
}
