/**---------------------------------------------------------------------------
  @Source file : tp3prog7.c
  @Author      : Khaled HAOUET
  @Class       : L1-GEx
  @Brief       :
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <stdint.h>

#define MAX_STR_LENGTH 255



int main()
{
    uint8_t  i8;
    uint16_t i16;
    uint32_t i32;
    uint64_t i64,

    char c,c_remp;
    char str[MAX_STR_LENGTH+1];
    int i;
    setlocale(LC_ALL,"");
    printf("Saisir Chaine : ");
    gets(str);
    printf("Saisir caractère à remplacer : ");
    c = (char) getchar();
    getchar();
    printf("Saisir le caractère de remplacement : ");
    c_remp = (char) getchar();
    for( i = 0 ; i < strlen(str) ; i++)
    {
        if (str[i] == c )
            str[i] = c_remp;
    }
    puts(str);


    return 0;
}
