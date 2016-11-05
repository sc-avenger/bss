#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}


/*-----------min heapify function-------------------*/
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
		swap(a[i], a[smallest]);
		min_heapify(a, n, smallest);
	}

}

/*--------------building min heap--------------------*/
void build_min_heap(int *a, int n){
	int i;
	for(i=(n/2)-1; i>=0; i--){
		min_heapify(a, n, i);
	}
}

/*------------deleting root element-----------------*/
void del_root(int *a, int *p){
	build_min_heap(a, *p);
	swap(a[0], a[(*p)-1]);
	(*p)--;
	build_min_heap(a, *p);
}

/*-----------printing the heap-----------------------*/
void print_heap(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}


/*------------------------main function--------------------------*/
int main(){

int i, n, k, T, j;
scanf("%d", &T);

for(j=0; j<T; j++){	
	
	scanf("%d %d", &n, &k);
	int a[n];

	for(i=0; i<n; i++){
		scanf(" %d", &a[i]);
	}

	for(i=0; i<k; i++){
		del_root(a, &n);
		//n--;	
	}
print_heap(a, n);
printf("\n");

}
return 0;
}

