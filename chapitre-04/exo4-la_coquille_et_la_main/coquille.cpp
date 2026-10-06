#include <NKWindow/NKMain.h>
#include <NKCanvas/App/NkCanvasApp.h>

using namespace nkentseu;
using namespace renderer;

class Game : public NkCanvasApp {
    public :
        Game() {
            Config().title = "Moving Square";
            Config().width = 1280;
            Config().height = 600;
            Config().clearColor = NkColor2D(60, 32, 45, 255);
        }

        bool UpPressed;
        bool RightPressed;
        bool DownPressed;
        bool LeftPressed;

        bool OnEvent(const NkEvent &event) override {
            if (auto press = event.As<NkKeyPressEvent>()) {
                if (press->GetKey() == NkKey::NK_UP)     UpPressed    = true;
                if (press->GetKey() == NkKey::NK_RIGHT)  RightPressed = true;
                if (press->GetKey() == NkKey::NK_DOWN)   DownPressed  = true;
                if (press->GetKey() == NkKey::NK_LEFT)   LeftPressed  = true;
            }

            if (auto release = event.As<NkKeyReleaseEvent>()) {
                if (release->GetKey() == NkKey::NK_UP)     UpPressed    = false;
                if (release->GetKey() == NkKey::NK_RIGHT)  RightPressed = false;
                if (release->GetKey() == NkKey::NK_DOWN)   DownPressed  = false;
                if (release->GetKey() == NkKey::NK_LEFT)   LeftPressed  = false;
            }
            return false;
        }

        float x = 0.f, y = 640.f;
        float vitesse = 150.f;

        void OnUpdate(float32 dt) override {
            if (UpPressed)    y -= vitesse * dt;
            if (RightPressed) x += vitesse * dt;
            if (DownPressed)  y += vitesse * dt;
            if (LeftPressed)  x -= vitesse * dt;

            if (x < 0.f)    x = 1230.f;
            if (x > 1280.f) x = 0.f;
            if (y < 0.f)    y = 550.f;
            if (y > 600.f)  y = 0.f;
        }

        void OnRender(NkRenderWindow &target) override {
            NkRenderer2D &r = target.GetRenderer2D();
            r.DrawFilledRect({x, y, 50.f, 50.f}, NkColor2D::Red);
        }
};

int nkmain(const NkEntryState &state) {
    return NkCanvasApp::Run<Game>(state);
}