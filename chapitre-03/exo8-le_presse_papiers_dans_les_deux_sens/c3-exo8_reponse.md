# Exercice 8 : Le presse-papiers dans les deux sens

* En écrivant le programme, j'ai fait face à un problème : Mon programme n'arrivait pas à récupérer le texte ou les images du presse-papiers du système, ou à y injecter du texte ou des images.

* En ouvrant les fichiers source `Kernel/Runtime/NKWindow/src/NKWindow/Core/NkWindowClipboard.cpp` et `Nkentseu/Kernel/Runtime/NKWindow/src/NKWindow/Core/NkWindowClipboard.cpp`, j'ai vu qu'il a été spécifié dans ces fichiers qu'il n'y a aucune réelle implémentation du presse-papiers pour les systèmes Linux, et qu'on fait usage d'un pseudo presse-papiers interne au moteur.

```cpp
// =============================================================================
// NkWindowClipboard.cpp — Presse-papiers : FALLBACK multiplateforme.
//   Win32 fournit la vraie implementation OS (CF_UNICODETEXT) dans
//   Platform/Win32/NkWin32Window.cpp ; ce fichier (compile sur TOUTES les
//   plateformes via Core/**.cpp) fournit un presse-papiers INTERNE a
//   l'application pour les plateformes sans implementation OS dediee
//   (Linux/X11/Wayland, macOS, etc.) -> copier/coller intra-app fonctionne
//   partout. TODO : presse-papiers OS reel par plateforme (X11 CLIPBOARD,
//   NSPasteboard, wl_data_device...).
// =============================================================================
```

```cpp
// =============================================================================
// NkWindowClipboardImage.cpp — Presse-papiers IMAGE : FALLBACK multiplateforme.
//   Même philosophie que NkWindowClipboard.cpp (texte) : Win32 desktop fournit
//   la vraie implementation OS (CF_DIBV5/CF_DIB) dans
//   Platform/Win32/NkWin32Window.cpp ; ce fichier fournit un presse-papiers
//   IMAGE interne a l'application pour toutes les autres plateformes ->
//   copier/coller d'images intra-app fonctionne partout, sans exception de
//   link. TODO (ROADMAP « Fenetre discrete / presse-papiers ») : impl OS
//   reelles — X11 CLIPBOARD cible image/png (exige la boucle de selection),
//   NSPasteboard (NSPasteboardTypePNG/TIFF), wl_data_device.
//
//   Guard : on exclut UNIQUEMENT le desktop Win32 (meme expression que
//   NkWindowCursor.cpp) — UWP/Xbox recoivent donc ce fallback au lieu d'un
//   trou de link.
// =============================================================================
```

* Du coup, j'ai du initialiser le presse-papiers interne manuellement, plutot que de communiquer avec le presse-papiers du système.

## Procédure

1. J'ai créé deux fonctions, une pour le texte, qui lit le texte présent dans le presse-papiers texte interne du moteur, qui change toutes ses lettres minuscules en majuscules, et une pour les images, qui récupère l'image présente dans le presse-papiers image interne du moteur, inverse ses couleurs et la réinjecte.

```cpp
// Collecte le texte qui est dans le presse-papier, transforme tous ses caractères minuscules en majuscules et le réinjecte
void ProcessClipboardText(nkentseu::NkWindow& window) {
    nkentseu::NkString Texte = window.GetClipboardText();
    
    if (Texte.Empty()) {
        logger.Info("[Clipboard] Le presse-papiers ne contient pas de texte.");
        return;
    }

    logger.Info("[Clipboard] Texte lu avant transformation : {0}", Texte.CStr());

    nkentseu::NkString texteMaj = Texte.ToUpper();

    window.SetClipboardText(texteMaj);
    logger.Info("[Clipboard] Texte mis en majuscules avec succès : {0}", texteMaj.CStr());
}

// Récupère l'image présente dans le presse-papiers, inverse ses couleurs, et la réinjecte
void ProcessClipboardImage(nkentseu::NkWindow& window) {
    nkentseu::NkClipboardImage img;

    if (window.HasClipboardImage() && window.GetClipboardImage(img)) {
        logger.Info("[clipboard] Image du presse-papiers recuperee");

        uint8_t* pixels = img.pixels.Data();
        size_t pixelCount = img.height * img.width;

        for (size_t i = 0; i < pixelCount * 4; i += 4) {
            pixels[i]     = 255 - pixels[i];     // Inversion Rouje
            pixels[i + 1] = 255 - pixels[i + 1]; // Inversion Vert
            pixels[i + 2] = 255 - pixels[i + 2]; // Inversion Bleu
            pixels[i + 3] = pixels[i + 3];       // Alpha reste telquel
        }
    }

    window.SetClipboardImage(img);
    logger.Info("[clipboard] Couleurs de l'image inversees");
}
```

2. J'ai initialisé manuellement les presse-papiers internes du moteur.
    * Pour le texte, j'ai utilisé `window.SetClipboardText()`
    * Pour l'image, j'ai déssiné manuellement une image de 4x4 pixels qui contient juste du rouge

```cpp
// --- Initialization manuelle du presse-papiers interne ---

// Initialization du texte
window.SetClipboardText("Bonjour Nkentseu !");

// Initialisation de l'image
nkentseu::NkClipboardImage image;

image.width = 4;
image.height = 4;
image.pixels.Resize(image.width * image.height * 4); 

uint8_t* pix = image.pixels.Data();
size_t size = image.height * image.width * 4;

for (size_t i = 0; i < size; i += 4) {
    pix[i]     = 255; // R
    pix[i + 1] = 0;   // G
    pix[i + 2] = 0;   // B
    pix[i + 3] = 255; // A
}

if (image.IsValid()) {
    window.SetClipboardImage(image);
    logger.Info("[clipboard] Image initiale du presse-papiers definie");
} else {
    logger.Info("[clipboard] Echec d'initialisation du presse-papiers");
}
```

3. Dans la file d'évenements j'ai ajouté la lecture de deux racourcis pour les deux cas : `Ctrl+T` pour le texte, et `Ctrl+I` pour l'image.

```cpp
// Appelle la fonction ProcessClipboardText() quand on appuie Ctrl+T
if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
    if (keyEvent->GetKey() == nkentseu::NkKey::NK_T && keyEvent->HasCtrl()) {
        ProcessClipboardText(window);
    }
}

// Appelle la fonction ProcessClipboardImage() quand on appuie Ctrl+I
if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
    if (keyEvent->GetKey() == nkentseu::NkKey::NK_I && keyEvent->HasCtrl()) {
        ProcessClipboardImage(window);
    }
}
```

## Résultats

**Texte**
```
[2026-09-28 02:13:06.583] [INF] [default] [main.cpp:24 in ProcessClipboardText] -> [Clipboard] Texte lu avant transformation : Bonjour Nkentseu !
[2026-09-28 02:13:06.584] [INF] [default] [main.cpp:29 in ProcessClipboardText] -> [Clipboard] Texte mis en majuscules avec succes : BONJOUR NKENTSEU !
```

**Image**
```
[2026-09-28 02:28:53.775] [INF] [default] [main.cpp:90 in nkmain] -> [clipboard] Image initiale du presse-papiers definie
[2026-09-28 02:29:00.916] [INF] [default] [main.cpp:37 in ProcessClipboardImage] -> [clipboard] Image du presse-papiers recuperee
[2026-09-28 02:29:00.916] [INF] [default] [main.cpp:50 in ProcessClipboardImage] -> [clipboard] Couleurs de l'image inversees
```