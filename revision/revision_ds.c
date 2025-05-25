
/**
Exercice 1
        1. Définir la structure Etudiant contenant les champs/membres suivant :
            nom : le nom de l’étudiant
            prenom : le prénom de l’étudiant
            mat : le matricule de l’étudiant
            Tmoy : représente un pointeur vers un tableau qui va contenir les notes des
            matières d’un étudiant qui sera alloué dynamiquement.
            moyg : un champ qui va contenir la moyenne générale de l’étudiant

        2. Ecrire une fonction calcul_moyg qui retourne la moyenne générale d’un tableau donné en
            paramètre. (Les matières ont le même coefficient)
            float calcul_moyg (float *Tmoy, int n)

        3. Ecrire une fonction qui permet de saisir un étudiant :
            Etudiant saisie_etudiant ()
            Cette fonction
            saisit le nom, prénom, matricule d’un étudiant.
            demande le nombre de matières, alloue dynamiquement Tmoy et le remplit.
            calcule la moyg à l’aide de calcule_moyg.
        4. Ecrire un programme principal qui :
            demande le nombre des étudiants d’une classe et alloue dynamiquement un tableau
            d’étudiants.
            calcule la moyenne de la classe.
            affiche matricule, nom, prénom de l’étudiant qui a la moyenne la plus élevée.


*/
#include <stdio.h>
#include <stdlib.h>

//typedef struct etudiant_s  Etudiant;
/*struct etudiant_s {
    // char nom[40];
    char *nom; // HAOUET
    char *pnom; // Khaled
    //char pnom[64];
    unsigned int mat;
    float *Tmoy;
    float moyg;
};*/

typedef struct {
     char matiere[64];
     float note;
} Matiere;

typedef struct {
    // char *nom; // HAOUET --> Taille dynamique
    // char *pnom; // Khaled --> Taille dynamique
    char nom[40]; // type prédefinie  à la compilattion = 40 octets
    char pnom[64]; // type prédefinie  à la compilattion = 64 octets
    unsigned int mat;
    float *Tmoy;
    // Matiere *Tmoy;
    float moyg;
} Etudiant;




float calcul_moyg (float *Tmoy, int n);

Etudiant saisie_etudiant (void); // creation function
// void saisie_etudiant(Etudiant* e); // modification function

float calcul_moy_classe(Etudiant *Tedut, int n);

Etudiant meilleur_moy(Etudiant* p_etud, int n);

int main()
{
    // struct etudiant_s e1;
    // Etudiant e2;

    int nb_etudiants;
    Etudiant* p_etud, e;

    /**
            demande le nombre des étudiants d’une classe et alloue dynamiquement un tableau
            d’étudiants.
            calcule la moyenne de la classe.
            affiche matricule, nom, prénom de l’étudiant qui a la moyenne la plus élevée.
    */
    printf("Nombre d'étudiants : "); scanf("%d",&nb_etudiants);
    p_etud  = (Etudiant*) calloc(nb_etudiants, sizeof(Etudiant));
    if(p_etud != NULL)
    {
        for(int i = 0; i < nb_etudiants ; i++)
        {
            p_etud[i] = saisie_etudiant();
        }
         printf("\nMoyenne de la classe: %0.2f", calcul_moy_classe(p_etud,nb_etudiants));
         e = meilleur_moy(p_etud,nb_etudiants);
         printf("Meilleur moyenne generale:\n");
         printf("\tmat:%u\n", e.mat);
         printf("\tnom:%s\n", e.nom);
         printf("\tpnom:%s\n", e.pnom);
         printf("\tMoyenne:%.2f",e.moyg);

    }

    return 0;
}

// function definition
// Pre-condition Tmoy != NULL and n != 0
float calcul_moyg (float *Tmoy, int n)
{
    float moy_tmp = 0;
    for(int i = 0 ; i < n ; i++)
    {
        moy_tmp += Tmoy[i];
        // a op= b <==> a = a op b
    }
    return moy_tmp / n ;
}

// si la fonction ne réussit pas à créer un etudiant (défaut de mémoire) elle retourne
// un étudiant avec un matricule = 0;
Etudiant saisie_etudiant (void)
{
    Etudiant e_tmp;
    e_tmp.mat = 0;
    int nb_matieres;
    printf("Saisir Etudiant:\n");
    printf("\tnom : ");  scanf("%s",e_tmp.nom);
    printf("\tpnom : "); scanf("%s",e_tmp.pnom);
    printf("\tmat : ");  scanf("%u",&e_tmp.mat);
    printf("Nombre de Matieres:");scanf("%d",&nb_matieres);
    e_tmp.Tmoy  = (float*) calloc(nb_matieres, sizeof(float));
    if (e_tmp.Tmoy != NULL)
    {
        for(int i = 0 ; i < nb_matieres ; i++)
        {
            printf("note%d : ",i); scanf("%f",&e_tmp.Tmoy[i]);
        }
        e_tmp.moyg = calcul_moyg(e_tmp.Tmoy,nb_matieres);

    }
    return e_tmp;
}


float calcul_moy_classe (Etudiant *Tedut, int n)
{
    float moy_classe_tmp = 0;
    for(int i = 0 ; i < n ; i++)
    {
        moy_classe_tmp += Tedut[i].moyg;
    }
    return moy_classe_tmp / n ;
}

Etudiant meilleur_moy(Etudiant* p_etud, int n)
{
    int i_meilleur = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if (p_etud[i].moyg > p_etud[i_meilleur].moyg)
        {
            i_meilleur = i;
        }
    }
    return p_etud[i_meilleur];
}
