#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ALPHABET 26


int findBiggestValue(int tableauOccurence[])
{
    int maxOccurence = -1;
    int i = 0;
    int position = 0;
    while (i < SIZE_ALPHABET)
        { 
            if (tableauOccurence[i] > maxOccurence)
            {
                maxOccurence = tableauOccurence[i];
                position = i;
            }
            i++;
        }
        printf("le caractere qui revient le plus souvent est: %c avec %d occurences\n", (position + 65), maxOccurence);
        return position;
}

int mod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

void reecrireFichier(FILE* fichierEntree, FILE* fichierSortie, int keyValue) 
{
    char carac;
    char toInsert;
    int valueToModulo;

    carac = fgetc(fichierEntree); 
    while(!feof(fichierEntree)) 
    {
           
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
        putc(toInsert, fichierSortie);
        carac = fgetc(fichierEntree);
    }
}

void lireFichier(FILE* fichierEntree, int tableauOccurence[])
{
    char carac;
    int index;

    carac = fgetc(fichierEntree);
    while(!feof(fichierEntree)) 
    {
        printf("%c", carac); 
        if (carac >= 'a' && carac <= 'z')
        {
            index = carac - 'a';
            tableauOccurence[index]++;
            printf(": le compte est maintenant de %d", tableauOccurence[index]);
        } 
        else if (carac >= 'A' && carac <= 'Z')
        { 
            index = carac - 'A';
            tableauOccurence[index]++;
            printf(": le compte est maintenant de %d", tableauOccurence[index]);
        }
         printf("\n"); 
        carac = fgetc(fichierEntree);
    } 
    rewind(fichierEntree);//reinitialise le curseur et les flags
}


int main(int argc, char** argv)
{
    const char TAB_ALPHA_MIN[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    FILE* fichierEntree = NULL;
    FILE* fichierSortie = NULL;
    int position;
    int keyValue;
    int tableauOccurence[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    if (argc != 3)
    {
        printf("Vous devez saisir un fichier d'entree et un fichier de sortie\n");
    }
    else
    {
   	    fichierEntree = fopen(argv[1], "r");
    	fichierSortie = fopen(argv[2], "w");
        if (fichierEntree == NULL || fichierSortie == NULL )
        {
            fputs("au moins un des fichiers passés en arguments est invalide\n", stderr);
        }
        else
        {
        	lireFichier(fichierEntree, tableauOccurence);  
            position = findBiggestValue(tableauOccurence);
            keyValue = TAB_ALPHA_MIN[position] - 'e';
            printf("la cle d'encryptage est de : %d\n", keyValue);
            reecrireFichier(fichierEntree, fichierSortie, keyValue);
        	fclose(fichierEntree);
        	fclose(fichierSortie);
        	printf("Decryptage termine\n");	
        }
    }
    return EXIT_SUCCESS;
}