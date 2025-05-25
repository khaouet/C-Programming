#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h> /* fixed size integer types */

/* Functions declarations */
/* get_bit_value : retourne la valeur 0 ou 1 : valeur du bit à la position pos*/
/* pos est une valeur comprise entre 0 et 31 et correspont à la postion du bit dans variable reg*/
/* Definir la fonction suivante en utilisant les opérateurs sur les bits */
/* Si l'utilsateur appelle la fonction avec un paramètre pos non valide, la fonction doit retourner la valeur 255 */
uint8_t get_bit_value(uint32_t reg, uint8_t pos);

uint32_t reverse(uint32_t reg, uint8_t mode);

uint8_t reverse_8(uint8_t reg);

int main()
{
    unsigned int a = 0x63; /* 0x63 == 99 == 0110 0011 */
    unsigned int b = 0x2A; /* 0x2A == 42 == 0010 1010 */

    /* pour utiliser les types suivants il faut include <inttypes.h> */
    uint8_t a_8   = 0x63, b_8  = 0x2A;    /* Declaration de deux entiers non signés sur  8 bits */
    uint16_t a_16 = 0x63, b_16 = 0x2A;    /* Declaration de deux entiers non signés sur 16 bits */
    uint32_t a_32 = 0x63, b_32 = 0x2A;    /* Declaration de deux entiers non signés sur 32 bits */

    /* 0110 0011 & 0010 1010 == 0010 0010 == 0x22 == 34 */
    /* %X donne l'affichage en HEXDECIMAL d'un entier */
    printf("%2X\n", a & b);
    /* 0110 0011 | 0010 1010 == 0110 1011 == 0x6B == 107 */
    printf("%2X\n", a | b);
    /* 0110 0011 ^ 0010 1010 == 0100 1001 == 0x49 == 73 */
    printf("%2X\n", a ^ b);
    /*sizeof est l'opérateur C qui retourne la taille en octets d'une variable (y compris les tableaux) ou d'un type */
    printf("taille de a    = 0x%08X est %d octets\n", a, sizeof(a));       /* taille de a    = 0x00000064 est    4 octets */
    /* Compléter dans les zones pointiellées les commentaires suivants : */
    printf("taille de a_8  = 0x%02X est %d octets\n", a_8, sizeof(a_8));   /* taille de a_8  = .......... est .... octets (1)*/
    printf("taille de a_16 = 0x%04X est %d octets\n", a_16, sizeof(a_16)); /* taille de a_16 = .......... est .... octets (2)*/
    printf("taille de a_32 = 0x%08X est %d octets\n", a_32, sizeof(a_32)); /* taille de a_32 = .......... est .... octets (3)*/
    /* a_8  = 0x63 = 0b 0110 0011 */
    /* ~a_8 = 0x9C = 0b 1001 1100 */
    /* ~ : attention l'operateur complément opère sur la taille par defaut qui est 4 octets ici */
    printf("~a_8 = 0x%02X\n", ~a_8);                 /* ~a_8 = 0xFFFFFF9C */
    printf("~a_8 = 0x%02X\n", a_8 = (uint8_t) ~a_8); /* ~a_8 = 0x9C */
    /* Donner la valeur de a_8 après l'opération complément */
    printf(" a_8 = 0x%02X\n", a_8); /* a_8 = .................. (4)*/
    /* Décalage à droite d'un bit */
    a_8 = a_8 >> 1 ;
    /* a_8 = 0b 1001 1100  = 0x9C pour décaler à droite on insere un 0 à gauche et en enlève le bit le plus à droite */
    /* 0b 1 0 0 1 1 1 0 0 */
    /*     \ \ \ \ \ \ \ \--> le bit du poids faible est supprimé
    /* 0b 0 1 0 0 1 1 1 0 */
    /* a_8 = 0x4E = 0b 0100 1110 ; */
    printf(" a_8 = 0x%02X\n", a_8); /* a_8 = .................. (5)*/
    /* Décalage à gauche d'un bit */
    a_8 = a_8 << 1;
    /* a_8 = 0b 0100 1110  = 0x4E pour décaler à gauche on insere un 0 à droite et en enlève le bit le plus à gauche */
    /* 0b  0 1 0 0 1 1 1 0 */
    /*      / / / / / / /  <-- insere un zero à l'emplacement du bit du poids le plus faible.
    /* 0b  1 0 0 1 1 1 0 0*/
    /* a_8 = 0x9C = 0b 1001 1100 ; */
    printf(" a_8 = 0x%02X\n", a_8); /* a_8 = .................. (6)*/
    /* Pour votre information */
    /* - Un decalage à droite d'une position est une division entière par deux */
    /* - Un decalage à gauche d'une position est une multiplication entière par deux */
    /* Décalage à droite de deux bits */
    a_8 = a_8 >> 2 ;
    /* pour décaler à droite on insere deux zéros à gauche et en enlève les 02 bits les plus à droite */
    printf(" a_8 = 0x%02X\n", a_8); /* a_8 = .................. (7)*/
    /* Décalage à gauche de deux bits */
    a_8 = a_8 << 2;
    /* pour décaler à gauche on insere deux zeros à droite et en enlève les deux bits les plus à gauche */
    printf(" a_8 = 0x%02X\n", a_8); /* a_8 = .................. (8)*/

    /* - Un decalage à droite de deux positions est une division       entière par ............... */
    /* - Un decalage à gauche de deux positions est une multiplication entière par ............... */


    printf("le bit numéro %d de a_8 = 0x%02X est = %d\n", 3, a_8, (a_8 & (1<<3))>> 3 ); /* le bit numéro 3 de a_8 = ........ est = ....... (9)*/
    printf("le bit numéro %d de a_8 = 0x%02X est = %d\n", 5, a_8, (a_8 & (1<<3))>> 3 ); /* le bit numéro 5 de a_8 = ........ est = ....... (10)*/
    /* appel de la fonction get_bit_value*/

    printf("le bit numéro %d de a_32 = 0x%08X est = %d \n", 5, get_bit_value(a_32,5));  /* le bit numéro 5 de a_32 = ........ est = ....... (11)*/
    /* 0x9C = 1001 1100 ---> 0x39 = 0011 1001 */
    /* 0x2A = 0010 1010 ---> 0x54 = 0101 0100 */
    printf("le reverse bit de a_8^b_8 = 0x%02X^0x%02X = 0x%02X est = 0x%02X\n", a_8, b_8, a_8 ^ b_8,  reverse_8(a_8 ^ b_8));
    /* le reverse bit de a_8^b_8 = 0x....^ 0x..... = 0x.... est = 0x..... */


    printf("le reverse bit de 0x%02X est = 0x%02X\n", 0xB0,  reverse_8(0xB0));
    printf("le reverse bit de 0x%02X est = 0x%02X\n", 0x24,  reverse_8(0x24));
    printf("le reverse bit de 0x%02X est = 0x%02X\n", 0xE7,  reverse_8(0xE7));
    printf("le reverse bit de 0x%02X est = 0x%02X\n", 0xAE,  reverse_8(0xAE));

    printf("le reverse bit en mode 16bit de 0x%08X est = 0x%08X\n", 0xAE7C24B0 ,  reverse(0xAE7C24B0,16));
    printf("le reverse bit en mode  8bit  de 0x%08X est = 0x%08X\n", 0xAE7C24B0 ,  reverse(0xAE7C24B0,8));
    printf("le reverse bit en mode   bit de 0x%08X est = 0x%08X\n", 0xAE7C24B0 ,  reverse(0xAE7C24B0,1));

    return 0;
}

/* Function get_bit_value : retourne la valeur 0 ou 1 : valeur du bit à la position pos*/
/* pos est une valeur comprise entre 0 et 31 et correspont à la postion du bit dans variable reg*/
/* Definir la fonction suivante en utilisant les opérateurs sur les bits */
/* Si l'utilsateur appelle la fonction avec un paramètre pos non valide, la fonction doit retourner la valeur 255 */

uint8_t get_bit_value(uint32_t reg, uint8_t pos)
{
    if(pos>=0 && pos <=31 )   /* (12) */
        return (uint8_t) (reg & (1 << pos))>> pos ; /* (13) */
    else
        return 255; /* (14) */

}

uint8_t reverse_8(uint8_t reg) {
   reg = (reg & 0xF0) >> 4 | (reg & 0x0F) << 4;
   reg = (reg & 0xCC) >> 2 | (reg & 0x33) << 2;
   reg = (reg & 0xAA) >> 1 | (reg & 0x55) << 1;
   return reg;
}

/* reverse : fonction qui inverse les bits selon un mode */
/* mode peut être : 1 bit, 8 bits , 16 bits */
/* sachant que :*/
/* reverse_8(B0) = 0x0D */
/* reverse_8(24) = 0x24 */
/* reverse_8(E7) = 0xE7 */
/* reverse_8(AE) = 0x75 */
/* 0xAE7C24B0 en mode bit     -> 0x0D24E775 */
/* 0xAE7C24B0 en mode 8 bits  -> 0xB024E7AE   */
/* 0xAE7C24B0 en mode 16 bits -> 0x24B0AE7C   */
/* on considère que 0xFFFFFFFF est la valeur retourné si le mode introduit n'est pas 1 ou 8 ou 16 */
/* reverse opère sur les valeurs de 0 à 0xFFFFFFFE*/
uint32_t reverse(uint32_t reg, uint8_t mode)
{
    reg = (reg & 0xFFFF0000) >> 16 | (reg & 0x0000FFFF) << 16 ;
    switch (mode)
    {
    case 1 :
        reg = (reg & 0xFF00FF00) >> 8 | ( reg & 0x00FF00FF) << 8 ;
        reg = (reverse_8((uint8_t) ((reg & 0xFF000000 ) >> 24)) << 24) |
              (reverse_8((uint8_t) ((reg & 0x00FF0000 ) >> 16)) << 16) |
              (reverse_8((uint8_t) ((reg & 0x0000FF00 ) >>  8)) << 8 ) |
               reverse_8((uint8_t) (reg & 0x000000FF ));
        break;
    case 8:
        reg = (reg & 0xFF00FF00) >> 8 | ( reg & 0x00FF00FF) << 8 ;
        break;
    case 16:
        break;
    default:
        return 0xFFFFFFFF;
    }
    return reg;
}
