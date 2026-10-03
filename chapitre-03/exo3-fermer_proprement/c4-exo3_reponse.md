# Exercice 3 : Fermer proprement

L'objectif était d'écrire un programme qui crée une fenetre, et qui permet de la fermer proprement, passant uniquement par l'évènement de fermeture du système.

```cpp
window.Close();
```

On devait se rassurer que le bouton système (`x`), le raccource du gestionnaire de fenetres (`Alt+F4`), et une touche du clavier prédéfinie (`ESCAPE`) passent tous par le meme chemin. Pour se faire, le projet crée une fonction centralisée `fermeture()` qui est appelée dans les deux evènements (`NkWindowCloseEvent`, et `NkKeyPressEvent`).

```cpp
void fermeture(nkentseu::NkWindow &win) {
    logger.Info("[app] Fermeture de la fenetre.");
    win.Close();
}
```

**logs :**

Fermeture avec le bouton système :
```
[2026-10-03 02:29:46.539] [INF] [default] [main.cpp:14 in fermeture] -> [app] Fermeture de la fenetre.
```

Fermeture avec le raccource du gestionnaire de fenetres (`Alt+F4`) :
```
[2026-10-03 02:30:46.703] [INF] [default] [main.cpp:14 in fermeture] -> [app] Fermeture de la fenetre.
```

Fermeture avec la touche `ESCAPE`:
```
[2026-10-03 02:31:47.679] [INF] [default] [main.cpp:14 in fermeture] -> [app] Fermeture de la fenetre.
```

On peut voir que tous les cas passent par le meme chemin.