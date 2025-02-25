/**---------------------------------------------------------------------------
  Source file : tp2prog3.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : arrays using C language (arrays of arrays )
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[2][2] = {
                    {0,1},
                    {2,3}
                  };

    int B[2][3] = {
                    {
                        0, 1, 2
                    },
                    {
                        3, 4, 5
                    }
                  };
    int D[3][2] = {
                    {0, 1},
                    {2, 3},
                    {4, 5},
                  };
    int E[3][1] = {
                    {0},
                    {1},
                    {2}
                  };
    int C[3][2][2]  = {
//                        {
//                            {0,1},
//                            {2,3}
//                        },
                        {
                            {4,5},
                            {6,7}
                        },
                        {
                            {8,9},
                            {10,11}
                        }

                      };
    printf("(%-2d",A[0][0]);
    printf("%2d)\n",A[0][1]);
    printf("(%-2d",A[1][0]);
    printf("%2d)\n",A[1][1]);

    printf("(%-2d",B[0][0]);
    printf("%2d",B[0][1]);
    printf("%4d)\n",B[0][2]);

    printf("(%-2d",B[1][0]);
    printf("%2d",B[1][1]);
    printf("%4d)\n",B[1][2]);


    printf("(%-4d",C[0][0][0]);
    printf("%4d)\n",C[0][0][1]);
    printf("(%-4d",C[0][1][0]);
    printf("%4d)\n",C[0][1][1]);


    printf("(%-4d",C[1][0][0]);
    printf("%4d)\n",C[1][0][1]);
    printf("(%-4d",C[1][1][0]);
    printf("%4d)\n",C[1][1][1]);

    printf("(%-4d",C[2][0][0]);
    printf("%4d)\n",C[2][0][1]);
    printf("(%-4d",C[2][1][0]);
    printf("%4d)\n",C[2][1][1]);

    return 0;
}
