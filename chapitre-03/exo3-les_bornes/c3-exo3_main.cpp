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

int nkmain(const nkentseu::NkEntryState &state) {
    nkentseu::NkWindowConfig cfg;
    cfg.title = "Window";
    cfg.width = 1000;
    cfg.height = 600;
    // Limite la taille minimale de la fenetre à 400 x 300
    cfg.minWidth = 400;
    cfg.minHeight = 300;

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
            if (auto *keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_F11) {
                    window.SetFullscreen(true);
                }
            }
            // Récupère, stocke et affiche les dimensions de la fenetre chaque fois qu'elle est redimensionnée
            if (event->Is<nkentseu::NkWindowResizeEvent>()) {
                auto windowSize = window.GetSize();

                int width = windowSize.width;
                int height = windowSize.height;

                logger.Info("[app] window resized: {0}x{1}", width, height);
            }
        }

        auto windowSize = window.GetSize();

        int width = windowSize.width;
        int height = windowSize.height;
    }
    return 0;
}