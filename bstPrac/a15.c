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

//find min function
struct bstNode *findMin(struct bstNode *root){
	if(!root){
		return NULL;
	}
	while(root->left){
		root = root->left;
	}
	return root;
}

//inorder function
void inorder(struct bstNode *root){
	if(!root){
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

//delete function
struct bstNode *delete(struct bstNode *root, int data){
	if(root == NULL){
		return NULL;
	}
	else if(data < root->data){
		root->left = delete(root->left, data);
	}
	else if(data > root->data){
		 root->right = delete(root->right, data);
	}
	else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}
		else if(root->right == NULL){
			struct bstNode *temp = root;
			root = root->left;
			free(temp);
		}
		else if(root->left == NULL){
			struct bstNode *temp = root;
			root = root->right;
			free(temp);
		}
		else{
			struct bstNode *temp = findMin(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}
	return root;
}

//delete root
void delete_root(struct bstNode *root){
	while(root){
		root = delete(root, root->data);
		inorder(root);
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

	delete_root(node);
	
	return 0;
}
