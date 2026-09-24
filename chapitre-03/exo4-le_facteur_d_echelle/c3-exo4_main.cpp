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

    nkentseu::NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] creation de la fenetre echouee");
        return -1;
    }

    // Taille initiale de la zone client
    auto windowSize = window.GetSize();
    logger.Info("[app] Taille initiale de la zone client: {0}x{1}", windowSize.width, windowSize.height);

    // Taille initiale de la fenetre
    auto displaySize = window.GetDisplaySize();
    logger.Info("[app] Taille initiale de la fenetre: {0}x{1}", displaySize.width, displaySize.height);

    // Facteur d'échelle
    auto dpiScale = window.GetDpiScale();
    logger.Info("[app] Facteur d'echelle DPI: {0}", dpiScale);

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
            if (event->Is<nkentseu::NkWindowResizeEvent>()) {
                auto windowSize = window.GetSize();

                int width = windowSize.width;
                int height = windowSize.height;

                logger.Info("[app] window resized: {0}x{1}", width, height);
            }
        }
    }
    return 0;
}