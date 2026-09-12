# Exercice 7
J'ai écrit un petit programme dans mon fichier main.cpp, puis j'ai éffectué les deux constructions d'affilé sans rien modifier

## 1ere construction
La première construction a duré **2,25 secondes**. Nous pouvons facilement vérifier cette information dans la sortie sur le terminal après la construction :

```bash
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  17/17
Time:           2.25s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

## 2eme construction
La deuxième construction quant à elle, n'a duré que **1.92 secondes**. Là encore, nous pouvons vérifier cela dans la sortie sur le terminal après la construction :

```bash
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  17/17
Time:           1.92s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

## Explication

L'écart de temps entre les deux constructions (2,25 s contre 1,92 s) s'explique par le fait que, lors de la seconde construction, Jenga compare la date de dernière modification des fichiers sources (`.cpp`, `.h`) avec celle des fichiers objets (`.o` / `.obj`) et des binaires déjà générés. Comme aucun fichier n'a été modifié, Jenga détecte que tout est à jour et saute complètement l'étape de compilation et d'édition de liens. Ceci est d'ailleurs expliqué dans le chapitre 1 du cours.

* **Ce que mesurent les 1,92 secondes renstantes :** Ce temps ne correspond pas à des processus de compilation, mais au surcout du processus de construction :
    - La lecture et l'évaluation des scripts python (`.jenga`).
    - L'analyse du graphe de dépendences pour les 17 projets.
    - La vérification sur le disque des dates de chaque fichier.
    - L'affichage du jounal dans le terminal.