# Exercice 10 : La fenetre sans bordure

L'objectif était de créer une fenetre sans bordures décoratives de l'OS, de tenter d'en ajouter une nous-memes et d'evaluer le temps que ça prendrait. Notre barre de titre devait contenir/implémenter :

* **Le titre :** Je me suis rendu compte que je n'avais pas la possibilité d'ajouter un titre sur la barre, étant donné que je n'ai pas accès au module `NkCanvas` à partir de `NkWindow`.

* **Trois boutons :** J'ai créé trois "cliquables" au coin droit supérieur de la fenetre pour jouer les roles des boutons de fermeture, agrandissement/restauration, minimisation.

```cpp
customBtn closeBtn {(static_cast<nkentseu::nk_int32>(winSize.x) - buttonW), 5, buttonW, buttonH};
customBtn maxBtn   {(static_cast<nkentseu::nk_int32>(winSize.x) - (buttonW * 2 - 5)), 5, buttonW, buttonH};
customBtn minBtn   {(static_cast<nkentseu::nk_int32>(winSize.x) - (buttonW * 3 - 10)), 5, buttonW, buttonH};
```

* **Le déplacement à la souris :** Je l'ai implémenté en demandant au programme de détecter tout click éffectué dans la zone définie comme la "barre de titre", c'est-à-dire à une hauteur `<= 40px` du sommet de la fenetre.

```cpp
if (my <= titleBarH)
```

* **Le double-clic qui agrandit :** Je l'ai implémenté en demandant au programme d'agrandir la fenetre à chaque fois qu'il détecte un double-clic dans la zone définie comme la "barre de titre".

**Log généré dans le test :**
```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window
     /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/EXOS/FirstWindow/Build/Bin/Debug-Linux/Window/Window
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-28 10:07:34.041] [INF] [default] [main.cpp:37 in nkmain] -> [TitleBar] Barre de titre retiree
[2026-09-28 10:07:39.154] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:39.374] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:40.994] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:41.210] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:44.706] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:44.922] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Double click : Agrandissement de la fenetre.
[2026-09-28 10:07:45.442] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:45.690] [INF] [default] [main.cpp:98 in nkmain] -> Double click : Agrandissement de la fenetre.
[2026-09-28 10:07:46.130] [INF] [default] [main.cpp:98 in nkmain] -> [INF] [default] [main.cpp:85 in nkmain] -> [TitleBar] Click : Restauration de la fenetre
[2026-09-28 10:07:48.154] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:51.130] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:52.658] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:07:53.514] [INF] [default] [main.cpp:92 in nkmain] -> [TitleBar] Click : Minimisation de la fenetre.
[2026-09-28 10:08:00.738] [INF] [default] [main.cpp:92 in nkmain] -> [TitleBar] Click : Minimisation de la fenetre.
[2026-09-28 10:08:05.874] [INF] [default] [main.cpp:82 in nkmain] -> [TitleBar] Click : Agrandissement de la fenetre.
[2026-09-28 10:08:09.762] [INF] [default] [main.cpp:92 in nkmain] -> [TitleBar] Click : Minimisation de la fenetre.
[2026-09-28 10:08:14.874] [INF] [default] [main.cpp:85 in nkmain] -> [TitleBar] Click : Restauration de la fenetre.
[2026-09-28 10:08:16.386] [INF] [default] [main.cpp:85 in nkmain] -> [TitleBar] Click : Restauration de la fenetre.
[2026-09-28 10:08:19.242] [INF] [default] [main.cpp:85 in nkmain] -> [TitleBar] Click : Restauration de la fenetre.
[2026-09-28 10:08:19.970] [INF] [default] [main.cpp:85 in nkmain] -> [TitleBar] Click : Restauration de la fenetre.
[2026-09-28 10:08:20.706] [INF] [default] [main.cpp:85 in nkmain] -> [TitleBar] Click : Restauration de la fenetre.
[2026-09-28 10:08:22.242] [INF] [default] [main.cpp:98 in nkmain] -> [TitleBar] Click : Deplacement de la fenetre.
[2026-09-28 10:08:42.699] [INF] [default] [main.cpp:75 in nkmain] -> [TitleBar] Click : Fermeture de la fenetre.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (68.67s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

* **Estimation du temps que ça m'a pris :** L'intégration de la barre personnalisé m'a pris environ **2h15mins**. la durée de **2h15mins** représente le le cout réel ou le prix à payer quand un projet décide de concevoir sa propre interface de fenetrage, plutot que d'utiliser celle fournie par l'OS.