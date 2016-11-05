#include <stdio.h>
#include <stdlib.h>

//defining struct for bst node
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//defining function to create a new node in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
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
		return insert(&(*root)->left, data);
	}
	else{
		return insert(&(*root)->right, data);
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

//find min function
struct bstNode *findMin(struct bstNode *root){
	if(root == NULL){
		return NULL;
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root;
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

//main function
int main(){

struct bstNode *root = NULL;
//struct bstNode *del = NULL;

insert(&root, 12);
insert(&root, 5);
insert(&root, 15);
insert(&root, 3);
insert(&root, 7);
insert(&root, 13);
insert(&root, 17);
insert(&root, 1);
insert(&root, 9);

inorder(root);
printf("\n");

root = delete(root, 17);
inorder(root);

return 0;
}
