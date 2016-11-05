#include <stdio.h>
#include <stdlib.h>

//defining structure for binary tree
struct bstNode{
	int data;
	struct bstNode *left; 
	struct bstNode *right;
};

//creating a new node in binary tree
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//search function to return index of element searched
int search(int in[], int start, int end, int data){
	int i;
	for(i=start; i<=end; i++){
		if(in[i] == data){
			break;
		}
	}
	return i;
}

//build tree function
struct bstNode *build_tree(int in[], int post[], int inStrt, int inEnd, int *pIndex){
	if(inStrt > inEnd){
		return NULL;
	}

	struct bstNode *root = getNewNode(post[*pIndex]);
	(*pIndex)--;

	if(inStrt == inEnd){
		return root;
	}

	int inIndex = search(in, inStrt, inEnd, root->data);

	root->right = build_tree(in, post, (inIndex + 1), inEnd, pIndex);
	root->left = build_tree(in, post, inStrt, (inIndex - 1), pIndex);

	return root;
}

//build function
struct bstNode *build(int in[], int post[], int n){
	int pIndex = n - 1;
	return build_tree(in, post, 0, n - 1, &pIndex);
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
	struct bstNode *node = NULL;
	int in[] = {4, 6, 8, 9, 10, 2};
	int post[] = {4, 9, 8, 6, 2, 10};
	int len = sizeof(in)/sizeof(in[0]);

	node = build(in, post, len);
	
	preorder(node);
	printf("\n");	
	return 0;
}
