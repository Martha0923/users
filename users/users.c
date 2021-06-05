#include<stdio.h>
#include<stdlib.h>

typedef struct user{
   char nombre[20]; //Declaro variable nombre, con un maximo de 20 usuarios
   int ID;        // variable ID
   int tiempo;   // Variable tiempo transcurrido
}USER;

int main()
{
   FILE *file;
   //Matriz donde se almacenran los usuarios
   USER array[20];
   USER temp;
   int index=0,i,j,choice,id,flag;
   //Abrir el archivo en modo de lectura y escritura
   file=fopen("user_list.txt","r");
   //leer informacion del archivo
   while(fscanf(file,"%s",array[index].nombre)!=EOF)
   {
      
       fscanf(file,"%d",&array[index].ID);
       fscanf(file,"%d",&array[index].tiempo);
       index++;
      
      
   }
   //cerrar archivo
   fclose(file);
  
   //le pido que me muestre el menu
   while(1)
   {
       printf("Presione 1 para imprimir lista de usuarios\n"); //Presione 1 para imprimir lista de usuarios
       printf("Presione 2 para imprimir estado de usuario\n"); // presione 2 para imprimir estado del usuario
       printf("Presione 3 para saber ultimo acceso\n"); // presione 3 para conocer ultimo acceso
       printf("Presione 4 para actualizar datos\n"); // presione 4 para actualizar datos
       printf("Presione 5 para salir y guardar\n"); // presione 5 para salir y guardar
       printf("Ingrese numero: "); //Le pido que me diga que quiere
       scanf("%d",&choice);
       switch(choice)
       {
           case 1: //le pido que me imprima la lista
                   printf("%-20s%-12s%s\n","Nombre","ID","Ultimo acceso");
                   for(i=0;i<index;i++) // inicio con i igual 0 y mientras i sea menor index i se ira incrementando en uno despues de cada eje                                            cucion del for
                   {
                       printf("%-20s%-12d%d\n",array[i].nombre,array[i].ID,array[i].tiempo);
                   }
                   printf("\n");
                   break;
           case 2:
                   for(i=0;i<index;i++)
                   {
                       printf("%s: ",array[i].nombre);
                       if(array[i].tiempo==0)
                       {
                           printf("activo\n");
                       }
                       else if(array[i].tiempo==1)
                       {
                           printf("reciente\n");
                       }
                       else{
                           printf("inactivo\n");
                       }
                   }
                   printf("\n");
                   break;
           case 3: //Ordenar acorde al ultimo que tuvo acceso
                   for(i=0;i<index-1;i++)
                   {
                       for(j=0;j<index-i-1;j++)
                       {
                           if(array[j].tiempo>array[j+1].tiempo){
                               //intercambiar valores
                               temp=array[j];
                               array[j]=array[j+1];
                               array[j+1]=temp;
                           }
                       }
                   }
                   //imprimir la lista
                   printf("%-20s%-12s%s\n","Nombre","ID","Ultimo acceso");
                   for(i=0;i<index;i++)
                   {
                       printf("%-20s%-12d%d\n",array[i].nombre,array[i].ID,array[i].tiempo);
                   }
                   printf("\n");
                   break;
           case 4: //preguntar por id del usuario
                   printf("Ingrese ID: ");
                   scanf("%d",&id);
                   flag=0;
                   //Buscar nombre en la lista 
                   for(i=0;i<index;i++)
                   {
                       if(id==array[i].ID)
                       {
                           //Luego de que los id coiniciden, actualizar los otros valores
                           printf("Ingrese nombre de usuario: ");
                           scanf("%s",array[i].nombre);
                           printf("Ingrese ultima hora de acceso: ");
                           scanf("%d",&array[i].tiempo);
                           flag=1;
                           break;
                       }
                   }
                   if(flag==0)
                   {
                       printf("ID no encontrado");
                   }
                   printf("\n");
                   break;
           case 5: //escribir la matriz en el archivo y salir
                   //abrir archivo en modo escritura
                   file=fopen("user_list.txt","w");
                   for(i=0;i<index;i++)
                   {
                       fprintf(file,"%s\n%d\n%d\n",array[i].nombre,array[i].ID,array[i].tiempo);
                   }
                   //cerrar archivo
                   fclose(file);
                   //salir
                   exit(0);
           default: printf("Eleccion incorrecta\n\n");
      
       }
   }
  
}


