#include <stdio.h>
#include <string.h>

int main(){
    char frase[1024];
    char *pont;
    int cont = 0;

    fgets(frase,1024,stdin);
    pont = strtok(frase,"' ''' .,;:\t\n");
    while(pont){
        pont = strtok(NULL, "' ''' .,;:\t\n");
        cont++;
    }
    printf("%d",cont);
    return 0;
}
