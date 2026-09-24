# Exercice 2 : Les sept droits

Dans mon code source, j'ai désactivé chacun des sept droits à tour de role et j'ai noté le comportement de la fenetre.

## Redimensionnement

Après avoir affecté la valeur `false` au champ `cfg.resizable`;

```cpp
int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1000;
    cfg.height = 600;
    // Les sept droits
    cfg.resizable = false;
    cfg.movable = true;
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;
}
```
j'ai compilé et exécuté le programme. la fenetre s'est ouverte, mais il n'etait plus possible de redimensionner la fenetre. Quand je placais le curseur sur le bord de la fenetre, il restait sous forme de fleche, et aussi, le bouton du millieur pour agrandir et réduire n'etais plus là.

## Déplacement

Ensuite, j'ai remis le champ `cfg.resizable` à `vrai`, et j'ai affecté `false` à `cfg.movable`;
```cpp
int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1000;
    cfg.height = 600;
    // Les sept droits
    cfg.resizable = true;
    cfg.movable = false;
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;
}
```
puis j'ai compilé et executé. Quand la fenetre s'est ouvert, je n'ai observé aucun changement. j'arrivais toujours à déplacer la fenetre et faire toutes les manipulations de base.

## Fermeture par le bouton du système

Ensuite, j'ai réassigné la valeur `true` au champ `cfg.movable`, puis j'ai assigné la valeur `false` au champ `cfg.closable`;

```cpp
int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1000;
    cfg.height = 600;
    // Les sept droits
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = false;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;
}
```
Puis j'ai compilé et exécuté le programme. Là encore, je n'ai remarqué aucun changement dans le comportement de la fenetre. j'arrivais à la fermer normalement et a effectuer toutes les autres manipulations.

## Réduction

Ensuite, j'ai réassigné la valeur `true` au champ `cfg.movable`, puis j'ai assigné la valeur `false` au champ `cfg.minimizable`;

```cpp
int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1000;
    cfg.height = 600;
    // Les sept droits
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = true;
    cfg.minimizable = false;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;
}
```
Puis j'ai compilé et exécuté le programme. Là aussi, je n'ai remarqué aucun changement au niveau du comportement de la fenetre. J'arrivais toujours à minimiser la fenetre normalement.

## Agrandissement

Ensuite, j'ai réassigné la valeur `true` au champ `cfg.minimizable`, et j'ai assigné la valeur false au champ `cfg.maximizable`;

```cpp
int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1000;
    cfg.height = 600;
    // Les sept droits
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = false;
    cfg.canFullscreen = true;
    cfg.modal = true;
}
```
puis, j'ai compilé et exécuté le programme. Là encore, je n'ai remarqué aucun changement au niveau du comportement de la fenetre, elle s'agrandissait toujours normalement.

## Plein ecran

Pour pouvoir tester le mode plein écran, j'ai du ajouter une instruction dans la boucle principale du programme qui passe en mode plein ecran quand la touche `F11` est enfoncée :

```cpp
if (auto *keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
    if (keyEvent->GetKey() == nkentseu::NkKey::NK_F11) {
        window.SetFullscreen(true);
    }
}
```

Ensuite, j'ai réassigné la valeur `true` au champ `cfg.maximizable` et j'ai assigné la valeur `false` au champ `cfg.canFullscreen`;

```cpp
int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1000;
    cfg.height = 600;
    // Les sept droits
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = false;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = false;
    cfg.modal = true;
}
```
puis, j'ai compilé et exécuté le programme. Malgré le fait que le champ `cfg.canFullscreen` avait pour valeur `false`, la fenetre passait quand meme en mode plein écran quand j'enfoncais la touche `F11`.

## Blocage des autres fenetres

La modification du champ `cfg.modal` non plus n'avait aucun effet sur la fenetre.