# Exercice 11
* J'ai supprimé un point virgule qui se trouvait à la fin de l'instruction se trouvant sur la ligne `136` du fichier `NkFunctions.cpp`.

* J'ai ensuite tapé la commande de construction pour NKMath, et voici la sortie du terminal que j'ai obtenu :
```baxh
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.6.3             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkCGXDetect.cpp
✓   [2/7] Compiled: NkArchDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkCPUFeatures.cpp
✓   [6/7] Compiled: NkEnv.cpp
✓   [7/7] Compiled: NkPlatformConfig.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKPlatform.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.25s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkAssert.cpp
✓   [2/5] Compiled: NkBits.cpp
✓   [3/5] Compiled: NkLimits.cpp
✓   [4/5] Compiled: NkTraits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCore.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.39s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkContainerAllocator.cpp
✓   [2/14] Compiled: NkFunction.cpp
✓   [3/14] Compiled: NkAllocator.cpp
✓   [4/14] Compiled: NkGlobalOperators.cpp
✓   [5/14] Compiled: NkFunctionSIMD.cpp
✓   [6/14] Compiled: NkGc.cpp
✓   [7/14] Compiled: NkHash.cpp
✓   [8/14] Compiled: NkMultiLevelAllocator.cpp
✓   [9/14] Compiled: NkMemory.cpp
✓   [10/14] Compiled: NkProfiler.cpp
✓   [11/14] Compiled: NkPoolAllocator.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkUtils.cpp
✓   [14/14] Compiled: NkTracker.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMemory.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.99s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkUnorderedMap.cpp
✓   [2/43] Compiled: NkTrie.cpp
✓   [3/43] Compiled: NkBinaryTree.cpp
✓   [4/43] Compiled: NkMap.cpp
✓   [5/43] Compiled: NkHashMap.cpp
✓   [6/43] Compiled: NkSet.cpp
✓   [7/43] Compiled: NkBTree.cpp
✓   [8/43] Compiled: NkPriorityQueue.cpp
✓   [9/43] Compiled: NkUnorderedSet.cpp
✓   [10/43] Compiled: NkPool.cpp
✓   [11/43] Compiled: NkArray.cpp
✓   [12/43] Compiled: NkRingBuffer.cpp
✓   [13/43] Compiled: NkBind.cpp
✓   [14/43] Compiled: NkFunction.cpp
✓   [15/43] Compiled: NkPair.cpp
✓   [16/43] Compiled: NkFunctional.cpp
✓   [17/43] Compiled: NkTuple.cpp
✓   [18/43] Compiled: NkInitializerList.cpp
✓   [19/43] Compiled: NkIterator.cpp
✓   [20/43] Compiled: NkContainers.cpp
✓   [21/43] Compiled: NkDeque.cpp
✓   [22/43] Compiled: NkDoubleList.cpp
✓   [23/43] Compiled: NkVector.cpp
✓   [24/43] Compiled: NkList.cpp
✓   [25/43] Compiled: NkGraph.cpp
✓   [26/43] Compiled: NkASCII.cpp
✓   [27/43] Compiled: NkQuadTree.cpp
✓   [28/43] Compiled: NkEncoding.cpp
✓   [29/43] Compiled: NkBase64.cpp
✓   [30/43] Compiled: NkUTF16.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkFormat.cpp
✓   [35/43] Compiled: NkString.cpp
✓   [36/43] Compiled: NkStringBuilder.cpp
✓   [37/43] Compiled: NkStringHash.cpp
✓   [38/43] Compiled: NkStringView.cpp
✓   [39/43] Compiled: NkOptional.cpp
✓   [40/43] Compiled: NkStringUtils.cpp
✓   [41/43] Compiled: NkVariant.cpp
✓   [42/43] Compiled: NkResult.cpp
✓   [43/43] Compiled: NkSpan.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKContainers.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.30s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkAngle.cpp
✓   [2/12] Compiled: NkEulerAngle.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                              Compilation Error: NkFunctions.cpp                              ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKMath/s ║
║ rc/NKMath/NkFunctions.cpp:136:19: error: expected ';' after return statement                 ║
║   136 |                         return round(x)                                              ║
║       |                                        ^                                             ║
║       |                                        ;                                             ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKMath/src/NKMath/NkFunctions.cpp
✓   [4/12] Compiled: NkColor.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkQuat.cpp
✓   [7/12] Compiled: NkRandom.cpp
✓   [8/12] Compiled: NkSIMD.cpp
✓   [9/12] Compiled: NkRange.cpp
✓   [10/12] Compiled: NkRectangle.cpp
✓   [11/12] Compiled: NkVec.cpp
✓   [12/12] Compiled: NkSegment.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 3.43s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/5
Failed:         1
Errors:         2
Time:           9.36s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKMath
```

* Nous pouvons observer que la construction a mis 9.36s avans de s'arreter

## Temps mis par la construction pour s'apreter
La construction s'est arrêtée au bout de 9.36 secondes au total (dont 3.43 secondes consacrées à la tentative de compilation de NKMath).

## Les projets construits malgré tout
4 projets sur 5 ont été entièrement compilés et archivés sous forme de bibliothèques statiques (.a) avant l'échec :  
* `NKPlatform` 
* `NKCore`
* `NKMemory`
* `NKContainers`

## Ce que l'erreur enseigne sur l'ordre de construction
* Jenga respecte rigoureusement l'ordre de dépendance du graphe. Il compile et génère d'abord les fichiers archives des prérequis (NKPlatform.a, NKCore.a, NKMemory.a, NKContainers.a) avant de lancer le moindre fichier source du projet dépendant (NKMath).

* L'échec de NKMath n'annule pas les compilations précédentes. Les archives des 4 dépendances restent valides dans Build/Lib/Debug-Linux/ et n'auront pas besoin d'être re-compilées lors du prochain essai. 

* Parallélisme et arrêt à l'édition de liens : Lorsque l'erreur survient sur NkFunctions.cpp, les autres tâches de compilation du même projet déjà lancées en parallèle (fichiers 4 à 12) continuent jusqu'à leur terme, mais l'étape finale d'édition de liens (linking) du projet NKMath est bloquée.

Le point-virgule a été réinséré à la ligne 136 de NkFunctions.cpp. Une nouvelle commande jenga build --project NKMath confirme que la compilation réussit désormais intégralement.