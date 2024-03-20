#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elements.h"

#define SIZE 10

int int_compare(const void *elem1, const void *elem2)
{

    if (*(int *)elem1 > *(int *)elem2)
    {
        return 1;
    }
    if (*(int *)elem2 > *(int *)elem1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int char_compare(const void *elem1, const void *elem2)
{

    if (*(char *)elem1 > *(char *)elem2)
    {
        return 1;
    }
    if (*(char *)elem2 > *(char *)elem1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int string_compare(const void *elem1, const void *elem2)
{

    /*It compares the lexicographical order rather than the length*/

    char *str1, *str2;
    int i=0;

    str1= (char*)elem1;
    str2= (char*)elem2;


    while (str1[i]!='\0' && str2[i]!='\0') {
        if (str1[i] != str2[i]) {
            break;
        }
        i++;
    }

    if(str1[i]=='\0' && str2[i]=='\0'){
        return 0;
    }
    else if (str1[i]=='\0'){
        return -1;
    }
    else if(str2[i]=='\0'){
        return 1;
    }

    // Devolver el resultado de la comparación

    return char_compare((void *)(str1+i), (void *)(str2+i));



}

/*
void qsort Resumen
qsort(void *base, size_t nel, size_t size, int (*compar)(const void *, const void *));
"Esta función ordenada un array de nel elementos, donde base es un puntero al elemento inicial. El tamaño de cada elemento, en bytes, se especifica con el argumento size. Finalmente, compar es un puntero a una  función que se le pasa como argumento dos punteros a elementos a comparar, y devuelve un entero menor, igual o mayor que cero, segun el primer elemento sea menor, igual o mayor que el segundo."
*/

int main()
{

    int int_array[SIZE]={0}, total = 0, i, index;
    char char_array[SIZE]={'\0'};
    char string_array[SIZE][SIZE];

    puts("BIENVENIDO, puedes ordenar numeros(1), caracteres(2) o strings(3).");
    puts("Introduzca un número:");
    scanf("%d", &index);

    switch (index)
    {

    case 1:

        do
        {
            printf("¿Cuantos numeros deseas introducir (2-10)? ");
            scanf("%d", &total);

        } while (total < 2 || total > 10);

        for (i = 0; i < total; i++)
        {
            printf("Introduce el %d numero: ", i + 1);
            scanf("%d", &int_array[i]);
        }

        puts("Numeros ordenados: ");

        qsort(int_array, total, sizeof(int), int_compare);
        for (i = 0; i < total; i++)
        {
            printf("%d ", int_array[i]);
        }

        puts("\n");

        break;

    case 2:

        do
        {
            printf("¿Cuantos caracteres deseas introducir (2-10)?  ");
            scanf("%d", &total);

        } while (total < 2 || total > 10);

        for (i = 0; i < total; i++)
        {
            printf("Introduzca el %d caracter: ", i + 1);
            scanf("\n%c", &char_array[i]);
        }

        puts("Caracteres ordenados: ");

        qsort(char_array, total, sizeof(char), char_compare);

        for (i = 0; i < total; i++)
        {
            printf("%c ", char_array[i]);
        }

        puts("\n");

        break;

    case 3:
        do
        {
            printf("Cuantas palabras (2-10) quieres introducir? ");
            scanf("%d", &total);
        } while (total < 2 || total > 10);

        for (i = 0; i < total; i++)
        {
            printf("Introduzca la palabra %d sin espacios(maximo 10 caracteres): ", i + 1);
            scanf("%s", string_array[i]);
        }

        puts("Palabras ordenadas: ");

        qsort(string_array, total, sizeof(*string_array), string_compare);

        for (i = 0; i < total; i++)
        {
            printf("%s\n", string_array[i]);
        }

        break;

    default:
        printf("Opción no válida. Introduzca una opción del menú.");
        break;
    }


    return 0;
}