#ifndef CESAR_H
#define CESAR_H 

/*
 * findBiggestValue: prend en parametre un tableau de Integer et sa taille puis
 * retourne la position dans le tableau de l'Integer dont l'occurence est la
 * plus grande.
 */
int findBiggestValue(int tableauOccurence[], int taille);

/*
 * mod: prend en parametre deux nombres (a et b) qui sont respectivement le
 * dividende et le diviseur et retourne le reste de la division, si celui-ci
 * est négatif, alors le resultat retourne b-resultat.
 */
int mod (int a, int b);

/*
 * chooseThegoodLetter: prend en parametre un caractere de l'alphabet et une
 * valeur a soustraire et retourne le caractere - la valeur.
 */
int chooseThegoodLetter(char carac, int keyValue);

/*
 * incrementerDansLeTableau: prend en parametre un caractere  et incremente
 * la position a laquelle elle fait reference dans l'alphabet 
 */
void incrementerDansLeTableau(char carac, int tableauOccurence[]);

/*
 * reecrireFichier: prend en parametre un tableau de Integer de la taille de 
 * l'alphabet qui est de 26 et comptabilise les lettres selon leur position
 * dans l'alphabet
 * 
 */
void reecrireFichierAvecLaCle(FILE* fichierEntree, FILE* fichierSortie, int keyValue);

/*
 * lireFichier: prend en parametre un fichier d'entree et un tableau dans lequel
 * la methode comptabilise les caractere qu'elle a lu dans le fichier.
 */
void lireFichier(FILE* fichierEntree, int tableauOccurence[]);

/*
 * validationNombreDeParametre: prend en parametre argc afin de verifier si le nombre 
 * de parametre est valide.
 */
void validationNombreDeParametre(int nombreDeParametre, char* fichierExecution);

/*
 * ouvertureFichier: prend en parametre le chemin du fichier et le mode d'accès afin 
 * de verifier si le fichier est valide.
 */
FILE* ouvertureFichier(char* cheminFichier, char* droitAcces);
#endif