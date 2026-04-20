#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};
struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *producto; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir”
};
float costoTotal(struct Producto producto);
void mostrarDatos(struct Cliente *cliente,int cant);
int main(){
int cant;
char buff[50];
do{
  printf("Cuantos clientes visitaras:");
  scanf("%d",&cant);
}while(cant<1 || cant>5);
  struct Cliente *cliente=( struct Cliente*) malloc(sizeof(struct Cliente)* cant);
  for(int i=0 ;i<cant;i++){
    cliente[i].ClienteID=i+1;
    printf("\nIngrese su nombre de usuario:");
    fflush(stdin);
    gets(buff);
    int tama=strlen(buff);
    cliente[i].NombreCliente=(char *)malloc(sizeof(char)*tama+1);
    strcpy(cliente[i].NombreCliente,buff);
    cliente[i].CantidadProductosAPedir=rand() % 5 +1;
    cliente[i].producto=( struct Producto*) malloc(sizeof(struct Producto)* cliente[i].CantidadProductosAPedir);
    for(int j=0;j<cliente[i].CantidadProductosAPedir;j++){
      cliente[i].producto[j].ProductoID=j+1;
      cliente[i].producto[j].Cantidad=rand() % 10 +1;
      cliente[i].producto[j].TipoProducto=TiposProductos[rand() % 5];
      cliente[i].producto[j].PrecioUnitario=rand() % 91 + 10;
    }
  }
   mostrarDatos(cliente,cant);
  for(int i=0;i<cant;i++){
    free(cliente[i].NombreCliente);
    free(cliente[i].producto);
  }
  free(cliente);

  return 0;  
}
float costoTotal(struct Producto producto){
  float CostoTotal;
  CostoTotal=producto.Cantidad * producto.PrecioUnitario;
  return CostoTotal;
}
void mostrarDatos(struct Cliente *cliente,int cant){
  for(int i=0;i<cant;i++){
    float costo=0;
    printf("\nCliente ID:%d",cliente[i].ClienteID);
    printf("\nNombre del Cliente:%s",cliente[i].NombreCliente);
    printf("\nCantidad de productos a pedir:%d",cliente[i].CantidadProductosAPedir);
    for(int j=0;j<cliente[i].CantidadProductosAPedir;j++){
      printf("\nProducto ID:%d",cliente[i].producto[j].ProductoID);
      printf("\nCantidad:%d",cliente[i].producto[j].Cantidad);
      printf("\nTipo de Producto:%s",cliente[i].producto[j].TipoProducto);
      printf("\nPrecio Unitario:%f",cliente[i].producto[j].PrecioUnitario);
      costo= costo +costoTotal(cliente[i].producto[j]);
      printf("\nCosto:%f",costo);
    }
  }
}