#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}



/*-------------------max heapify function-----------------------------*/
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

/*---------------------min heapify function---------------------------*/
void min_heapify(int *a, int n, int i){
int l, r, smallest;
smallest = i;
l = (2*i)+1;
r = (2*i)+2;

	if(l<n && a[l]<a[smallest]){
		smallest = l;	
	}
	
	if(r<n && a[r]<a[smallest]){
		smallest = r;
	}

	if(smallest != i){
		swap(a[smallest], a[i]);
		min_heapify(a, n, smallest);
	}
}

/*---------------------build max heap function-------------------------*/
void build_max_heap(int *a, int n){
int i;
	for(i=(n/2)-1; i>=0; i--){
		max_heapify(a, n, i);
	}
}

/*--------------------build min heap function-------------------------*/
void build_min_heap(int *a, int n){
int i;
	for(i=(n/2)-1; i>=0; i--){
		min_heapify(a, n, i);
	}
}

/*------------------heap sort via max heap function---------------------------*/
void max_heap_sort(int *a, int n){
	
	int i;
	build_max_heap(a, n);
	for(i=n-1; i>=0; i--){
		swap(a[0],a[i]);
		n--;
		max_heapify(a, n, 0);
	}
}

/*------------------heap sort via min heap function----------------------*/
void min_heap_sort(int *a, int n){

	int i, m;
	m = n;

	for(i=0; i<m;i++){
		build_min_heap(&a[i], n--);
	}
}

/*-------------------function to increase key-----------------------*/
void increase_key(int *a, int k, int i){
	if(k < a[i]){
		printf("Error. Enter a bigger value.\n");
	}
		
	else{
		a[i] = k;
		while(i>=0 && a[i] > a[i/2]){
			swap(a[i], a[i/2]);
			i = i/2;	
		}
	}
}

/*-----------------function to decrease key-----------------*/
void decrease_key(int *a, int n, int k, int i){
	if(k > a[i]){
		printf("Error. Enter a smaller value\n");
	}
	else{
		a[i] = k;
		while(i<n){
			max_heapify(a, n, i);
			i++;
		}
	}
}


/*--------------function to print elements in heap-----------------*/
void print_heap(int *a, int n){
int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}

/*------------------main function--------------------------*/
int main(){

int n, k, i;
int a[]={33,42,32,5,64,54,1,66,98,23};
n = sizeof(a)/sizeof(a[0]);

build_max_heap(a, n);
print_heap(a, n);
printf("\n");
//max_heap_sort(a,n);
//print_heap(a,n);

//min_heap_sort(a,n);
//print_heap(a,n);

/*
printf("Enter the new increased value and index for inserting \n");
scanf("%d %d", &k, &i);
increase_key(a, k, i);
print_heap(a, n);
*/

printf("Enter the new decreased value and index for inserting \n");
scanf("%d %d", &k, &i);
decrease_key(a, n, k, i);
print_heap(a, n);

return 0;
}

