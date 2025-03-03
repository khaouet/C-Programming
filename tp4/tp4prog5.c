/**
  * ---------------------------------------------------------------------------
  * @Source file : tp4prog4.c
  * @Author      : Khaled HAOUET
  * @Class       : L1-GEx
  * @Brief       : Pointers and arrays in C
  * @description :
  *
  *
  *
  * ---------------------------------------------------------------------------
  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[10]={'a','b','c','d','e','f','g','h','i','j'};
    int t[10]={10,11,12,13,14,15,16,17,18,19};
    int v[10];
    int* p;
    char* pc;


    p  = t;
    pc = s;
    /* an array identifier here t is a constant pointer to the first element of the array */
    printf("the value of p = %p\n",p);
    printf("@t = %p\n", t);
    printf("@t = %p\n", &t[0]);
    printf("%d\n",*p);
    printf("%d\n",*(p+1));
    printf("%d\n",*(p+2));
    for(int i=0 ; i < 10 ; i++)
    {
        printf("%d == %d == %d, @ = %p\n",*(p+i), t[i], p[i], p+i );

    }

 /* an array identifier here t is a constant pointer to the first element of the array */
    printf("the value of pc = %p\n",pc);
    printf("@s = %p\n", s);
    printf("@s = %p\n", &s[0]);
    printf("%c\n",*p);
    printf("%c\n",*(p+1));
    printf("%c\n",*(p+2));
    for(int i=0 ; i < 10 ; i++)
    {
        printf("%c == %c == %c, @ = %p\n",*(pc+i), s[i], pc[i], pc+i );

    }
    for(int i=0 ; i < 10 ; i++)
    {
        printf("%c , @ = %p\n",*(pc++), pc );

    }

    return 0;
}
