/**---------------------------------------------------------------------------
  Source file : tp3prog5.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : read and reverse a string using one array of char
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_STR_LENGTH 255

/**
    entrée : abcde
    sortie : edcbe

*/


int main()
{
    setlocale(LC_ALL,"");
    unsigned int start, end;
    char str[MAX_STR_LENGTH+1];
    printf("Saisir Chaine : ");
    //scanf("%s",str);
    gets(str);
    printf("%s\n",str);
    printf("longeur de \"%s\" est %d\n",str,strlen(str));
    start = 0;
    end = strlen(str) - 1;
    while(start < end)
    {
        char tmp;
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
    printf("la chaine inversée est %s\n",str);
    return 0;
}
