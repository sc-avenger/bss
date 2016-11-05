#include <stdio.h>
#include <stdlib.h>

//defining structure for node
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//creating new node in a tree
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
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

//inorder function
void inorder(struct bstNode *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

//counting total nodes function
int total_count(struct bstNode *root){
	if(root){
		return (1 + total_count(root->left) + total_count(root->right));
	}
	else{
		return 0;
	}
}

//counting leaf nodes function
int leaf_count(struct bstNode *root){
	
	if(root == NULL){
		return 0;
	}	
	if(root->left == NULL && root->right == NULL){
		return 1;
	}
	else{
		return(leaf_count(root->left) + leaf_count(root->right));
	}
}

//counting non leaf nodes function
int nonleaf_count(struct bstNode *root){
	if(!root){
		return 0;
	}
	if(!root->left && !root->right){
		return 0;
	}
	else{
		return(1 + nonleaf_count(root->left) + nonleaf_count(root->right));
	}
}

//counting full nodes function
int fullnodes_count(struct bstNode *root){
	if(!root){
		return 0;
	}
	if(!root->left && !root->right){
		return 0;
	}
	return(fullnodes_count(root->left) + fullnodes_count(root->right) + ((root->left && root->right) ? 1 : 0));
}

//counting the height of bst function
int height(struct bstNode *root){
	if(!root){
		return 0;
	}	
	if(!root->left && !root->right){
		return 0;
	}

	int l,r;
	l = height(root->left);
	r = height(root->right);

	return(1 + ((l>r) ? l : r));
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

printf("Total Nodes: %d\n", total_count(root));
printf("Leaf Nodes: %d\n", leaf_count(root));
printf("Non Leaf Nodes: %d\n", nonleaf_count(root));
printf("Full Nodes: %d\n", fullnodes_count(root));
printf("Height: %d\n", height(root));

//inorder(root);

return 0;
}
