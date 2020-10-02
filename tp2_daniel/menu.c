#include <stdio.h>
#include "employees.h"
#include "menu.h"
#include <string.h>
#include <stdlib.h>
#define T 1000



void menuDos(sEmployee list[T], int len)
{
    int answer;
    float salaries;
    float averages;


    salaries = 0;
    averages = 0;


    system("cls");
    do
    {


        printf("\t\n\n\n-----Bienvenido al Menu de Empleados-----\n\n\n");
        printf("\t1. Mostrar Empleado ordenados.\n\t2. Mostar Empleados con salario excedido del promedio.\n\t3. Salir.");
        scanf("%d", &answer);

        switch(answer)
        {
        case 1:
            system("cls");
            sortEmployees(list, T);
            printEmployees(list, T);

            break;
        case 2:
            salaries = AllSalaries(list, T);
            averages = averageSalaries(list, T);

            system("cls");

            printf("\n\nLa suma de todos los salarios es: %2.f", salaries);
            printf("\n\nEl promedio de todos  los salarios es: %2.f", averages);
            printf("\n\nEl/Los empleados con salario por arriba del promedio son:\n");
            exceedAverage(list, T);




            break;
        case 3:
                system("cls");
            break;
        default:
            printf("\n\n\n  No seleccionaste una opcion existente! \n\n\n");
            break;

        }





    }
    while(answer!=3);





}


void menuUno(sEmployee list[], int len)
{
    int answer;
    int idAIngresar;
    int aux;
    int flag;



    flag=0;


    do
    {


        printf("\t\n\n\n-----Bienvenido al Menu-----\n\n\n");
        printf("\t1. Agregar un Empleado.\n\t2. Modificar un Empleado.\n\t3. Remover un Empleado.\n\t4. Informar empleados.\n\t5. Salir. ");
        scanf("%d", &answer);

        switch(answer)
        {


        case 1:

            chargeListOfEmployees(list, T);
            flag=1;
            break;


        case 2:
            if(flag==1)
            {

                printEmployees(list, T);
                printf("\nIngrese el ID a modificar: ");
                scanf("%d",&idAIngresar);
                modifyAnEmployee(list, T, idAIngresar );



            }
            else
            {

                printf("\n Necesita ingresar al menos 1 empleado para acceder a esta opcion");

            }
            break;
        case 3:

            if(flag==1)
            {

                printEmployees(list, T);
                printf("\nIngrese el ID a eliminar: ");
                scanf("%d",&idAIngresar);
                aux = removeEmployee(list, T, idAIngresar);

                if(aux == 1)
                {
                    system("cls");
                    printf("\n\n La eliminacion fue exitosa \n");

                }
                else
                {
                    system("cls");
                    printf("\n\n No se pudo encontrar el ID \n\n");

                }


            }
            else
            {

                printf("\n Necesita ingresar al menos 1 empleado para acceder a esta opcion");

            }
            break;

        case 4:
            if(flag==1)
            {

                menuDos(list, T);


            }
            else
            {

                printf("\n Necesita ingresar al menos 1 empleado para acceder a esta opcion");
                break;
            }

            break;
        case 5:

            break;
        default:
            printf("\n\n La opcion que seleccionaste no existe! \n\n");
            break;




        }

    }
    while(answer!=5);







}

