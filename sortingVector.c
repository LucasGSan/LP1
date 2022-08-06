#include<stdio.h>
#include<stdlib.h>

int main(){
    float *vetor;
    int tam;
    float aux;
    scanf("%d",&tam);
    vetor =malloc(tam*sizeof(float));
    
    for(int i=0;i<tam;i++){
        scanf("%f",&vetor[i]);
    }
    for(int j=0;j < tam;j++){
        for(int k=0;k<tam-1;k++){
            if(vetor[k]<vetor[k+1]){
                aux = vetor[k];
                vetor[k] = vetor[k+1];
                vetor[k+1] = aux;
            }
        }
    }

    for(int i=0;i<tam;i++){
        if(vetor[i] == (int)vetor[i]){
        printf("%d ",(int)vetor[i]);       
        }
        else{
        printf("%.1f ",vetor[i]);
        }
    }
    free(vetor);
    return 0;
}
