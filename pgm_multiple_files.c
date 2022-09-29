//main

#include <stdlib.h>
#include "functions.h"

int main(){
    FILE* file;
    pgm image;
    char fileName[20];
    scanf("%s",fileName);
    image = read(fileName,image);
    print(image);
    free(image.bitmap);
    return 0;
}

//functions.c
#include "functions.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>



pgm read(char fileName[20],pgm image){
    FILE* file;
    file = fopen(fileName,"r");
    image = Header(file,fileName,image);
    fscanf(file,"%d %d",&image.Cols,&image.Rows);
    fscanf(file, "%u", &image.maximum);
    image.bitmap = pixels(file,image);
    return image;
    fclose(file);
}
pgm Header(FILE* file, char fileName[],pgm image){
        if (file == NULL){
        fprintf(stderr,"Erro: arquivo inexistente\n");
        exit(1);
    }
    char Header [255];
    if(fscanf(file,"%s",Header)!=1){
      fprintf(stderr,"Arquivo corrompido\n");
      exit(2);
    }
   
    if (strcmp(Header,"P2")){
         fprintf(stderr,"Formato inválido\n");
         exit(3);
    }
    while(getc(file) != '\n');
    while (getc(file) == '#'){
        while (getc(file) != '\n');
   }
   fseek(file, -1, SEEK_CUR); 
}
unsigned int* pixels(FILE* file,pgm image){
    image.bitmap = malloc(image.Cols*image.Rows*4);
    unsigned int *iterator = image.bitmap;
    for (int i = 0; i < image.Rows; i++){
        for (int j = 0; j < image.Cols; j++, iterator++){
            if(fscanf(file,"%u",iterator)!=1){
                perror("Arquivo ruim\n");
                exit(5);
            }
        }
    }
    return image.bitmap;
}

void print(pgm image){
    for(int i=0;i<image.Rows;i++){
        for(int j=0;j<image.Cols;j++,image.bitmap++){
            if(j==0){
                printf("%3X",*image.bitmap);
            }
            else{
                printf(" %3X",*image.bitmap);
            }
        }
    printf("\n");
    }
}

//functions.h
#include<stdio.h>

typedef struct{
    int Cols;
    int Rows;
    unsigned int maximum;
    unsigned int *bitmap;
}pgm;

void print(pgm);
pgm read(char[],pgm);
unsigned int* pixels(FILE*,pgm);
pgm Header(FILE*, char[],pgm);
