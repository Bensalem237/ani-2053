Exercice 11 : Deux fenetres

L'objectif était :

De créer simultanément deux instances de `NkWindow` :

```cpp
nkentseu::NkWindow windowA(cfg1);
nkentseu::NkWindow windowB(cfg2);
```

D'intercepter les clics de la souris :

```cpp
if (auto* clickEvent = event->As<nkentseu::NkMouseButtonPressEvent>()) {
    if (clickEvent->GetButton() == nkentseu::NkMouseButton::NK_MB_LEFT) {
        // Routage des clics
    }
}
```

Et d'identifier quelle instance de `NkWindow` a reçu quel clic :

```cpp
if (targetId == idA) {
    logger.Info("[Clic] Reçu par la FENÊTRE A (ID: {0}) aux coordonnées locales ({1}, {2})", 
                targetId, clickEvent->GetX(), clickEvent->GetY());
} 
else if (targetId == idB) {
    logger.Info("[Clic] Reçu par la FENÊTRE B (ID: {0}) aux coordonnées locales ({1}, {2})", 
                targetId, clickEvent->GetX(), clickEvent->GetY());
} 
else {
    logger.Info("[Clic] Reçu par une fenêtre inconnue (ID: {0})", targetId);
}
```

**Log généré lors du test :**
```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window
     /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/EXOS/FirstWindow/Build/Bin/Debug-Linux/Window/Window
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-28 21:10:01.503] [INF] [default] [main.cpp:40 in nkmain] -> [Multi-Win] Fenetre A creee avec l'ID : 1
[2026-09-28 21:10:01.504] [INF] [default] [main.cpp:41 in nkmain] -> [Multi-Win] Fenetre B creee avec l'ID : 2
[2026-09-28 21:10:08.662] [INF] [default] [main.cpp:72 in nkmain] -> [Clic] Recu par la FENETRE B (ID: 2) aux coordonnees locales (162, 148)
[2026-09-28 21:10:14.515] [INF] [default] [main.cpp:72 in nkmain] -> [Clic] Recu par la FENETRE B (ID: 2) aux coordonnees locales (112, 251)
[2026-09-28 21:10:15.998] [INF] [default] [main.cpp:68 in nkmain] -> [Clic] Recu par la FENETRE A (ID: 1) aux coordonnees locales (280, 159)
[2026-09-28 21:10:17.798] [INF] [default] [main.cpp:72 in nkmain] -> [Clic] Recu par la FENETRE B (ID: 2) aux coordonnees locales (83, 73)
[2026-09-28 21:10:18.252] [INF] [default] [main.cpp:68 in nkmain] -> [Clic] Recu par la FENETRE A (ID: 1) aux coordonnees locales (336, 98)
[2026-09-28 21:10:18.739] [INF] [default] [main.cpp:68 in nkmain] -> [Clic] Recu par la FENETRE A (ID: 1) aux coordonnees locales (131, 71)
[2026-09-28 21:10:19.261] [INF] [default] [main.cpp:72 in nkmain] -> [Clic] Recu par la FENETRE B (ID: 2) aux coordonnees locales (163, 63)
[2026-09-28 21:10:19.716] [INF] [default] [main.cpp:68 in nkmain] -> [Clic] Recu par la FENETRE A (ID: 1) aux coordonnees locales (272, 101)
[2026-09-28 21:10:23.340] [INF] [default] [main.cpp:55 in nkmain] -> [Multi-Win] Fermeture de la fenetre B.
[2026-09-28 21:10:26.161] [INF] [default] [main.cpp:52 in nkmain] -> [Multi-Win] Fermeture de la fenetre A.
[2026-09-28 21:10:26.163] [INF] [default] [main.cpp:83 in nkmain] -> [Multi-Win] Toutes les fenetres sont fermees. Fin du programme.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (24.68s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

Ensuite il falait répondre à la question technique : **Que vous manquerait-il pour déssiner dans les deux instances?**

**Réponse :** Pour pouvoir déssiner dans chaque fenetre séparément, il faut :
* Attribuer à chaque fenetre son propre contexte graphique.
* Puis effectuer une commutation du contexte de rendu à chaque trame, étant donné que
la carte graphique ne peut déssiner que sur un contexte à la fois.

```cpp
// À l'intérieur de la boucle principale
graphicsContext.MakeCurrent(windowA);
// Rendu...

graphicsContext.MakeCurrent(windowB);
// Rendu...
```
