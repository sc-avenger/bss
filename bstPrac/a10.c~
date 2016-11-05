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

//mirro function
void mirror(struct bstNode * root){
	if(!root){
		return;
	}
	else{
		struct bstNode *temp;	
	
		mirror(root->left);
		mirror(root->right);

		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}	
}

//inorder function
void inorder(struct bstNode *root){
	if(root){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
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
	
	mirror(node);
	
	inorder(node);	
	printf("\n");

	return 0;
}
