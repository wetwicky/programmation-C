#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "cesar.h"

int findBiggestValue(int tableauOccurence[],int taille)
{
    int maxOccurence;
    int i = 0;
    int position = 0;
    while (i < taille)
    { 
        if (tableauOccurence[i] > maxOccurence)
        {
            maxOccurence = tableauOccurence[i];
            position = i;
        }
        i++;
    }
    return position;
}

int mod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
   {
     ret += b;
     ret = mod(ret, b);
   }
   return ret;
}

int chooseThegoodLetter(char carac, int keyValue)
{
    int valueToModulo;
    char toInsert;
    if (carac >= 'a' && carac <= 'z')
    {
        valueToModulo = (carac - 97) - keyValue;
        toInsert = mod(valueToModulo,26) + 97;
    }
    else if (carac >= 'A' && carac <= 'Z')
    {
        valueToModulo = (carac - 65) - keyValue;
        toInsert = mod(valueToModulo,26) + 65;
    }
    else
    {
        toInsert = carac;
    }
    return toInsert;
}


void reecrireFichierAvecLaCle(FILE* fichierEntree, FILE* fichierSortie, int keyValue) 
{
    char carac, toInsert;
    carac = fgetc(fichierEntree); 
    while(!feof(fichierEntree)) 
    {
        toInsert = chooseThegoodLetter(carac, keyValue);
        putc(toInsert, fichierSortie);
        carac = fgetc(fichierEntree);
    }
}

void incrementerDansLeTableau(char carac, int tableauOccurence[])
{
    int index;
    if (carac >= 'a' && carac <= 'z')
    {
        index = carac - 'a';
        tableauOccurence[index]++;
    } 
    else if (carac >= 'A' && carac <= 'Z')
    { 
        index = carac - 'A';
        tableauOccurence[index]++;
    }
}

void lireFichier(FILE* fichierEntree, int tableauOccurence[])
{
    char carac;
    carac = fgetc(fichierEntree);
    while(!feof(fichierEntree)) 
    {
        incrementerDansLeTableau(carac, tableauOccurence);
        carac = fgetc(fichierEntree);
    } 
    rewind(fichierEntree);//reinitialise le curseur et les flags
}
void validationNombreDeParametre(int nombreDeParametre, char* fichierExecution)
{
    if (nombreDeParametre != 3)
    {
        fprintf(stderr, "Usage: %s [nom_du_fichier_d_entree] [nom_du_fichier_de_sortie]\n",fichierExecution);
        exit(EXIT_FAILURE);
    }
}

FILE* ouvertureFichier(char* cheminFichier, char* droitAcces)
{
    FILE* fichierAOuvrir = fopen(cheminFichier, droitAcces);
    if (!fichierAOuvrir)
    {
        fprintf( stderr, "Erreur: %s\n", strerror(errno) );
        exit(EXIT_FAILURE);
    }
    return fichierAOuvrir;
}

int main(int argc, char** argv)
{
    const char TAB_ALPHA_MIN[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    FILE* fichierEntree = NULL;
    FILE* fichierSortie = NULL;
    int position, keyValue;
    int tableauOccurence[26] = {0};
    int tailleTableau = 26;
    
    validationNombreDeParametre(argc, argv[0]);
    fichierEntree = ouvertureFichier(argv[1], "r");
	fichierSortie = ouvertureFichier(argv[2], "w");
    lireFichier(fichierEntree, tableauOccurence);  
    position = findBiggestValue(tableauOccurence, tailleTableau);
    keyValue = TAB_ALPHA_MIN[position] - 'e';
    reecrireFichierAvecLaCle(fichierEntree, fichierSortie, keyValue);
    fclose(fichierEntree);
    fclose(fichierSortie);
    return EXIT_SUCCESS;
}
