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

//height function
int height(struct bstNode *node){
	if(!node){
		return 0;
	}	
	if(!node->left && !node->right){
		return 0;
	}
	
	int l = height(node->left);
	int r = height(node->right);

	return (1 + (l > r ? l : r));	
}

//depth function
int depth(struct bstNode *root, struct bstNode *node){
	int c = 0;
	if(!node){
		return 0;
	}
	while(node != root){
		if(node->data < root->data){
			root = root->left;
			c++;
		}
		else{
			root = root->right;
			c++;
		}
	}
	return c;
}

//function to find height and depth of individual nodes
void *hd(struct bstNode *root, struct bstNode *node){
	int heig = 0, dep = 0;
	if(node)
	{	
		hd(root, node->left);
		
		heig = height(node);
		dep = depth(root, node);
		printf("Node->%7d\n", node->data);
		printf("Height->%5d\n", heig);
		printf("Depth->%6d\n\n", dep);
		
//		hd(root, node->left);
		hd(root, node->right);
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

	hd(node, node);
	
	return 0;
}
