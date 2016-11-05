#include <stdio.h>
#include <stdlib.h>

//defining structure for node
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

//creating new node in a tree
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
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

//search function
int search(struct bstNode *root, int data){
	if(root == NULL){
		return 0;
	}
	else if(root->data == data){
		return 1;
	}
	else if(data <= root->data){
		return search(root->left, data);
	}
	else{
		return search(root->right, data);
	}
}

//min function
int findMin(struct bstNode *root){
	if(root == NULL){
		return -1;
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root->data;
}

//max function
int findMax(struct bstNode *root){
	if(root == NULL){
		return -1;
	}	
	while(root->right != NULL){
		root = root->right;
	}
	return root->data;
}

//inorder function
void inorder(struct bstNode *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

//main function
int main(){

int i, n, min, max;
int a[3] = {0,0,0};
struct bstNode *root = NULL;

insert(&root, 20);
insert(&root, 10);
insert(&root, 25);
insert(&root, 30);
insert(&root, 5);
insert(&root, 100);
insert(&root, 80);
insert(&root, 75);
insert(&root, 60);
insert(&root, 45);

for(i=0; i<3; i++){
	printf("Enter the number to be searched\n");
	scanf("%d", &n);
	a[i] = search(root, n);
}

for(i=0; i<3; i++){
	if(a[i] == 1){
		printf("%c\n", 'y');
	}
	else{
		printf("%c\n", 'n');
	}
}
printf("\n");
inorder(root);
printf("\n");
min = findMin(root);
printf("Min = %d\n", min);
max = findMax(root);
printf("Max = %d\n", max);

return 0;
}
