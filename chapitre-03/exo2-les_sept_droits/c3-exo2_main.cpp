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
    // Les sept droits
    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = false;
    cfg.modal = true;

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
        }
    }
    return 0;
}