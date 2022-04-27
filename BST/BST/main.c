//
//  main.c
//  BST
//
//  Created by xike on 2021/11/26.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct BSTNODE{
    int data;
    struct BSTNODE* left;
    struct BSTNODE* right;
}BSTNODE;

BSTNODE* root=NULL;

int searchT(BSTNODE* root,int x){
    if (root == NULL){return 0;}
    else if (root->data == x){return 1;}
    else if (x <= root->data){
        return searchT(root->left,x);
    }
    else {
        return searchT(root->right, x);
    }
}

BSTNODE* newnode(int x){
    struct BSTNODE* newnode=(BSTNODE*)malloc(sizeof(BSTNODE));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    
    return newnode;
}

BSTNODE* insert(BSTNODE* root , int data){

    if (root == NULL){
        root = newnode(data);
    }
    
    else if (data <= root->data){
        root->left=insert(root->left,data);
    }
    else if (data > root->data){
        root->right=insert(root->right,data);
    }
    
    return root;
}

int main() {
    root=insert (root,4);
    root=insert (root,5);
    root=insert (root,3);
    root=insert (root,4);
    root=insert (root,2);
    root=insert (root,8);
    int number;
    printf("enter number be searched\n");
    scanf("%d",&number);
    if (searchT(root, number) == 1){
        printf("Found\n");
    }
    else {printf("not found\n");}
    printf("root->data=%d\n",root->data);
    
    
}
