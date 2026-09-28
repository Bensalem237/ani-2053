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

int nkmain(const nkentseu::NkEntryState &state) {
    // Configure et ouvre les deux fenetres
    nkentseu::NkWindowConfig cfg1;
    cfg1.title = "Fenetre Principale (A)";
    cfg1.width = 400;
    cfg1.height = 300;
    nkentseu::NkWindow windowA(cfg1);
    if (!windowA.IsOpen()) {
        logger.Error("[Multi-Win] creation de la fenetre principale (A) echouee");
        return -1;
    }

    nkentseu::NkWindowConfig cfg2;
    cfg2.title = "Fenetre Secondaire (B)";
    cfg2.width = 400;
    cfg2.height = 300;
    nkentseu::NkWindow windowB(cfg2);
    if (!windowB.IsOpen()) {
        logger.Error("[Multi-Win] creation de la fenetre secondaire (B) echouee");
        return -1;
    }

    // Récupère et affiche les identifiants uniques au démarrage
    nkentseu::NkWindowId idA = windowA.GetId();
    nkentseu::NkWindowId idB = windowB.GetId();
    logger.Info("[Multi-Win] Fenetre A creee avec l'ID : {0}", idA);
    logger.Info("[Multi-Win] Fenetre B creee avec l'ID : {0}", idB);

    // Boucle principale : tourne tant qu'au moins une fenetre est ouverte
    while (windowA.IsOpen() || windowB.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;

        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {

            // Gestion de la fermeture indépendante des fenetres
            if (auto* closeEvent = event->As<nkentseu::NkWindowCloseEvent>()) {
                if (closeEvent->GetWindowId() == idA) {
                    logger.Info("[Multi-Win] Fermeture de la fenetre A.");
                    windowA.Close();
                } else if (closeEvent->GetWindowId() == idB) {
                    logger.Info("[Multi-Win] Fermeture de la fenetre B.");
                    windowB.Close();
                }
            }

            // Traitement et routage du clic de souris
            if (auto* clickEvent = event->As<nkentseu::NkMouseButtonPressEvent>()) {
                if (clickEvent->GetButton() == nkentseu::NkMouseButton::NK_MB_LEFT) {

                    // Récupération de l'ID de la fenetre qui a capturé le click
                    nkentseu::NkWindowId targetId = clickEvent->GetWindowId();

                    if (targetId == idA) {
                        logger.Info("[Clic] Reçu par la FENÊTRE A (ID: {0}) aux coordonnées locales ({1}, {2})", 
                                    targetId, clickEvent->GetX(), clickEvent->GetY());
                    } 
                    else if (targetId == idB) {
                        logger.Info("[Clic] Reçu par la FENÊTRE B (ID: {0}) aux coordonnées locales ({1}, {2})", 
                                    targetId, clickEvent->GetX(), clickEvent->GetY());
                    } 
                    else {
                        logger.Info("[Clic] Reçu par une fenêtre inconnue (ID: {0})", targetId);
                    }
                }
            }
        }
    }

    logger.Info("[Multi-Win] Toutes les fenetres sont fermees. Fin du programme.");
    return 0;
}