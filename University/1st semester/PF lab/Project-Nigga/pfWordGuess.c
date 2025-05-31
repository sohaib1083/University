#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>

void setcolor(int value){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
int main(){
	srand(time(0));
    char word[10][7]={"paris" ,"music","tiger","panda","donut","prince","earth","baker","faith","sport","women","heart","model","sound","horse" };
    char guess[6],c[6];
    int i,a,tries,b;
    
  a=rand()%5;
  tries=6;
  do{
  	printf("Write a five letter word");
  	printf("\nInput your guess(remember you have got 6 tries!):");
  gets(guess);
  for(i=0;i<5;i++){
  	if(guess[i]==word[a][i]){
  		c[i]=guess[i];
	  }
}
  for(i=0;i<=5;i++){
  	setcolor(2);
  	printf("%c",c[i]);
  }
  	setcolor(7);
  		b=strcmp(word,guess);
  		if(b==0){
  			printf("\nCorrect");
            break;
		  }
		  
tries--;

  } while(tries>1);
  for(i=0; i<5; i++){
  	printf("The correct word: %c", word[a][i]);
  }
}
