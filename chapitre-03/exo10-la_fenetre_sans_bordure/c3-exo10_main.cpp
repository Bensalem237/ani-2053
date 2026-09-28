#include <NKWindow/NKWindow.h>
#include <NKWindow/NKMain.h>
#include <NKLogger/NkLog.h>
#include <NKEvent/NkWindowEvent.h>
#include <NKEvent/NkKeyboardEvent.h>
#include <NKWindow/Core/NkDialogs.h>

NKENTSEU_DEFINE_APP_DATA(([]() {
    nkentseu::NkAppData d{};
    d.appName = "Window";
    d.appVersion = "1.0.0";
    return d;
})());

// Structure pour définir la géométrie du bouton
struct customBtn {
    nkentseu::nk_int32 x, y, width, height;
    bool hovered(nkentseu::nk_int32 mx, nkentseu::nk_int32 my) const {
        return(mx >= x && mx <= x + width && my >= y && my <= y + height);
    }
};

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 300;
    cfg.height = 300;

    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation de la fenetre echouee");
        return -1;
    }

    // Retire la barre de titre et les marges de la fenetre
    window.SetDecorated(false);
    logger.Info("[TitleBar] Barre de titre retiree");

    // Dimensions de la barre de titre custom
    const nkentseu::nk_int32 titleBarH = 40;
    const nkentseu::nk_int32 buttonW = 45;
    const nkentseu::nk_int32 buttonH = 30;

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }

            if (auto* pressEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (pressEvent->GetKey() == nkentseu::NkKey::NK_ESCAPE) {
                    window.Close();
                }
            }

            // Récupère la taille de la fenetre à chaque itération
            nkentseu::math::NkVec2u winSize = window.GetSize();

            // Recalcule la position des trois boutons en haut à droite
            customBtn closeBtn {(static_cast<nkentseu::nk_int32>(winSize.x) - buttonW), 5, buttonW, buttonH};
            customBtn maxBtn   {(static_cast<nkentseu::nk_int32>(winSize.x) - (buttonW * 2 - 5)), 5, buttonW, buttonH};
            customBtn minBtn   {(static_cast<nkentseu::nk_int32>(winSize.x) - (buttonW * 3 - 10)), 5, buttonW, buttonH};

            // Intéractions avec la souris
            if (auto* clickEvent = event->As<nkentseu::NkMouseButtonPressEvent>()) {
                if (clickEvent->GetButton() == nkentseu::NkMouseButton::NK_MB_LEFT) {

                    // On récupère les coordonnées de la souris à l'instant du click
                    nkentseu::nk_int32 mx = clickEvent->GetX();
                    nkentseu::nk_int32 my = clickEvent->GetY();

                    // Bouton de fermeture
                    if (closeBtn.hovered(mx, my)) {
                        logger.Info("[TitleBar] Click : Fermeture de la fenetre.");
                        window.Close();
                    }

                    // Bouton Agrandir/Restaurer
                    else if (maxBtn.hovered(mx, my)) {
                        if (!window.IsMaximized()) {
                            logger.Info("[TitleBar] Click : Agrandissement de la fenetre.");
                            window.Maximize();
                        } else if (window.IsMaximized()) {
                            logger.Info("[TitleBar] Click : Restauration de la fenetre.");
                            window.Restore();
                        }
                    }

                    // Bouton Minimiser
                    else if (minBtn.hovered(mx, my)) {
                        logger.Info("[TitleBar] Click : Minimisation de la fenetre.");
                        window.Minimize();
                    }

                    // Déplacement de la fenêtre par la barre de titre
                    else if (my <= titleBarH) {
                        logger.Info("[TitleBar] Click : Déplacement de la fenetre.");
                        window.BeginDragMove();
                    }
                }
            }

            // Double-clic pour agrandir
            else if (auto* doubleClick = event->As<nkentseu::NkMouseDoubleClickEvent>()) {
                if (doubleClick->GetButton() == nkentseu::NkMouseButton::NK_MB_LEFT) {

                    // Recupère les coordonnées du double click
                    nkentseu::nk_int32 mouseY = doubleClick->GetY();

                    if (mouseY <= titleBarH) {
                        window.Maximize();
                        logger.Info("[TitleBar] Double click : Agrandissement de la fenetre.");
                    }
                }
            }
        }
    }

    return 0;
}