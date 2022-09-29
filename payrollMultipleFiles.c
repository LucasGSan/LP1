//main
#include "funcoes.h"

int main(){
    FILE *file;
    FILE * month;
    FILE * final;
    cadastro funcionario[10];
    mes novembro[10];
    file = fopen("Funcionarios.txt","r");
    if (file == NULL){
        fprintf(stderr,"Erro: arquivo Funcionarios.txt inexistente\n");
    }
    month = fopen("Novembro.txt","r");
    if (month == NULL){
        fprintf(stderr,"Erro: arquivo Novembro.txt inexistente\n");
    }
    final = fopen("Final.txt","w");
    int i=0;
    while(i < 10){
        funcionario[i] = read(file);
        novembro[i] = readMonth(month);
        i++;
    }
    for(int l = 0; l < 9;l++){
        for(int m = 0; m<9;m++){
            if(strcmp(funcionario[m].nome,funcionario[m+1].nome)>0){
                cadastro aux = funcionario[m];
                funcionario[m] = funcionario[m+1];
                funcionario[m+1] = aux;
            }
        }
    }
    for(int n = 0; n < 10;n++){
        for(int o = 0; o < 10; o++){
            if(strcmp(funcionario[n].matricula,novembro[o].matricula)==0){
                funcionario[n].valor_hora *= novembro[o].horas;
                fprintf(final,"%s|%s|%s|%s|%s|%.2f\n",funcionario[n].nome,funcionario[n].cpf,funcionario[n].cod_banco,funcionario[n].agencia,funcionario[n].conta,funcionario[n].valor_hora);
                printf("%s|%s|%s|%s|%s|%.2f\n",funcionario[n].nome,funcionario[n].cpf,funcionario[n].cod_banco,funcionario[n].agencia,funcionario[n].conta,funcionario[n].valor_hora);
            }
        }
    }
    fclose(file);
    fclose(month);
    fclose(final);
    return 0;
}

//functions.h
#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[51];
    char matricula[13];
    char endereco[66];
    char cpf[12];
    char cod_banco[4];
    char agencia[6];
    char conta[9];
    float valor_hora;
}cadastro;

typedef struct{
    char matricula[13];
    int horas;
}mes;

cadastro read(FILE*);
//void print(cadastro[]);
mes readMonth(FILE * file);

//functions.c
#include"funcoes.h"

mes readMonth(FILE * month){
    mes mess;
    fgets(mess.matricula,13,month);
    fgetc(month);
    fscanf(month,"%d\n",&mess.horas);
    return mess;
    
}

cadastro read(FILE* file){
    cadastro temp;
    fgets(temp.nome,51,file);
    getc(file);
    fgets(temp.matricula,13,file);
    getc(file);
    fgets(temp.endereco,66,file);
    getc(file);
    fgets(temp.cpf,12,file);
    getc(file);
    fgets(temp.cod_banco,4,file);
    getc(file);
    fgets(temp.agencia,6,file);
    getc(file);
    fgets(temp.conta,9,file);
    getc(file);
    fscanf(file,"%f",&temp.valor_hora);
    getc(file);
    return temp;
}
