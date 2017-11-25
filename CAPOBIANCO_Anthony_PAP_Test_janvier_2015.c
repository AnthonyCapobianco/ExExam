/*-------------------------------------------------------------------------
 IPAM - Annee Academique 2015-2016
 Bachelier en Informatique
 Cours de Principes Algorithmiques et Programmation
 Test Dispensatoire de Janvier 2016
 ---------------------------------------------------------------------------
 Remarque: ce fichier est intentionnellement sans caracteres accentues.
 ---------------------------------------------------------------------------

 Enonce:
 =======
 Dans le calendrier gregorien, une annee est bisextile si son nombre est
 divisible par 4 (exemples: 1984, 1960, 2016), sauf si c'est une annee
 seculaire (exemples: 1900, 1800, 1700), mais dans ce dernier cas elle sera
 quand meme seculaire si son nombre est divisible par 400 (exemples: 2000,
 1600).
 On vous demande:
 (I) D'ecrire le GNS d'un programme qui
 (a) demandera � l'utilisateur:
 - une annee borne inferieure,
 - une annee borne superieure;
 (b) affichera pour chaque annee comprise entre les bornes si celle-ci
 est bisextile ou non.
 (II) De traduire le GNS en programme C, avec comme variation que
 ledit programme affichera ensuite, au choix:
 - la liste des annees bisextiles comprises entre les bornes,
 - la liste des annees non bisextiles comprises entre les bornes,
 - la liste complete des annees comprises entre les bornes,
 les annees bisextiles etant alors differenciees des autres
 (par exemple suivie du caractere *).
 Le choix precedent etant propose a l'utilisateur via un menu:
 =======================================================================
 Souhaitez vous afficher les annees comprises entre les bornes fournies:
 1) qui sont bisextiles
 2) qui sont non bisextiles
 3) toutes (avec une marque pour les bisextiles).
 Votre choix (1, 2 ou 3, 0 pour sortir):
 =======================================================================
 Idealement, votre programme C verifiera toujours que les entrees
 attendues de l'utilisateur soient dans le champs des valeurs attendues,
 et en informera l'utilisateur le cas echeant, l'invitant � reiterer son
 entree.

 Tant dans le GNS que dans le programme C, veuillez a utiliser les
 structures (sequentielles, de choix ou de repetitions) les plus adequates
 possibles pour r�aliser les taches necessaires. Soyez econome de votre code
 et veuillez a ce que ce dernier soit le plus efficient possible.
 N.B.: Le programme ne prendra en compte que les annees � nombre positif.

 ---------------------------------------------------------------------------
 Vous realiserez le GNS sur une feuille de papier, alors que vous ecrirez
 votre programme C dans ce fichier que vous renommerez comme suit :
 NOM_Prenom_PAP_Test_janvier_2015.c

 De plus vous indiquerez vos nom et prenom dans l'espace reserve ci-dessous.

 Bon travail.
 -------------------------------------------------------------------------------
 PS: Ne modifiez aucunement les commentaires de ce fichier, merci.
 -------------------------------------------------------------------------------

 Nom: CAPOBIANCO

 Prenom: Anthony
 -------------------------------------------------------------------------------
 Ecrivez votre programme C ci-dessous:*/

#include <stdio.h>
/*
 *    Année bisextile:
 *    si l'année est divisible par 4 et non divisible par 100, ou
 *    si l'année est divisible par 400.
 */

int estBisextile(unsigned int annee){
    return ((annee %4 == 0 && annee %100 != 0)||(annee %400 == 0))? 1:0;
}
void askAnnee(unsigned int choice){
    unsigned int     min = 0
		    ,max = 2017
		    ,it;
    do
    {
        printf("\n Veuillez introduire l'année de départ (minimum 1583) :");
        scanf("%u", &min);
        if (min < 1583 && min != 0)
        {
            printf("La date doit faire partie du calendrier gregorien.");
        }

    }while (min < 1583); // 1583 est le début du calendrier gregorien (merci Wendy)

    printf("\n Veuillez introduire l'année de fin:");
    scanf("%u", &max);

    for (it = min; it <= max; ++it) {
        switch(choice)
        {
            case 1:
            //bisextile
            if (estBisextile(it) == 1)
                printf("%u\n", it );
            break;
            case 2:
            //non bisextile
            if (estBisextile(it) == 0)
                printf("%u\n", it );
            break;
            case 3:
            //toutes plus une marque pour les bisextiles
            if (estBisextile(it) == 0)
                printf("%u\n", it );
            else
                printf("%u *\n", it);
            break;
        }
    }
}
int main(int argc, const char * argv[]) {
    unsigned int    choix = -1;
    do
        {
        printf(
               "Souhaitez vous afficher les annees comprises entre les bornes fournies:\n"
               "1) qui sont bisextiles \n"
               "2) qui sont non bisextiles\n"
               "3) toutes (avec une marque pour les bisextiles).\n"
               "Votre choix (1, 2 ou 3, 0 pour sortir):"
              );
        scanf("%u", &choix);
        switch(choix)
            {
                case 1:
                case 2:
                case 3:
                    askAnnee(choix);
                break;
                case 0:
                    printf("Aurevoir.\n");
                return 0;
                default:
                    printf("%u n'est pas un choix correcte.", choix);
                break;
            }// Switch
        }while(choix != 0);
    return 0;
}

