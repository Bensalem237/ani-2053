# Exercice 1 : Le dépot d'éssai

J'ai commencé par créer le dépot vide comme ç'a été demandé dans l'énoncé via la commande
```bash
git init depot_vide
```
et j'ai obtenu le retour suivant :
```
Initialized empty Git repository in /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/EXOS/depot_vide/.git/
```
Ensuite, j'ai créé les fichier un par un comme demandé et pour chaque fichier, j'ai commancé par l'ajouter à l'index :
```bash
git add fichierX.cpp
```
puis le sauvegarder :
```bash
git commit -m "Commit du n_ieme fichier"
```

## Historique

J'ai obtenu l'historique en tapant :
```bash
git log --oneline
```

```bash
f228c11 (HEAD -> main) Commit du troisieme fichier
56e698f Commit du deuxieme fichier
ca5e171 Commit du premier fichier
```

## Graphe

J'ai obtenu le graphe grace à la commande :
```bash
git log --graph --oneline --all
```

```bash
* f228c11 (HEAD -> main) Commit du troisieme fichier
* 56e698f Commit du deuxieme fichier
* ca5e171 Commit du premier fichier
```

Nous pouvons observer que ce graphe contient une seule colonne d'étoiles sans séparation, ni jonction. Cela est du au fait que chaque commit a un seul parent, Il n'y a donc pas de branche secondaire.