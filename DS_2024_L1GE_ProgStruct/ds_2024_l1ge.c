#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/*
On se propose de modéliser à l’aide d’une structure en C, un objet du monde réel : 
la LED RGB (Light Emitting Diode)
En effet une LED RGB est caractérisée par plusieurs propriétés : 
on s’intéresse ici aux caractéristiques physiques et électriques suivantes :
La propriété « Color » de type structure colot_t :
on se limite aux trois couleurs ‘R’ : Rouge, et ‘V’ : Verte, ‘B’ : Bleue
- Une tension nominale de fonctionnement à 20mA de type réel nommée : Vseuil
- Un courant direct qui traverse la LED ≥ 2mA et ≤ 20mA noté IF de type entier
- Un état de type entier décrivant l’état de la LED, 0 : éteinte, 1 : allumée

*/




typedef struct{
    uint8_t R; // 0-255
    uint8_t G; // 0-255
    uint8_t B; // 0-255
} color_t;




 typedef struct {
     color_t color;


 } RGB_Led_t;

typedef struct t_led LED;

struct t_led {
    char Color;   // 'R':Rouge  , 'V' Verte 'B' Bleu
    float VSeuil; // tension nominale de fonctionnement à 20 mA
    int IF;       // Courant direct (Forward Current) qui traverse la LED >= 2mA et <=20mA
    int etat;     // 0: éteinte ; 1: allum� si le IF >= 2mA on consid�re que la LED est allum�e
} ;

typedef struct t_guirlande Guirlande;
struct t_guirlande {
    int n; // nombre de leds dans la guirlande
    LED *stripLED; // liste des LEDs montées en série
};
// le courant 20 mA est ici considérée comme une limite pour toutes les LED
/*-------------------------------------------------------------------------*
| rouge 1,6V/20mA | verte  2,1V/20mA  | bleue 3,6V/20mA         ]
*--------------------------------------------------------------------------*/

// fonction pour initialiser une LED
LED init_led(char Color);
// retourne la valeur de le r�sistance s�rie d'une la led pour une
float r_serie_led(LED *led, float Ualim, int I , float *Pdisp );
void affiche(LED led);
void affiche_g(Guirlande g);
// retourne une guirlande de n leds identiques
Guirlande  init_guir(int n, char color);
float r_serie_g(Guirlande g, float Ualim, int I , float *Pdisp);



int main()
{

    LED d;
    Guirlande g;
    d = init_led('R');
    float P,R,U=5; // U 5V
    int I=15; // mA
    R=r_serie_led(&d,U,I,&P);
    printf("R=%2.0f Ohms, Ualim =%2.2fV, I=%dmA , P=%2.2fW\n",R ,U,I,P );
    affiche(d);
    g = init_guir(4,'R');
    affiche_g(g);
    U=8;
    R=r_serie_g(g,U,I,&P);
    printf("R=%2.0f Ohms, Ualim =%2.2fV, I=%dmA , P=%2.2fW\n",R ,U,I,P );
    affiche_g(g);
    return 0;
}

void affiche_g(Guirlande g)
{
    int i;
    printf("nb_leds:%d\n",g.n);
    for(i=0;i<g.n;i++)
    {
        affiche(g.stripLED[i]);
    }
}

Guirlande  init_guir(int n, char color )
{
    Guirlande g;
    g.n = n;
    g.stripLED = (LED*) malloc(n*sizeof(LED));
    if(g.stripLED!=NULL)
    {
        for (int i=0; i < n ;i++)
            g.stripLED[i] = init_led(color);
    }
    return g;
}


float r_serie_led(LED *led, float Ualim, int I , float *Pdisp )
{
    float R;
    led->IF = I;
    R= (Ualim - led->VSeuil)*1000/I;
    *Pdisp = (Ualim - led->VSeuil)*(Ualim - led->VSeuil)/R;
    if(I>20 || I < 2 || R <0)
      {
        led->etat = 0;
        R=0;
        *Pdisp = 0;
      }
    else
        led->etat = 1;
    return R;
}

float r_serie_g(Guirlande g, float Ualim, int I , float *Pdisp)
{
    float R,P=0.0;
    int i,etat=1;
    R= (Ualim - g.n*g.stripLED[0].VSeuil)*1000/I;
    *Pdisp = (Ualim - g.n*g.stripLED[0].VSeuil)*(Ualim - g.n*g.stripLED[0].VSeuil)/R;

       if(I>20 || I < 2 || R <0)
      {
          etat=0;
          R=0;
          *Pdisp = 0;
      }
    for(i=0;i<g.n ; i++)
    {
        g.stripLED[i].etat = etat;
        g.stripLED[i].IF = I;
    }

    return R;
}

// initialiser une led initailement �teinte
// parametres : couleur
//

LED init_led(char Color)
{
    LED d;
    d.Color = Color;
    d.IF = 0;
    d.etat = 0; // la led est �teinte
    switch(Color)
    {
        case 'R':
            d.VSeuil = 1.6;
            break;
        case 'V':
            d.VSeuil = 2.1;
            break;
        case 'B':
            d.VSeuil = 3.6;
            break;
    }
    return d;
}

void affiche(LED d)
{
    char etat[8];
     if(d.etat)
        strcpy(etat,"Allumee");
     else
        strcpy(etat,"Eteinte");
    printf("[color:%c,IF=%dmA, VSeuil:%2.1fV, Etat:%s]\n",d.Color,d.IF,d.VSeuil,etat);
}
