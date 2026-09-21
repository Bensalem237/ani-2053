# Exercice 11 : Le fichier qu'on n'aurait pas du

* Avant toute chose, j'ai commencé par mesurer la taille initiale de mon répertoire `.git` grace à la commande `du sh .git`

**Sortie du terminal :**
```
888K	.git
```

* La taille initiale est de `888Ko`.

* Ensuite j'ai commit un fichier de `10.7Mo` précisement.

**Sortie du terminal :**
```
[main 88e7963] c2exo11
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100755 Classifications of Computer Architecture.mp4
```

* Ensuite, j'ai mesuré de nouveau la taille de `.git` avec la commande `du -sh .git`

**Sortie du terminal :**
```
11M	.git
```

* La taille est maintenant de `11Mo`

* Ensuite, j'ai supprimé le commit grace à la commande suivante

```bash
git reset --hard HEAD~1
```

**Sortie du terminal :**
```
HEAD is now at be11658 Deuxieme commit sur fonctionnalite_1 (Rejouer)
```

* Ensuite, j'ai de nouveau vérifié la taille de `.git` avec la commande `du -sh .git`

**Sortie du terminal :**
```
11M	.git
```
La taille du répertoire `.git` n'a pas changé.

## Conclusion

* Une fois qu'on fait un commit, il est stocké définitivement dans l'historique du dépot, et ne peut etre supprimé en annulant simplement le commit.