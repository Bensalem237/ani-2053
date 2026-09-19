# Exercice 2 : Les trois endroits

## 1. Le répertoire de travail

J'ai commencé par modifier le fichier `fichier_1.cpp` en y ajoutant deux lignes de code. Ensuite j'ai tapé la commande
```bash
git status
```
Et j'ai obtenu la sortie suivante :

```bash
On branch main
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   fichier_1.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```
* La sortie nous indique que des modifications ont été faites, mais qu'une ou plusieurs d'entre elles n'ont pas été ajoutées à l'index.
* Ensuite, elle nous propose deux commandes. La première (`git add <file>...`) pour effectivement ajouter le(s) fichier(s) modifié(s) à l'index, et la deuxième (`git restore <file>...`) pour supprimer les modifications faites.
* La deuxième partie de la sortie nous avertit simplement qu'aucune modification n'a éte indexée pour le commit et nous propose deux commandes : `git add` et `git commit -a` (pour commit directement tous les fichiers sans passer par git add).

## 2. L'index
Deuxièmement, j'ai utilisé la commande
```bash
git add fichier_1.cpp
```
pour ajouter le fichier à l'index, puis j'ai de nouveau tapé la commande
```
git status
```
Et j'ai obtenu la sortie suivante :
```bash
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	modified:   fichier_1.cpp

```

* Là, on n'obtiens plus d'avertissement (car toutes les modifications ont été indexées), mais une liste des fichiers qui vont etre sauvegardés au prochain commit.
* Ensuite, elle nous propose une commande pour défaire les modifications (`git restore --staged <file>...`).

## 3. Le dépot
Troisièmement, j'ai commit les changement via la commande
```bash
git commit -m "Ajout de deux lignes de code"
```
Ensuit j'ai de nouveau tapé la commande
```bash
git status
```
Et j'ai obtenu la sortie suivante
```bash
On branch main
nothing to commit, working tree clean
```
* La sortie nous dit que tout est à jour.