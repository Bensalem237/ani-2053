# Démonstration 1 : Le graphe au tableau

Date de présentation : Lundi, 21 Septembre 2026
Heure de début : 11:07

* J'ai commencé par créer un depot local vide dans lequel j'ai fait quelques commits, avec une second branche que j'ai fusionner ensuite pour qu'il y ait un point de divergence et de fusion dans le graphe.

* Ensuite j'ai fait une representation graphique de l'historique de commits dans lequel chaque commit représentait un point, et était lié à son parent par une ligne, le premier commit étant en haut et le dernier en bas.

```
*    (C1:main)
|
|
*    (C2:main)
|\
| \
|  * (C1:branche)
|  |
*  | (C3:main)
|  |
|  * (C2:branche)
|  |
| /
|/
*    (Cfinal)
```

* Ensuite, j'ai généré le graphe du projet grace à la commande `git log --graph --oneline`

```
*   commit f8b9ab2b6ee41d6dba50014936bf1ea0e2bcbd8d (HEAD -> main)
|\  Merge: 2f1b684 7318a65
| | Author: Ben-salem <emmanuel.eponse@facsciences-uy1.cm>
| | Date:   Mon Sep 21 11:26:49 2026 +0100
| | 
| |     Cfinal
| | 
| * commit 7318a652807a2ebf9011a5c0224e46a124f0f2c6 (branche)
| | Author: Ben-salem <emmanuel.eponse@facsciences-uy1.cm>
| | Date:   Mon Sep 21 11:22:47 2026 +0100
| | 
| |     C2:branche
| | 
| * commit 473c9fbb19d34976b21690b67ba7f435efc7333f
| | Author: Ben-salem <emmanuel.eponse@facsciences-uy1.cm>
| | Date:   Mon Sep 21 11:17:57 2026 +0100
| | 
| |     c1:branche
| | 
* | commit 2f1b6846d7a8f581d01d1058114f2567787f2853
|/  Author: Ben-salem <emmanuel.eponse@facsciences-uy1.cm>
|   Date:   Mon Sep 21 11:19:59 2026 +0100
|   
|       C3:main
| 
* commit 2c22619ad1ed548c4449ea7a26dd3a89548fdaba
| Author: Ben-salem <emmanuel.eponse@facsciences-uy1.cm>
| Date:   Mon Sep 21 11:16:06 2026 +0100
| 
|     C2:main
| 
* commit 23db2e917acb9323ea592c62c04b71c5e880d3ef
  Author: Ben-salem <emmanuel.eponse@facsciences-uy1.cm>
  Date:   Mon Sep 21 11:15:12 2026 +0100
  
      C1:main
```

## Correspondance entre les deux graphes

* Le commit au sommet de mon graphe (`C1:main`) correspond au commit tout en bas (`commit 23db2e917acb9323ea592c62c04b71c5e880d3ef`) dans le graphe déssiné par Git.

* La bifurcation de mon graphe au commit (`C2:main`) correspond au commit `commit 2c22619ad1ed548c4449ea7a26dd3a89548fdaba` du graphe de Git

* La fusion des deux branches dans mon graphe (`Cfinal`) correspond au dernier commit (`commit f8b9ab2b6ee41d6dba50014936bf1ea0e2bcbd8d (HEAD -> main)`) du graphe de Git.