# Exercice 4 : Le facteur d'échelle

J'ai ajouté les instructions suivantes à mon code source pour pouvoir récupérer les tailles de la zone client, la fenetre, et le facteur d'échelle de l'écran.

```cpp
// Taille initiale de la zone client
    auto windowSize = window.GetSize();
    logger.Info("[app] Taille initiale de la zone client: {0}x{1}", windowSize.width, windowSize.height);

    // Taille initiale de la fenetre
    auto displaySize = window.GetDisplaySize();
    logger.Info("[app] Taille initiale de la fenetre: {0}x{1}", displaySize.width, displaySize.height);

    // Facteur d'échelle
    auto dpiScale = window.GetDpiScale();
    logger.Info("[app] Facteur d'echelle DPI: {0}", dpiScale);
```

Ensuite, j'ai compilé et lancé le programme avec `jenga build`, puis `jenga run` et puis j'ai récupéré les valeurs dans le `log`.

```
[2026-09-24 15:44:06.336] [INF] [default] [main.cpp:31 in nkmain] -> [app] Taille initiale de la zone client: 1000x600
[2026-09-24 15:44:06.336] [INF] [default] [main.cpp:35 in nkmain] -> [app] Taille initiale de la fenetre: 1366x768
[2026-09-24 15:44:06.338] [INF] [default] [main.cpp:39 in nkmain] -> [app] Facteur d'echelle DPI: 1.16587
```

## Résultats

| Taille de la fenetre | Taille de la cible de rendu | Facteur d'échelle |
| :--- | :--- | :--- |
| 1366x768 | 1000x600 | 1.16587 |