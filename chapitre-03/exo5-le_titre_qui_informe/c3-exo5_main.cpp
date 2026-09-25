#include <NKWindow/NKWindow.h>
#include <NKWindow/NKMain.h>
#include <NKLogger/NkLog.h>
#include <NKTime/NkTime.h>
#include <NKTime/NkChrono.h>

#include <NKEvent/NkWindowEvent.h>
#include <NKEvent/NkKeyboardEvent.h>

NKENTSEU_DEFINE_APP_DATA(([]() {
    nkentseu::NkAppData d{};
    d.appName = "Window";
    d.appVersion = "1.0.0";
    return d;
})());

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

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1000;
    cfg.height = 600;
    cfg.minWidth = 400;
    cfg.minHeight = 300;

    // --- Initialization ---

    // Nom par défaut du document
    nkentseu::NkString NomDoc = "sans_titre.txt";
    nkentseu::nk_bool estModifie = true; // On initialise avec 'vrai' pour pouvoir tester l'astérique

    int lastWidth = cfg.width;
    int lastHeight = cfg.height;

    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation de la fenetre echouee");
        return -1;
    }

    // Premier affichage du titre
    RafraishirTitre(window, NomDoc, estModifie, lastWidth, lastHeight);

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }

            if (auto *keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                // Mode Plein Ecran quand on enfonce F11
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_F11) {
                    window.SetFullscreen(true);
                }
                
                // Simule une sauvegarde quand on enfonce Ctrl+S
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_S && keyEvent->HasCtrl()) {
                    estModifie = false; // Simule l'enregistrement
                    RafraishirTitre(window, NomDoc, estModifie, lastWidth, lastHeight);
                    logger.Info("[app] fichier sauvegarde: {0}", NomDoc);
                }
            }

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
        }
    }

    return 0;
}