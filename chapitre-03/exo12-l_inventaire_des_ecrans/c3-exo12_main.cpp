#include <NKWindow/NKWindow.h>
#include <NKWindow/NKMain.h>
#include <NKLogger/NkLog.h>
#include <NKEvent/NkWindowEvent.h>
#include <NKEvent/NkKeyboardEvent.h>

NKENTSEU_DEFINE_APP_DATA(([]() {
    nkentseu::NkAppData d{};
    d.appName = "Window";
    d.appVersion = "1.0.0";
    return d;
})());

// Affiche la liste des écrans, leurs caractéristiques, et repère celle qui héberge la fenetre
void DisplayMonitorsInfo(const nkentseu::NkWindow &window) {
    logger.Info("--- ÉTAT DES ÉCRANS CONNECTÉS ---");

    // Récupère l'écran qui contient actuellement la fenetre
    nkentseu::NkDisplayInfo currentScreen = window.GetCurrentMonitor();

    // Énumère tous les moniteurs connectés au système
    nkentseu::NkVector<nkentseu::NkDisplayInfo> monitors = window.EnumerateMonitors();
    for (nkentseu::usize i = 0; i < monitors.Size(); ++i) {
        const nkentseu::NkDisplayInfo &monitor = monitors[i];
        bool holdsWindow = (monitor.index == currentScreen.index);
        logger.Info("Ecran[{0}] : Position({1}, {2}) | Taille({3}, {4}) | Principal: {5} | Fenetre presente: {6}",
            i,
            monitor.posX, monitor.posY,
            monitor.width, monitor.height,
            monitor.isPrimary ? "OUI" : "NON",
            holdsWindow ? "OUI" : "NON"
        );

        // 3. Affichage du facteur d'échelle DPI actuel de la fenêtre
        logger.Info("Facteur d'échelle (DPI) actuel de la fenêtre : {0}", window.GetDpiScale());
        logger.Info("---------------------------------");
    }
}

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

    logger.Info("[Multi-Screen] Application lancee. Appuyez sur [  ESPACE  ] pour afficher l'état des écrans connectés.");

    // Affichage initial au démarrage
    DisplayMonitorsInfo(window);

    // Mémorise l'ID de l'écran précédent afin de détecter un changement de moniteur
    auto lastMonitorId = window.GetCurrentMonitor().index;

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }
        
            // Déclanche l'affichage manuelle via la touche Espace
            if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_SPACE) {
                    DisplayMonitorsInfo(window);
                }
            }

            // Interroge l'écran actuel à chaque frame
            auto currentMonitorId = window.GetCurrentMonitor().index;

            if (currentMonitorId != lastMonitorId) {
                logger.Info("[Multi-Screen] La fenêtre a changé d'écran.");
                DisplayMonitorsInfo(window);
                lastMonitorId = currentMonitorId;
            }
        }
    }

    return 0;
}