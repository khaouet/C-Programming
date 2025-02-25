/**---------------------------------------------------------------------------
  Source file : tp3prog6.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : read and reverse a string using 02 arrays of char
                the second array contains the reversed string of the first one
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
    char rev_str[MAX_STR_LENGTH+1];
    printf("Saisir Chaine : ");
    //scanf("%s",str);
    gets(str);
    //printf("%s\n",str);
    //printf("longeur de \"%s\" est %d\n",str,strlen(str));
    start = 0;
    end = strlen(str) - 1;
    rev_str[end+1] = '\0';
    while(start < end)
    {
        rev_str[end] = str[start];
        rev_str[start] = str[end];
        start++;
        end--;
    }
    printf("la chaine inverse de\n %s \nest\n %s\n",str, rev_str);
    return 0;
}
