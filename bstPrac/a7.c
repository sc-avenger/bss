#include <stdio.h>
#include <stdlib.h>

//defining structure for bst
struct bstNode{
	int data;
	struct bstNode *left, *right;
};

//creating new node in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//searching  the index of root in inorder function
int search(int a[], int strt, int end, int data){
	int i;
	for(i=strt; i<=end; i++){
		if(a[i] == data){
			break;
		}
	}
	return i;
}

//build tree function
struct bstNode *build_tree(int in[], int inStrt, int inEnd, int post[], int postStrt, int postEnd){
	if(inStrt > inEnd || postStrt > postEnd){
		return NULL;
	}

	int rootVal = post[postEnd];
	struct bstNode *root = getNewNode(rootVal);

	int inIndex = search(in, inStrt, inEnd, root->data);
	
	root->left = build_tree(in, inStrt, inIndex - 1, post, postStrt, ((postStrt + inIndex) - (inStrt + 1)));
	root->right = build_tree(in, inIndex + 1, inEnd, post, (postStrt + inIndex - inStrt), (postEnd - 1));

	return root;
}

//build function to call build tree
struct bstNode *build(int in[], int post[], int n){
	int inStrt = 0;
	int inEnd = n-1;
	int postStrt = 0;
	int postEnd = n-1;
	return build_tree(in, inStrt, inEnd, post, postStrt, postEnd);
}

//inorder function
void preorder(struct bstNode *root){
	if(root == NULL){
		return;
	}
	else{
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
//	printf("%d\n", len);
//	len = len - 1;
//	int postIndex = len;

	node = build(in, post, len);
	
	preorder(node);
	printf("\n");	
	return 0;
}
