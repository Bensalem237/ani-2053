# Démonstration 2 : Le conflit résolu en direct

Date de présentation : Lundi, 21 Septembre 2026
Heure de début : 12:18
Heure de fin : 12:34

## Déclanchement du conflit

* Pour déclancher le conflit, j'ai modifié les memes lignes du meme fichier sur deux branches parallèles de mon depot, ensuite, j'ai essayé de fusionner les deux branches avec la commande `git merge branche` et ç'a déclanché le conflit.

```
Auto-merging fichier.txt
CONFLICT (content): Merge conflict in fichier.txt
Automatic merge failed; fix conflicts and then commit the result.
```

## Résolution du conflit

Pour résoudre le conflit, j'ai suivi les étapes suivantes :

* J'ai tapé `git status` pour voir le fichier concerné.

* Ensuite, je l'ai ouvert et j'ai modifié les lignes qui étaient en conflit.

* Ensuite, j'ai tapé la commande `git commit -m "demo2" pour commit le fichier.