# Exercice 8 : Six manières de défaire

## 1er cas : Modification non voulue

* J'ai modifié une ligne d'un fichier de mon dépot. En effet, j'ai ajouté `entier` à la ligne 5, ensuite j'ai sauvegardé mon fichier.

```cpp
#include <iostream>
#include <cmath>

int main() {
    int x, n1, n2, entier;
    std::cout << "Hello World !"  << std::endl;
    std::cout << "Entrez un nombre : ";
    std::cin >> x;
    std::cout << "Sa racine carrée est " << std::sqrt(x) << std::endl;
    std::cout << "Maintenant, entrez deux entiers : ";
    std::cin >> n1 >> n2;
    std::cout << "Leur somme est " << n1 + n2 << std::endl;

    return 0;
}
```

* Dans le terminal, j'ai tapé la commande suivante

```bash
git restore fichier_4.cpp
```

* Ensuite j'ai rouvert le fichier et la variable que j'avais ajouté avais disparue.

```cpp
#include <iostream>
#include <cmath>

int main() {
    int x, n1, n2;
    std::cout << "Hello World !"  << std::endl;
    std::cout << "Entrez un nombre : ";
    std::cin >> x;
    std::cout << "Sa racine carrée est " << std::sqrt(x) << std::endl;
    std::cout << "Maintenant, entrez deux entiers : ";
    std::cin >> n1 >> n2;
    std::cout << "Leur somme est " << n1 + n2 << std::endl;

    return 0;
}
```

## 2eme cas : Un `add` de trop

* J'ai refait la meme modification dans mon fichier que dans le 1er cas, puis j'ai ajouté mon fichier à l'index grace à la commande suivante

```bash
git add fichier_4.cpp
```

* Ensuite, j'ai vérifié le `add` avec `git status`

**Sortie :**
```
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	modified:   fichier_4.cpp
```

* Ensuite, j'ai tapé la commande suivante pour défaire le `add`

```bash
git restore --staged fichier_4.cpp
```

* Ensuite, j'ai vérifié que le add ait été défait avec `git status`

**Sortie :**
```
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   fichier_4.cpp

```

## 3eme cas : Un `commit` de trop

* J'ai refait `add`, puis j'ai commit mon fichier avec la commande suivante

```bash
git commit -m "exo8"
```

**Sortie :**
```
[main 342350f] exo8
 1 file changed, 1 insertion(+), 1 deletion(-)
```

* Puis j'ai défait le commit sans supprimer les modifications avec la commande suivante

```bash
git reset --soft HEAD~1
```

* Ensuite, j'ai vérifié avec `git status`

**Sortie :**
```
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	modified:   fichier_4.cpp

```

## 4eme cas : Un `commit` poussé qu'il faut annuler

* J'ai de nouveau commit mes changements, puis j'ai poussé avec la commande

```bash
git push origin main
```

**Sortie :**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 298 bytes | 298.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Bensalem237/depot_vide.git
   866c3ee..2536152  main -> main
```

* Ensuite j'ai défait le commit poussé grace à la commande suivante

```bash
git revert HEAD
```

**Sortie :**
```
[main 39d1924] Revert "exo8"
 1 file changed, 1 insertion(+), 1 deletion(-)
 ```

 ## 5eme cas : Un travail en cours qu'il faut mettre de coté

* J'ai d'abord vérifié l'état du depot avec `git status`

**Sortie :**
```
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

```
Visiblement, `git revert` a défait le `push`, mais pas le `commit`, donc je l'ai defait avec la commande `git reset --soft HEAD~1`

* Ensuite, j'ai tapé la commande suivante pour mettre de coté le travail qui était en cours

```bash
git stash
```

**Sortie :**
```
Saved working directory and index state WIP on main: 2536152 exo8
```

## 6eme cas : Un commit "Perdu" à retrouver par le `reflog`

* J'ai refait une modification sur mon fichier et je l'ai commit

**Sortie :**
```
[main 7b71d70] 6eme cas
 1 file changed, 1 insertion(+), 1 deletion(-)
```

* En suit j'ai fait un `hard reset` pour tout effacer

```bash
git reset --hard HEAD~1
```

**Sortie :**
```
HEAD is now at 2536152 exo8
```

* J'ai utilisé `git status` pour vérifier l'etat du dépot

**Sortie :**
```
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```
On remarque que le dépot est "perdu"

* Ensuite, j'ai utiliser la commande suivante pour retrouver la trace du commit

```bash
git reflog
```

**Sortie :**
```
2536152 (HEAD -> main, origin/main) HEAD@{0}: reset: moving to HEAD~1
7b71d70 HEAD@{1}: commit: 6eme cas
2536152 (HEAD -> main, origin/main) HEAD@{2}: reset: moving to HEAD
2536152 (HEAD -> main, origin/main) HEAD@{3}: reset: moving to HEAD~1
39d1924 HEAD@{4}: revert: Revert "exo8"
2536152 (HEAD -> main, origin/main) HEAD@{5}: commit: exo8
866c3ee HEAD@{6}: reset: moving to HEAD~1
342350f HEAD@{7}: commit: exo8
866c3ee HEAD@{8}: pull --no-rebase: Merge made by the 'ort' strategy.
b9fe048 HEAD@{9}: commit: Exo7, deuxiième répertoire de travail
41100c2 HEAD@{10}: commit: Modification du premier fichier
3bf1eef HEAD@{11}: commit: :(
6a79af4 HEAD@{12}: pull --no-rebase: Merge made by the 'ort' strategy.
bd30e93 HEAD@{13}: commit: exo6
f4f83ed HEAD@{14}: pull: Fast-forward
010b5be HEAD@{15}: reset: moving to HEAD~1
f4f83ed HEAD@{16}: commit: refus
010b5be HEAD@{17}: commit: exo6
3e83dc6 HEAD@{18}: merge exo5: Fast-forward
1057d1c HEAD@{19}: checkout: moving from exo5 to main
3e83dc6 HEAD@{20}: commit: Troisième commit
5de390f HEAD@{21}: commit: Deuxième commit
2dcd2ee HEAD@{22}: commit: Pemier commit
1057d1c HEAD@{23}: checkout: moving from main to exo5
1057d1c HEAD@{24}: commit: Added a little message at the end of the program
13beb4f HEAD@{25}: commit: Prolonged the array
9c6e362 HEAD@{26}: commit: Ajout de deux lignes au code
f228c11 HEAD@{27}: commit: Commit du troisieme fichier
56e698f HEAD@{28}: commit: Commit du deuxieme fichier
ca5e171 HEAD@{29}: commit (initial): Commit du premier fichier
```
J'ai noté la position du commit (`HEAD@{1}`)

* Ensuite, j'ai tapé la commande suivante pour restorer le commit

```bash
git reset --hard HEAD@{1}
```

**Sortie :**
```
HEAD is now at 7b71d70 6eme cas
```