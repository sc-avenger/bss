#include <stdio.h>
#include <stdlib.h>

//defining structure for the node
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//creating a new node in bst
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

//function to find sum of all leaf nodes
int sum_leaf(struct bstNode *root){
	if(!root){
		return 0;
	}
	if(!root->left && !root->right){
		return(root->data);
	}
	else{
		return(sum_leaf(root->left) + sum_leaf(root->right));
	}
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

printf("%d\n", sum_leaf(root));

return 0;
}
