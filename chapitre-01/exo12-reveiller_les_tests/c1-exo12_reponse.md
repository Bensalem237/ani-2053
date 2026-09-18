# Exercice 12

## 1. Ligne désactivant la compilation et l'exécution des tests

Dans le fichier Nkentseu.jenga, la désactivation des tests unitaires est gérée au niveau de la déclaration du workspace : 

```python
dutc(enable=True)
dute(enable=True)
```

## 2. Commande de lancement d'une suite de tests
J'ai forcé les tests via la commande : 

```bash
jenga test --force --project NKContainers_Tests
```
Résultat :
```bash
Running tests for NKContainers_Tests...
╔======================================================================╗
║                                                                      ║
║      ██╗   ██╗███╗   ██╗██╗████████╗███████╗███████╗████████╗        ║
║      ██║   ██║████╗  ██║██║╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝        ║
║      ██║   ██║██╔██╗ ██║██║   ██║   █████╗  ███████╗   ██║           ║
║      ██║   ██║██║╚██╗██║██║   ██║   ██╔══╝  ╚════██║   ██║           ║
║      ╚██████╔╝██║ ╚████║██║   ██║   ███████╗███████║   ██║           ║
║       ╚═════╝ ╚═╝  ╚═══╝╚═╝   ╚═╝   ╚══════╝╚══════╝   ╚═╝           ║
║                                                                      ║
║                C++ Unit Testing Framework v1.0.0                     ║
║              Fast, Reliable, and Developer-Friendly                  ║
║                                                                      ║
║  Number of tests: 37                                                 ║
║  Verbose mode: enabled                                               ║
║  Colors: enabled                                                     ║
║  Progress bar: disabled                                              ║
║                                                                      ║
║               Session started: 2026-09-18 21:44:11                   ║
║                                                                      ║
╚======================================================================╝

✓ NKContainersBTree_BulkInsertAndSearch         [OK]  5/5 assertions  (< 1ms)
  ✓ 5 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersBTree_InsertAndSearch             [OK]  5/5 assertions  (< 1ms)
  ✓ 5 assertion(s) réussie(s) (moy: < 1ms/assert)
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_map.cpp:97 [NKContainers Benchmark] NkMap vs std::map
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_map.cpp:98   NkMap     : 79809901.00 ns total
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_map.cpp:99   std::map  : 131320609.00 ns total
✓ NKContainersBenchmark_MapVsStdMap             [OK]  3/3 assertions  (211ms)
  ✓ 3 assertion(s) réussie(s) (moy: 70ms/assert)
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_priority_queue.cpp:85 [NKContainers Benchmark] NkPriorityQueue vs std::priority_queue
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_priority_queue.cpp:86   NkPriorityQueue      : 684728573.00 ns total
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_priority_queue.cpp:87   std::priority_queue  : 811613538.00 ns total
✓ NKContainersBenchmark_PriorityQueueVsStdPriorityQueue [OK]  3/3 assertions  (1.400000s)
  ✓ 3 assertion(s) réussie(s) (moy: 498ms/assert)
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_vector.cpp:91 [NKContainers Benchmark] NkVector vs std::vector
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_vector.cpp:92   NkVector   : 18878313.00 ns total
[INF] /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Kernel/Foundation/NKContainers/tests/test_vector.cpp:93   std::vector: 20910572.00 ns total
✓ NKContainersBenchmark_VectorVsStdVector       [OK]  3/3 assertions  (39ms)
  ✓ 3 assertion(s) réussie(s) (moy: 13ms/assert)
✓ NKContainersGraph_AllocatorInjection          [OK]  2/2 assertions  (< 1ms)
  ✓ 2 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersGraph_BfsAndDfsTraversalCoverReachableNodes [OK]  6/6 assertions  (< 1ms)
  ✓ 6 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersGraph_DirectedAndUndirectedEdges  [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersInitializerList_ManualConstruction [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersInitializerList_VectorConstructorFromInitializerList [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersIterator_AdvanceDistanceNextPrev  [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersIterator_ReverseIterator          [OK]  3/3 assertions  (< 1ms)
  ✓ 3 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersMap_BracketOperatorInsertDefault  [OK]  3/3 assertions  (< 1ms)
  ✓ 3 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersMap_InsertFindContainsAndOrder    [OK]  14/14 assertions  (< 1ms)
  ✓ 14 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersPair_ConstructionAndComparison    [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersPair_HelpersAndSwap               [OK]  6/6 assertions  (< 1ms)
  ✓ 6 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersPriorityQueue_AllocatorInjection  [OK]  2/2 assertions  (< 1ms)
  ✓ 2 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersPriorityQueue_PushPopAndTopOrder  [OK]  5/5 assertions  (< 1ms)
  ✓ 5 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersSpan_ConstructFromVector          [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersSpan_ViewsAndIndexing             [OK]  13/13 assertions  (< 1ms)
  ✓ 13 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersUnorderedHasher_CleChaineLongueHorsSSO [OK]  2/2 assertions  (< 1ms)
  ✓ 2 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersUnorderedHasher_CleChaineSeRetrouveApresEcriture [OK]  3/3 assertions  (< 1ms)
  ✓ 3 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersUnorderedHasher_ClesTrivialesInchangees [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersUnorderedHasher_EnsembleDeChaines [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersUnorderedHasher_PlusieursClesChaines [OK]  6/6 assertions  (< 1ms)
  ✓ 6 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersVector_InsertEraseAndResize       [OK]  8/8 assertions  (< 1ms)
  ✓ 8 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKContainersVector_PushBackAndAccess          [OK]  5/5 assertions  (< 1ms)
  ✓ 5 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_LaBrancheOuverteEstPrise        [OK]  2/2 assertions  (< 1ms)
  ✓ 2 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_LitterauxVisiblesSansQualification [OK]  3/3 assertions  (< 1ms)
  ✓ 3 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_MakePairForwarding              [OK]  3/3 assertions  (< 1ms)
  ✓ 3 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_PairMoveCtorEtAssign            [OK]  7/7 assertions  (< 1ms)
  ✓ 7 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_PoolConstructForwarding         [OK]  3/3 assertions  (< 1ms)
  ✓ 3 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_PriorityQueueMovePush           [OK]  2/2 assertions  (< 1ms)
  ✓ 2 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_QueueEtStackMovePushEmplace     [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_RingBufferMoveCtor              [OK]  2/2 assertions  (< 1ms)
  ✓ 2 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_TupleMoveCtor                   [OK]  3/3 assertions  (< 1ms)
  ✓ 3 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKCpp11Gardes_UnorderedSetMoveCtor            [OK]  2/2 assertions  (< 1ms)
  ✓ 2 assertion(s) réussie(s) (moy: < 1ms/assert)


┌────────────────────── RÉSULTATS DES TESTS ──────────────────────┐
│ SUCCÈS                                                          │
├─────────────────────────────────────────────────────────────────┤
│ Tests :      37 réussis, 37 au total                            │
│ Assertions : 160 réussies, 160 au total                         │
│ Taux succès : Tests: 100.0%, Assertions: 100.0%                 │
│ Temps total : 1.700000s (47ms/test)                             │
└─────────────────────────────────────────────────────────────────┘

✅ Tous les tests sont réussis !

All tests passed for NKContainers_Tests.
```

## 3. Bilan d'exécution
* Nombre de suites de tests existantes : **37**
* Nombre de suites exécutées : **37**
* Nombre de suites qui passent : **37**