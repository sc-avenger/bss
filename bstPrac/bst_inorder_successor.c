#include <stdio.h>
#include <stdlib.h>

//defining structure for node in bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//defining function to create new node
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
		insert(&(*root)->left, data);
	}
	else{
		insert(&(*root)->right, data);
	}
}

//inorder function
void inorder(struct bstNode *root){
	if(root != NULL){
	inorder((root)->left);
	printf("%d\n", (root)->data);
	inorder((root)->right);
	}
}

//find function
struct bstNode *find(struct bstNode *root, int data){
	if(root == NULL){
		return NULL;
	}
	else if(root->data == data){
		return root;
	}
	else if(data <= root->data){
		return find(root->left, data);
	}
	else{
		return find(root->right, data);
	}
}

//find minimum node in right subtree function
struct bstNode *findMin(struct bstNode *root){
	if(root == NULL){
		return NULL;
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

//finding max node of the tree (to avoid segmentation fault in successor)
struct bstNode *findMax(struct bstNode *root){
	if(root == NULL){
		return NULL;
	}	
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}	

//inorder successor function
struct bstNode *getSuccessor(struct bstNode *root, int data){
	struct bstNode *current = find(root, data);
	struct bstNode *maxElement = findMax(root);	
	//printf("%d\n", maxElement->data);
	
	if(current == NULL){
		return NULL;
	}
	if(current == maxElement){
		return NULL;
	}
	else if(current->right != NULL){
		return findMin(current->right);
	}
	else{
		struct bstNode *successor = NULL;
		struct bstNode *ancestor = root;

		while(ancestor != current){
			if(current->data < ancestor->data){
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}

}

//main function
int main(){

struct bstNode *succu = NULL;
struct bstNode *root = NULL;
insert(&root, 15);
insert(&root, 10);
insert(&root, 20);
insert(&root, 25);
insert(&root, 8);
insert(&root, 12);

succu = getSuccessor(root, 25);
if(succu != NULL){
printf("\n%d\n", succu->data);
}
else{
printf("NULL\n");
}
//inorder(root);
return 0;
}
