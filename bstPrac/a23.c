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

//search function
struct bstNode *search(struct bstNode *root, int data){
	if(!root){
		return NULL;
	}
	else if(root->data == data){
		return root;
	}
	else if(data < root->data){
		search(root->left, data);
	}
	else{
		search(root->right, data);
	}
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

//deleting a node from bst
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

//deleting duplicate function
struct bstNode *del_dup(struct bstNode *root){
	struct bstNode *tmp = root;
	if(!tmp){
		return NULL;
	}

	del_dup(tmp->left);

	while(search(tmp->left, tmp->data) != NULL){
		struct bstNode *dupNode = search(tmp->left, tmp->data);
		tmp = delete(tmp, dupNode->data);
	}	
	while(search(tmp->right, tmp->data) != NULL){
		struct bstNode *dupNode = search(tmp->right, tmp->data);
		tmp = delete(tmp, dupNode->data);
	}	

	del_dup(tmp->right);

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

//main function
int main(){
	struct bstNode *node = getNewNode(12);
	node->left = getNewNode(10);
	node->right = getNewNode(20);
	node->left->left = getNewNode(9);
	node->left->right = getNewNode(11);
	node->right->left = getNewNode(12);
	node->left->right->left = getNewNode(10);
	node->right->left->right = getNewNode(12);

	struct bstNode *root = del_dup(node);
	inorder(root);	
	printf("\n");	

	return 0;
}
