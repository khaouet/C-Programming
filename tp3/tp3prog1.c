/**---------------------------------------------------------------------------
  Source file : tp3prog1.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : strings using C language
                - strlen
                - strcmp
                - strncmp
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define NB_VOYELLES 6
#define NB_LETTERS 26

int main()
{

        char mystr[] = "Lx-GE6";
        char voyelles[] = {'A','E','I','O','U','Y','\0'};
        char chat[] = {'\x63','\x61','\x74','\0'};
        char cat[] = {0x63,0x61,0x74,'\0'};

        printf("length of mystr = %u\n",sizeof(mystr));
        printf("length of voyelles = %u\n",sizeof(voyelles));
        puts(mystr);
        puts(voyelles);
        printf("%s\n",mystr);
        printf("%s\n",voyelles);
        //voyelles[6] = '+';
        puts(mystr);
        puts(chat);
        puts(cat);
        puts(voyelles);
        printf("%d\n",atoi("123"));
        int n = atoi("1234567");

        for(int i =0; i < sizeof(mystr); i++)
        {
            printf("%c",mystr[i]);
        }
        printf("get a char = \n");
        scanf("%c",mystr+1);
        printf("%s\t",mystr);
        printf("%s\n",voyelles);
        /** strlen used to get a length of a string (nb chars)*/
        printf("%u\n",strlen(mystr));
        printf("%u\n",strlen(voyelles));
        char t[] = "ABCDE FGH";
        /** strcmp used to compare 02 strings */
        printf("%u\n",strlen(t));
        printf("%d\n",strcmp(t,mystr));
        printf("%d\n",strcmp(mystr,t));
        printf("%d\n",strcmp("ABCDE","ABCDE"));
        printf("%d\n",strcmp("ABCDE","abcde"));
        printf("%d\n",strcmp("abcde","ABCDE"));
        printf("%d\n",strcmp("ABCDE","ABCD"));
        printf("%d\n",strcmp("ABC","ABCD"));
        printf("%d\n",strncmp("ABFDE","ABCD",3));
        printf("%d\n",strncmp("ABFDE","ABCD",2));
        return 0;
}
