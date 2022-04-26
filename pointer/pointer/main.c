//
//  main.c
//  pointer
//
//  Created by xike on 2021/11/21.
//

#include <stdio.h>
void A(void)
{
    printf("Hello\n");
}

void B(void (*ptr)(void))//the pointer of the function 'void ptr(void)', pointer is address
                        // in ASM, it's same like the address combined by CS:IP
{
    ptr();//call-back function that *ptr() to
}

int main(void) {
    void (*p)(void) = A;//the *p() = A, so the address of p() = the address of A
    B (p);
    return 0;
}
