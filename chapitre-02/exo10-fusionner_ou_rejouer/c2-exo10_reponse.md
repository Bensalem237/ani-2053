# Exercice 10 : Fusionner ou rejouer

## Fusion

Voici le graphe des commit que j'ai obtenu en fusionnant mes deux branches sans rebase

```
*   50353b4 (HEAD -> main, origin/main) Fusion de la branche fonctionnalite_1 sans rebase
|\  
| * 3dfee30 (fonctionnalite_1) Deuxieme commit fonctionnalite_1
| * 6275f67 Premier commit fonctionnalite_1
* | 92b1c87 Commit sur la branche principale
|/  
* 7b71d70 6eme cas
* 2536152 exo8
```

Nous pouvons voir que le dervier commit a deux parents et qu'on peut facilement retracer l'historique.

## Rejouer

Voici le graphe de la fusion des deux branches avec rebase avec le graphe précédent juste en dessous

```
* be11658 (HEAD -> main, origin/main, fonctionnalite_1) Deuxieme commit sur fonctionnalite_1 (Rejouer)
* 937e97c Premier commit sur fonctionnalite_1 (Rejouer)
* 91d75df Encore un commit sur la branche principale
* b04cc27 Un autre commit sur la branche principale
*   50353b4 Fusion de la branche fonctionnalite_1 sans rebase
|\  
| * 3dfee30 Deuxieme commit fonctionnalite_1
| * 6275f67 Premier commit fonctionnalite_1
* | 92b1c87 Commit sur la branche principale
|/  
* 7b71d70 6eme cas
* 2536152 exo8
```

Sur ce graphe, nous pouvons mieux voir la différence entre les deux. Avec rebase, git a completement fusionné tous les commits comme s'il s'agissait d'une seule branche depuis le départ.

## Comparaison

Dans la fusion sans rebase, git garde l'historique des deux branches séparées, et on peut facilement retracer l'historique de chaque brache séparément, ce qui n'est pas le cas de la fusion avec rebase. C'est pour cela que je prefère lire le graphe de la fusion sans rebase
