#include <stdio.h>
#include <string.h>
#include "employees.h"
#include <stdlib.h>
#define T 1000


int AllSalaries(sEmployee list[], int len)
{
    int i;
    float acc;

    acc = 0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty != 1)
        {

            acc = list[i].salary + acc;

        }



    }

    return acc;
}



int accEmployees(sEmployee list[], int len)
{
    int i;
    float acc;

    acc = 0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty != 1)
        {

            acc++;

        }



    }

    return acc;
}


int averageSalaries(sEmployee list[], int len)
{
    float accSalaries;
    float result;
    float allEmployees;

    allEmployees = 0;
    result = 0;

    allEmployees = accEmployees(list, len);

    accSalaries = AllSalaries(list,len);

    result = accSalaries / allEmployees;



    return result;

}



void exceedAverage(sEmployee list[], int len)
{
    int i;
    float averages;


    averages = averageSalaries(list, len);




    printf("  ID     Nombre    Apellido   Salario   Sector");

    for(i=0; i<len ; i++)
    {



        if(averages < list[i].salary && list[i].isEmpty != 1)
        {



            printf ("\n%5d", list[i].id);
            printf ("%10s", list[i].name);
            printf ("%10s", list[i].lastName);
            printf ("%10.f", list[i].salary);
            printf ("%10d", list[i].sector);



        }


    }





}




int searchFree(sEmployee list[], int len)
{

    int i;
    int index;

    index=-1;


    for(i=0; i<len; i++)
    {

        if(list[i].isEmpty == 1)
        {
            index=i;
            break;
        }


    }

    return index;

}


void
initEmployees (sEmployee list[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {

        list[i].isEmpty = 1;
        list[i].id = -1;


    }




}


void chargeListOfEmployees(sEmployee list[], int len)
{
    int i;



    i = searchFree(list, len);

    if(i != -1)
    {
        if(list[i].isEmpty == 1 )
        {
            system("cls");
            list[i] = addEmployee();
            list[i].id = 1+i;
            list[i].isEmpty = 0;
        }
        else
        {
            printf("\n\nNo hay mas espacio! \n\n");

        }

        if(list[i].isEmpty == 0)
        {
            system("cls");

            printf("\n La carga fue exitosa \n");

        }
        else
        {
            system("cls");

            printf("\n No se pudo realizar la carga \n");

        }


    }



}


sEmployee addEmployee ()
{

    sEmployee  aEmployee;

    printf ("\nIngrese el Nombre: ");
    fflush(stdin);
    scanf ("%s", aEmployee.name);

    printf ("Ingrese el Apellido: ");
    fflush(stdin);
    scanf ("%s",aEmployee.lastName);

    printf ("Ingrese el salario: ");
    scanf ("%f", &aEmployee.salary);

    printf ("Ingrese el sector: ");
    scanf ("%d", &aEmployee.sector);



    return aEmployee;

}



int removeEmployee (sEmployee list[], int len, int id)
{

    int i;
    int retorno;


    for(i=0; i<len; i++)
    {

        if(id == list[i].id && list[i].isEmpty != 1)
        {
            list[i].isEmpty=1;
            list[i].id = 0;
            retorno = 1;

            break;

        }
        else if(list[i].id != id && list[i].isEmpty == 1)
        {

            retorno = 0;

        }

    }
    return retorno;

}




void sortEmployees(sEmployee list[], int len)
{
    int i;
    int j;
    sEmployee auxEmployee;



    for(i = 0; i < len - 1; i++)
    {
        for( j = i + 1; j < len; j++)
        {
            if(list[i].sector > list[j].sector && list[i].isEmpty != 1 && list[j].isEmpty != 1)
            {


                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;


            }




        }
    }


    for(i = 0; i < len - 1; i++)
    {
        for( j = i + 1; j < len; j++)
        {
            if(list[i].sector == list[j].sector && list[i].isEmpty != 1 && list[j].isEmpty != 1)
            {

                if(strcmp(list[i].lastName,list[j].lastName)>0 && list[i].isEmpty != 1 && list[j].isEmpty != 1)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }



            }




        }
    }



}



void printOneEmployee (sEmployee showAEmployee)
{

    printf ("\n%5d", showAEmployee.id);
    printf ("%10s", showAEmployee.name);
    printf ("%10s", showAEmployee.lastName);
    printf ("%10.f", showAEmployee.salary);
    printf ("%10d", showAEmployee.sector);

}


void printEmployees (sEmployee list[], int len)
{
    int i;

    printf("    ID   Nombre    Apellido   Salario     Sector");

    for (i = 0; i < len; i++)
    {
        if(list[i].isEmpty != 1)
        {

            printOneEmployee (list[i]);

        }


    }



}



int findEmployeeById (sEmployee list[], int len, int id)
{
    int i;
    int index;

    index = -1;


    for (i = 0; i < len; i++)
    {

        if (list[i].id == id)
        {
            if(list[i].isEmpty != 1)
            {
                index=i;
                break;
            }

        }


    }

    return index;

}




void modifyAnEmployee(sEmployee list[], int len, int id)
{
    int i;
    char ans;
    int index;
    char auxName[20];
    char auxLastName[20];
    float auxSalary;
    int auxSector;
    char ansAux;


    index = 0;


    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty != 1 && id == list[i].id)
        {

            printf("\n\nQue queres modificar?");
            printf("\n 1- Nombre \n 2- Apellido \n 3-Salario \n 4- Sector ");
            fflush(stdin);
            scanf("%c", &ans);


            switch(ans)
            {

            case '1':
                printf("\nIngrese el nuevo Nombre: ");
                fflush(stdin);
                scanf("%s",&auxName);

                printf("\n Esta seguro que quiere modificar el Nombre? (s-n) ");
                fflush(stdin);
                scanf("%c",&ansAux);

                if(ansAux=='s')
                {
                    strcpy(list[i].name, auxName);
                    index = 1;
                }
                else
                {

                    printf("\n La operacion fue cancelada. \n");

                }




                break;
            case '2':
                printf("\nIngrese el nuevo Apellido: ");
                fflush(stdin);
                scanf("%s",&auxLastName);

                printf("\n Esta seguro que quiere modificar el Apellido? (s-n) ");
                fflush(stdin);
                scanf("%c",&ansAux);

                if(ansAux=='s')
                {
                    strcpy(list[i].lastName, auxLastName);
                    index = 1;
                }
                else
                {

                    printf("\n La operacion fue cancelada. \n");

                }



                break;
            case '3':
                printf("\nIngrese el nuevo Salario: ");
                fflush(stdin);
                scanf("%f", &auxSalary);

                printf("\n Esta seguro que quiere modificar el Salario? (s-n) ");
                fflush(stdin);
                scanf("%c",&ansAux);

                if(ansAux=='s')
                {
                    list[i].salary = auxSalary;
                    index = 1;
                }
                else
                {

                    printf("\n La operacion fue cancelada. \n");

                }


                break;
            case '4':
                printf("\nIngrese el nuevo Sector: ");
                fflush(stdin);
                scanf("%d", &auxSector);

                printf("\n Esta seguro que quiere modificar el Sector? (s-n) ");
                fflush(stdin);
                scanf("%c",&ansAux);

                if(ansAux=='s')
                {
                    list[i].sector = auxSector;
                    index = 1;
                }
                else
                {

                    printf("\n La operacion fue cancelada. \n");

                }


                break;
            case '5':
                printf("\n\n La modificacion no se llevo a cabo \n\n");
                break;
            default:
                printf("\nLa opcion no existe!\n");
                break;

            }



            break;
        }


    }
    system("cls");

    if(index==1)
    {

        printf("\n\n La modificacion fue exitosa \n\n");

    }
    else
    {

        printf("\n\n La modificacion no se llevo a cabo \n\n");

    }



}
