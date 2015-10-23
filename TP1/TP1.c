#include <stdio.h>
#include <stlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	char chaineEntree[40];
	char chaineSortie[40];
    FILE* fichierEntree;
    FILE* fichierSortie;
    char chaine[900];
    char* chaine_p;

    if (argc != 3)
    {
        printf("Vous devez saisir un fichier d'entree et un fichier de sortie\n");
    }
    else
    {
        chaineEntree = argv[0];
        chaineSortie = argv[1];
    //on doit verifier aussi si le fichier est present...
   	    fopen(chaineEntree, "r");
    	fopen(chaineSortie, "w");

    	printf("dechiffrement par analyse frequentiel\n");
   		*chaine_p = scanf("%s", chaineEntree);

    	fclose(fichierEntree);
    	fclose(fichierSortie);
    	printf("Decryptage termine\n");	
    }
    
    system("Pause");
    return 0;

}