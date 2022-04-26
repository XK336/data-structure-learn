//
//  main.c
//  recursionOUTP
//
//  Created by xike on 2021/11/19.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
}node;

struct node* head;

node* NEWnode(struct node* newnode,int x){//create a new node in dynamic memory(heap)
    newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

node* insert(node* head,int x){
    struct node* newnode = NULL;
    struct node* temp=NULL;
    temp=NEWnode(newnode,x);
    
    struct node* temp1=head;
    if (head==NULL){
        head=temp;
    }
    else if(head !=NULL){
        while(temp1->next!=NULL){
        temp1=temp1->next;
        }
        temp1->next=temp;
        temp->prev=temp1;
    
    }
        
    return head;
}

void print(void){
    struct node* temp=head;
    printf("the list is: ");
    while (temp !=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reversal_print(void){
    struct node* temp=head;
    while (temp->next !=NULL){
        temp=temp->next;
    }
    printf("the reversial list is: ");
    while (temp !=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void reversal_link(void){
    struct node* temp=head;
    while (temp->next !=NULL){
        temp=temp->next;
    }
    head=temp;
    struct node* temp1=NULL;
    while(temp != NULL){
        temp1=temp->prev;
        temp->prev=temp->next;
        temp->next=temp1;
        temp=temp1;
    }
    
        
}

int main() {
    head=NULL;//empty list
    
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,5);
    head=insert(head,6);
    
    print();
    
    reversal_print();
    
    reversal_link();
    print();
    
}

