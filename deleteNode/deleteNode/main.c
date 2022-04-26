//
//  main.c
//  deleteNode
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

void insert(int x){
    struct node* temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->next=NULL;
    struct node* temp1=head;
    if (head == NULL){
        head=temp;
    }
    else if(head != NULL){
        while (temp1->next != NULL){
                temp1=temp1->next;
            }
        temp1->next=temp;
    }
}

void print(void){
    struct node* temp= head;
    printf("list is: ");
    while (temp !=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void deleteNode(int n){
    struct node* temp=head;
    struct node* next=temp->next;
    if (n==1){
        head=next;
        free(temp);
    }
    else if(n>1){
        for (int i=0;i<n-2;i++){
            temp=temp->next;
        }
        next=temp->next;
        temp->next=next->next;
        free(next);
    }
    
}

int main() {
    head=NULL;//empty list
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    print();
    
    while(1){
        int n;
        printf("the position of number you want to delete:No.");
        scanf("%d",&n);
        deleteNode(n);
        print();
    }
}
