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
    struct node* next;
}node;

struct node* head;

node* NEWnode(struct node* newnode,int x){
    newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
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
    return;
}

void reversalLIST(node* temp1){//if we change 'temp1' to head, then all 'head' in this
                              //function is a local variable not global one.
    struct node* temp=temp1;
    head=temp; //this head is global varial
    struct node* p=NULL;
        if (temp->next==NULL){ //250->NEXT = NULL
            return;
        }
    reversalLIST(temp->next);//recursion//next=250,temp=200
    
    p=temp->next;//temp=200,p=250
    p->next=temp;
    temp->next=NULL;
    
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
    
    printf("the reversal list is: ");
    reversalLIST(head); //this head is global varial
    print();
    printf("\n");
    return 0;
}
