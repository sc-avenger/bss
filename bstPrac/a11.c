#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;	
};

//creating a new node in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//function to print all nodes at defined distance
void *nodes_at_dist(struct bstNode *root, int n){
	if(!root){	
		return NULL;
	}
	if(n == 0){
		printf("%d ", root->data);
	//	return;
	}	
	else{
		nodes_at_dist(root->left, n - 1);
		nodes_at_dist(root->right, n - 1);
	}
}

//main function
int main(){
	int n;
	
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
	
	scanf("%d", &n);
	
	nodes_at_dist(node, n);

	return 0;
}
