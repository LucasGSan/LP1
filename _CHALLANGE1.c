//Problem Set 1 from CS50: Introduction to computer science(Week 1)
/*The program recreaters Super Mario pyramids using hashes (#) for bricks. The user decide how tall the pyramids should be by choosing a positive integer
between 1 and 12, inclusive and it stops when the user uses a negative integer.*/

#include <stdio.h>

int main(){
  int height;
  
  while(1){
      scanf("%d",&height);
      if(height <0){
          break;
      }
      if(height <= 12){
            for(int c = 0; c < height ; c++){
                for(int i = height-1; i > c; i--){
                    printf(" ");
              }
                for(int j = 0; j <= c ; j++){
                    printf("#");
              }
                printf(" ");
                for(int j = 0; j <= c ; j++){
                    printf("#");
              }
            printf("\n");
          }
          
      }
      else{
          printf("Invalid height! \n");
      }
  }
  
  printf("End");
  return 0;
}
