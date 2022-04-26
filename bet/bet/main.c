//
//  main.c
//  bet
//
//  Created by xike on 2021/11/21.
//
// "simple betting game"
// "Jack","Queen","King"
// when the position player input of Queen is corrct, give player 3 times of bet
// whne the position player iniput of Queen is wrong, delete the bet
// give player cash: 100$ at beginning
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash= 100;

int shuffle_po(int bet){
    char* C = (char*)malloc(3*sizeof(char));
    C[0]='J';C[1]='Q';C[2]='K';
    printf("shuffling ... \n");
    srand(time(NULL));
    int i;
    for (i=0; i<10; i++){ //shuffle 5 times
        int x = rand()%3;//the value of x,y can be only from 0,1,2
        int y = rand()%3;
        int temp = C[x]; C[x]=C[y];C[y]=temp;//shuffle the position
    }
    int n;
    printf("what is the position of Queen? 1? 2? 3?\nthe number:");
    scanf ("%d",&n);
    printf("\n");
    if (C[n-1] == 'Q'){
        cash += 3*bet;
        printf("you Win! the result is \"%c %c %c\"\nthe total cash = $%d\n",C[0],C[1],C[2],cash);
    }
    else {
        cash -= bet;
        printf("you Loose! the result is \"%c %c %c\"\nthe total cash = $%d\n",C[0],C[1],C[2],cash);
    }
    free(C);
    return 0;
}
int main() {
    int bet;
    printf("welcome to betting game\n");
    printf("total cash is $%d\n",cash);
    while (cash>0){
        printf("how much your bet is in this round:$");
        scanf("%d",&bet);
        printf("\n");
        if ((bet != 0) && (bet <= cash)){
            shuffle_po(bet);
        }
        else {printf("cash is not enough\n");}
    }
    printf("total cash is $%d\n",cash);
    printf("********GAME OVER**********\n");
}
