# Exercice 5
Selon les instructions de l'exercice, j'ai créé le dossier `MonEssai` dans le repertoire `Applications` du workspace `Nkentseu`.

## main.cpp
Ensuite j'y ai créé le fichier `main.cpp` annoté ci-dessous :

```cpp
// Nkentseu/Applications/MonEssai/main.cpp
int main () {
    return 0;
}
```
## MonEssai.jenga
J'ai ensuite créé le fichier de projet `MonEssai.jenga` annoté ci-dessous :

```python
# Nkentseu/Applications/MonEssai/MonEssai.jenga
from Jenga import *
from jengaconfig import *

with project("MonEssai"):
    windowedapp()
    language("C++")
    cppdialect("C++17")
    location(".")

    files(["src/**.cpp"])

    nkentseudependson(["NKCanvas", "NKFont", "NKGlad"], extra_includes=["src"])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

    with filter("system:Windows"):
        usetoolchain(TC_WINDOWS)
        links(["user32", "gdi32", "opengl32", "dwmapi", "shell32"])

    with filter("system:Linux"):
        links(["X11", "Xrandr", "GL", "pthread", "dl"])

    with filter("config:Debug"):
        defines(["_DEBUG"]); optimize("Off"); symbols(True)

    with filter("config:Release"):
        defines(["NDEBUG"]); optimize("speed"); symbols(False)
```
## Declaration au workspace
Ensuite, je me suis bien rassuré de déclarer le fichier `MonEssai.jenga` au workspace `Nkentseu` grace à la commande :

```python
# Inclusion de Mon Essai pour l'exercice 5 de l'évaluation
    with include("Applications/MonEssai/MonEssai.jenga") :
        pass
```

Ensuite, j'ai vérifié qu'il apparaissent avec la commande `jenga info` qui a produit le resultat suivant :

```bash
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.6.3             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

========================== Jenga Workspace: Nkentseu ===========================

Location: /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu
Entry file: /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/Nkentseu/Nkentseu.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Linux, macOS, Android, iOS, Web, HarmonyOS, XboxSeries, XboxOne
Target Architectures: x86_64, arm64, wasm32
Start project: Sandbox


Projects
------------------------------------------------------------
Name                         Kind          Language   Test   External
=====================================================================
__Unitest__                  StaticLib     C++        No     No
NKPlatform                   StaticLib     C++        No     Yes
NKPlatform_Tests             TestSuite     C++        Yes    Yes
NKCore_Tests                 TestSuite     C++        Yes    Yes
NKCore                       StaticLib     C++        No     Yes
NKLogger                     StaticLib     C++        No     Yes
NKLogger_Tests               TestSuite     C++        Yes    Yes
NKMath_Tests                 TestSuite     C++        Yes    Yes
NKMath                       StaticLib     C++        No     Yes
NKMemory                     StaticLib     C++        No     Yes
NKMemory_Tests               TestSuite     C++        Yes    Yes
NKContainers_Tests           TestSuite     C++        Yes    Yes
NKContainers                 StaticLib     C++        No     Yes
NKImage_Tests                TestSuite     C++        Yes    Yes
NKImage                      StaticLib     C++        No     Yes
NKFont_Tests                 TestSuite     C++        Yes    Yes
NKFont                       StaticLib     C++        No     Yes
NKAudio                      StaticLib     C++        No     Yes
NKAudio_Tests                TestSuite     C++        Yes    Yes
NKMedia                      StaticLib     C++        No     Yes
NKTime                       StaticLib     C++        No     Yes
NKTime_Tests                 TestSuite     C++        Yes    Yes
NKStream                     StaticLib     C++        No     Yes
NKStream_Tests               TestSuite     C++        Yes    Yes
NKThreading                  StaticLib     C++        No     Yes
NKThreading_Tests            TestSuite     C++        Yes    Yes
NKFileSystem_Tests           TestSuite     C++        Yes    Yes
NKFileSystem                 StaticLib     C++        No     Yes
NKReflection_Tests           TestSuite     C++        Yes    Yes
NKReflection                 StaticLib     C++        No     Yes
NKNetwork                    StaticLib     C++        No     Yes
NKNetwork_Tests              TestSuite     C++        Yes    Yes
NKSerialization              StaticLib     C++        No     Yes
NKSerialization_Tests        TestSuite     C++        Yes    Yes
NKGlad                       StaticLib     C          No     Yes
NKGLSlang                    StaticLib     C++        No     Yes
NKSPIRVCross                 StaticLib     C++        No     Yes
NKMbedTLS                    StaticLib     C          No     Yes
pybind11                     StaticLib     C++        No     Yes
NKEvent                      StaticLib     C++        No     Yes
NKEvent_Tests                TestSuite     C++        Yes    Yes
NKWindow_Tests               TestSuite     C++        Yes    Yes
NKWindow                     StaticLib     C++        No     Yes
NKSL                         StaticLib     C++        No     Yes
NKCanvas                     StaticLib     C++        No     Yes
NKCanvas_Tests               TestSuite     C++        Yes    Yes
NKRHI                        StaticLib     C++        No     Yes
NKRHI_Tests                  TestSuite     C++        Yes    Yes
NKUI                         StaticLib     C++        No     Yes
NKUI_Tests                   TestSuite     C++        Yes    Yes
NKGui                        StaticLib     C++        No     Yes
NKEditorKit                  StaticLib     C++        No     Yes
Unkeny                       StaticLib     C++        No     Yes
NKCode                       WindowedApp   C++        No     Yes
NkPdfProbe                   ConsoleApp    C++        No     Yes
NkFileWorkerTest             ConsoleApp    C++        No     Yes
NkPdfRasterTest              ConsoleApp    C++        No     Yes
NkPdfRenderProbe             ConsoleApp    C++        No     Yes
NK3DModeler                  WindowedApp   C++        No     Yes
NKImGuiIntegration           StaticLib     C++        No     Yes
NKUIIntegration              StaticLib     C++        No     Yes
NKGuiIntegration             StaticLib     C++        No     Yes
NKCamera                     StaticLib     C++        No     Yes
NKCamera_Tests               TestSuite     C++        Yes    Yes
NKCollision_Tests            TestSuite     C++        Yes    Yes
NKCollision                  StaticLib     C++        No     Yes
NKPhysics                    StaticLib     C++        No     Yes
NKPhysics_Tests              TestSuite     C++        Yes    Yes
NKAnimPhysics                StaticLib     C++        No     Yes
NKAnimation                  StaticLib     C++        No     Yes
NKNavigation                 StaticLib     C++        No     Yes
NKNavigation_Tests           TestSuite     C++        Yes    Yes
NKXR                         StaticLib     C++        No     Yes
NKXR_Tests                   TestSuite     C++        Yes    Yes
NkDrawableDemo_Tests         TestSuite     C++        Yes    Yes
NkRHIInterpTest_Tests        TestSuite     C++        Yes    Yes
r2d01                        WindowedApp   C++        No     Yes
firsttriangle                WindowedApp   C++        No     Yes
NkRHIDemoFullImage_Tests     TestSuite     C++        Yes    Yes
gltftest_Tests               TestSuite     C++        Yes    Yes
NkFDV2                       WindowedApp   C++        No     Yes
Gamepad_Tests                TestSuite     C++        Yes    Yes
NkRHIDemoFullImage           WindowedApp   C++        No     Yes
RendererRHI                  WindowedApp   C++        No     Yes
NKRHIDemo                    WindowedApp   C++        No     Yes
r2d01_Tests                  TestSuite     C++        Yes    Yes
NkRHIDemoFull_Tests          TestSuite     C++        Yes    Yes
renderdemo                   WindowedApp   C++        No     Yes
NkSWRasterPrimitives_Tests   TestSuite     C++        Yes    Yes
NkRHIDemoFull                WindowedApp   C++        No     Yes
NKRHIDemo_Tests              TestSuite     C++        Yes    Yes
NkSWRasterPrimitives         WindowedApp   C++        No     Yes
cr2d                         WindowedApp   C++        No     Yes
FontLoad                     WindowedApp   C++        No     Yes
RendererRHI_Tests            TestSuite     C++        Yes    Yes
NkCanvasDemo_Tests           TestSuite     C++        Yes    Yes
NkFontDemo                   WindowedApp   C++        No     Yes
NkFDV2_Tests                 TestSuite     C++        Yes    Yes
cr2d_Tests                   TestSuite     C++        Yes    Yes
NkDrawableDemo               WindowedApp   C++        No     Yes
gltftest                     WindowedApp   C++        No     Yes
NkCanvasDemo                 WindowedApp   C++        No     Yes
Gamepad                      WindowedApp   C++        No     Yes
NewGeneration                WindowedApp   C++        No     Yes
NewGeneration_Tests          TestSuite     C++        Yes    Yes
firsttriangle_Tests          TestSuite     C++        Yes    Yes
NkRHIInterpTest              WindowedApp   C++        No     Yes
NkSpriteDemo                 WindowedApp   C++        No     Yes
NkFontDemo_Tests             TestSuite     C++        Yes    Yes
renderdemo_Tests             TestSuite     C++        Yes    Yes
NkSpriteDemo_Tests           TestSuite     C++        Yes    Yes
ConquerorProto               WindowedApp   C++        No     Yes
NkAudioDemo                  ConsoleApp    C++        No     Yes
NkCameraDemos                WindowedApp   C++        No     Yes
SandboxNKFileSystem          ConsoleApp    C++        No     Yes
SandboxNKLogger              ConsoleApp    C++        No     Yes
SandboxNKReflection          ConsoleApp    C++        No     Yes
SandboxNKNetwork             ConsoleApp    C++        No     Yes
NKRenderer_Tests             TestSuite     C++        Yes    Yes
NKRenderer                   StaticLib     C++        No     Yes
NKTensor_Tests               TestSuite     C++        Yes    Yes
NKTensor                     StaticLib     C++        No     Yes
NKAutograd                   StaticLib     C++        No     Yes
NKAutograd_Tests             TestSuite     C++        Yes    Yes
NKNN                         StaticLib     C++        No     Yes
NKNN_Tests                   TestSuite     C++        Yes    Yes
NKOptim                      StaticLib     C++        No     Yes
NKOptim_Tests                TestSuite     C++        Yes    Yes
NKData_Tests                 TestSuite     C++        Yes    Yes
NKData                       StaticLib     C++        No     Yes
NKTrain_Tests                TestSuite     C++        Yes    Yes
NKTrain                      StaticLib     C++        No     Yes
NKInfer_Tests                TestSuite     C++        Yes    Yes
NKInfer                      StaticLib     C++        No     Yes
NKRL_Tests                   TestSuite     C++        Yes    Yes
NKRL                         StaticLib     C++        No     Yes
NKAgent                      StaticLib     C++        No     Yes
NKAgent_Tests                TestSuite     C++        Yes    Yes
NKEvolve                     StaticLib     C++        No     Yes
NKEvolve_Tests               TestSuite     C++        Yes    Yes
NKCivilization               StaticLib     C++        No     Yes
NKCivilization_Tests         TestSuite     C++        Yes    Yes
NKEmbodied                   StaticLib     C++        No     Yes
NKEmbodied_Tests             TestSuite     C++        Yes    Yes
NKGen_Tests                  TestSuite     C++        Yes    Yes
NKGen                        StaticLib     C++        No     Yes
NKGpt                        StaticLib     C++        No     Yes
NKSpeech                     StaticLib     C++        No     Yes
NKTensorDemo                 ConsoleApp    C++        No     Yes
NkSLComputeCheck             ConsoleApp    C++        No     Yes
NkGpuProbe                   ConsoleApp    C++        No     Yes
NkComputeNkSL                ConsoleApp    C++        No     Yes
NkTensorGpuTest              ConsoleApp    C++        No     Yes
NKGpuBenchTest               ConsoleApp    C++        No     Yes
NKConvBenchTest              ConsoleApp    C++        No     Yes
NKConvResidentBench          ConsoleApp    C++        No     Yes
NKMlpResidentBench           ConsoleApp    C++        No     Yes
NKMnistGpuTrain              ConsoleApp    C++        No     Yes
NKRebasinTest                ConsoleApp    C++        No     Yes
NKMnistCnnGpuTrain           ConsoleApp    C++        No     Yes
NKTransformerTest            ConsoleApp    C++        No     Yes
NKGptTrain                   ConsoleApp    C++        No     Yes
NKIlyana                     ConsoleApp    C++        No     Yes
NKAutogradTest               ConsoleApp    C++        No     Yes
NKNNTest                     ConsoleApp    C++        No     Yes
NKConvTest                   ConsoleApp    C++        No     Yes
NKDataTest                   ConsoleApp    C++        No     Yes
NKBpeTest                    ConsoleApp    C++        No     Yes
NKLlamaBlockTest             ConsoleApp    C++        No     Yes
NKRebasinTransformer         ConsoleApp    C++        No     Yes
NKTrainTest                  ConsoleApp    C++        No     Yes
NKFp16Test                   ConsoleApp    C++        No     Yes
NKRnnCtcTest                 ConsoleApp    C++        No     Yes
NKASRTest                    ConsoleApp    C++        No     Yes
NKImageCodecTest             ConsoleApp    C++        No     Yes
NkEditableMeshDemo           ConsoleApp    C++        No     Yes
NkLocomotionDemo             ConsoleApp    C++        No     Yes
NkAssetIODemo                ConsoleApp    C++        No     Yes
NkFBXParityDemo              ConsoleApp    C++        No     Yes
NkSVGImportDemo              ConsoleApp    C++        No     Yes
NKMeshAITest                 ConsoleApp    C++        No     Yes
NKEditMeshHarness            ConsoleApp    C++        No     Yes
NkAnimPhysTest               ConsoleApp    C++        No     Yes
NkMicRecord                  ConsoleApp    C++        No     Yes
NKSpeechTest                 ConsoleApp    C++        No     Yes
NKTTSTrain                   ConsoleApp    C++        No     Yes
NkVoiceLoopDemo              ConsoleApp    C++        No     Yes
NKSpeechFeatureDemo          ConsoleApp    C++        No     Yes
NKMediaTest                  ConsoleApp    C++        No     Yes
NkVideoReadTest              ConsoleApp    C++        No     Yes
NkAudioPlayer                WindowedApp   C++        No     Yes
NkVideoPlayer                WindowedApp   C++        No     Yes
NKOpusRef                    ConsoleApp    C++        No     Yes
NKVideoTest                  ConsoleApp    C++        No     Yes
NKInferTest                  ConsoleApp    C++        No     Yes
NKGGUFInspectTest            ConsoleApp    C++        No     Yes
NKLLMInferTest               ConsoleApp    C++        No     Yes
NKQwenTokenizerTest          ConsoleApp    C++        No     Yes
NKQwen2BackwardTest          ConsoleApp    C++        No     Yes
NKQwen2SftTest               ConsoleApp    C++        No     Yes
NKQ4MatmulTest               ConsoleApp    C++        No     Yes
NKQwen2GpuTest               ConsoleApp    C++        No     Yes
NKQwen2Chat                  ConsoleApp    C++        No     Yes
NKQwen2SftGpuTest            ConsoleApp    C++        No     Yes
NKQwen2Train                 ConsoleApp    C++        No     Yes
NKQwen2Ask                   ConsoleApp    C++        No     Yes
NKRLTest                     ConsoleApp    C++        No     Yes
NKAgentTest                  ConsoleApp    C++        No     Yes
NKAgentLLMTest               ConsoleApp    C++        No     Yes
NkAgentEcsDemo               ConsoleApp    C++        No     Yes
NKEmbodiedTest               ConsoleApp    C++        No     Yes
NKEvolveTest                 ConsoleApp    C++        No     Yes
NKEvolveNNTest               ConsoleApp    C++        No     Yes
NKCivilizationTest           ConsoleApp    C++        No     Yes
NKCivilizationSocialTest     ConsoleApp    C++        No     Yes
NKCivilizationScaleTest      ConsoleApp    C++        No     Yes
NKGenTest                    ConsoleApp    C++        No     Yes
NKVAETest                    ConsoleApp    C++        No     Yes
NKMnistVAETest               ConsoleApp    C++        No     Yes
NKMnistConvVAETest           ConsoleApp    C++        No     Yes
NKConvVAETest                ConsoleApp    C++        No     Yes
NKDiffusionTest              ConsoleApp    C++        No     Yes
NKVoxelGenTest               ConsoleApp    C++        No     Yes
NKObjectGenTest              ConsoleApp    C++        No     Yes
NKGen3DTest                  ConsoleApp    C++        No     Yes
NKGenMeshTest                ConsoleApp    C++        No     Yes
NKSmoothMeshTest             ConsoleApp    C++        No     Yes
NKMatTypeResetTest           ConsoleApp    C++        No     Yes
NKEditTargetTest             ConsoleApp    C++        No     Yes
NKMeshRenderTest             ConsoleApp    C++        No     Yes
Model                        WindowedApp   C++        No     Yes
NkSLCheck                    ConsoleApp    C++        No     Yes
NKPA                         WindowedApp   C++        No     Yes
NKECS_Tests                  TestSuite     C++        Yes    Yes
NKECS                        StaticLib     C++        No     Yes
Noge                         StaticLib     C++        No     Yes
Noge_Tests                   TestSuite     C++        Yes    Yes
Nogee                        WindowedApp   C++        No     Yes
NKEditorKitDemo              WindowedApp   C++        No     Yes
NKEditorKitTest              ConsoleApp    C++        No     Yes
NKUIDesign                   WindowedApp   C++        No     Yes
ConquerorLab                 WindowedApp   C++        No     Yes
NkRef                        WindowedApp   C++        No     Yes
NkAnimaEditor                WindowedApp   C++        No     Yes
ImGuiRef                     WindowedApp   C++        No     Yes
NKGuiDrawTest                ConsoleApp    C++        No     Yes
NKGuiDemo                    WindowedApp   C++        No     Yes
NKViewportDemo               WindowedApp   C++        No     Yes
PV3DE                        WindowedApp   C++        No     Yes
Pong                         WindowedApp   C++        No     Yes
Nkoung                       WindowedApp   C++        No     Yes
Mou                          WindowedApp   C++        No     Yes
NkImeTest                    WindowedApp   C++        No     Yes
NkImageDemo                  WindowedApp   C++        No     Yes
RihenDefi                    WindowedApp   C++        No     Yes
NkAudioECSDemo               ConsoleApp    C++        No     Yes
NkNetWorldDemo               ConsoleApp    C++        No     Yes
NkNavDemo                    ConsoleApp    C++        No     Yes
NkNavCoreDemo                ConsoleApp    C++        No     Yes
NkHotReloadDemo              ConsoleApp    C++        No     Yes
NkUIHudDemo                  ConsoleApp    C++        No     Yes
Tuto05Meshes                 WindowedApp   C++        No     Yes
Tuto04Camera                 WindowedApp   C++        No     Yes
Tuto01Fenetre                WindowedApp   C++        No     Yes
Tuto02Renderer               WindowedApp   C++        No     Yes
Tuto03Scene                  WindowedApp   C++        No     Yes
NKXRDemo                     WindowedApp   C++        No     Yes
NKARDemo                     WindowedApp   C++        No     Yes
GemCrush                     WindowedApp   C++        No     Yes
NkDames                      WindowedApp   C++        No     Yes
NkEchecs                     WindowedApp   C++        No     Yes
NkLudo                       WindowedApp   C++        No     Yes
UnkenyEditor                 WindowedApp   C++        No     Yes
MonEssai                     WindowedApp   C++        No     Yes


Available Toolchains
------------------------------------------------------------
Name          Family   Target OS   Arch     Env  
=================================================
host-clang    clang    Linux       x86_64   gnu
host-gcc      gcc      Linux       x86_64   gnu
clang-mingw   clang    Windows     x86_64   mingw


Daemon
------------------------------------------------------------
Status: Not running
```
Nous pouvons remarquer le projet `MonEssai` listé dans la liste des projets en dernière position.

## Construction
Enfin, j'ai tapé la commande
```bash
jenga build --project MonEssai
```
pour construire le projet, la construction a bel et bien réussi comme vous pouvez le voir ci-dessous :

```bash
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.6.3             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (17 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  11. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  12. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  13. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  14. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  15. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  16. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  17. MonEssai [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.22s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.11s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.13s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [7/9] Compiled: NkContext.cpp
✓   [8/9] Compiled: NkXLibWindow.cpp
✓   [9/9] Compiled: NkXLibEventSystem.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKWindow.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.52s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.19s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCanvas                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 31 source file(s)
✓   [1/31] Compiled: NkDX11ComputeContext.cpp
✓   [2/31] Compiled: NkCanvasApp.cpp
✓   [3/31] Compiled: NkDX11Context.cpp
✓   [4/31] Compiled: NkDX11Renderer2D.cpp
✓   [5/31] Compiled: NkDX12ComputeContext.cpp
✓   [6/31] Compiled: NkDX12Renderer2D.cpp
✓   [7/31] Compiled: NkDX12Context.cpp
✓   [8/31] Compiled: NkOpenGLComputeContext.cpp
✓   [9/31] Compiled: NkOpenGLContext.cpp
✓   [10/31] Compiled: NkOpenGLRenderer2D.cpp
✓   [11/31] Compiled: NkSoftwareContext.cpp
✓   [12/31] Compiled: NkSoftwareComputeContext.cpp
✓   [13/31] Compiled: NkSoftwareRenderer2D.cpp
✓   [14/31] Compiled: NkVulkanComputeContext.cpp
✓   [15/31] Compiled: NkVulkanContext.cpp
✓   [16/31] Compiled: NkVulkanRenderer2D.cpp
✓   [17/31] Compiled: NkContextFactory.cpp
✓   [18/31] Compiled: NkGpuPolicy.cpp
✓   [19/31] Compiled: NkBatchRenderer2D.cpp
✓   [20/31] Compiled: NkRenderer2DFactory.cpp
✓   [21/31] Compiled: NkRenderer2DTypes.cpp
✓   [22/31] Compiled: NkFont.cpp
✓   [23/31] Compiled: NkShader.cpp
✓   [24/31] Compiled: NkShape.cpp
✓   [25/31] Compiled: NkSprite.cpp
✓   [26/31] Compiled: NkTexture.cpp
✓   [27/31] Compiled: NkRenderTarget.cpp
✓   [28/31] Compiled: NkRenderTexture.cpp
✓   [29/31] Compiled: NkUICanvasBackend.cpp
✓   [30/31] Compiled: NkRenderWindow.cpp
✓   [31/31] Compiled: NkRenderWindowCapture.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCanvas.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 12.64s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project MonEssai

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  17/17
Time:           15.34s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```