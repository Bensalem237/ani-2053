# Exercice 3 : Les bornes

## Avec les bornes

* J'ai commencé par fixer la largeur minimale (`minWidth`) à **400 points** et la longeur minimale (`minLength`)  à **300 points**.

```cpp
// Limite la taille minimale de la fenetre à 400 x 300
cfg.minWidth = 400;
cfg.minHeight = 300;
```

* Ensuite, j'ai ajouté une condition dans la boucle principale qui récupère la taille de la fenetre chaque fois qu'elle est redimensionnée, la stocke, et l'affiche dans le `log`.

```cpp
// Récupère, stocke et affiche les dimensions de la fenetre chaque fois qu'elle est redimensionnée
if (event->Is<nkentseu::NkWindowResizeEvent>()) {
    auto windowSize = window.GetSize();

    int width = windowSize.width;
    int height = windowSize.height;

    logger.Info("[app] window resized: {0}x{1}", width, height);
}
```

* Ensuite, j'ai compilé et lancé le programme avec `jenga build`, puis `jenga run`

* J'ai réduit la fenetre et la taille minimale était éffectivement de `400x300 points`.

```
[2026-09-24 14:33:35.416] [INF] [default] [main.cpp:49 in nkmain] -> [app] window resized: 400x300
```

## Sans les bornes

* Ensuite, j'ai retiré les bornes dans mon code source, puis j'ai compilé et lancé le programme.

* La taille minimale imposée par le système est de `160x90 points`.

```
[2026-09-24 14:57:46.871] [INF] [default] [main.cpp:49 in nkmain] -> [app] window resized: 160x90
```