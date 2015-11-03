=======
#UTILITE
=======
Ce logiciel permet de decrypter des chaines de caracteres qui ont ete encryptees
avec le chiffre de Cesar. Il a ete redige en langage C dans le cadre du cours 
INF3135 de Jacques Bergers pour la session d'automne 2015.

=============
#MODE D'EMPLOI
=============
##etape 1
-------
pour compiler, vous devez saisir la ligne suivante, cela vous donnera un executable
```c
gcc -Wall cesar.c
```
*Vous pouvez rajouter l'option `-o <nom du fichier>` si vous souhaiter renommer l'executable 

##etape 2
-------
pour utiliser le fichier executable, vous devez avoir  1 fichier crypté. Si tel est le cas,
alors vous devez prefixer `./` au nom du fichier et ajouter le nom du fichier d'entrée et
le nom du fichier de sortie.
```c
./a.out          OU          ./<nom du fichier>
```
*ce qui donne avec les deux parametres:*

```c
./a.out fichierEntree.txt fichierSortie.txt
```
##etape 3
-------
en appuyant sur `Enter` vous venez d'executer le fichier avec les deux parametres nécessaire.
Vous pouvez ensuite ouvrir le fichierSortie qui a été créé (ou écraser s'il existait déja)
et admirer le texte décrypter a partir de fichierSorite.

*ATTENTION: si vous utiliser bloc-notes pour visualiser les resultats, il est possible que les saut de ligne ne s'affiche pas correctement. Pour éviter cela, ouvrez le fichier avec un autre editeur de texte.*


