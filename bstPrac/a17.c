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

//checking if sumtree or not function
int sumtree(struct bstNode *root){
	if(!root){
		return 1;
	}
	if(!root->left && !root->right){
		return 1;
	}
	if(!root->right){
		if(root->left->data + 0 != root->data){
			return 0;
		}
	}
	if(!root->left){
		if(root->right->data + 0 != root->data){
			return 0;
		}
	}
	if(root->left && root->right){
		if(root->left->data + root->right->data != root->data){
			return 0;
		}
	}
	if(!sumtree(root->left) || !sumtree(root->right)){
		return 0;
	}
	return 1;
}
	
//main function
int main(){
	struct bstNode *node = getNewNode(35);
	node->left = getNewNode(15);
	node->right = getNewNode(20);
	node->left->left = getNewNode(3);
	node->left->right = getNewNode(12);
	node->right->left = getNewNode(14);
	node->right->right = getNewNode(6);
	node->left->left->left = getNewNode(1);
	node->left->left->right = getNewNode(2);
	node->right->left->left = getNewNode(9);
	node->right->left->right = getNewNode(5);
	
	printf("%d\n", sumtree(node));	

	return 0;
}
