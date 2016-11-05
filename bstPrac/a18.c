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

//finding all ancestors of a node
void find_ancestors(struct bstNode *root, int data, int *a){
	if(root){
		*a = root->data;
		if(data != root->data){	
			if(data < root->data) find_ancestors(root->left, data, ++a);
			if(data > root->data) find_ancestors(root->right, data, ++a);
		}
	}
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
		return search(root->left, data);
	}
	else{
		return search(root->right, data);
	}
}

//node dist function
int node_dist(struct bstNode *root, int lca, int data){
	int c = 0;
	struct bstNode *l = search(root, lca);
	struct bstNode *curr = search(root, data);

	while(l != curr)
	{
		if(data < l->data){
			l = l->left;
			c++;
		} else {
			l = l->right;
			c++;

		}
	}
	
	return c;
}
//distance function
void dist(struct bstNode *root, int data1, int data2, int n){
	int x[n], y[n], ca[n];
	int i, j, f, s, c, lca;
	int dist1, dist2, distance;
	
	//initiliazing all array values to -1
	for(i=0; i<n; i++){
		x[i] = -1;
		y[i] = -1;
		ca[i] = -1;
	}

	//finding all ancestors for given data
	find_ancestors(root, data1, x);
	find_ancestors(root, data2, y);

	//finding index for array traversal in first ancestor array 
	for(f=0; f<n; f++){
		if(x[f] == -1){
			break;
		}
	}

	//finding index for array traversal in second ancestor array
	for(s=0; s<n; s++){
		if(y[s] == -1){
			break;
		}
	}
	
	//putting common ancestors in array ca
	int t = 0;
	for(i=0; i<f; i++){
		for(j=0; j<s; j++){
			if(x[i] == y[j]){
				ca[t] = x[i];
				t++;
			}
		}
	}
	
	c = t;	
	//findi lowest common ancestor
	lca = ca[0];

	for(i=1; i<c; i++){
		if(ca[i] < lca){
			lca = ca[i];
		}
	}
	dist1 = node_dist(root, lca, data1);
	dist2 = node_dist(root, lca, data2);

	distance = dist1 + dist2;
	printf("%d\n", distance);

}

//total nodes function
int total_nodes(struct bstNode *root){
	if(root){
		return (1 + total_nodes(root->left) + total_nodes(root->right));
	}
	else{
		return 0;
	}
}

//main function
int main(){
	int n;
	
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

	n = total_nodes(node);

	dist(node, 3, 11, n);	
	

	return 0;
}
