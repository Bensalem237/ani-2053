# Exercice 4 : Le commit partiel

* J'ai commencé par modifier deux choses sans rapport dans mon fichier_2.cpp comme demandé dans l'énoncé.

Ensuite, j'ai tapé la commande
```bash
git add -p
```
pour commit les deux changements séparement. J'ai obtenu la sortie suivante :

```
diff --git a/fichier_2.cpp b/fichier_2.cpp
index f744748..7e68b83 100644
--- a/fichier_2.cpp
+++ b/fichier_2.cpp
@@ -2,13 +2,14 @@
 #include <vector>
 
 int main() {
-    std::vector<int> numbers = {1, 2, 3, 4, 5};
+    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8. 9. 10};
     
     std::cout << "Numbers in the vector: ";
     for (const auto& num : numbers) {
         std::cout << num << " ";
     }
     std::cout << std::endl;
+    std::cout << "Fin du programme !" << std::endl;
 
     return 0;
}

(1/1) Stage this hunk [y,n,q,a,d,s,e,?]?
```

* Il m'a été demandé d'entrer un caractère en fonction de ce que je voulais faire, et j'ai tapé `s` pour séparer les parties contenant les différents changements. Le fichier a donc été séparé en deux.

* J'ai tapé `y` pour ajouter la première modification à l'index, puis j'ai tapé `n` pour la deuxième, car il fallait que je commit d'abord le premier changement.

* J'ai commit le premier changement
```bash
git commit -m "Prolonged the array"

[main 13beb4f] Prolonged the array
 1 file changed, 1 insertion(+), 1 deletion(-)
```

* J'ai ensuite vérifié le status du dépot pour vérifier que ça n'ait commit qu'une partie de mon fichier
 ```bash
git status

On branch main
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   fichier_2.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

* J'ai ensuite tapé de nouveau `git add -p` puis j'ai tapé `y` pour valider
```bash
git add -p
diff --git a/fichier_2.cpp b/fichier_2.cpp
index 9e99214..7e68b83 100644
--- a/fichier_2.cpp
+++ b/fichier_2.cpp
@@ -9,6 +9,7 @@ int main() {
         std::cout << num << " ";
     }
     std::cout << std::endl;
+    std::cout << "Fin du programme !" << std::endl;
 
     return 0;
-}
\ No newline at end of file
+}
(1/1) Stage this hunk [y,n,q,a,d,s,e,?]? y
```

* J'ai ensuite commit
```bash
git commit -m "Added a little message at the end of the program"
[main 1057d1c] Added a little message at the end of the program
 1 file changed, 2 insertions(+), 1 deletion(-)
```

## Historique

```
git log --oneline

1057d1c (HEAD -> main) Added a little message at the end of the program
13beb4f Prolonged the array
9c6e362 Ajout de deux lignes au code
f228c11 Commit du troisieme fichier
56e698f Commit du deuxieme fichier
ca5e171 Commit du premier fichier
```

Nous pouvons remarquer que les deux commits sont séparés.