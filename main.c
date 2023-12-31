#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>

struct info{
    char nombre[20];
    int cantidad;
    float precio;
    int vacio;
    int codigo;
}Productos[10];

struct infoProv{
    char nombre[20];
    char direccion[20];
    char telefono[20];
    int codigo;
}Proveedor[10];

struct infoVentas{
    char nombre[20];
    char factura;
    float costo;
    int vacio;
}Ventas[100];

void Inicializador(struct Productos *info){
    for (int i=0;i<10;i++){
        strcpy(Productos[i].nombre, "-");
        Productos[i].cantidad = 0;
        Productos[i].precio = 0;
        Productos[i].vacio = 0;
        Productos[i].codigo = 0;
    }

    for (int i=0;i<10;i++){
        strcpy(Proveedor[i].nombre, "-");
        strcpy(Proveedor[i].direccion, "-");
        strcpy(Proveedor[i].telefono, "-");
        Proveedor[i].codigo = -1;
    }

    for (int i=0;i<10;i++){
        strcpy(Ventas[i].nombre,"-");
        Ventas[i].factura = '-';
        Ventas[i].costo = 0;
        Ventas[i].vacio = 0;
    }
}

void Agregar(struct Productos *info){
    int intentos = 1;
    for(int i=0;i<10;i++){
        if(Productos[i].vacio == 0){
            fflush(stdin);
            puts("Ingrese el nombre del producto: ");
            gets(Productos[i].nombre);
            puts("Ingrese la cantidad del producto: ");
            scanf("%d",&Productos[i].cantidad);
            puts("Ingrese el precio del producto: ");
            scanf("%f",&Productos[i].precio);
            puts("Ingrese el codigo del proveedor: ");
            scanf("%d",&Productos[i].codigo);
            Productos[i].vacio = 1;

            i = 11;
        }
        intentos = intentos +1;
    }

    if (intentos>10){
        puts ("No hay lugar para m�s productos, intente borrar alguno...");
    }
}

void Buscador(struct Productos *info){
    char buscador[20];
    int intentos = 1;
    puts("Ingrese el nombre del producto que desea buscar: ");
    fflush(stdin);
    printf("Buscar: ");
    gets(buscador);

    for (int i = 0; i<10; i++){
        if (strcmp(buscador,Productos[i].nombre)==0){
            printf("Producto: %s\n",Productos[i].nombre);
            printf("Cantidad: %i\n",Productos[i].cantidad);
            printf("Precio: %.1f\n",Productos[i].precio);
            printf("Codigo proveedor: %d\n",Productos[i].codigo);
            break;
        }
        intentos = intentos + 1;
    }

    if (intentos>10){
        puts("No se ha encontrado el producto :(");
    }
}

void Modificacion(struct Productos *info){
    int j = 1,op;
    puts("Qu� producto quiere modificar?");

    for(int i=0; i<10; i++){
        if(Productos[i].vacio == 1){
            printf("%d. %s\n",j,Productos[i].nombre);
                j = j + 1;
        }else{
                j = j;
        }

    }

    if (j==1){
    puts("\nNo hay productos....");
    }

    printf("\n%d. Salir\n",j);
    puts("Elegir opci�n: ");
    scanf("%d",&op);

    if(op>j || op<1){
        puts("Opcion invalida, intente de nuevo");
            puts("Elegir opci�n: ");
    scanf("%d",&op);

    }
    if (op == j){
        return 0;
    }else{
    for(int i=0;i<10;i++){
        if(op-1 == i){
            puts("A continuaci�n modifique el precio y stock del producto");
            printf("Stock anterior: %d\n",Productos[i].cantidad);
            printf("Stock nuevo: ");
            scanf("%d",&Productos[i].cantidad);
            printf("Precio anterior: %f\n",Productos[i].precio);
            printf("Precio nuevo: ");
            scanf("%f",&Productos[i].precio);
            break;
        }
    }
    }

}

void AgregarProveedor(struct Productos *info, struct Proveedor *infoProv){
    int intentos = 1;
    for(int i=0;i<10;i++){
        if(Productos[i].vacio == 0){
            fflush(stdin);
            puts("Ingrese el nombre del proveedor: ");
            gets(Proveedor[i].nombre);
            fflush(stdin);
            puts("Ingrese la direccion del proveedor: ");
            gets(Proveedor[i].direccion);
            fflush(stdin);
            puts("Ingrese el telefono del proveedor: ");
            gets(Proveedor[i].telefono);
            puts("Ingrese el codigo del proveedor: ");
            scanf("%d",&Productos[i].codigo);
            Productos[i].vacio = 1;

            i = 11;
        }
        intentos = intentos +1;
    }

    if (intentos>10){
        puts ("No hay lugar para m�s proveedores, intente borrar alguno...");
    }
}

void BuscadorProveedor(struct Productos *info, struct Proveedor *infoProv){
    int buscador;
    int intentos = 1;
    puts("Ingrese el c�digo del proveedor que desea buscar: ");
    printf("Buscar: ");
    scanf("%d",&buscador);

    for (int i = 0; i<10; i++){
        if (buscador == Productos[i].codigo){
                    if(Productos[i].cantidad==0){
                        puts("El proveedor no tiene productos disponibles...");
                    }else{
                        printf("Producto: %s\n",Productos[i].nombre);
                    printf("Cantidad: %i\n",Productos[i].cantidad);
                    printf("Precio: %.1f\n",Productos[i].precio);
                    printf("Codigo proveedor: %d\n",Productos[i].codigo);
                    }
        }else{
            intentos = intentos + 1;
        }
    }

    if (intentos>10){
        puts("No se ha encontrado el proveedor :(");
    }
}

void Vender(struct Ventas *infoVentas, struct Productos *info, struct Proveedor *infoProv){

    char buscador[20];
    int intentos = 1,cantidad;
    puts("Ingrese el nombre del producto que desea vender: ");
    fflush(stdin);
    printf("Buscar: ");
    gets(buscador);

    for(int i = 0; i<10; i++){
        if (strcmp(buscador,Productos[i].nombre)==0){
            puts("Cuantos desea vender?");
            scanf("%d",&cantidad);
            while (cantidad>Productos[i].cantidad){
                puts("Cantidad invalida, intente de nuevo...");
                puts("Cuantos desea vender?");
            scanf("%d",&cantidad);
            }
            for(int k = 0; k<10; k++){
                if(Ventas[k].vacio==0){
                fflush(stdin);
                puts("Ingrese el nombre del comprador: ");
                gets(Ventas[k].nombre);
                puts("Ingrese el tipo de factura: ");
                scanf(" %c",&Ventas[i].factura);

                Productos[i].cantidad= Productos[i].cantidad - cantidad;

                Ventas[k].costo = Productos[i].precio * cantidad;

                Ventas[k].vacio = 1;
                break;
                }
            }
            break;
        }else{
        intentos = intentos + 1;
        }

    }

    if (intentos>10){
        puts("No se ha encontrado el producto :(");
    }
}

void VerVentas(struct Ventas *infoVentas, struct Productos *info, struct Proveedor *infoProv){
    int j = 1,op;
    puts("Qu� venta quiere modificar?");

    for(int i=0; i<10; i++){
        if(Ventas[i].vacio == 1){
            printf("%d. %s\n",j,Ventas[i].nombre);
                j = j + 1;
        }else{
                j = j;
        }

    }

    if (j==1){
    puts("\nNo hay ventas....");
    }

    printf("\n%d. Salir\n",j);
    puts("Elegir opci�n: ");
    scanf("%d",&op);

    if(op>j || op<1){
        puts("Opcion invalida, intente de nuevo");
            puts("Elegir opci�n: ");
    scanf("%d",&op);

    }
    if (op == j){
        return 0;
    }else{
    for(int i=0;i<10;i++){
        if(op-1 == i){
            puts("A continuaci�n info sobre la venta: ");
            printf("Nombre del comprador: %s\n",Ventas[i].nombre);
            printf("Tipo de factura: %c\n",Ventas[i].factura);
            printf("Costo de la venta: %.1f\n",Ventas[i].costo);
            break;
        }
    }
    }

}

int main()
{
    int op, bandera = 0;
    int numAleatorio;

    struct info *Productos;
    struct infoProv *Proveedor;
    struct infoVentas *Ventas;

    srand(time(NULL));

        setlocale(LC_ALL, "");
    numAleatorio = ((rand()%10)+1);

    do{
            system("cls");
        puts("Primer parcial entrenamiento");
    puts("Menu ");
    puts("1. Inicializar");
    puts("2. Agregar producto");
    puts("3. Buscar producto");
    puts("4. Modificar producto");
    puts("5. Agregar proveedor");
    puts("6. Buscar por proveedor");
    puts("7. Vender");
    puts("8. Ver ventas");
    puts("9. Salir");
    puts("------------------------");
    printf("Opci�n: ");
    scanf("%d",&op);

    while (op>9 || op<1){
        puts("Opcion invalida, intente de nuevo...");
        puts("------------------------");
        printf("Opci�n: ");
        scanf("%d",&op);
    }

    switch(op){
        case 1:
            Inicializador(Productos);
            puts("Programa inicializado!!");
            system("pause");
            int inicio = 1;
            break;
        case 2:
            if(inicio!=1){
                puts("Debe incializar el programa");
                system("pause");
            }else{
            Agregar(Productos);
            puts("Producto agregado!!");
            system("pause");
            }
            break;
        case 3:
            if(inicio!=1){
                puts("Debe incializar el programa");
                system("pause");
            }else{
            Buscador(Productos);
            puts("Producto visto!!");
            system("pause");
            }
            break;
        case 4:
            if(inicio!=1){
                puts("Debe incializar el programa");
                system("pause");
            }else{
            Modificacion(Productos);
            puts("Producto modificado!!");
            system("pause");
            }
            break;
        case 5:
            if(inicio!=1){
                puts("Debe incializar el programa");
                system("pause");
            }else{
            AgregarProveedor(Productos,Proveedor);
            system("pause");
            }
            break;
        case 6:
            if(inicio!=1){
                puts("Debe incializar el programa");
                system("pause");
            }else{
            BuscadorProveedor(Productos,Proveedor);
            system("pause");
            }
            break;
        case 7:
            if(inicio!=1){
                puts("Debe incializar el programa");
                system("pause");
            }else{
            Vender(Ventas, Productos, Proveedor);
            system("pause");
            }
            break;
        case 8:
            if(inicio!=1){
                puts("Debe incializar el programa");
                system("pause");
            }else{
            VerVentas(Ventas,Productos, Proveedor);
            system("pause");
            }
            break;
        case 9:
            bandera = 1;
            break;
    }
    }while(bandera != 1);


    return 0;
}
