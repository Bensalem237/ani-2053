# Demo 1

Dans cette demo, je vais vous présenter le fichier de projet `NK3DModeler.jenga` bloc par bloc. NK3DModeler est un système de modelisation 3D, et nous allons parcourir son fichier .jenga.

## Appercu du fichier
```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""NK3DModeler — application de modelisation 3D.

SQUELETTE : la coquille de fenetre et la disposition de l'ecran A (maquette
Banani validee) — bandes, colonnes, panneaux aux bonnes places, alimentes par
NkTheme et NkShortcutTable. Le contenu reel (vue 3D, pile de modificateurs,
navigateur de projet) vient ensuite, panneau par panneau.

Calque sur NKCode.jenga, MOINS ce dont un modeleur n'a pas besoin : ni Python
embarque (NKCode integre jenga in-process), ni NKAudio/NKMedia. En revanche il
LIE NKRenderer, que NKCode n'utilise pas : c'est la que vivent NkEditMesh, les
modificateurs, la decimation QEM et la retopologie.
"""

from Jenga import *
from jengaconfig import *
import os


with project("NK3DModeler"):
    windowedapp()
    language("C++")
    cppdialect("C++17")
    location(".")

    files(["src/**.cpp"])

    # NKMedia ajoute pour l'ENREGISTREMENT VIDEO de la sortie (NkVideoWriter,
    # NkImageSequenceWriter) : filmer la session de modelisation et les
    # tutoriels. Le commentaire d'en-tete disait le modeleur sans NKMedia --
    # c'etait vrai tant qu'il ne produisait que des images fixes.
    nkentseudependson(
        ["NKEditorKit", "NKRenderer", "NKRHI", "NKSL", "NKCanvas", "NKGui",
         "NKMedia",
         "NKWindow", "NKEvent", "NKGlad", "NKFont", "NKImage", "NKFileSystem",
         "NKSerialization", "NKReflection", "NKThreading", "NKLogger", "NKMath",
         "NKTime", "NKStream", "NKContainers", "NKMemory", "NKCore", "NKPlatform",
         "NKGLSlang", "NKSPIRVCross"],
        extra_includes=["src", "src/NK3DModeler", "%{wks.location}/Integrations",
                        "%{NKGlad.location}/include",
                        "%{wks.location}/Kernel/Runtime/NKGraph/src"]
                       + ([VULKAN_INCLUDE] if VULKAN_INCLUDE else []),
        extra_defines=[f"NKENTSEU_ENABLE_VULKAN_BACKEND={1 if WANT_VULKAN else 0}"],
    )

    # Backend UI NKGui -> NKRHI. La vue 3D impose la regle « une fenetre = une
    # pile » : NKRenderer vit sur NKRHI, donc l'interface doit y vivre aussi. On
    # quitte NKCanvas pour NkEditorRHIRenderer, qui presente exactement la meme
    # interface NkIEditorRenderer -- et qui, lui, expose son device.
  
    dependson(["NKGuiIntegration"])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

    apppublisher("Rihen Universe")
    appversion("0.1.0")
    licensefile("../../LICENSE")

    # ===== Windows ============================================================
    with filter("system:Windows && !options:windows-runtime=uwp"):
        windowedapp()
        usetoolchain(TC_WINDOWS)
        defines(["WIN32_LEAN_AND_MEAN", "_UNICODE", "UNICODE"])
        if VULKAN_LIB:
            libdirs([VULKAN_LIB])
        _WIN_LINKS = [
            "user32", "gdi32", "opengl32", "dwmapi", "shell32", "comdlg32",
            "uuid", "ole32", "dinput8", "dxguid",
            "d3d11", "d3d12", "dxgi", "d3dcompiler",
            "winmm",
        ]
        if WANT_VULKAN:
            _WIN_LINKS.append("vulkan-1")
        links(_WIN_LINKS)

    # ===== Linux ==============================================================
    with filter("system:Linux"):
        windowedapp()
        usetoolchain("clang-native")
        defines(["NKENTSEU_FORCE_WINDOWING_XLIB_ONLY"])
        links(["pthread", "X11", "Xext", "GL", "m"])

    # ===== macOS ==============================================================
    with filter("system:macOS"):
        windowedapp()
        usetoolchain("clang-native")
        frameworks(["Cocoa", "QuartzCore", "OpenGL", "Foundation"])
```

## Présentation de chaque élement de ce programme
* **premier block**
```python
#!/usr/bin/env python3
#-*- coding utf-8 -*-
```

ce block contient deux instructions. La première, `#!/usr/bin/env python3` permet de spécifier au système d'expoitation d'utiliser python3 qui se trouve dans la variable d'environnement `PATH`. La deuxième, `#-*- coding utf-8 -*-` permet tout simplement de spécifier l'encodage des caractères que le système va utiliser pour ce projet.

* **deuxième block est**
```python
from Jenga import *
from jengaconfig import *
import os
```

`from Jenga import *` permet d'importer les fonctions, classes et constantes de jenga directement dans l'espace de noms courant. Cela permet d'utiliser des fonctions comme `workspace(), include(), targetoses()` sans devoir les préfixer par jenga.
`jengaconfig import *` permet d'importer les fonctions et variables de configuration dont le système a besoin.
`import os` importe le module standard permettant d'interagir avec le système.

* **troisième block**
```python
with project("NK3DModeler"):
    windowedapp()
    language("C++")
    cppdialect("C++17")
    location(".")

    files(["src/**.cpp"])
```

`with project("NK3DModeler) :` permet de déclarer le projet NK3DModeler
`windowedapp()` permet de specifier que le resultat de la compilation est un programme sous forme de fenetre graphique, sans l'apparition de console, à l'inverse de ConsoleApp
`language(C++)` permet de spécifier le langage de programmation utilisé afin de sélectionner le workspqce adeuat.jenga
`cppdialect(C++17)` permet de specifier la version de C++ utilisée.
`location9\(.)` permet de specifier la racine du projet l`a oú tous les fichiers intermédiares dont crees
`files(["src/**.cpp])` demande au compilateur de parcourir le dossier src et de récupérer tous les fichiers .cpp dans src et dans tous ses sous-dossiers.

* **Quatrième bloc**
```python
nkentseudependson(
        ["NKEditorKit", "NKRenderer", "NKRHI", "NKSL", "NKCanvas", "NKGui",
         "NKMedia",
         "NKWindow", "NKEvent", "NKGlad", "NKFont", "NKImage", "NKFileSystem",
         "NKSerialization", "NKReflection", "NKThreading", "NKLogger", "NKMath",
         "NKTime", "NKStream", "NKContainers", "NKMemory", "NKCore", "NKPlatform",
         "NKGLSlang", "NKSPIRVCross"],
        extra_includes=["src", "src/NK3DModeler", "%{wks.location}/Integrations",
                        "%{NKGlad.location}/include",
                        "%{wks.location}/Kernel/Runtime/NKGraph/src"]
                       + ([VULKAN_INCLUDE] if VULKAN_INCLUDE else []),
        extra_defines=[f"NKENTSEU_ENABLE_VULKAN_BACKEND={1 if WANT_VULKAN else 0}"],
    )

    dependson(["NKGuiIntegration"])
```

`nkentseudependson` est une fonction personnalisée du workspace Jenga qui permet de définir les chaines de dependances du projet, ses dossiers d'inclusion d'en-tete, et ses macros de préprocesseur. Dans ce cas de figure, le projet possède `26 dépendances` qui doivent etre construits avant NK3DModeler.
`extra_includes=[...]` définit les répertoires suplémentaires où le compilateur doit chercher des fichiers d'en-tete (`.h` / `.hpp`).
`extra_defines=[...]` permet d'injecter des macros de précompilation C/C++.
`dependson(["NKGuiIntegration"])` indique une dépendance suplémentaire sur `NKGuiIntegration`

* **Cinquième bloc**
```python
objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
```

`objdir` définit le repertoire où les modules objet vont etre stockés durant la compilation.
`targetdir` définit le repertoire où les fichiers binaires vont etre stockés après la compilation.
Dans les deux cas :
`wks.location` sera remplacé par le chemin d'accès du workspace.
`%{cfg.buildcfg}` sera remplacé par la configuration (`Debug` / `Release`).
`%{cfg.system}` sera remplacé par le système d'exploitation (ex: Linux).

* **sixième bloc**
```python
apppublisher("Rihen Universe")
appversion("0.1.0")
licensefile("../../LICENSE")
```

`apppublisher("...")` définit l'auteur de l'application.
`appversion("...")` définit la version de l'application.
`licensefile("...")` définit le chemin d'access à l'emplacement de la license du projet.

* **septième bloc (Les filtres)**
```python
# ===== Windows ============================================================
    with filter("system:Windows && !options:windows-runtime=uwp"):
        windowedapp()
        usetoolchain(TC_WINDOWS)
        defines(["WIN32_LEAN_AND_MEAN", "_UNICODE", "UNICODE"])
        if VULKAN_LIB:
            libdirs([VULKAN_LIB])
        _WIN_LINKS = [
            "user32", "gdi32", "opengl32", "dwmapi", "shell32", "comdlg32",
            "uuid", "ole32", "dinput8", "dxguid",
            "d3d11", "d3d12", "dxgi", "d3dcompiler",
            "winmm",
        ]
        if WANT_VULKAN:
            _WIN_LINKS.append("vulkan-1")
        links(_WIN_LINKS)

    # ===== Linux ==============================================================
    with filter("system:Linux"):
        windowedapp()
        usetoolchain("clang-native")
        defines(["NKENTSEU_FORCE_WINDOWING_XLIB_ONLY"])
        links(["pthread", "X11", "Xext", "GL", "m"])

    # ===== macOS ==============================================================
    with filter("system:macOS"):
        windowedapp()
        usetoolchain("clang-native")
        frameworks(["Cocoa", "QuartzCore", "OpenGL", "Foundation"])
```

Les filtres permettent de faire des configurations précises en fonction de conditions (ex: `system:Windows`, `config:Release`).

* **Question : Où est-il décidé que ce module est une bibliothèque statique?**
On declare qu'un module est une bibliotèque statique en ajoutant l'instruction `staticlib()` sous le projet, ou dans un filtre... Mais ce module ci est un windowedapp() comme on l'a vu en parcourant le code.