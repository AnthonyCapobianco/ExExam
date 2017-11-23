/*(II) De traduire le GNS en programme C, avec comme variation que
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
 */
/*
 Année bisextile:
 si l'année est divisible par 4 et non divisible par 100, ou
 si l'année est divisible par 400.
 */
#include <stdio.h>
int estBisextile(unsigned int annee)
{
	return ((annee %4 == 0 && annee %100 != 0)||(annee %400 == 0))? 1:0;
}
void askAnnee(unsigned int choice){
	unsigned int	 min = 0
					,max = 2017
					,it;
	printf("\n Veuillez introduire l'année de départ:");
	scanf("%u", &min);
	printf("\n Veuillez introduire l'année de fin:");
	scanf("%u", &max);

	for (it = min; it <= max; ++it) {
		switch(choice) {
			case 1:
				//bisextile
				if (estBisextile(it) == 1)
				{
					printf("%u\n", it );
				}
				break;
			case 2:
				//non bisextile
				if (estBisextile(it) == 0)
					{
						printf("%u\n", it );
					}
				break;
			case 3:
				//toutes plus une marque pour les bisextiles
				if (estBisextile(it) == 0)
					{
						printf("%u\n", it );
					}
				else
					{
						printf("-%u-\n", it);
					}
				break;
		}
	}
}
int main(int argc, const char * argv[]) {
	unsigned int	choix = -1;
	do
	{
		printf("1) qui sont bisextiles \n2) qui sont non bisextiles\n3) toutes (avec une marque pour les bisextiles).\nVotre choix (1, 2 ou 3, 0 pour sortir):");
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
		}

	}while(choix != 0);
	return 0;
}
