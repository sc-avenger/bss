#include <stdio.h>
#include <stdlib.h>

//defining the structure for node
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//creating a new node in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//search function
int search(int *a, int strt, int end, int val){
	int i;
	for(i=strt; i<=end; i++){
		if(a[i] == val){
			break;
		}
	return i;
	}	
}

//function to build tree recursively using inorder and postorder
struct bstNode *build_tree_rec(int *in, int *post, int inStrt, int inEnd, int *pIndex){
	if(inStrt > inEnd){
		return NULL;
	}
	
	struct bstNode *node = getNewNode(post[*pIndex]);
	(*pIndex)--;

	if(inStrt == inEnd){
		return node;
	}

	int inIndex = search(in, inStrt, inEnd, node->data);
	
	node->right = build_tree_rec(in, post, inIndex+1, inEnd, pIndex);
	node->left = build_tree_rec(in, post, inStrt, inIndex-1, pIndex);

	return node;
}

//function to build tree, defining the length of array ot be passed
struct bstNode *build_tree(int *in, int *post, int n){
	int pIndex = n-1;
	return build_tree_rec(in, post, 0, n-1, &pIndex);	
}

//preorder function
void preorder(struct bstNode *root){
	if(root == NULL) return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
	
}

void inorder(struct bstNode *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}	
}

//main function
int main(){

int len;
int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
len = sizeof(in)/sizeof(in[0]);

struct bstNode *root = build_tree(in, post, len);

preorder(root);
printf("\n");
inorder(root);

return 0;
}
