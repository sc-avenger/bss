#include <stdio.h>
#include <stdlib.h>

//definign structure for bst
struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
	int height;
};

//creating a new node in bst
struct bstNode *getNewNode(int data){
	struct bstNode *newNode = (struct bstNode *)malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

//max function
int max(int a, int b){
	return ((a > b) ? a : b);
}

//height function
int height(struct bstNode *root){
	if(!root){
		return 0;
	}
	return root->height;
}

//get Bal function
int getBal(struct bstNode *root){
	if(!root){
		return 0;
	}
	return (height(root->left) - height(root->right));
}

//rotate right function
struct bstNode *rot_right(struct bstNode *root){
	struct bstNode *temp1 = root->left;
	struct bstNode *temp2 = temp1->right;

	//perform rotation
	temp1->right = root;
	root->left = temp2;

	//update height
	root->height = max(height(root->left), height(root->right)) + 1;
	temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

	return temp1;
}

//rotate left function
struct bstNode *rot_left(struct bstNode *root){
	struct bstNode *temp1 = root->right;
	struct bstNode *temp2 = temp1->left;

	//perform rotation
	temp1->left = root;
	root->right = temp2;

	//update height
	root->height = max(height(root->left), height(root->right)) + 1;
	temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

	return temp1;	
}

//find min function
struct bstNode *find_min(struct bstNode *root){
	if(!root){
		return NULL;
	}
	else{
		while(root->left){
			root = root->left;
		}
	}
	return root;
}

//delete function in balanced bst
struct bstNode *delete(struct bstNode *root, int data){
	if(!root){
		return NULL;
	}
	else if(data < root->data){
		root->left = delete(root->left, data); 
	}
	else if(data > root->data){
		root->right = delete(root->right, data);
	}
	else{
		if(!root->left && !root->right){
			free(root);
			root = NULL;
		}
		else if(!root->right){
			struct bstNode *temp = root;
			root = root->left;
			free(temp);
		}
		else if(!root->left){
			struct bstNode *temp = root;
			root = root->right;
			free(temp);
		}
		else{
			struct bstNode *temp = find_min(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}

	//checking if there was only one node, then after delete height doesnt matter, it is balanced
	if(!root){
		return root;
	}

	//updating height of root after delete
	root->height = max(height(root->left), height(root->right)) + 1;

	//get the balance factor
	int bal = getBal(root);

	//left-left case
	if(bal > 1 && getBal(root->left) >= 0){
		return rot_right(root);
	}
	
	//right-right case
	if(bal < -1 && getBal(root->right) <= 0){
		return rot_left(root);
	}

	//left-right case
	if(bal > 1 && getBal(root->left) < 0){
		root->left = rot_left(root->left);
		return rot_right(root);
	}

	//right-left case
	if(bal < -1 && getBal(root->right) > 0){
		root->right = rot_right(root->right);
		return rot_left(root);
	}
	
	return root;
}	

//insert function for balanced bst
struct bstNode *insert(struct bstNode *root, int data){
	if(!root){
		root = getNewNode(data);
		return root;
	}
	if(data < root->data){
		root->left = insert(root->left, data);
	}
	else{
		root->right = insert(root->right, data);
	}

	//update the height of the inserted node
	root->height = max(height(root->left), height(root->right)) + 1;

	//get the balance factor
	int bal = getBal(root);

	//left-left case
	if(bal > 1 && data < root->left->data){
		return rot_right(root);
	}
	
	//right-right cae
	if(bal < -1 && data > root->right->data){
		return rot_left(root);
	}	

	//left-right case
	if(bal > 1 && data > root->left->data){
		root->left = rot_left(root->left);
		return rot_right(root);
	}

	//right-left case
	if(bal < -1 && data < root->right->data){
		root->right = rot_right(root->right);
		return rot_left(root);
	}

	return root;
}

//preorder function
void preorder(struct bstNode *root){
	if(!root){
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

//main function
int main(){
	struct bstNode *root = NULL;
	int n, i, data, t, del;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &data);
		root = insert(root, data);
	}

	scanf("%d", &t);
	int a[t];
	for(i=0; i<t; i++){
		scanf("%d", &a[i]);
	}
	
	preorder(root);
	printf("\n");

	for(i=0; i<t; i++){
		root = delete(root, a[i]);
		preorder(root);
		printf("\n");
	}

	return 0;
}
