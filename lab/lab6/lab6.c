#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

FILE* ouvrirFichier(char *fichier);

int fermerFichier(FILE *fichierp);


int main (int argc, char *argv[])
{

  if (argc != 2)
  {
    printf("Usage: ./%s [nom_du_fichier]\n",argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fichierp;

  fichierp = ouvrirFichier(argv[1]);

  if (!fichierp)
  {
    fprintf( stderr, "Erreur: %s\n", strerror(errno) );
    return EXIT_FAILURE;
  }
  if ( fermerFichier(fichierp) == EOF)
  {
    fprintf( stderr, "Erreur: %s\n", strerror(errno) );
    return EXIT_FAILURE;
  }
    fgets(str, fichierp);
    fputs(str, 1024, stdout)
    return EXIT_SUCCESS;
}


FILE* ouvrirFichier(char *fichier)
{
  return fopen(fichier, "r");
}

int fermerFichier(FILE *fichierp)
{
  return fclose(fichierp);
}