#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void MostrarPersonas(char *vector[]);
void BuscaNombrePorId(int n,char *vector[]);
int BuscaNombrePorPalabra(char *palabra, char *vector[]);
int main(){
    char buff[50];
    char *vector[5];
    int n;
    char palabra[30];
    int opcion;
    for(int i=0;i<5;i++){
        printf("Ingrese el nombre:");
        fflush(stdin);
        gets(buff);
        int tamanioDeNombre=strlen(buff);
        vector[i]=(char *) malloc (sizeof(char)* tamanioDeNombre +1);
        strcpy(vector[i],buff);
    }
    printf("Ingrese la opcion(1,2):");
    scanf("%d",&opcion);
    MostrarPersonas(vector);
    switch(opcion){
        case 1:
            printf("\nIngrese la posicon:");
            scanf("%d",&n);
            BuscaNombrePorId(n,vector);
        break;
        case 2:  
            printf("\nIngrese la palabra:");
            fflush(stdin);
            gets(palabra);
            int posicion=BuscaNombrePorPalabra(palabra,vector);
            printf("%d",posicion);     
        break;
        default:
        break;
    }
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
void BuscaNombrePorId(int n,char *vector[]){
    if(n<5){    
        printf("\n%s",vector[n]);
    }else{
        printf("no se encontró el valor buscado");
    }
}
int BuscaNombrePorPalabra(char *palabra, char *vector[]){
    for(int i=0;i<5;i++){
        if(strstr(vector[i],palabra)!=NULL){
            return i;
        }
    }
    return -1;
}