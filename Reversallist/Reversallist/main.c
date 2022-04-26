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

void reversalList(void){
    struct node* prev=NULL;
    struct node* current=NULL;
    struct node* later=NULL;
    while (head->next !=NULL){
        current=head;
        later=current->next;
        
        head->next=prev;
        head=later->next;
        later->next=current;
    
        prev=later;
    }
    head->next=prev;
}

int main() {
    head=NULL;//empty list
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    print();
    
    reversalList();
    printf("Reversal list is:\n");
    print();
}
