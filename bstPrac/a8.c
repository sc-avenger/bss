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

//build tree function
struct bstNode *build_tree(int pre[], int n, int post[], int l, int h, int *preIndex){
	if(*preIndex >= n || l > h){
		return NULL;
	}
	
	struct bstNode *root = getNewNode(pre[*preIndex]);
	++(*preIndex);

	if(l == h){
		return root;
	}

	int i;
	for(i=l; i<=h; ++i){
		if(pre[*preIndex] == post[i]){
			break;
		}
	}

	if(i <= h){
		root->left = build_tree(pre, n, post, l, i, preIndex);
		root->right = build_tree(pre, n, post, i + 1, h, preIndex);
	}

	return root;
}

//build function
struct bstNode *build(int pre[], int post[], int n){
	int preIndex = 0;
	return build_tree(pre, n, post, 0, n - 1, &preIndex);
}

//inorder function
void inorder(struct bstNode *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);	
	}
}

//main function
int main(){
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
	int len = sizeof(pre)/sizeof(pre[0]);
	
	struct bstNode *node = build(pre, post, len);
	
	inorder(node);
	printf("\n");
	
	return 0;
}
