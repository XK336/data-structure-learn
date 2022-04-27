//
//  main.c
//  link2queue
//
//  Created by xike on 2021/11/26.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
struct node* rear=NULL;
struct node* tail=NULL;
void push(int x){
    struct node* temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->next=NULL;
    if (rear==NULL){
        rear=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
void delete(void){
    if (rear==NULL){
        printf("empty queue can not do delete\n");
        return;
    }
    if (rear==tail){
        rear->data=0;
        rear=NULL;
        return;
    }
    rear->data=0;
    rear=rear->next;
}
void print(void){
    struct node* temp=rear;
    while (temp !=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}
int main(void) {
    push(4);
    push(3);
    push(2);
    print();
    delete();
    push(4);
    
    print();
    delete();
    delete();
    delete();
    delete();
    delete();
    push(4);
    print();
}
