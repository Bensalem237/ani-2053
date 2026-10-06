#include "NKWindow/Core/NkWindow.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"
#include <NKWindow/NKMain.h>
#include "NKCanvas/Renderer/Shapes/NkRectangleShape.h"

int nkmain(const nkentseu::NkEntryState& state) {
    nkentseu::NkWindow window;
    nkentseu::NkWindowConfig cfg;
    cfg.title  = "Moving Square";
    cfg.width  = 1280;
    cfg.height = 600;
    if (!window.Create(cfg)) return -1;

    nkentseu::NkContextDesc desc;
    desc.api = nkentseu::NkGraphicsApi::NK_GFX_API_OPENGL;

    nkentseu::renderer::NkRenderWindow target(window, desc);
    if (!target.IsValid()) return -1;

    float x = 0.f, y = 640.f;
    float vitesse = 150.f;

    while(window.IsOpen()) {
        if (nkentseu::NkEvent *ev = nkentseu::NkEvents().PollEvent()) {

            if (ev->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }

            if (auto* press = ev->As<nkentseu::NkKeyPressEvent>()) {
                if (press->GetKey() == nkentseu::NkKey::NK_UP)     y -= vitesse;
                if (press->GetKey() == nkentseu::NkKey::NK_RIGHT)  x += vitesse;
                if (press->GetKey() == nkentseu::NkKey::NK_DOWN)   y += vitesse;
                if (press->GetKey() == nkentseu::NkKey::NK_LEFT)   x -= vitesse;

                if (x < 0.f)    x = 1230.f;
                if (x > 1280.f) x = 0.f;
                if (y < 0.f)    y = 550.f;
                if (y > 600.f)  y = 0.f;
            }
        }

        target.Clear(nkentseu::renderer::NkColor2D{ 60, 32, 45, 255 });
        nkentseu::renderer::NkRectangleShape rect({ 50.f, 50.f });
        rect.SetPosition({ x, y });
        rect.SetFillColor({ 255, 0, 0, 255 });
        target.Draw(rect);
        target.Display();
    }
    return 0;
}
