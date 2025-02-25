/**---------------------------------------------------------------------------
  Source file : tp3prog3.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : strings using C language
                - strchr
                - strrchr
-----------------------------------------------------------------------------*/

/**
    char* strchr( const char* str, int ch );

    Finds the first occurrence of ch (after conversion to char as if by (char)ch)
    in the null-terminated byte string pointed to by str (each character interpreted
                                                          as unsigned char).
    The terminating null character is considered to be a part of the string and can
    be found when searching for '\0'
*/

/**

    char* strrchr( const char* str, int ch );

    Finds the last occurrence of ch (after conversion to char as if by (char)ch)
    in the null-terminated byte string pointed to by str (each character interpreted as unsigned char).
    The terminating null character is considered to be a part of the string and can be found if searching for '\0'.
*/



/**
str+0                   str+3
    |                       |
    V                       V
    +-------+-------+-------+-------+-------+-------+--------+
    |  'A'  |  'B'  |  'C'  |  'D'  |  'E'  |  'F'  |  '\0'  |
    +-----------------------------------------------+--------+
    0       1       2       3       4       5       6

    str[0] ? 45
    &str[0] == str ? True
    str + 3 == &str[3]
    strlen(str) == 6 ? True
    sizeof(str) == 6 ? False
    sizeod(str) == 7 ? True
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str[] = "Try not. Do, or do not. There is no try.";
    char target = 'o';

    puts(strchr(str, 'T'));
    puts(strrchr(str, 'T'));
    puts(strchr(str, 'D'));
    puts(strrchr(str, 'D'));
    puts(strchr(str, 't'));
    puts(strrchr(str, 't'));
    puts(strchr(str, target));
    puts(strrchr(str, target));
    puts("---------------------");
    int i;
    for(i = 0 ; i <= strlen(str) && (str[i] != target) ; i++)
    {
        /* nothing to do */
    }
    printf("length of str = %d\n", strlen(str));
    printf("size in bytes of str = %d\n", sizeof(str));
    printf("index of searched target = %d",i);
    puts("---------------------");
    puts(&str[i]);
    puts(str+i);
}
