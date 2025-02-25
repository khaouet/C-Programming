#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    unsigned short ColorFormat;
    unsigned int ColorFormat2;

    printf("Color in format 1 = ");
    scanf("%x",&ColorFormat);
    ColorFormat2 = (ColorFormat & 0xFF) << ((ColorFormat & 0x0F00)>>8);
    printf("Transform of %x to format2 = %d",ColorFormat, ColorFormat2 );

    return 0;
}
