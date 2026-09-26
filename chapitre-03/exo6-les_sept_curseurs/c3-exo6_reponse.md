# Exercice 6 : Les sept curseurs

1. **Le changement de curseur au survol de différentes zones de la fenetre:**

Afin d'implémenter le changement du curseur au survol des différentes zones, j'ai suivi les étapes suivantes :

* J'ai commencé par initializer une variable `lastZone` qui va permettre de suivre le changement de zone du curseur.

```cpp
int lastZone = -1;
```

* Ensuite, dans la file des évenements, j'ai ajouté une condition qui permet d'éffectuer des opérations quand on bouge la souris.

```cpp
if (auto* MouseMoveEvent = event->As<nkentseu::NkMouseMoveEvent>()) {}
```

* On commence par récupérer la largeur actuelle de la zone client et la diviser par 7.

```cpp
int currentWidth = window.GetSize().width;

int zoneWidth = currentWidth / 7;
```

* Ensuite, on récupère la coordonée x de la souris.

```cpp
int mouseX = MouseMoveEvent->GetX();
```

* Ensuite, on détermine la zone actuelle dans laquelle la souris se trouve.

```cpp
int currentZone = mouseX / zoneWidth;
```

* Ensuite, on assigne le curseur à déssiner en fonction de la zone dans laquelle la souris se trouve.

```cpp
// On change le curseur uniquement si on changé a de zone
if (currentZone != lastZone) {
    lastZone = currentZone;

    // Attribue le curseur en fonction de la zone actuelle
    switch (currentZone) {
    case 0: window.SetCursor(nkentseu::NkWindow::NkCursorType::Arrow); break;
    case 1: window.SetCursor(nkentseu::NkWindow::NkCursorType::Hand); break;
    case 2: window.SetCursor(nkentseu::NkWindow::NkCursorType::ResizeNESW); break;
    case 3: window.SetCursor(nkentseu::NkWindow::NkCursorType::ResizeNS); break;
    case 4: window.SetCursor(nkentseu::NkWindow::NkCursorType::ResizeNWSE); break;
    case 5: window.SetCursor(nkentseu::NkWindow::NkCursorType::ResizeWE); break;
    case 6: window.SetCursor(nkentseu::NkWindow::NkCursorType::TextInput); break;
    }
}
```

2. **Le positionnement du curseur au centre de la souris une fois, au démarrage :**

Pour cela, j'ai ajouté l'instruction suivante à mon code source avant la boucle de jeu.

```cpp
window.SetMousePosition(cfg.width / 2, cfg.height / 2);
```

3. **Ce qui se passe :**

J'ai ensuite compilé et lancé le programme. Après le lancement, j'ai remarqué que le curseur ne se téléportait pas au centre de la fenetre, et le curseur de la souris ne changeait pas en survolant toutes les zones de la fenetre.