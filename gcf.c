//Calculate the Greatest Common Factor of two integers

#include<stdio.h>

void ordena();

int main(){
    int a,b,aux,aux2;
    scanf("%d %d",&a,&b);
    ordena(&a,&b);
    for(int i=1;i<b;i++){
        if(a%i==0 && b%i==0){
            aux = i;
            aux2 = i;
        }
    }
    if(aux == aux2){
        printf("%d",aux);
    }
}

void ordena(int*a,int*b){
    int aux;
    if(*a>*b){
        aux = *a;
        *a = *b;
        *b = aux;
    }
}
