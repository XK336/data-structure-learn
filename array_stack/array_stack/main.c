//
//  main.c
//  array_stack
//
//  Created by xike on 2021/11/25.
//

#include <stdio.h>
#define MAX 10
int a[MAX];
int top=-1;
void print(void){
    int i = 0;
    while (i<=top){
        printf("%d ",a[i]);
        i++;
    }
    printf("\n");
}
void pop(void){
    if (top==-1){
        printf("error:array is empty\n");
        return;
    }
    top--;
}
void push (int x){
    top++;
    if (top>=MAX){
        printf("error:array is full\n");
        return;
    }
    a[top]=x;
}
int main(void) {

    push(10);
    push(3);
    push(5);
    print();
    pop();
    print();
    push(5);
    push(5);
    push(5);
    push(5);
    push(5);
    push(5);
    push(5);
    push(5);
    push(5);
    print();
}
