# Démonstration 3 : La barre de titre à soi

## 1. Fonctionnalités Validées en Démonstration
L'application sans décoration native (`SetDecorated(false)`) a été présentée avec succès en classe, démontrant une réplication fonctionnelle des comportements standards :
* **Déplacement :** Prise en charge transparente par le gestionnaire de fenêtres de l'OS grâce au couplage de la zone réactive haute (Y <= 40px) avec l'appel de façade `window.BeginDragMove()`.
* **Gestion des états :** Routage univoque des clics de souris locaux vers les méthodes `Close()`, `Minimize()`, `Maximize()` et `Restore()` via des structures de collision géométriques recalculées dynamiquement.
* **Double-clic :** Interception de l'événement `NkMouseDoubleClickEvent` pour basculer de manière fluide entre l'état maximisé et l'état restauré.

## 2. Bilan de l'Abstraction : Ce qui a été perdu par rapport au système natif

1. **L'Ancrage Magnétique (Snapping) :** Disparition de la gestion automatique du placement des fenêtres (comme glisser sur un bord de l'écran pour diviser l'affichage en tuiles).
2. **Le Redimensionnement Périphérique :** Perte de la capacité pour l'utilisateur d'attraper les flancs ou les angles de la fenêtre pour ajuster sa taille, ce qui nécessite l'écriture d'un sous-système de détection complexe lié à `window.BeginResize()`.
3. **L'Accessibilité et la Cohérence Système :** Rupture des raccourcis clavier natifs de gestion de fenêtres, disparition du menu contextuel système (clic droit sur la barre) et abandon de l'uniformité visuelle liée aux thèmes graphiques globaux de la machine hôte.
