#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}


/*void swap(int *a,int *b){
	int t=(*a);
	*a=*b;
	*b=t;

}*/
void max_heapify(int *a, int n, int i){
	int l,r,largest;
	largest=i;
	l = (2*i)+1;
	r = (2*i)+2;

	if(l<n && a[l]>a[largest]){
		largest = l;
	}	

	if(r<n && a[r]>a[largest]){
		largest = r;
	}
	
	if(largest != i){
		swap(a[i], a[largest]);
		max_heapify(a, n, largest);
	}
}


void display(int *a, int *p){

int i;
	for(i=0; i<(*p); i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}


void build_max_heap(int *a, int n){

	int i;
	for(i=(n/2)-1; i>=0; i--){
		max_heapify(a, n, i);
	}
}


void insert(int *a, int *p, int v){
	
//(*n)++;
a[*p] = v;
++*p;
build_max_heap(a, *p);
//display(a, p);
//printf("\n");
}


int find(int *a, int v, int n){
int i;
	for(i=0; i<n; i++){
		if(a[i] == v){
		return i;
		}		
	}
return -1;
}

void delete(int *a, int *p, int v){
	int k = find(a, v, *p);
	swap(a[k],a[(*p)-1]);
	(*p) = (*p)-1;
//	printf("\n%d\n",a[*p-1]);
	build_max_heap(a, *p);
}

int main(){

int a[100];
int n=0, c, v;

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
