//Convert date to days 
//E.G. : 06/09/2022(June 9th) -> 160

#include <stdio.h>

int main(){
    int dia, mes, ano,somaTemp = 0;
    int somaDias=0;
  
    scanf("%d %d %d",&dia,&mes,&ano);
    somaDias += dia; //dia
    int meses[] = {31,28,31,30,31,30,31,31,30,31,30,31}; //mes
    for(int i = 0; i <mes-1;i++){
        somaDias += meses[i];
    }
    if((ano%4 == 0 && ano%100 !=0)|| ano % 400==0){ //bissexto
        (somaDias)++;
    }
    printf("%d\n",somaDias);
    return 0;
}
