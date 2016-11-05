#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next, *rep;
};

struct node *getnode(int data) {
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->rep = rep;
    return newnode;
}


struct node *makeset(int data) {
    struct node *temp = NULL;
    temp=getnode(data);
    temp->rep = temp;
    return temp;
}

int findIndex(struct node *head[], int x, int n){
    for(int i=0; i<n; i++) {
        struct node *temp = NULL;
        temp = head[i];
        while(temp != NULL) {
            if(temp->data == x) {
                return i;
            }
            else {
                temp = temp->next;
            }
        }
    }
}


int size (struct node *node) {
    int counter=0;
    while(node->next) {
        counter++;
        node=node->next;
    }
    return counter;
}

struct node *find(struct node *head[], int x, int n){
    for(int i=0; i<n; i++) {
        struct node *temp = NULL;
        temp = head[i];
        while(temp != NULL) {
            if(temp->data == x) {
                return temp->rep;
            }
            else {
                temp = temp->next;
            }
        }
    }
}

struct node *union_set(struct node *head[], int x, int y, int n) {
    struct node *temp1, *temp2, *t1, *t2;
    temp1 = find(head, x, n);
    temp2 = find(head, y, n);
    t1=temp1;
    t2=temp2;
    int index1 = findIndex(head,x,n);
    int index2 = findIndex(head,y,n);

    if(size(temp1) <= size(temp2)) {
//        printf("%d",size(temp1));
        while(t2->next != NULL) {
            t2=t2->next;
        }
        t2->next=temp1;
        while(t1 != NULL) {
            t1->rep=temp2->rep;
            t1=t1->next;
        }
        head[index1] = NULL;
    }
    else {
        while(t1->next != NULL) {
            t1=t1->next;
        }
        t1->next=temp2;
        while(t2 != NULL) {
            t2->rep=temp1->rep;
            t2=t2->next;
        }
        head[index2] = NULL;
    }
}


void display (struct node *head[], int n){
    for(int i=0; i<n; i++) {
        struct node * temp = NULL;
        temp = head[i];
        printf("{");
        while(temp!=NULL) {
            printf("%d", temp->data);
            if(temp->next != NULL) {
                printf(",");
            }
            temp=temp->next;
        }
        printf("}\n");
    }
}

int main() {
    int n, temp, x, y;
    scanf("%d",&n);
    struct node *head[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        head[i] = makeset(temp);
    }
    display(head,n);
    int numberofunions;
    scanf("%d", &numberofunions);
    for(int j=0; j<numberofunions; j++) {
        scanf("%d %d" ,&x, &y);
        union_set(head,x,y,n);
        display(head,n);
    }
}
