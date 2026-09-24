# Exercice 1 : La fenetre nue

## Nombre de lignes

Mon fichier source (`chapitre-03/exo1-la_fenetre_nue/c3-exo1_main.cpp`) compte **26** lignes.

## Comparaison avec le code du chapitre

**Mon code source**
```cpp
#include <NKWindow/NKWindow.h>
#include <NKWindow/NKMain.h>
#include <NKEvent/NkWindowEvent.h>

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1280;
    cfg.height = 720;

    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation de la fenetre echouee");
        return -1;
    }

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }
        }
    }
    return 0;
}
```

**Code du chapitre**
```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title  = "Ma fenetre";
    cfg.width  = 1280;
    cfg.height = 720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation fenetre echouee");
        return -1;
    }
    while (window.IsOpen()) { /* les evenements arrivent ici */ }
    return 0;
}
```

### Inclusions

Dans mon code, je commence par inclure les bibloithèques `NKWindow/NKWindow.h`, `NKWindow/NKMain.h`, et `NKEvent/NkWindowEvent.h`. Le code du chapitre inclut les deux premières bibliothèques, mais pas la troisième, car ce n'est pas necessaire du fait que le programme ne gère pas du tout les évènements.

## Le point d'entrée et la structure de configuration

Dans les deux codes, on peur remarquer la présence du point d'entrée (`int nkmain`), de la déclaration de la structure de configuration `cfg`, et l'initialization de trois de ses champs (`cfg.title`, `cfg.width`, `cfg.height`).

## Declaration de la fenetre

Ensuite, dans les deux bouts de code, on voit la déclaration d'une fenetre à laquelle l'on passe la structure de configuration?

## Erreur de creation

Ensuite, dans les deux bouts de code, on voit l'instruction conditionnelle pour gérer les erreurs de création de la fenetre.

## La boucle principale

Ensuite, dans les deux bouts de code, on a l'ouverture de la boucle principale que mentient la fenetre ouverte.

## La particularité

Le code du chapitre se limite à créer une fenetre vide dans lequel il ne se passe rien. Dans mon code, j'ai ajoué la possibilité de fermer l'écran en appuyant sur le `x` sur la barre de titre.