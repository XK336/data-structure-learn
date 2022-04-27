//
//  main.c
//  array2queues
//
//  Created by xike on 2021/11/25.
//

#include <stdio.h>
#define MAX 10
int rear=-1;
int tail=-1;
int temp=-1;
int a[MAX];
void push(int x){
    if (rear==-1){
        rear=0;
        tail=0;
        a[rear]=x;
    }
    if (tail==temp){
        printf("error:full queue can not add number any more\n");
        return;
        }
    a[tail]=x;
    temp=tail;
    tail=(tail+1)%10;
    if (tail==rear){
        tail=temp;
        return;
        }
}


void delete(void){
    if (rear == -1){
        printf("error: empty queue can not do delete\n");
        return;
    }
    a[rear]=0;
    if (rear == tail){
        rear=-1;
        tail=-1;
        return;
    }
    rear=(rear+1)%10;
    
    
}

void print(void){
    int i=0;
    while (i<MAX){
        printf("%d ",a[i]);
        i++;
    }
    printf("\n");
}

int main(void) {
    push(10);
    push(5);
    push(3);
    push(3);
    push(3);
    print();
    
    delete();
    delete();
    print();
    
    push(10);
    push(5);
    push(3);
    push(3);
    push(3);
    print();
    push(10);
    push(5);
    push(5);
    print();
}
