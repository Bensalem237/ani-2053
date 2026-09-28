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
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 300;
    cfg.height = 300;

    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation de la fenetre echouee");
        return -1;
    }

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }
            
            // Ouvre le dialogue d'ouverture de fichier quand on enfonce F1
            if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_F1) {
                    logger.Info("[Dialog] Tentative d'ouverture de fichier.");
                    nkentseu::NkDialogResult r1 = nkentseu::NkDialogs::OpenFileDialog("*.docx;*.txt;*.pdf", "Ouvrir un document");

                    // Gestion de l'annulation
                    if (!r1.confirmed) {
                        logger.Info("[Dialog] Ouverture de fichier annulee.");
                    } else logger.Info("[Dialog] Fichier ouvert avec succes : {0}", r1.path.CStr());
                }
            }

            // Ouvre le dialogue d'enregistrement d'un fichier quand on enfonce F2
            if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_F2) {
                    logger.Info("[Dialog] Tentative d'ouverture d'un fichier.");
                    nkentseu::NkDialogResult r2 = nkentseu::NkDialogs::SaveFileDialog(".cpp", "Enregistrer le fichier");

                    // Gestion de l'annulation
                    if (!r2.confirmed) {
                        logger.Info("[Dialog] Sauvegarde de fichier annulee.");
                    } else logger.Info("[Dialog] Fichier sauvegardé avec succès : {0}", r2.path.CStr());
                }
            }

            // Ouvre le dialogue d'ouverture d'un dossier quand on enfonce F3
            if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_F3) {
                    logger.Info("[Dialog] Tentative d'ouverture d'un dossier.");
                    nkentseu::NkDialogResult r3 = nkentseu::NkDialogs::OpenFolderDialog("Ouvrir un dossier");

                    // Gestion de l'annulation
                    if (!r3.confirmed) {
                        logger.Info("[Dialog] Ouverture de dossier annulee.");
                    } else logger.Info("[Dialog] Dossier sélectionné avec succès : {0}", r3.path.CStr());
                }
            }

            // Affiche le message quand on enfonce F4
            if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_F4) {
                    logger.Info("[Dialog] Tentative d'affichage du message.");
                    nkentseu::NkDialogs::OpenMessageBox("Hello World!", "Salutation");
                    logger.Info("[Dialog] Message affiché avec succès.");
                }
            }
        }
    }

    return 0;
}