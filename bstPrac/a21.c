#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;	
};

//creating new nodes in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//height function
int height(struct bstNode *root){
	if(!root){
		return 0;
	}
	if(!root->left && !root->right){
		return 0;
	}
	int l = height(root->left);
	int r = height(root->right);

	return (1 + (l > r ? l : r));
}

//print level function to print nodes at every level
void print_level(struct bstNode *root, int level){
	if(!root){
		return;
	}
	if(level == 0){
		printf("%d ", root->data);
	}
	else if(level > 0){
		print_level(root->left, level - 1);
		print_level(root->right, level - 1);
	}
}

//level order function to reach individual levels traversing the tree
void level_order(struct bstNode *root){
	int h = height(root);
	int i;
	for(i=0; i<=h; i++){
		print_level(root, i);
		printf("\n");	
	}	
}

//main function
int main(){
	
	struct bstNode *node = getNewNode(10);
	node->left = getNewNode(7);
	node->right = getNewNode(20);
	node->left->left = getNewNode(5);
	node->left->right = getNewNode(9);
	node->right->left = getNewNode(12);
	node->right->right = getNewNode(24);
	node->left->left->left = getNewNode(3);
	node->left->left->right = getNewNode(6);
	node->right->left->left = getNewNode(11);
	node->right->left->right = getNewNode(13);

	level_order(node);	

	return 0;
}
