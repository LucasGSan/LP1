#include <stdio.h>

int main(){
	FILE* arq1;
	FILE* arq2;
	FILE* saida;
	int num1=0;
	int num2=0;
	int contador=0;
	arq1 = fopen("arq1.txt","r");
	if(arq1 == NULL){
		printf("Erro ao abrir arq1.txt\n");
	}
	arq2 = fopen("arq2.txt","r");
	if(arq2 == NULL){
		printf("Erro ao abrir arq2.txt\n");
	}
	saida = fopen("saida.txt","w");
	if(saida == NULL){
		printf("Erro ao abrir saida.txt\n");
	}	
	while(((fscanf(arq1,"%d",&num1))!= EOF)&&(fscanf(arq2,"%d",&num2)!=EOF)){
		if(num1!=num2){
			if(num1<num2){
				fprintf(saida,"%d\n",num1);
				fscanf(arq1,"%d",&num1);
			}
			if(num1>num2){
				fprintf(saida,"%d\n",num2);
				fscanf(arq2,"%d",&num2);
			}
			contador++;
		}	
		if(num1!=num2){
			contador++;
			fprintf(saida,"%d\n",num1);
		}	
		if(num1==num2){
			contador++;
			fprintf(saida,"%d\n",num1);
		}
	}
	fscanf(arq1,"%d",&num1);
	fprintf(saida,"%d\n",num1);
	contador++;
	printf("%d",contador);
	fclose(arq1);
	fclose(arq2);
	fclose(saida)
	return 0;
}
