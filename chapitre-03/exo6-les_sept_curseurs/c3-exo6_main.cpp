#include <NKWindow/NKWindow.h>
#include <NKWindow/NKMain.h>
#include <NKLogger/NkLog.h>
#include <NKEvent/NkWindowEvent.h>
#include <NKEvent/NkKeyboardEvent.h>
#include <NKEvent/NkMouseEvent.h>

NKENTSEU_DEFINE_APP_DATA(([]() {
    nkentseu::NkAppData d{};
    d.appName = "Window";
    d.appVersion = "1.0.0";
    return d;
})());

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1050;
    cfg.height = 600;

    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation de la fenetre echouee");
        return -1;
    }

    // Place le curseur au centre de la fenetre au lancement du programme
    window.SetMousePosition(cfg.width / 2, cfg.height / 2);
    logger.Info("[app] Curseur initializé au centre au démarrage");

    int lastZone = -1; // Pour suivre les déplacements de la souris

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }

            // Détecte les mouvements de la souris
            if (auto* MouseMoveEvent = event->As<nkentseu::NkMouseMoveEvent>()) {
                // Récupère la largeur actuelle de la zone client
                int currentWidth = window.GetSize().width;

                // Calcule la taille d'une zone (On divise la fenetre en 7 zones verticales de tailles égales)
                int zoneWidth = currentWidth / 7;
                if (zoneWidth <= 0) zoneWidth = 1;

                // Récupère la coordonée x de la souris
                int mouseX = MouseMoveEvent->GetX();

                // Détermine la zone actuelle dans laquelle la souris se trouve (0 à 6)
                int currentZone = mouseX / zoneWidth;

                // Sécurité pour les bordures droites
                if (currentZone < 0) currentZone = 0;
                if (currentZone > 6) currentZone = 6;

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
            }
        }
    }

    return 0;
}