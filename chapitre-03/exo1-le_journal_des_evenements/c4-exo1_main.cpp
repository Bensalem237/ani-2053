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

int nkmain(const nkentseu::NkEntryState &state) {
    // Structure de configuration de la fenetre
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Test";
    cfg.width = 800;
    cfg.height = 600;

    // Déclare la fenetre
    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] Echec de creation de la fenetre");
        return -1;
    }

    while (window.IsOpen()) {

        if (nkentseu::NkEvent *event = nkentseu::NkEvents().PollEvent()) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                logger.Info("[app] Fermeture de la fenetre");
                window.Close();
            }

            if (auto* keyPress = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyPress->GetKey() == nkentseu::NkKey::NK_ESCAPE) {
                    logger.Error("[app] Fermeture de la fenetre");
                    window.Close();
                }
            }

            // Déplacement de la souris
            if (auto* mouseMove = event->As<nkentseu::NkMouseMoveEvent>()) {
                logger.Info("[app] Souris déplacée : Famille({0}), Type({1})", nkentseu::NkEventCategory::ToString(mouseMove->GetCategory()), nkentseu::NkEventType::ToString(mouseMove->GetType()));
            }

            // Pression du clavier
            if (auto* keyPress = event->As<nkentseu::NkKeyPressEvent>()) {
                logger.Info("[app] Touche du clavier pressée : Famille({0}), Type({1})", nkentseu::NkEventCategory::ToString(keyPress->GetCategory()), nkentseu::NkEventType::ToString(keyPress->GetType()));
            }

            // Redimenssionement de la fenetre
            if (auto* rz = event->As<nkentseu::NkWindowResizeEvent>()) {
                logger.Info("[app] Fenetre redimensionnée : Famille({0}), Type({1})", nkentseu::NkEventCategory::ToString(rz->GetCategory()), nkentseu::NkEventType::ToString(rz->GetType()));
            }

            // Dépot d'un fichier
            if (auto* drop = event->As<nkentseu::NkDropFileEvent>()) {
                logger.Info("[app] Fichier déposé dans la zone client : Famille({0}), Type({1})", nkentseu::NkEventCategory::ToString(drop->GetCategory()), nkentseu::NkEventType::ToString(drop->GetType()));
            }
        }
    }

    return 0;
}
