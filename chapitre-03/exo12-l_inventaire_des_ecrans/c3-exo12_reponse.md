# Exercice 12 : L'inventaire des écrans

L'objectif était :

D'écrire un programme capable de lister les moniteurs branchés sur l'OS et leurs caratéristiques (taille, position, facteur d'echelle, lequel porte la fenetre), et détecter en temps réel quel écran porte la fenetre active :

```cpp
void DisplayMonitorsInfo(const nkentseu::NkWindow &window)
```

**Log généré lors du test :**
```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window
     /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/EXOS/FirstWindow/Build/Bin/Debug-Linux/Window/Window
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-28 22:30:43.218] [INF] [default] [main.cpp:52 in nkmain] -> [Multi-Screen] Application lancee. Appuyez sur [  ESPACE  ] pour afficher l'etat des ecrans connectes.
[2026-09-28 22:30:43.218] [INF] [default] [main.cpp:16 in DisplayMonitorsInfo] -> --- ETAT DES ECRANS CONNECTES ---
[2026-09-28 22:30:43.273] [INF] [default] [main.cpp:26 in DisplayMonitorsInfo] -> Ecran[0] : Position(0, 0) | Taille(1366, 768) | Principal: OUI | Fenetre presente: OUI
[2026-09-28 22:30:43.276] [INF] [default] [main.cpp:35 in DisplayMonitorsInfo] -> Facteur d'echelle (DPI) actuel de la fenetre : 1.16587
[2026-09-28 22:30:43.276] [INF] [default] [main.cpp:36 in DisplayMonitorsInfo] -> ---------------------------------
[2026-09-28 22:30:43.276] [INF] [default] [main.cpp:26 in DisplayMonitorsInfo] -> Ecran[1] : Position(1366, 0) | Taille(1360, 768) | Principal: NON | Fenetre presente: NON
[2026-09-28 22:30:43.277] [INF] [default] [main.cpp:35 in DisplayMonitorsInfo] -> Facteur d'echelle (DPI) actuel de la fenetre : 1.16587
[2026-09-28 22:30:43.278] [INF] [default] [main.cpp:36 in DisplayMonitorsInfo] -> ---------------------------------
[2026-09-28 22:31:04.970] [INF] [default] [main.cpp:78 in nkmain] -> [Multi-Screen] La fenetre a change d'ecran.
[2026-09-28 22:31:04.970] [INF] [default] [main.cpp:16 in DisplayMonitorsInfo] -> --- ETAT DES ECRANS CONNECTES ---
[2026-09-28 22:31:04.971] [INF] [default] [main.cpp:26 in DisplayMonitorsInfo] -> Ecran[0] : Position(0, 0) | Taille(1366, 768) | Principal: OUI | Fenetre presente: NON
[2026-09-28 22:31:04.971] [INF] [default] [main.cpp:35 in DisplayMonitorsInfo] -> Facteur d'echelle (DPI) actuel de la fenetre : 1
[2026-09-28 22:31:04.971] [INF] [default] [main.cpp:36 in DisplayMonitorsInfo] -> ---------------------------------
[2026-09-28 22:31:04.971] [INF] [default] [main.cpp:26 in DisplayMonitorsInfo] -> Ecran[1] : Position(1366, 0) | Taille(1360, 768) | Principal: NON | Fenetre presente: OUI
[2026-09-28 22:31:04.973] [INF] [default] [main.cpp:35 in DisplayMonitorsInfo] -> Facteur d'echelle (DPI) actuel de la fenetre : 1
[2026-09-28 22:31:04.973] [INF] [default] [main.cpp:36 in DisplayMonitorsInfo] -> ---------------------------------
[2026-09-28 22:31:14.396] [INF] [default] [main.cpp:78 in nkmain] -> [Multi-Screen] La fenetre a change d'ecran.
[2026-09-28 22:31:14.396] [INF] [default] [main.cpp:16 in DisplayMonitorsInfo] -> --- ETAT DES ECRANS CONNECTES ---
[2026-09-28 22:31:14.397] [INF] [default] [main.cpp:26 in DisplayMonitorsInfo] -> Ecran[0] : Position(0, 0) | Taille(1366, 768) | Principal: OUI | Fenetre presente: OUI
[2026-09-28 22:31:14.397] [INF] [default] [main.cpp:35 in DisplayMonitorsInfo] -> Facteur d'echelle (DPI) actuel de la fenetre : 1.16587
[2026-09-28 22:31:14.398] [INF] [default] [main.cpp:36 in DisplayMonitorsInfo] -> ---------------------------------
[2026-09-28 22:31:14.398] [INF] [default] [main.cpp:26 in DisplayMonitorsInfo] -> Ecran[1] : Position(1366, 0) | Taille(1360, 768) | Principal: NON | Fenetre presente: NON
[2026-09-28 22:31:14.398] [INF] [default] [main.cpp:35 in DisplayMonitorsInfo] -> Facteur d'echelle (DPI) actuel de la fenetre : 1.16587
[2026-09-28 22:31:14.398] [INF] [default] [main.cpp:36 in DisplayMonitorsInfo] -> ---------------------------------

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (34.16s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```