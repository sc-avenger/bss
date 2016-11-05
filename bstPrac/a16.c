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

//find max function
int find_max(struct bstNode *root){
	if(!root){
		return -1;
	}
	while(root->right){
		root = root->right;
	}
	return root->data;
}

//find min function
int find_min(struct bstNode *root){
	if(!root){
		return -1;
	}
	while(root->left){
		root = root->left;
	}
	return root->data;
}

//checking if bst or not function
int check_bst(struct bstNode *root){
	if(!root){
		return 1;
	}
	if(root->left && find_max(root->left) > root->data){
		return 0;
	}
	if(root->right && find_min(root->right) < root->data){
		return 0;
	}
	if(!check_bst(root->left) || !check_bst(root->right)){
		return 0;
	}
	return 1;
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

	n = check_bst(node);
	
	if(n == 0){
		printf("Tree is NOT BST\n");
	}	
	else{
		printf("Tree is BST\n");
	}

	return 0;
}
