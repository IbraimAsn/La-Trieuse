Un repo qui contient un programme qui trie et vérifie que les arguments donnés en paramètre
soient bien des nombres entiers.

Pour compiler ce programme il vous suffit de faire :

    gcc -Wall la_trieuse.c

Vous obtiendrez alors un ficher intitulé "a.out".

Pour utiliser le programme veuillez taper ./a.out suivi de quelques arguments, ex :

    ./a.out  1 23 4 8 10

Vous obtiendrez alors :

    1
    4
    8
    10
    23

/!\ Le programme vous indiquera le message d'erreur suivant si le nombre d'arguments est = à 0 ou > à 20 :

    error : wrong nbr of arguments

/!\ Si vous donnez autre chose que des nombres entiers en arguments vous obtiendrez le message d'erreur suivant :

    error : character representing anything other than an int found