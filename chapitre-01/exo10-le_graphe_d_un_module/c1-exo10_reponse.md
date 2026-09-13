# Exercice 10

## Dépendances directes
En ouvrant le fichier `NKCanvas.jenga`, la variable `_canvasDeps` passée a `nkentseudependson` contient la liste des dépendences directes de NKCanvas.

```python
_canvasDeps = ["NKWindow", "NKFont", "NKImage", "NKStream", "NKTime", "NKGlad", "NKThreading"]
```

Nous avons également l'instruction conditionelle qui ajoute `NKUI` à la liste si le flag `USE_CANVAS_NKUI` est activé.

```python
if USE_CANVAS_NKUI:
        _canvasDeps.append("NKUI")
```

Nous pouvons donc considérer que NKUI fait partie des dépendances.

* **Niveau 1 - Dépendances directes :**
    * `NKWindow`
    * `NKFont`
    * `NKImage`
    * `NKStream`
    * `NKTime`
    * `NKGlad`
    * `NKThreading`
    * `NKUI`

## Dépendances des dépendances de Niveau 1
Apres avoir consulté les fichiers .jenga de chaque dépendance de Niveau 1, j'ai relevé les dépendences de niveau 2 ci-dessous :

* **Niveau 2 - Dépendances des dépendances de Niveau 1 :**
    * **`NKWindow`** -> `NKPlatform`, `NKCore`, `NKLogger`, `NKMath`, `NKTime`, `NKContainers`, `NKMemory`, `NKThreading`, `NKEvent`, `NKFileSystem`
    * **`NKFont`** -> `NKPlatform`, `NKCore`, `NKMemory`, `NKMath`, `NKContainers`, `NKThreading`, `NKLogger`
    * **`NKImage`** -> `NKPlatform`, `NKCore`, `NKMemory`, `NKMath`, `NKContainers`, `NKLogger`, `NKThreading`, `NKFileSystem`, `NKStream`
    * **`NKStream`** -> `NKCore`, `NKPlatform`, `NKLogger`, `NKMemory`, `NKContainers`, `NKThreading`, `NKFileSystem`
    * **`NKTime`** -> `NKContainers`, `NKMemory`, `NKLogger`, `NKCore`, `NKPlatform`
    * **`NKGlad`** -> `Aucune dépendance`
    * **`NKThreading`** -> `NKCore`, `NKPlatform`, `NKMemory`, `NKContainers`
    * **`NKUI`** -> `NKPlatform`, `NKCore`, `NKMemory`, `NKMath`, `NKThreading`, `NKLogger`, `NKContainers`, `NKEvent`, `NKFont`

---

## Graphe de dépendances sur deux niveaux

```bash
                                                              ┌──────────┐
                                                              │ NKCanvas │
                                                              └────┬─────┘
                                                                   │
       ┌────────────────┬────────────┬────────────┬────────────────┴───────────────┬──────────────┬────────────┐
       │                │            │            │            │                   │              │            │
       │                ▼            ▼            ▼            ▼                   ▼              ▼            ▼
       │            ┌──────────┐  ┌────────┐  ┌─────────┐  ┌──────────┐        ┌────────┐  ┌─────────────┐  ┌──────┐
       │            │ NKWindow │  │ NKFont │  │ NKImage │  │ NKStream │        │ NKGlad │  │ NKThreading │  │ NKUI │
       │            └────┬─────┘  └──┬─────┘  └──┬──────┘  └───┬──────┘        └────────┘  └─────┬───────┘  └──┬───┘
       │                 │           │           │             │                                 │             │
       ├────────────┬────┴───────────┴───────────┴─────────────┴─────────────────────────────────┴─────────────┤
       │            │                                                                                          │
       ▼            │                                                                                          │
  ┌────────┐        │                                                                                          │
  │ NKTime │        │                                                                                          │
  └────┬───┘        │                                                                                          │
       ├────────────┼───────────────────┬──────────────────────┬───────────────────┬───────────────────────────┤
       │            │                   │                      │                   │                           │
       │            ▼                   ▼                      ▼                   ▼                           │
       │      ┌───────────┐       ┌────────────┐          ┌───────────┐       ┌───────────┐                    │
       │      │  NKEvent  │       │NKFileSystem│          │  NKLogger │       │  NKMath   │                    │
       │      └─────┬─────┘       └─────┬──────┘          └────┬──────┘       └────┬──────┘                    │
       │            │                   │                      │                   │                           │
       │            ├───────────────────┴──────────────────────┼───────────────────┘                           │
       │            ▼                                          ▼                                               │
       │      ┌────────────┐                             ┌───────────┐                                         │
       │      │NKContainers│                             │ NKMemory  │                                         │
       │      └─────┬──────┘                             └─────┬─────┘                                         │
       │            │                                          │                                               │
       └────┬───────┴───────────────────┬──────────────────────┘                                               │
            │                           │                                                                      │
            │                           ▼                                                                      │
            │                     ┌───────────┐                                                                │
            │                     │  NKCore   │                                                                │
            │                     └─────┬─────┘                                                                │
            │                           │                                                                      │
            └───────────────────────────┼──────────────────────────────────────────────────────────────────────┘
                                        │
                                        ▼
                                 ┌────────────┐
                                 │ NKPlatform │
                                 └────────────┘
```

## Nombre de projets à construire avant NKCanvas
En consolidant l'ensemble des 16 dépendances uniques (Niveau 1 et Niveau 2) requises par le projet :

1. NKGlad
2. NKPlatform
3. NKCore
4. NKMemory
5. NKContainers
6. NKMath
7. NKLogger
8. NKEvent
9. NKFileSystem
10. NKTime
11. NKThreading
12. NKStream
13. NKImage
14. NKFont
15. NKWindow
16. NKUI

Nous constatons qu'il faut construire 16 projets avant de pouvoir compiler NKCanvas.