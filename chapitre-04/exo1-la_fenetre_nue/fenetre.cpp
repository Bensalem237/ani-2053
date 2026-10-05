#include <NKWindow/NKMain.h>
#include <NKCanvas/App/NkCanvasApp.h>

class Fenetre : public nkentseu::renderer::NkCanvasApp {
    public :
        Fenetre() {
            Config().title = "Fenetre";
            Config().width = 1280;
            Config().height = 720;
            Config().clearColor = nkentseu::renderer::NkColor2D(18, 18, 24);
        }
};

int nkmain(const nkentseu::NkEntryState &state) {
    return nkentseu::renderer::NkCanvasApp::Run<Fenetre>(state);
}