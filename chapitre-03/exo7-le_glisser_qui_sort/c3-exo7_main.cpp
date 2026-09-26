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

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }

            // Capture les mouvements de la souris quand on maintient le click gauche
            if (auto* MousePress = event->As<nkentseu::NkMouseButtonPressEvent>()) {
                if (MousePress->GetButton() == nkentseu::NkMouseButton::NK_MB_LEFT) {
                    window.CaptureMouse(true);
                    logger.Info("[app] Capture de la souris inititee");
                }
            }

            // Arrete la capture dès que le bouton gauche de la souris est relaché
            if (auto* MouseRelease = event->As<nkentseu::NkMouseButtonReleaseEvent>()) {
                if (MouseRelease->GetButton() == nkentseu::NkMouseButton::NK_MB_LEFT) {
                    window.CaptureMouse(false);
                    logger.Info("[app] Capture de la souris terminee");
                }
            }

            // Détecte les mouvements de la souris
            if (auto* MouseMoveEvent = event->As<nkentseu::NkMouseMoveEvent>()) {
                window.CaptureMouse(true);
                float mouseX = MouseMoveEvent->GetX();
                float mouseY = MouseMoveEvent->GetY();
                logger.Info("[app] souris deplacee : x={0}, y={1}", mouseX, mouseY);
            }
        }
    }

    return 0;
}