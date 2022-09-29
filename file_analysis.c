#include <stdio.h>
#include <ctype.h>

int main(){
    int count=0;
    int lineCount=0;
    int printable=0;
    FILE* file;
    char fileName[50],c;
    
    scanf("%s", fileName);
    file = fopen(fileName,"r");
    if (!file){
        printf("Erro no arquivo %s\n",fileName);
        return -1;
    }
    else{
        while( (c = fgetc(file)) != EOF){
		    count++;
	        if(c=='\n'){
		        lineCount++;
		    }
		    if(isprint(c)){
		        printable++;
		    }
	    }
    }

    fclose(file);
    printf("%d\n",count);
    printf("%d\n",printable);
    printf("%d\n", lineCount);
