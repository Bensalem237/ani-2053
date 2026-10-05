#include <NKWindow/NKMain.h>
#include <NKCanvas/App/NkCanvasApp.h>

using namespace nkentseu;
using namespace nkentseu::renderer;

class Fenetre : public NkCanvasApp {
    public :
        Fenetre() {
            Config().title = "Fenetre";
            Config().width = 1280;
            Config().height = 720;
            Config().clearColor = NkColor2D(18, 18, 24);
        }
};

int nkmain(const NkEntryState &state) {
    return NkCanvasApp::Run<Fenetre>(state);
}
