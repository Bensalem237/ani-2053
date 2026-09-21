# Démonstration 3 : Ce que reflog sauve

Date de présentation : Lundi, 21 Septembre 2026
Heure de début : 12:41
Heure de fin : 12:58

* J'ai commencé par vérifier l'état de mon depot avec la commande `git log --oneline`

**Sortie du terminal :**
```
7a0b0db (HEAD -> main) demo2
c22db92 demo2
```

* Ensuite, j'ai détruit le dernier commit avec la commande `git rese --hard HEAD~1`

**Sortie du terminal :**
```
HEAD is now at c22db92 demo2
```

* Ensuite, j'ai constaté la perte avec la commande `git log --oneline`

**Sortie du terminal :**
```
c22db92 (HEAD -> main) demo2
```
**On a remarqué que le dernier commit etait perdu**

* Ensuite, J'ai tapé la commande `git reflog` pour retrouver le fichier.

**Sortie du terminal**
```
c22db92 (HEAD -> main) HEAD@{0}: reset: moving to HEAD~1
7a0b0db HEAD@{1}: commit: demo2
c22db92 (HEAD -> main) HEAD@{2}: checkout: moving from branche to main
afddcdf (branche) HEAD@{3}: commit: demo2
c22db92 (HEAD -> main) HEAD@{4}: checkout: moving from main to branche
c22db92 (HEAD -> main) HEAD@{5}: commit (initial): demo2
```

* On a retrouvés le commit qui est listé à la troisième ligne de la sortie du terminal.

* Ensuite, on l'a restauré avec la commande `git reset --hard HEAD@{1}`.

**Sortie du terminal :**
```
HEAD is now at 7a0b0db demo2
```

* Ensuite, on a vérifiés avec la commande `git log --oneline`

**Sortie du terminal :**
```
7a0b0db (HEAD -> main) demo2
c22db92 demo2
```