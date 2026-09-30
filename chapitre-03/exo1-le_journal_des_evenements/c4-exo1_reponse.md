# Exercice 1 : Le journal des évènements

L'objectif était de créer des évènements (Déplacement de la souris, pression du clavier, redimensionnement de la fenetre, dépot de fichier),

```cpp
// Déplacement de la souris
if (auto* mouseMove = event->As<nkentseu::NkMouseMoveEvent>()) {}

// Pression du clavier
if (auto* keyPress = event->As<nkentseu::NkKeyPressEvent>()) {}

// Redimenssionement de la fenetre
if (auto* rz = event->As<nkentseu::NkWindowResizeEvent>()) {}

// Dépot d'un fichier
if (auto* drop = event->As<nkentseu::NkDropFileEvent>()) {}
```

Et d'afficher dans le journal chaque évènement reçu avec sa famille et son type.

```cpp
// Souris
logger.Info("[app] Souris déplacée : Famille({0}), Type({1})", nkentseu::NkEventCategory::ToString(mouseMove->GetCategory()), nkentseu::NkEventType::ToString(mouseMove->GetType()));

// Clavier
logger.Info("[app] Touche du clavier pressée : Famille({0}), Type({1})", nkentseu::NkEventCategory::ToString(keyPress->GetCategory()), nkentseu::NkEventType::ToString(keyPress->GetType()));

// Redimensionnement
logger.Info("[app] Fenetre redimensionnée : Famille({0}), Type({1})", nkentseu::NkEventCategory::ToString(rz->GetCategory()), nkentseu::NkEventType::ToString(rz->GetType()));

// Dépot de fichier
logger.Info("[app] Fichier déposé dans la zone client : Famille({0}), Type({1})", nkentseu::NkEventCategory::ToString(drop->GetCategory()), nkentseu::NkEventType::ToString(drop->GetType()));
```

**Journal :**
```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window
     /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/EXOS/FirstWindow/Build/Bin/Debug-Linux/Window/Window
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-30 16:11:59.362] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:11:59.365] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:11:59.423] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.644] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.654] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.664] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.674] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.684] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.695] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.704] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.715] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.725] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.735] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.745] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.755] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.765] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.776] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.786] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.796] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.807] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.816] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.827] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.837] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.847] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.857] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.870] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.878] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.888] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.898] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.909] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.918] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.929] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.939] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.949] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.959] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.970] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.980] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:00.990] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:01.000] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:02.469] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:02.645] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:02.832] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:02.832] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:02.930] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:02.952] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.022] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.026] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.132] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.132] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.213] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.321] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.329] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.334] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:03.425] [INF] [default] [main.cpp:49 in nkmain] -> [app] Touche du clavier pressee : Famille(INPUT|KEYBOARD), Type(NK_KEY_PRESSED)
[2026-09-30 16:12:05.988] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:05.998] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.008] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.019] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.030] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.039] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.049] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.059] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.070] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.080] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.090] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.100] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.110] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.121] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.130] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.141] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.151] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.161] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.171] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.181] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.192] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.202] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.212] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.222] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.232] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.242] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.253] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.263] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.273] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.283] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.293] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.304] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.314] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.324] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.334] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.344] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.355] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.365] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.375] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.385] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.395] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.405] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.415] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.426] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.436] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.446] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.456] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:06.466] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:08.691] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.705] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.735] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.769] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.800] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.834] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.866] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.901] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.933] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:08.969] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.004] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.036] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.068] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.102] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.143] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.187] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.219] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.252] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.285] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.325] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.353] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.382] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.414] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.447] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.480] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.497] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.516] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.531] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.564] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.578] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.596] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.616] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.635] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.649] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.679] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.714] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.731] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.780] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.798] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.830] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.848] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.880] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:09.915] [INF] [default] [main.cpp:54 in nkmain] -> [app] Fenetre redimensionnee : Famille(WINDOW), Type(NK_WINDOW_RESIZE)
[2026-09-30 16:12:24.864] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:24.869] [INF] [default] [main.cpp:59 in nkmain] -> [app] Fichier depose dans la zone client : Famille(NONE), Type(NK_DROP_FILE)
[2026-09-30 16:12:25.347] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:25.358] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:25.368] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:25.378] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:25.388] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:25.399] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:25.408] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:25.419] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:27.263] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:27.266] [INF] [default] [main.cpp:59 in nkmain] -> [app] Fichier depose dans la zone client : Famille(NONE), Type(NK_DROP_FILE)
[2026-09-30 16:12:27.859] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:27.872] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:27.880] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:27.890] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:27.901] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:29.766] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:29.768] [INF] [default] [main.cpp:59 in nkmain] -> [app] Fichier depose dans la zone client : Famille(NONE), Type(NK_DROP_FILE)
[2026-09-30 16:12:30.482] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.493] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.503] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.513] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.523] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.533] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.543] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.554] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.564] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.574] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.584] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.594] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:30.604] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:32.005] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:32.404] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:32.414] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:32.424] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:32.435] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:32.445] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:32.455] [INF] [default] [main.cpp:44 in nkmain] -> [app] Souris deplacee : Famille(INPUT|MOUSE), Type(NK_MOUSE_MOVE)
[2026-09-30 16:12:33.958] [INF] [default] [main.cpp:31 in nkmain] -> [app] Fermeture de la fenetre

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (34.62s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

Enfin, il falait compter le nombre d'évènements qu'un usage normal produit en moyenne en une seconde. pour ce faire, j'ai copié le journal, puis je l'ai collé dans un fichier `journalc4exo1.log` que j'ai créé, ensuite, dans le terminal, j'ai tapé la commande suivante :

```bash
cut -d. -f1 journalc4exo1.log | sort | uniq -c | awk '{sum+=$1; count++} END {print sum/count}'
```

`cut -d. -f1 journalc4exo1.log` permet de couper chaque ligne du journal à partir du premier point, afin de ne préserver que les secondes, et éliminer les millisecondes.

`sort | uniq -c` permet de regroupper toutes les lignes qui ont la même valeur de seconde.

`awk '...'` permet de compter le nombre de lignes de chaque regrouppement, le nombre de regrouppements, puis d'écrire le quotient dans le terminal.


**Résultat :**
```
11.5625
```
