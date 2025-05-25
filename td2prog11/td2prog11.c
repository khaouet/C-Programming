/**---------------------------------------------------------------------------
  Source file : td2prog11.c
  Author      : Khaled HAOUET
  Class       : L1-GEx
  Brief       : Parcours d'un damier en spirale extérieur vers intérieur
-----------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n; /* n taille d'une grille n x n*/
    unsigned int lim_g = 0;
    unsigned int lim_d;
    unsigned int lim_h = 0;
    unsigned int lim_b;
    unsigned int pos_lig = 0;
    unsigned int pos_col = 0;
    printf("n = ");
    scanf("%u",&n);
    lim_d = n - 1;
    lim_b = n - 1;
    /* Parcours de la grille en sprirale de l'extérieur vers l'intérieur*/
    /* Position de Départ lig = 0, col = 0 */
    while (lim_g < lim_d)
    {
    for (pos_col = lim_g ; pos_col < lim_d ; pos_col++)
    {
        printf("d<%u,%u>",pos_lig, pos_col);
    }
    printf("<%u,%u>\n",pos_lig, pos_col);
    for (pos_lig = lim_h ; pos_lig < lim_b ; pos_lig++)
    {
        printf("b<%u,%u>",pos_lig, pos_col);
    }
    printf("<%u,%u>\n",pos_lig, pos_col);

    for (; pos_col > lim_g ; pos_col--)
    {
        printf("g<%u,%u>",pos_lig, pos_col);
    }
    printf("<%u,%u>\n",pos_lig, pos_col);
    for(;pos_lig > lim_h ; pos_lig --)
    {
        printf("h<%u,%u>",pos_lig, pos_col);
    }
    printf("\n");
    pos_col++;
    pos_lig++;
    lim_h ++;
    lim_b --;
    lim_g ++;
    lim_d --;
    printf("lim_g= %u lim_d =%u lim_h= %u lim_b=%u\n",lim_g, lim_d, lim_h, lim_b);
    }
    printf("A<%u,%u>",pos_lig, pos_col);
    return 0;
}
