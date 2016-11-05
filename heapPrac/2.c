#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}


/*----------------------max heapify function------------------*/
void max_heapify(int *a, int n, int i){

int l, r, largest;
largest = i;
l = (2*i)+1;
r = (2*i)+2;

	if(l<n && a[l]>a[largest]){
		largest = l;
	}

	if(r<n && a[r]>a[largest]){
		largest = r;
	}

	if(largest != i){
		swap(a[largest], a[i]);
		max_heapify(a, n, largest);
	}	
}


/*------------------------build max heap-----------------------*/
void build_max_heap(int *a, int n){
int i;
	for(i=(n/2)-1; i>=0; i--){
		max_heapify(a, n, i);
	}
}


/*--------------------------insert-------------------------------*/
void insert(int *a, int *p, int v){

a[*p] = v;
(*p)++;
build_max_heap(a, *p);
printf("Inserted\n");
}

/*-------------------------find-------------------------------*/
int find(int *a, int p, int v){
	int i;
	for(i=0; i<p; i++){
		if(a[i] == v){
			return i;	
		}
	}
	return -1;
}


/*--------------------------delete-----------------------------*/
void delete(int *a, int *p, int v){

int k = find(a, *p, v);

	if(k == -1){
		printf("%d not found.\n", v);
	}
	else{ 
		swap(a[k], a[(*p)-1]);
		(*p)=(*p)-1;
		build_max_heap(a, *p);
		printf("Deleted.\n");
	}
}

/*--------------------------display-------------------------------*/
void display(int *a, int *p){
	int i;
	for(i=0; i<(*p); i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*----------------------------main function-------------------------*/
int main(){

int a[100];
int c, v;
int n=0;

do{
scanf("%d", &c);

	switch(c){
		case 1: scanf("%d", &v);
			insert(a, &n, v);
			break;
		case 2: scanf("%d", &v);
			delete(a, &n, v);
			break;
		case 3: display(a, &n);
			break;
		case 4: break;	
	}
	

}while(c!=4);


return 0;
}
