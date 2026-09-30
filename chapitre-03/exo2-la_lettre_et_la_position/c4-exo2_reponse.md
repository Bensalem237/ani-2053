# Exercice 2 : La lettre et la position

L'objectif était de créer un évènement de saisie au clavier,

```cpp
// Créé uniquement pour pouvoir récupérer `NkScancode`, étant donné que `NkTextInputEvent` ne contient pas de classe pour stocker le code physique
if (auto* keyPress = event->As<nkentseu::NkKeyPressEvent>()) {}

// L'évènement central, pour récupérer la lettre de la touche pressée
if (auto* keyPress = event->As<nkentseu::NkTextInputEvent>()) {}
```

De récupérer, pour toute touche pressée. sa lettre et son code physique,

```cpp
nkentseu::NkString Lettre = letterPress->GetUtf8();
// Récupère le code physique
nkentseu::NkScancode Code = GetCodePhysique();
```

Puis de les afficher cote à cote dans le journal

```cpp
logger.Info("[app] Touche pressée. Lettre : {0} ; Code physique : {1}", Lettre, nkentseu::NkScancodeToString(Code));
```

## Journaux pour les deux dispositions clavier

La disposition initiale de mon clavier est `US (QWERTY)`. Voici le journal généré lors de l'utilisation :

```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window
     /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/EXOS/FirstWindow/Build/Bin/Debug-Linux/Window/Window
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-30 23:46:49.575] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : J ; Code physique : SC_J
[2026-09-30 23:46:52.859] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : ' ; Code physique : SC_APOSTROPHE
[2026-09-30 23:46:56.108] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : a ; Code physique : SC_A
[2026-09-30 23:46:56.455] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : i ; Code physique : SC_I
[2026-09-30 23:46:56.794] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : m ; Code physique : SC_M
[2026-09-30 23:46:57.046] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : e ; Code physique : SC_E
[2026-09-30 23:46:58.100] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre :   ; Code physique : SC_SPACE
[2026-09-30 23:46:59.036] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : l ; Code physique : SC_L
[2026-09-30 23:46:59.284] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : e ; Code physique : SC_E
[2026-09-30 23:47:01.485] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre :   ; Code physique : SC_SPACE
[2026-09-30 23:47:02.046] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : C ; Code physique : SC_C
[2026-09-30 23:47:03.875] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : + ; Code physique : SC_EQUALS
[2026-09-30 23:47:04.141] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : + ; Code physique : SC_EQUALS
[2026-09-30 23:47:24.676] [INF] [default] [main.cpp:44 in nkmain] -> [app] Fermeture de la fenetre

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (39.80s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

Ensuite, j'ai changé la disposition du clavier pour `Cameroon (AZERTY)`. voici le journal généré lors de l'utilisation :

```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window
     /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/EXOS/FirstWindow/Build/Bin/Debug-Linux/Window/Window
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-30 23:47:46.231] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : J ; Code physique : SC_J
[2026-09-30 23:47:49.602] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : q ; Code physique : SC_A
[2026-09-30 23:47:51.603] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : i ; Code physique : SC_I
[2026-09-30 23:47:56.523] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : , ; Code physique : SC_M
[2026-09-30 23:47:56.920] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : e ; Code physique : SC_E
[2026-09-30 23:47:58.118] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre :   ; Code physique : SC_SPACE
[2026-09-30 23:47:58.908] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : l ; Code physique : SC_L
[2026-09-30 23:47:59.155] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : e ; Code physique : SC_E
[2026-09-30 23:47:59.690] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre :   ; Code physique : SC_SPACE
[2026-09-30 23:48:04.022] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : C ; Code physique : SC_C
[2026-09-30 23:48:06.876] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : + ; Code physique : SC_EQUALS
[2026-09-30 23:48:07.717] [INF] [default] [main.cpp:60 in nkmain] -> [app] Touche pressee. Lettre : + ; Code physique : SC_EQUALS
[2026-09-30 23:48:12.564] [INF] [default] [main.cpp:44 in nkmain] -> [app] Fermeture de la fenetre

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (29.53s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

## Observations et Explications

Quand j'ai utilisé la disposition `QWERTY`, toutes les lettres correspondaient parfaitement avec les codes physiques, mais quand j'ai changé la disposition du clavier pour `AZERTY`, j'ai tappé exactement les mêmes boutons dans le même ordre, mais les lettre différaient, ce qui est normal, étant donné que j'ai changé la disposition du clavier. Cependant, les codes physiques n'ont pas changés pour chacune des touches, parceque `NkScancode` renvoit la position du bouton (Se servant du clavier `US QWERTY` comme reference), indépendament de la disposition actuelle du clavier.