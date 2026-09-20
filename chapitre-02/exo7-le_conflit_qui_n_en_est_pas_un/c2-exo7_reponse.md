# Exercice 7 : Le conflit qui n'en est pas un

* J'ai clonné le meme depot dans deux répertoires de travail différents et j'ai modifié le meme fichier à deux endroits différents.

* J'ai ensuite commit et poussé le fichier dans le premier dépot premier dépot

```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 331 bytes | 331.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Bensalem237/depot_vide.git
   9c00e44..d5e1cc6  main -> main
```

* Ensuite j'ai fait de meme pour le fichier du deuxième répertoire, et j'ai reçu un rejet, car j'essayais de pousser sur un dépot en ligne qui avait des commit que mon depot local n'avait pas, du coup j'ai tapé `git pull --no-rebase` pour force `git pull` à fusionner les changements.

```
remote: Enumerating objects: 18, done.
remote: Counting objects: 100% (16/16), done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 9 (delta 6), reused 8 (delta 5), pack-reused 0 (from 0)
Unpacking objects: 100% (9/9), 1006 bytes | 503.00 KiB/s, done.
From https://github.com/Bensalem237/depot_vide
   41100c2..d5e1cc6  main       -> origin/main
Auto-merging fichier_2.cpp
Merge made by the 'ort' strategy.
 fichier_1.cpp | 2 +-
 fichier_2.cpp | 1 +
 2 files changed, 2 insertions(+), 1 deletion(-)
 ```

 On voit bien sur la sortie que les deux changements ont étés modifiés sans erreur.