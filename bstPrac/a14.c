#include <stdlib.h>
#include <stdio.h>

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

//fucntion to delete the terminal nodes
struct bstNode *delete_term(struct bstNode *root){
	if(!root){
		return NULL;
	}
	else{
		if(!root->left && !root->right){
			free(root);
		//	root = NULL;
			return NULL;
		}

		root->left = delete_term(root->left);
		root->right = delete_term(root->right);			
	}
	return root;
}

//inorder function
void inorder(struct bstNode *root){
	if(!root){
		return;
	}
	else{
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

//	inorder(node);	

	struct bstNode *root = delete_term(node);
	inorder(root);
	printf("\n");	

	return 0;
}
