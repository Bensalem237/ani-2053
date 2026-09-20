# Exercice 5 : La branche mesurée

* Pour commencer, j'ai noté la taille du dépot avant de créer la branche : Je suis allé dans l'explorateur de fichiers, j'ai fait un click droit sur le dossier du dépot, et j'ai cliqué sur propriétés. La taille était de **`151.3kB`**

* Ensuite j'ai utilisé la commande suivante
```bash
git switch -c exo5
```
pour créer la branche et me deplacer directement dessus.

* J'ai ensuite créé un nouveau fichier dans la nouvelle branche, puis je l'ai commit.
```
[exo5 2dcd2ee] Pemier commit
 1 file changed, 7 insertions(+)
```
* J'ai ensuite effectué des modifications et commit deux fois de suite.

* Ensuite, je suis allé vérifier la taille de nouveau. la nouvelle taille du dépot était de **`191.2kB`**

* J'ai observé que la taille du dépot a augmenté de **`39.9kB`**, alors mon fichier source ne pèse que **`458`**.

## Explication

L'augmentation de la taille du dépot de `39.9kB` peut s'expliquer par :

* **Le fichier physique dans le répertoire de travail**

* **Les fichiers stockés par git dans le répertoire `.git` :** Á chaque commit qu'on fait git stocke un certain nombre de fichiers relatifs à notre commit dans le répertoire `.git`.
    * Á chaque commit, git stocke un fichier compressé contenant une copie exact du contenu de nos fichiers appelé **Blob*.
    * Git stocke également un objet Tree contenant la structue du repertoire à l'instant du commit.
    * Git stocke également un objet contenant les metadonnées sur le commit (l'auteur, la date, le message de commit, le pointeur vers le commit parent)