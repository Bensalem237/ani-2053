# Exercice 6 : Le conflit provoqué

J'ai clonné mon dépot dans deux répertoires de travail différents et j'ai modifié la meme ligne du meme fichier dans les deux clonnes, puis j'ai poussé les changements dans un des clonnes.

## Le refus

* Après avoir commit les changements du deuxième clonne, j'ai utilisé `git push origin main` pour pousser et ç'a déclanché le refus.

Voici le message de refus :

```
To https://github.com/Bensalem237/depot_vide.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/Bensalem237/depot_vide.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

## Le conflit

* Après le refus, j'ai tapé `git pull --no-rebase` pour récuperer les commits du dépot en ligne tout en forcant git à fusionner les changements et ç'a provoqué le conflit en voulant fusionner les deux changement de `fichier_1.cpp`

Voice le message de conflit :

```
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (1/1), done.
remote: Total 3 (delta 2), reused 3 (delta 2), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 301 bytes | 301.00 KiB/s, done.
From https://github.com/Bensalem237/depot_vide
   3bf1eef..41100c2  main       -> origin/main
Auto-merging fichier_1.cpp
CONFLICT (content): Merge conflict in fichier_1.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

## Résolution du conflit

* Premièrement, j'ai tapé `git status` pour savoir quels fichiers sont en conflit

```
On branch main
Your branch and 'origin/main' have diverged,
and have 3 and 1 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
	both modified:   fichier_1.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

* Je me suis rendu compte que c'était `fichier_1.cpp`

* Du coup j'ai ouvert le fichier avec `nano fichier_1.cpp`

```
#include <iostream>

int main() {
<<<<<<< HEAD
    int a = 99;
=======
    int a = 1;
>>>>>>> 41100c2d9bdd07128378cd5f63762795aa669582
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Le Monde est tellement beau !!!" << std::endl;
    std::cout << "C'est quand meme vrai qu'il y a des endroits qui sont laids... mais dans l'ensemble le monde est quand meme beau *h" << std::endl;
    return 0;
}
```

* J'ai remarqué les lignes qui étaient en conflit, et j'en ai éffacé une, ainsi que les marqueurs ajoutés par git

* Puis, j'ai recommit le fichier

```
[main 9c00e44] Resolution des conflits
```