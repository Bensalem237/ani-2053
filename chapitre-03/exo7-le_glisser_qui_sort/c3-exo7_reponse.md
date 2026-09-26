Exercice 7 : Le glisser qui sort

## Procédure

Pour intégrer la fonctionnalité de capture à mon code, j'ai ajouté dans la file des évènements deux contitions :

* Une qui initie la capture quand le bouton gauche de la souris est enfoncé.

```cpp
// Capture les mouvements de la souris quand on maintient le click gauche
if (auto* MousePress = event->As<nkentseu::NkMouseButtonPressEvent>()) {
    if (MousePress->GetButton() == nkentseu::NkMouseButton::NK_MB_LEFT) {
        window.CaptureMouse(true);
        logger.Info("[app] Capture de la souris inititee");
    }
}
```

* Et une qui arrete la capture de la souris dès que le bouton gauche de la souris est relaché

```cpp
// Arrete la capture dès que le bouton gauche de la souris est relaché
if (auto* MouseRelease = event->As<nkentseu::NkMouseButtonReleaseEvent>()) {
    if (MouseRelease->GetButton() == nkentseu::NkMouseButton::NK_MB_LEFT) {
        window.CaptureMouse(false);
        logger.Info("[app] Capture de la souris terminee");
    }
}
```

J'ai aussi ajouté une condition dans la file d'attente des évènements qui détecte les mouvements de la souris, récupère les coordonées de la souris à chaque fois qu'elle se déplace et les affiche dans la console.

```cpp
// Détecte les mouvements de la souris
if (auto* MouseMoveEvent = event->As<nkentseu::NkMouseMoveEvent>()) {
    window.CaptureMouse(true);
    float mouseX = MouseMoveEvent->GetX();
    float mouseY = MouseMoveEvent->GetY();
    logger.Info("[app] souris deplacee : x={0}, y={1}", mouseX, mouseY);
}
```

## Observations du point de vue d'un utilisateur

* Avant d'implémenter la capture de la souris, j'ai éffectué un click dans la fenetre, puis j'ai glissé la souris jusqu'à l'extérieur de la fenetre. La curseur sortait simplement de la fenetre, et l'on ne remarquait rien de spécial.

* Ensuite j'ai implémenté les étapes que j'ai éxpliqué dans la première partie pour la capture de la souris, puis j'ai refait le glisser. Là encore, on ne remarquait rien, etant donné qu'on était dans une fenetre noire, ne contenant rien a faire glisser.