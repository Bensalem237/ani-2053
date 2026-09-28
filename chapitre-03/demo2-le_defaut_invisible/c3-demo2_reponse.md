# Démonstration 2 : Le défaut invisible

### 1. Phénomène observé (Interface fausse)
Lorsqu'une taille de fenêtre est spécifiée de manière brute et statique à la création (`cfg.width = 300`), l'application demande des pixels physiques à l'OS. Sur une machine à forte densité, ces 300 pixels représentent une surface physique minuscule à l'écran, rendant l'interface graphique totalement inutilisable et les polices de caractères illisibles.

```cpp
// MAUVAISE PRATIQUE :
nkentseu::NkWindowConfig cfg;
cfg.title = "Window";
cfg.width = 300;
cfg.height = 300;

nkentseu::NkWindow window(cfg);
```

### 2. Mécanisme de correction
La correction consiste à découpler la taille logique (perçue par l'utilisateur) de la taille physique (envoyée à la carte graphique) en changeant l'ordre des opérations :
1. Instanciation de la fenêtre pour lier le contexte à l'écran courant.
2. Interrogation dynamique du multiplicateur système via `window.GetDpiScale()`.
3. Recalcul et application immédiate de la taille via `window.SetSize(Taille_Logique * DPI)`.

```cpp
#include <NKWindow/NKWindow.h>
#include <NKWindow/NKMain.h>
#include <NKLogger/NkLog.h>
#include <NKEvent/NkWindowEvent.h>

NKENTSEU_DEFINE_APP_DATA(([]() {
    nkentseu::NkAppData d{};
    d.appName = "Window";
    d.appVersion = "1.0.0";
    return d;
})());

int nkmain(const nkentseu::NkEntryState &state) {
    // 1. On configure une taille de base logique souhaitée
    const uint32_t baseWidth = 300;
    const uint32_t baseHeight = 300;

    nkentseu::NkWindowConfig cfg;
    cfg.title = "Fenetre Parfaitement Adaptee";
    cfg.width = baseWidth;
    cfg.height = baseHeight;

    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] Échec de la création");
        return -1;
    }

    // ── 2. LA CORRECTION CRUCIALE ──
    // On interroge le facteur d'échelle fourni par l'OS
    float32 dpiScale = window.GetDpiScale();
    logger.Info("[DPI Demo] Facteur d'échelle détecté : {0}", dpiScale);

    // On calcule la taille physique corrigée
    uint32_t correctedWidth = static_cast<uint32_t>(baseWidth * dpiScale);
    uint32_t correctedHeight = static_cast<uint32_t>(baseHeight * dpiScale);

    // On applique le redimensionnement dynamique après coup
    window.SetSize(correctedWidth, correctedHeight);
    logger.Info("[DPI Demo] Taille physique finale ajustée : {0}x{1}", correctedWidth, correctedHeight);

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }
        }
    }

    return 0;
}
```

Cette approche garantit que la fenêtre occupera exactement la même proportion visuelle à l'écran, peu importe la densité de pixels de la machine cible.
