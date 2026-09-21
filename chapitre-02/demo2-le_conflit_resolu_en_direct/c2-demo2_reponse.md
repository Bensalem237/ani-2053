# Démonstration 2 : Le conflit résolu en direct

Date de présentation : Lundi, 21 Septembre 2026
Heure de début : 12:18
Heure de fin : 12:34

## Déclanchement du conflit

* Pour déclancher le conflit, j'ai modifié les memes lignes du meme fichier sur deux branches parallèles de mon depot, ensuite, j'ai essayé de fusionner les deux branches avec la commande `git merge branche` et ç'a déclanché le conflit.

**Sortie du terminal :**
```
Auto-merging fichier.txt
CONFLICT (content): Merge conflict in fichier.txt
Automatic merge failed; fix conflicts and then commit the result.
```

## Résolution du conflit

Pour résoudre le conflit, j'ai suivi les étapes suivantes :

* J'ai tapé `git status` pour voir le fichier concerné.

**Sortie tu terminal :**
```
On branch main
You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
	both modified:   fichier.txt

no changes added to commit (use "git add" and/or "git commit -a")
```

* Ensuite, je l'ai ouvert le fichier avec `nano fichier.txt` et j'ai supprimé une des lignes ainsi que les marqueurs mis par git

**Sortie du terminal :**
```
<<<<<<< HEAD
modifa
=======
modifi
>>>>>>> branche
```

* Ensuite, j'ai tapé la commande `git add fichier.txt` suivi de `git commit -m "demo2"` pour commit le fichier.

**Sortie du terminal :**
```
[main 392a844] demo2
```

* Ensuite, j'ai revérifié le status avec `git status`

**Sortie du terminal :**
```
On branch main
nothing to commit, working tree clean
```

**Conflit résolu !**