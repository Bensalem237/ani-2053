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

// Variable pour stocker le code physique
nkentseu::NkScancode codePhysique;

// Fonction pour récupérer le codePhysique
nkentseu::NkScancode GetCodePhysique() {
    return codePhysique;
}

// Fonction pour modifier le code physique stocké
void SetCodePhysique(nkentseu::NkScancode &codePhysique, nkentseu::NkScancode newCode) {
    codePhysique = newCode;
}

int nkmain(const nkentseu::NkEntryState &state) {
    // Structure de configuration de la fenetre
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Test";
    cfg.width = 100;
    cfg.height = 75;

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

            // NkKeyPressEvent pour obtenir le code physique de la touche appuyée
            if (auto* keyPress = event->As<nkentseu::NkKeyPressEvent>()) {
                // Variable qui récupère le code
                nkentseu::NkScancode newCode = keyPress->GetScancode();
                // Modifie notre variable codePhysique
                SetCodePhysique(codePhysique, newCode);
            }

            if (auto* letterPress = event->As<nkentseu::NkTextInputEvent>()) {
                nkentseu::NkString Lettre = letterPress->GetUtf8();
                // Récupère le code physique
                nkentseu::NkScancode Code = GetCodePhysique();
                logger.Info("[app] Touche pressée. Lettre : {0} ; Code physique : {1}", Lettre, nkentseu::NkScancodeToString(Code));
            }
        }
    }

    return 0;
}
