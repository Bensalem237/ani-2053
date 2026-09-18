# Démo 4

## Les cinq couches
Voici les cinq couches listées dans l'ordre de la hierarchie, allant de la plus basse à la plus haute :

* **Kernel/Foundation**
* **Kernel/System**
* **Kernel/Runtime**
* **Engine**
* **Applications**

Ces information proviennent directement du cours

## Les dix modules qui pèsent le plus en lignes

Pour obtenir la liste des dix modules qui pèsent le plus en lignes, j'ai tapé la commande :

```bash
find {Kernel/Foundation,Kernel/System,Kernel/Runtime,Engine,Applications} -mindepth 1 -maxdepth 1 -type d 2>/dev/null | while read -r mod; do
    total_lines=$(find "$mod" -maxdepth 10 -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" -o -name "*.cc" -o -name "*.cxx" -o -name "*.jenga" \) -exec cat {} + | wc -l)
    echo -e "$total_lines\t$mod"
done | sort -nr | head -n 10
```

Voici les dix modules :

```
                ╔══════════════════════════════╗
                ║ #1 Kernel/Runtime/NKRenderer ║
                ║        (101179 Lines)        ║
                ╚══════════════════════════════╝
                     │   │   │   │   │
                     ├───┼───┼───┼───┴───────► #8 NKRHI
                     ├───┼───┼───┴───────────► #9 NKWindow
                     ├───┼───┴───────────────► #10 NKEvent
                     ├───┴───────────────────► #7 NKFont
                     └───────────────────────► #4 NKContainers

                ╔══════════════════════════════╗
                ║   #2 Applications/Sandbox    ║
                ║         (87470 Lines)        ║
                ╚══════════════════════════════╝
                     │   │   │
                     ├───┼───┴───────────────► #1 NKRenderer
                     ├───┴───────────────────► #8 NKRHI
                     └───────────────────────► #7 NKFont

                ╔══════════════════════════════╗
                ║   #3 Kernel/Runtime/NKMedia  ║
                ║         (68200 Lines)        ║
                ╚══════════════════════════════╝
                     │   │
                     ├───┴───────────────────► #7 NKFont
                     └───────────────────────► #4 NKContainers

              ╔═══════════════════════════════════╗
              ║ #4 Kernel/Foundation/NKContainers ║
              ║           (65601 Lines)           ║
              ╚═══════════════════════════════════╝
                     └───────────────────────► Aucune dépendence

                 ╔══════════════════════════════╗
                 ║     #5 Applications/NKCode   ║
                 ║         (59389 Lines)        ║
                 ╚══════════════════════════════╝
                     │   │   │   │   │
                     ├───┼───┼───┼───┴───────► #3 NKMedia
                     ├───┼───┼───┴───────────► #9 NKWindow
                     ├───┼───┼───────────────► #10 NKEvent
                     ├───┴───────────────────► #7 NKFont
                     └───────────────────────► #4 NKContainers

                 ╔══════════════════════════════╗
                 ║ #6 Applications/NK3DModeler  ║
                 ║         (56423 Lines)        ║
                 ╚══════════════════════════════╝
                     │   │   │   │   │   │   │
                     ├───┼───┼───┼───┼───┼───► #1 NKRenderer
                     ├───┼───┼───┼───┼───┴───► #3 NKMedia
                     ├───┼───┼───┼───┴───────► #8 NKRHI
                     ├───┼───┼───┴───────────► #9 NKWindow
                     ├───┼───┴───────────────► #10 NKEvent
                     ├───┴───────────────────► #7 NKFont
                     └───────────────────────► #4 NKContainers

                 ╔══════════════════════════════╗
                 ║   #7 Kernel/Runtime/NKFont   ║
                 ║         (50528 Lines)        ║
                 ╚══════════════════════════════╝
                     └───────────────────────► #4 NKContainers

                 ╔══════════════════════════════╗
                 ║    #8 Kernel/Runtime/NKRHI   ║
                 ║         (34851 Lines)        ║
                 ╚══════════════════════════════╝
                     │   │   │
                     ├───┼───┴───────────────► #9 NKWindow
                     ├───┴───────────────────► #10 NKEvent
                     └───────────────────────► #4 NKContainers

                 ╔══════════════════════════════╗
                 ║  #9 Kernel/Runtime/NKWindow  ║
                 ║         (30741 Lines)        ║
                 ╚══════════════════════════════╝
                     │   │
                     ├───┴───────────────────► #10 NKEvent
                     └───────────────────────► #4 NKContainers

                 ╔══════════════════════════════╗
                 ║  #10 Kernel/Runtime/NKEvent  ║
                 ║         (30509 Lines)        ║
                 ╚══════════════════════════════╝
                     └───────────────────────► #4 NKContainers
```