#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left, *right;
};

//creating new nodes in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}	

//insert function
void insert(struct bstNode **root, int data){
	if(!(*root)){
		(*root) = getNewNode(data);
		return;
	}
	if(data < (*root)->data){
		insert(&(*root)->left, data);
	}
	else{
		insert(&(*root)->right, data);
	}
}

void print_ancestors(struct bstNode *root, int data){

	struct bstNode *ancestor = root;	

	if(!root){
		return;
	}
	if(data == root->data){
		return;
	}
	if(data < ancestor->data){
		printf("%d ", ancestor->data);
		print_ancestors(ancestor->left, data);
	}
	else{
		printf("%d ", ancestor->data);
		print_ancestors(ancestor->right, data);
	}
}

//main function
int main(){
	
	int n;
	struct bstNode *root = NULL;

	insert(&root, 10);
	insert(&root, 7);
	insert(&root, 20);
	insert(&root, 5);
	insert(&root, 9);
	insert(&root, 12);
	insert(&root, 24);
	insert(&root, 3);
	insert(&root, 6);
	insert(&root, 11);
	insert(&root, 13);
	
	scanf("%d", &n);	

	print_ancestors(root, n);
	printf("\n");

	return 0;
}
