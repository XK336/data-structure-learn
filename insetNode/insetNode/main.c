//
//  main.c
//  insetNode
//
//  Created by xike on 2021/11/16.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}node;

struct node* head;

void insert (int n,int x){
    struct node* temp1 = (node*)malloc(sizeof(node));
    temp1 ->data = x;
    temp1 ->next = NULL;
    
    if (n == 1)
    {
        temp1->next=head;
        head = temp1;
        return;
    }
    node* temp2=head;
    for (int i=0;i<n-2;i++){
        temp2=temp2->next;
        
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

void print(void){
    struct node* temp=head;
    while (temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() {
    head = NULL;//empty list
    insert(1,4);
    insert(2,5);
    insert(1,8);
    insert(3,3);
    
    print();
}
