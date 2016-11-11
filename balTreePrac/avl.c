#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
	int height;
};

//creating new nodes in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

//max function
int max(int a, int b){
	return ((a > b) ? a : b);
}

//height function
int height(struct bstNode *root){
	if(!root){
		return 0;
	}
	return root->height;
}

//calculating balance factor
int getBal(struct bstNode *root){
	if(!root){
		return 0;
	}
	return (height(root->left) - height(root->right));
}

//rotate right function
struct bstNode *rot_right(struct bstNode *root){
	struct bstNode *temp1 = root->left;
	struct bstNode *temp2 = temp1->right;

	//perform rotation
	temp1->right = root;
	root->left = temp2;

	//update heights of modified nodes
	root->height = max(height(root->left), height(root->right)) + 1;
	temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

	return temp1;
}

//rotate left function
struct bstNode *rot_left(struct bstNode *root){
	struct bstNode *temp1 = root->right;
	struct bstNode *temp2 = temp1->left;

	//perform rotation
	temp1->left = root;
	root->right = temp2;

	//update heights of the modified nodes
	root->height = max(height(root->left), height(root->right)) + 1;
	temp1->height = max(height(temp1->left), height(temp1->right)) + 1;	

	return temp1;
	
}

//insert function
struct bstNode *insert(struct bstNode *root, int data){
	if(!root){
		root = getNewNode(data);
		return root;
	}
	if(data < root->data){
		root->left = insert(root->left, data);
	}
	else{
		root->right = insert(root->right, data);
	}

	//updating the height of the inserted node
	root->height = max(height(root->left), height(root->right)) + 1;

	int bal = getBal(root);

	//left-left case
	if(bal > 1 && data < root->left->data){
		return rot_right(root);
	}
	
	//right-right case
	if(bal < -1 && data > root->right->data){
		return rot_left(root);
	}

	//left-right case
	if(bal > 1 && data > root->left->data){
		root->left = rot_left(root->left);
		return rot_right(root);
	}

	//right-left case
	if(bal < -1 && data < root->right->data){
		root->right = rot_right(root->right);
		return rot_left(root);
	}
	
	return root;
}

//preorder function
void preorder(struct bstNode *root){
	if(root){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//main function
int main(){
	struct bstNode *root = NULL;
	
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	
	preorder(root);
	printf("\n");
	return 0;
}
