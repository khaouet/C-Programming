/**---------------------------------------------------------------------------
  Source file : tp3prog3.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : prints ASCII Table from code 0 to 255
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "cs_CZ.iso88592");
    unsigned short  c = 0x00U;
    printf("-------------------------\n",c ,c, c, (char) c );
    while( c < 256)
    {
        if (c != '\n')
            printf("%3x | %3o | %3d | %3c |\n",c++ ,c, c, (char) c);
        else
            printf("%3x | %3o | %3d | '\\n' |\n",c++ ,c, c );

        //c++;
    }
    return 0;
}
