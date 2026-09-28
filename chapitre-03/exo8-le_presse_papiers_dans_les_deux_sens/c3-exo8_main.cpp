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

// Collecte le texte qui est dans le presse-papier, transforme tous ses caractères minuscules en majuscules et le réinjecte
void ProcessClipboardText(nkentseu::NkWindow& window) {
    nkentseu::NkString Texte = window.GetClipboardText();
    
    if (Texte.Empty()) {
        logger.Info("[Clipboard] Le presse-papiers ne contient pas de texte.");
        return;
    }

    logger.Info("[Clipboard] Texte lu avant transformation : {0}", Texte.CStr());

    nkentseu::NkString texteMaj = Texte.ToUpper();

    window.SetClipboardText(texteMaj);
    logger.Info("[Clipboard] Texte mis en majuscules avec succès : {0}", texteMaj.CStr());
}

// Récupère l'image présente dans le presse-papiers, inverse ses couleurs, et la réinjecte
void ProcessClipboardImage(nkentseu::NkWindow& window) {
    nkentseu::NkClipboardImage img;

    if (window.HasClipboardImage() && window.GetClipboardImage(img)) {
        logger.Info("[clipboard] Image du presse-papiers recuperee");

        uint8_t* pixels = img.pixels.Data();
        size_t pixelCount = img.height * img.width;

        for (size_t i = 0; i < pixelCount * 4; i += 4) {
            pixels[i]     = 255 - pixels[i];     // Inversion Rouje
            pixels[i + 1] = 255 - pixels[i + 1]; // Inversion Vert
            pixels[i + 2] = 255 - pixels[i + 2]; // Inversion Bleu
            pixels[i + 3] = pixels[i + 3];       // Alpha reste telquel
        }
    }

    window.SetClipboardImage(img);
    logger.Info("[clipboard] Couleurs de l'image inversees");
}

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

    // --- Initialization manuelle du presse-papiers interne ---

    // Initialization du texte
    window.SetClipboardText("Bonjour Nkentseu !");
    
    // Initialisation de l'image
    nkentseu::NkClipboardImage image;

    image.width = 4;
    image.height = 4;
    image.pixels.Resize(image.width * image.height * 4); 

    uint8_t* pix = image.pixels.Data();
    size_t size = image.height * image.width * 4;

    for (size_t i = 0; i < size; i += 4) {
        pix[i]     = 255; // R
        pix[i + 1] = 0;   // G
        pix[i + 2] = 0;   // B
        pix[i + 3] = 255; // A
    }

    if (image.IsValid()) {
        window.SetClipboardImage(image);
        logger.Info("[clipboard] Image initiale du presse-papiers definie");
    } else {
        logger.Info("[clipboard] Echec d'initialisation du presse-papiers");
    }

    while (window.IsOpen()) {
        nkentseu::NkEvent* event = nullptr;
        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {
                window.Close();
            }
            
            // Appelle la fonction ProcessClipboardText() quand on appuie Ctrl+T
            if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_T && keyEvent->HasCtrl()) {
                    ProcessClipboardText(window);
                }
            }

            // Appelle la fonction ProcessClipboardImage() quand on appuie Ctrl+I
            if (auto* keyEvent = event->As<nkentseu::NkKeyPressEvent>()) {
                if (keyEvent->GetKey() == nkentseu::NkKey::NK_I && keyEvent->HasCtrl()) {
                    ProcessClipboardImage(window);
                }
            }
        }
    }

    return 0;
}
