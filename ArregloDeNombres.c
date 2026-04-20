#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void MostrarPersonas(char *vector[]);
void BuscarNombre(int n,char *vector[]);
int main(){
    char buff[50];
    char *vector[5];
    int n;
    for(int i=0;i<5;i++){
        printf("Ingrese el nombre:");
        fflush(stdin);
        gets(buff);
        int tamanioDeNombre=strlen(buff);
        vector[i]=(char *) malloc (sizeof(char)* tamanioDeNombre +1);
        strcpy(vector[i],buff);
    }
    MostrarPersonas(vector);
    printf("\nIngrese la posicon:");
    scanf("%d",&n);
    BuscarNombre(n,vector);
    for(int i=0;i<5;i++){
           free(vector[i]);
    }

  
  return 0;  
}
void MostrarPersonas(char *vector[]){
    for(int i=0;i<5;i++){
         printf("\n%s",vector[i]);
    }
}
void BuscarNombre(int n,char *vector[]){
    if(n<5){    
        printf("\n%s",vector[n]);
    }else{
        printf("no se encontró el valor buscado");
    }
}