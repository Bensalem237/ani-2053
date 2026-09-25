# Exercice 5 : Le titre qui informe

J'ai créé une fonction pour mettre à jour le titre de la fenetre

```cpp
// Met a jour le titre de la fenetre
void RafraishirTitre(nkentseu::NkWindow& window, const nkentseu::NkString& NomDocument, nkentseu::nk_bool estModifie, int width, int height) {
    // On construit le titre
    nkentseu::NkString nouvTitre = NomDocument;

    // Ajoute l'astérique si le fichier a été modifié
    if (estModifie) {
        nouvTitre += "*";
    }

    // Ajoute les dimensions de la fenetre
    nouvTitre += ("  ( " + std::to_string(width) + "x" + std::to_string(height) + " )").c_str();


    // Applique le nouveau titre
    window.SetTitle(nouvTitre);
}
```

Ensuite, j'ai initialisé les paramètres

```cpp
// --- Initialization ---

    // Nom par défaut du document
    nkentseu::NkString NomDoc = "sans_titre.txt";
    nkentseu::nk_bool estModifie = true; // On initialise avec 'vrai' pour pouvoir tester l'astérique

    int lastWidth = cfg.width;
    int lastHeight = cfg.height;
```

Avant d'entrer dans la boucle de jeu, j'appelle d'abord la fonction pour afficher le titre initial

```cpp
// Premier affichage du titre
    RafraishirTitre(window, NomDoc, estModifie, lastWidth, lastHeight);
```

Comme il a été demandé dans l'énoncé de mettre le titre á jour au bon moment, et non à chaque image, j'ai ajouté deux conditions dans la boucle de jeu :

* Une pour simuler l'enregistrement et faire disparaitre l'astérique quand on enfonce Ctrl+S

```cpp
// Simule une sauvegarde quand on enfonce Ctrl+S
if (keyEvent->GetKey() == nkentseu::NkKey::NK_S && keyEvent->HasCtrl()) {
    estModifie = false; // Simule l'enregistrement
    RafraishirTitre(window, NomDoc, estModifie, lastWidth, lastHeight);
    logger.Info("[app] fichier sauvegarde: {0}", NomDoc);
}
```

* Une pour modifier les dimensions affichées dans le titre chaque fois que la fenetre est redimensionnée

```cpp
// Modification du titre en cas de redimensionnement
if (event->Is<nkentseu::NkWindowResizeEvent>()) {
    auto windowSize = window.GetSize();

    int currentWidth = windowSize.width;
    int currentHeight = windowSize.height;

    if (lastWidth != currentWidth || lastHeight != currentHeight) {
        RafraishirTitre(window, NomDoc, estModifie, currentWidth, currentHeight);

        lastWidth = currentWidth;
        lastHeight = currentHeight;

        logger.Info("[app] window resized: {0}x{1}", currentWidth, currentHeight);
    }
}
```