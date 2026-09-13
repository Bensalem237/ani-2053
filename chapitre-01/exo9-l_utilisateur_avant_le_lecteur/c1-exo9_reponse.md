# Exercice 9

**Date d'expérimentation :** 13 septembre 2026
**Durée du test :** 10 minutes (Exécutable : `NkRef`)

---

## 1. Fonctionnalités observées

* **Ouverture d'une fenetre graphique :**
    * Affiche une interface utilisateur interactive gérée par le moteur.

* **Manipulation d'images :**
    * Permet d'importe et d'afficher une image sur la zone de travail en la faisant glisser depuis l'explorateur de fichiers.
    * On peut aussi redimensionner l'image par les coins et effectuer une rotation manuelle de l'image via la poignée circulaire supérieure.
    * On a aussi un effet miroir horizontal (`X`) et vertical (`Y`) et la possibilité de régler l'opacité de l'image via un slider.
    * On a aussi une gestion de la pile d'affichage (`Page Up` / `Page Down`) et `copier/coller` d'images (`Ctrl+C` / `Ctrl+V`).

* **Déplacement / Navigation :**
    * Permet de déplacer la grille de référence ou de faire du panoramique dans la fenetre, ou de zoomer dessus avec la molette.
    * La grille de repérage est aussi activable/désactivable avec la touche `G`.

* **Outil Crayon & Annotation :**
    * Le système possède également un mode crayon activable/désactivable (`D`) permettant de dessiner directement sur la planche.
    * On a également une palette de 7 couleurs prédéfinies (Orange, Pétrole, Rouge, Vert, Bleu, Blanc, Noir) et réglage de l'épaisseur du trait.
    * On peut également annuler le dernier trait ou effacer tous les traits.

* **Interface & Fenetre :**
    * On a un panneau latéral "Propriétés" rétractable.
    * Des options de fenetre : mode "Toujours devant" (`T`), ajustement de l'opacité globale de la fenetre et mode "Glisser le fond = fenetre"
    * On a également un Thème sombre/clair configurable.
    * Menu contextuel complet (Gestion de projet : `Ctrl+O`, `Ctrl+S`, `Ctrl+K`, fonction `Pack` avec `Ctrl+P`).
    * Une option `Recents` dans le menu contextuel permettant de voir les derniers projets qu'on a manipulés.

---

## 2. Améliorations & ergonomie désirée

* **Raccourcis clavier :** Ajouter des raccourcis usuels (`Ctrl+Z` pour annuler, `Suppr` pour retirer une image, `R` pour réinitialiser la vue).
* **Gomme et édition vectorielle des traits :** Il est impossible d'effacer une zone précise du dessin à l'aide d'une gomme ; on ne peut qu'annuler le dernier trait ou tout supprimer.
* **Sélecteur de couleurs libre (Color Picker) :** La palette est limitée à 7 couleurs. On devrait avoir un sélecteur de couleur libre ayant toutes les couleurs possibles, ou la possibilité de saisir le code couleur HEX, HSV ou RGB.
* **Import/Export limité :** On a la possibilité d'exporter le rendu final sur la planche, mais il n'y a pas vraiment de format qui marche, `.nkref` ne fonctionne pas, meme le format `PNG` ne marche pas. aussi, il n'y a pas la possibilité d'importer un autre projet externe, bien qu'il y ait une option `Recents` dans le menu contextuel. Quand on essaye d'ouvrir un fichier récent, une erreur s'affiche sur la barre de titre disant **"format illisible(format?)"** meme pour l'extension `.nkref`.
* **Ajustement automatique du tiroir de propriétés :** Le panneau lateral superpose et masque partiellement la grille de travail à droite quand il est ouvert.
