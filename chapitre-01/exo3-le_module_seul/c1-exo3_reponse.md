# Exercice 3
J'ai construit le projet NKMath seul avec la commande :

```bash
jenga build --project NKMath
```
Et voici les éléments demandés dans l'exercice :

## L'ordre de construction (Build Order)
Voici l'ordre de construction que j'ai relevé dans le terminal après la construction :

```bash
Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)
```
A partir de là, nous avons les informations necessaires pour dessiner le graphe de dépendances que voici

## Graphe de dépendances

```bash
                                 ┌──────────────────┐
                                 │      NKMath      │
                                 └────────┬─────────┘
                                          │
       ┌──────────────────────────────────┴──────────────────┬──────────────────┐
       ▼                          │                          │                  │
┌──────────────┐                  │                          │                  │
│ NKContainers │                  │                          │                  │
└──────┬───────┘                  │                          │                  │
       ├──────────────────────────┤                          │                  │
       │                          ▼                          │                  │
       │                   ┌────────────┐                    │                  │
       │                   │  NKMemory  │                    │                  │
       │                   └──────┬─────┘                    │                  │
       └──────────────────────────┼──────────────────────────┤                  │
                                  │                          ▼                  │
                                  │                    ┌───────────┐            │
                                  │                    │  NKCore   │            │
                                  │                    └─────┬─────┘            │
                                  ├──────────────────────────┘                  │
                                  │                                             │
                                  │                                             │
                                  ├─────────────────────────────────────────────┘
                                  ▼ 
                            ┌────────────┐
                            │ NKPlatform │
                            └────────────┘
```