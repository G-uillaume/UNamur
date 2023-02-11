Programmation 2: TP01 (17/02/2022)

Programme:
* Linux terminal
* Rappel exercices fonctions
* Modules & structures
* Makefile
* Fichiers

== Linux terminal

== Rappel exerices fonctions
Voir syllabus TP chapitre 5
Ex 22-23-25

== Modules & structure
1. Créez un programme qui permet d'afficher un nom et prénom entré par l'utilisateur. Le fichier principal fera appel plusieurs fonctions qui seront dans un module : 
* Une fonction pour demander nom/prénom (retourne le nom/prénom entré);
* Une fonction pour afficher le nom + prénom.

2. Editez votre module pour y inclure une structure style carte d'identité. Une carte d'identité contient les champs suivants:
* Nom
* Prénom
* Age
Modifiez votre programme pour demander l'âge et remplir cette structure de données.

== Makefile
1. Créez un makefile pour compiler le programme précédent.

== Fichiers
1. Modifiez votre programme pour stocker la carte d'identité dans un fichier.

2. Ajoutez un menu à votre programme, il comportera les entrées suivantes:
* Consulter le registre -> permet d'afficher toutes les personnes contenues dans le fichier;
* Ajouter une personne au registre -> permet d'ajouter une personne au registre.

3. Ajoutez une entrée au menu qui permet de supprimer une personne du registre.

== Bonus
1. Modifiez votre code pour avoir les modules suivants:
* un module pour la gestion lecture/écriture dans un fichier;
* un module pour la gestion de la carte d'identité;
* un module pour la gestion du registre.

2. Lorsque qu'on affiche le registre, triez les personnes par ordre alphabétique.

3. Permettez à l'utilisateur de supprimer une personne du registre sur ce même principe.


== Exemples fichiers
- Mode d'ouverture
"r": lecture seule
"w": écriture seule (créé le fichier si inexistant)
"a": ajout, écriture à partir de la fin du fichier
"a+": comme "a" avec création du fichier si inexistant

- Ecrire dans un fichier
int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
 
    fichier = fopen("test.txt", "w");
 
    if (fichier != NULL)
    {
        fputc('A', fichier); // Écriture du caractère A
        fclose(fichier);
    }
 
    return 0;
}

- Lire un fichier

#define TAILLE_MAX 1000

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";
 
    fichier = fopen("test.txt", "r");
 
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }
 
        fclose(fichier);
    }
 
    return 0;
}
