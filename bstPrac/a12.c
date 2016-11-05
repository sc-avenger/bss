#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;	
};

//creating 	a new node in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//function to find predecessor and successor
void findPreSuc(struct bstNode *root, struct bstNode **pre, struct bstNode **suc, int data){
	if(root == NULL){
		return;
	}
	if(root->data == data){
		if(root->left != NULL){
			struct bstNode *temp = root->left;
			while(temp->right){
				temp = temp->right;
			}
			*pre = temp;
//			printf("%d\n", pre->data);
		}
		
		if(root->right != NULL){
			struct bstNode *temp = root->right;
			while(temp->left){
				temp = temp->left;	
			}
			*suc = temp;
//			printf("%d\n", suc->data);
		}
		return;
	}

	if(data < root->data){
		*suc = root;
		findPreSuc(root->left, pre, suc, data);
	}
	else{
		*pre = root;
		findPreSuc(root->right, pre, suc, data);
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

	struct bstNode *pre = NULL;
	struct bstNode *suc = NULL;
	int n;

	scanf("%d", &n);

	findPreSuc(node, &pre, &suc, n);

	if(pre != NULL){
		printf("Predecessor: %d\n", pre->data);
	}
	else{
		printf("No predecessor\n");
	}
	
	if(suc != NULL){
		printf("Successor: %d\n", suc->data);
	}
	else{
		printf("No Successor\n");
	}

	return 0;
}
