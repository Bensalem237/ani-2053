#include <NKWindow/NKWindow.h>
#include <NKWindow/NKMain.h>
#include <NKEvent/NkEvent.h>
#include <NKEvent/NkKeyboardEvent.h>

NKENTSEU_DEFINE_APP_DATA (([](){
    nkentseu::NkAppData d{};
    d.appName = "Test";
    d.appVersion = "1.0.0";
    return d;
})());

void fermeture(nkentseu::NkWindow &win) {
    logger.Info("[app] Fermeture de la fenetre.");
    win.Close();
}

int nkmain(const nkentseu::NkEntryState &state) {
    // Structure de configuration de la fenetre
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Test";
    cfg.width = 400;
    cfg.height = 300;

    // Déclare la fenetre
    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] Echec de creation de la fenetre");
        return -1;
    }

    while (window.IsOpen()) {

        if (nkentseu::NkEvent *event = nkentseu::NkEvents().PollEvent()) {

            // Bouton système et raccource Alt+F4
            if (auto* closeEvent = event->As<nkentseu::NkWindowCloseEvent>()) {
                fermeture(window);
            }

            // Touche pressée (ESCAPE)
            if (auto* keyPress = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyPress->GetKey() == nkentseu::NkKey::NK_ESCAPE) {
                    fermeture(window);
                }
            }
        }
    }

    return 0;
}
