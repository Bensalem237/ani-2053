# Demo 2

## Le tableau des temps
| Construction complète à froid | Construction complète à chaud | Construction d'un seul module | Construction après modification d'un seul fichier source | Construction après modification d'un seul en-tete |
| :--- | :--- | :--- | :--- | :--- |
| 66m37.0s | 2m9.5s | 4m14.1s | 2m26.8s | 3m18.4s |

## Construction après la modification d'un seul fichier : Observations et Explication

À partir des résultats, nous observons que la construction prend plus de temps quand on modifie un seul fichier en-tete (3m18.4s) que quand on modifie un seul fichier source (2m26.8s) ceci est du au fait que quand on modifie un seul fichier source, seul ce fichier est recompilé durant la deuxième construction pourtant quand on modifie un fichier en-tete, tous les fichiers sources qui l'incluent sont recompilés durant la deuxième construction.