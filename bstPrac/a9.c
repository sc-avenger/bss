#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//creating new node in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//delete function using postorder traversal
void delete(struct bstNode *root){
	if(root == NULL){
		return;
	}
		delete(root->left);
		delete(root->right);
		
		printf("%d ", root->data);
		free(root);
		root = NULL;
}

//main function
int main(){
	struct bstNode *root = getNewNode(1);
	root->left = getNewNode(2);
	root->left->left = getNewNode(4);
	root->right = getNewNode(3);
	root->left->right = getNewNode(5);

	delete(root);

	printf("\n%d\n", root->data);	

	return 0;
}
