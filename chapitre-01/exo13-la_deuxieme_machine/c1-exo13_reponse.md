# Exercice 13

## Informations sur le système

* **Système d'exploitation :** **Ubuntu 24.04.4 LTS**
* **Outils absents du système :**
    * Le depot Jenga
    * Le depot Nkentseu
* **Outils obsolètes :**
    * python 2.9.1 (python 3 minimum requis)

## Procedure suivie

1. J'ai commencé par cloner le dépot jenga à l'aide de la commande suivante :
```bash
git clone https://github.com/Rihen-Universe/Jenga.git"
```

2. J'ai également cloné le dépot Nkentseu qui sera notre projet de test avec la commande suivante
```bash
git clone https://github.com/Rihen-Universe/Nkentseu.git
```

3. Par la suite, j'ai mis python à jour grace à la commande suivante
```bash
sudo apt install python
```
J'ai ensuite entamé le processus d'installation de jenga

4. J'ai commencé par naviguer vers le dépot de jenga sur l'ordinateur grace à la commande suivante
```bash
cd /home/ani-2053/Documents/Jenga
```

5. Ensuite, j'ai tapé la commande pour installer Jenga
```bash
pip install -e .
```
J'ai obtenu une erreur après cette commande
```bash
error: externally-managed-environment

× This environment is externally managed
╰─> To install Python packages system-wide, try apt install
    python3-xyz, where xyz is the package you are trying to
    install.
    
    If you wish to install a non-Debian-packaged Python package,
    create a virtual environment using python3 -m venv path/to/venv.
    Then use path/to/venv/bin/python and path/to/venv/bin/pip. Make
    sure you have python3-full installed.
    
    If you wish to install a non-Debian packaged Python application,
    it may be easiest to use pipx install xyz, which will manage a
    virtual environment for you. Make sure you have pipx installed.
    
    See /usr/share/doc/python3.12/README.venv for more information.

note: If you believe this is a mistake, please contact your Python installation or OS distribution provider. You can override this, at the risk of breaking your Python installation or OS, by passing --break-system-packages.
hint: See PEP 668 for the detailed specification.
```
J'ai essayé de résoudre le problème en créant un environnement virtuel (jenga_env) grace à la commande suivante
```bash
source jenga_env/bin/activate
```
Cela n'a pas résolu le problème, alors j'ai fait une deuxième tentative de résolution
J'ai essayer d'utiliser `pipx` au lieu de `pip`
```bash
pipx install -e .
```
L'installation a réussi

6. Par la suite j'ai ajouté Jenga qu PATH environment variable
```bash
pipx ensurepath
```

7. Ensuite j'ai re-ouvert le terminal pour enregister les variables d'environnement

8. J'ai ensuite vérifié l'installation complète de jenga avec la commande
```bash
jenga
```
Le résultat affiché était le suivant
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

Jenga Build System v2.6.3
Usage: Jenga <command> [options]

Commandes principales :
  build, b             Compile le workspace ou un projet
  run, r               Exécute un projet
  gdb, g, debug        Débogue un projet avec GDB (ou LLDB)
  test, t              Lance les tests unitaires
  clean, c             Supprime les fichiers générés
  rebuild              Nettoie et compile
  watch, w             Surveille les fichiers et rebuild automatiquement
  info, i              Affiche les informations du workspace
  gen                  Génère des fichiers projet (CMake, VS, Makefile)
  workspace, init      Crée un nouveau workspace
  project, create      Crée un nouveau projet
  file, add            Ajoute des fichiers/dépendances à un projet
  examples, e          Liste et copie des projets d'exemple
  install              Installe dépendances et toolchains locales
  kit                  Extrait un kit redistribuable (en-tetes + libs construites)
  keygen               Génère une keystore Android
  sign                 Signe un APK ou IPA
  docs                 Génère la documentation du projet
  ```

  9. Jenga étant installé avec succès, je suis allé construire Nkentseu
  ```bash
  cd /home/ani-2053/Documents/Nkentseu
  ```

  10. J'ai d'abord tapé la commande
  ```bash
  jenga info
  ```
  J'ai obtenu le résultat suivant :
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

[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
========================== Jenga Workspace: Nkentseu ===========================

Location: /home/ani-2053/Documents/Nkentseu
Entry file: /home/ani-2053/Documents/Nkentseu/Nkentseu.jenga
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
NKMath                       StaticLib     C++        No     Yes
NKMath_Tests                 TestSuite     C++        Yes    Yes
NKMemory_Tests               TestSuite     C++        Yes    Yes
NKMemory                     StaticLib     C++        No     Yes
NKContainers_Tests           TestSuite     C++        Yes    Yes
NKContainers                 StaticLib     C++        No     Yes
NKImage_Tests                TestSuite     C++        Yes    Yes
NKImage                      StaticLib     C++        No     Yes
NKFont                       StaticLib     C++        No     Yes
NKFont_Tests                 TestSuite     C++        Yes    Yes
NKAudio_Tests                TestSuite     C++        Yes    Yes
NKAudio                      StaticLib     C++        No     Yes
NKMedia                      StaticLib     C++        No     Yes
NKTime                       StaticLib     C++        No     Yes
NKTime_Tests                 TestSuite     C++        Yes    Yes
NKStream                     StaticLib     C++        No     Yes
NKStream_Tests               TestSuite     C++        Yes    Yes
NKThreading                  StaticLib     C++        No     Yes
NKThreading_Tests            TestSuite     C++        Yes    Yes
NKFileSystem                 StaticLib     C++        No     Yes
NKFileSystem_Tests           TestSuite     C++        Yes    Yes
NKReflection_Tests           TestSuite     C++        Yes    Yes
NKReflection                 StaticLib     C++        No     Yes
NKNetwork_Tests              TestSuite     C++        Yes    Yes
NKNetwork                    StaticLib     C++        No     Yes
NKSerialization              StaticLib     C++        No     Yes
NKSerialization_Tests        TestSuite     C++        Yes    Yes
NKGlad                       StaticLib     C          No     Yes
NKGLSlang                    StaticLib     C++        No     Yes
NKSPIRVCross                 StaticLib     C++        No     Yes
NKMbedTLS                    StaticLib     C          No     Yes
pybind11                     StaticLib     C++        No     Yes
NKEvent_Tests                TestSuite     C++        Yes    Yes
NKEvent                      StaticLib     C++        No     Yes
NKWindow_Tests               TestSuite     C++        Yes    Yes
NKWindow                     StaticLib     C++        No     Yes
NKSL                         StaticLib     C++        No     Yes
NKCanvas_Tests               TestSuite     C++        Yes    Yes
NKCanvas                     StaticLib     C++        No     Yes
NKRHI_Tests                  TestSuite     C++        Yes    Yes
NKRHI                        StaticLib     C++        No     Yes
NKUI                         StaticLib     C++        No     Yes
NKUI_Tests                   TestSuite     C++        Yes    Yes
NKGui                        StaticLib     C++        No     Yes
NKEditorKit                  StaticLib     C++        No     Yes
Unkeny                       StaticLib     C++        No     Yes
NkPdfRenderProbe             ConsoleApp    C++        No     Yes
NkFileWorkerTest             ConsoleApp    C++        No     Yes
NkPdfProbe                   ConsoleApp    C++        No     Yes
NKCode                       WindowedApp   C++        No     Yes
NkPdfRasterTest              ConsoleApp    C++        No     Yes
NK3DModeler                  WindowedApp   C++        No     Yes
NKImGuiIntegration           StaticLib     C++        No     Yes
NKUIIntegration              StaticLib     C++        No     Yes
NKGuiIntegration             StaticLib     C++        No     Yes
NKCamera_Tests               TestSuite     C++        Yes    Yes
NKCamera                     StaticLib     C++        No     Yes
NKCollision                  StaticLib     C++        No     Yes
NKCollision_Tests            TestSuite     C++        Yes    Yes
NKPhysics_Tests              TestSuite     C++        Yes    Yes
NKPhysics                    StaticLib     C++        No     Yes
NKAnimPhysics                StaticLib     C++        No     Yes
NKAnimation                  StaticLib     C++        No     Yes
NKNavigation_Tests           TestSuite     C++        Yes    Yes
NKNavigation                 StaticLib     C++        No     Yes
NKXR_Tests                   TestSuite     C++        Yes    Yes
NKXR                         StaticLib     C++        No     Yes
gltftest_Tests               TestSuite     C++        Yes    Yes
NkRHIDemoFull_Tests          TestSuite     C++        Yes    Yes
gltftest                     WindowedApp   C++        No     Yes
NkFDV2_Tests                 TestSuite     C++        Yes    Yes
NkSpriteDemo_Tests           TestSuite     C++        Yes    Yes
NkRHIDemoFull                WindowedApp   C++        No     Yes
Gamepad                      WindowedApp   C++        No     Yes
NkFontDemo_Tests             TestSuite     C++        Yes    Yes
NkSWRasterPrimitives         WindowedApp   C++        No     Yes
NkDrawableDemo               WindowedApp   C++        No     Yes
r2d01_Tests                  TestSuite     C++        Yes    Yes
NewGeneration_Tests          TestSuite     C++        Yes    Yes
NkDrawableDemo_Tests         TestSuite     C++        Yes    Yes
cr2d_Tests                   TestSuite     C++        Yes    Yes
renderdemo_Tests             TestSuite     C++        Yes    Yes
Gamepad_Tests                TestSuite     C++        Yes    Yes
FontLoad                     WindowedApp   C++        No     Yes
NKRHIDemo                    WindowedApp   C++        No     Yes
NkFontDemo                   WindowedApp   C++        No     Yes
NkCanvasDemo_Tests           TestSuite     C++        Yes    Yes
NkSWRasterPrimitives_Tests   TestSuite     C++        Yes    Yes
cr2d                         WindowedApp   C++        No     Yes
NkRHIDemoFullImage           WindowedApp   C++        No     Yes
r2d01                        WindowedApp   C++        No     Yes
NkRHIInterpTest_Tests        TestSuite     C++        Yes    Yes
NkRHIDemoFullImage_Tests     TestSuite     C++        Yes    Yes
renderdemo                   WindowedApp   C++        No     Yes
NewGeneration                WindowedApp   C++        No     Yes
firsttriangle_Tests          TestSuite     C++        Yes    Yes
NkSpriteDemo                 WindowedApp   C++        No     Yes
NkCanvasDemo                 WindowedApp   C++        No     Yes
NKRHIDemo_Tests              TestSuite     C++        Yes    Yes
RendererRHI_Tests            TestSuite     C++        Yes    Yes
firsttriangle                WindowedApp   C++        No     Yes
RendererRHI                  WindowedApp   C++        No     Yes
NkFDV2                       WindowedApp   C++        No     Yes
NkRHIInterpTest              WindowedApp   C++        No     Yes
ConquerorProto               WindowedApp   C++        No     Yes
NkAudioDemo                  ConsoleApp    C++        No     Yes
NkCameraDemos                WindowedApp   C++        No     Yes
SandboxNKFileSystem          ConsoleApp    C++        No     Yes
SandboxNKLogger              ConsoleApp    C++        No     Yes
SandboxNKReflection          ConsoleApp    C++        No     Yes
SandboxNKNetwork             ConsoleApp    C++        No     Yes
NKRenderer_Tests             TestSuite     C++        Yes    Yes
NKRenderer                   StaticLib     C++        No     Yes
NKTensor                     StaticLib     C++        No     Yes
NKTensor_Tests               TestSuite     C++        Yes    Yes
NKAutograd_Tests             TestSuite     C++        Yes    Yes
NKAutograd                   StaticLib     C++        No     Yes
NKNN                         StaticLib     C++        No     Yes
NKNN_Tests                   TestSuite     C++        Yes    Yes
NKOptim                      StaticLib     C++        No     Yes
NKOptim_Tests                TestSuite     C++        Yes    Yes
NKData                       StaticLib     C++        No     Yes
NKData_Tests                 TestSuite     C++        Yes    Yes
NKTrain                      StaticLib     C++        No     Yes
NKTrain_Tests                TestSuite     C++        Yes    Yes
NKInfer_Tests                TestSuite     C++        Yes    Yes
NKInfer                      StaticLib     C++        No     Yes
NKRL_Tests                   TestSuite     C++        Yes    Yes
NKRL                         StaticLib     C++        No     Yes
NKAgent                      StaticLib     C++        No     Yes
NKAgent_Tests                TestSuite     C++        Yes    Yes
NKEvolve                     StaticLib     C++        No     Yes
NKEvolve_Tests               TestSuite     C++        Yes    Yes
NKCivilization_Tests         TestSuite     C++        Yes    Yes
NKCivilization               StaticLib     C++        No     Yes
NKEmbodied                   StaticLib     C++        No     Yes
NKEmbodied_Tests             TestSuite     C++        Yes    Yes
NKGen                        StaticLib     C++        No     Yes
NKGen_Tests                  TestSuite     C++        Yes    Yes
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
Tuto04Camera                 WindowedApp   C++        No     Yes
Tuto05Meshes                 WindowedApp   C++        No     Yes
Tuto03Scene                  WindowedApp   C++        No     Yes
Tuto02Renderer               WindowedApp   C++        No     Yes
Tuto01Fenetre                WindowedApp   C++        No     Yes
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

11. Enfin, j'ai construit le module NKCanvas de Nkentseu
```bash
jenga build --progect NKCanvas
```
Construction réussie avec une durée de `3m10.7s` et `0` avertissement

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
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Linux x86_64
Toolchain:     host-clang

Build Order (16 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  11. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  12. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  13. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  14. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  15. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  16. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkCPUFeatures.cpp
✓   [5/7] Compiled: NkEndianness.cpp
✓   [6/7] Compiled: NkEnv.cpp
✓   [7/7] Compiled: NkPlatformConfig.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKPlatform.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.81s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: glx.c
✓   [2/2] Compiled: gl.c
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKGlad.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.88s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkBits.cpp
✓   [2/5] Compiled: NkLimits.cpp
✓   [3/5] Compiled: NkAssert.cpp
✓   [4/5] Compiled: NkTraits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCore.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.88s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkContainerAllocator.cpp
✓   [2/14] Compiled: NkFunction.cpp
✓   [3/14] Compiled: NkAllocator.cpp
✓   [4/14] Compiled: NkGlobalOperators.cpp
✓   [5/14] Compiled: NkGc.cpp
✓   [6/14] Compiled: NkFunctionSIMD.cpp
✓   [7/14] Compiled: NkHash.cpp
✓   [8/14] Compiled: NkMemory.cpp
✓   [9/14] Compiled: NkMultiLevelAllocator.cpp
✓   [10/14] Compiled: NkPoolAllocator.cpp
✓   [11/14] Compiled: NkProfiler.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkUtils.cpp
✓   [14/14] Compiled: NkTracker.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMemory.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.60s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBinaryTree.cpp
✓   [2/43] Compiled: NkHashMap.cpp
✓   [3/43] Compiled: NkBTree.cpp
✓   [4/43] Compiled: NkPriorityQueue.cpp
✓   [5/43] Compiled: NkMap.cpp
✓   [6/43] Compiled: NkSet.cpp
✓   [7/43] Compiled: NkUnorderedSet.cpp
✓   [8/43] Compiled: NkUnorderedMap.cpp
✓   [9/43] Compiled: NkTrie.cpp
✓   [10/43] Compiled: NkArray.cpp
✓   [11/43] Compiled: NkPool.cpp
✓   [12/43] Compiled: NkRingBuffer.cpp
✓   [13/43] Compiled: NkBind.cpp
✓   [14/43] Compiled: NkFunction.cpp
✓   [15/43] Compiled: NkPair.cpp
✓   [16/43] Compiled: NkFunctional.cpp
✓   [17/43] Compiled: NkTuple.cpp
✓   [18/43] Compiled: NkInitializerList.cpp
✓   [19/43] Compiled: NkIterator.cpp
✓   [20/43] Compiled: NkContainers.cpp
✓   [21/43] Compiled: NkDoubleList.cpp
✓   [22/43] Compiled: NkDeque.cpp
✓   [23/43] Compiled: NkVector.cpp
✓   [24/43] Compiled: NkList.cpp
✓   [25/43] Compiled: NkASCII.cpp
✓   [26/43] Compiled: NkQuadTree.cpp
✓   [27/43] Compiled: NkGraph.cpp
✓   [28/43] Compiled: NkEncoding.cpp
✓   [29/43] Compiled: NkBase64.cpp
✓   [30/43] Compiled: NkUTF16.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkFormat.cpp
✓   [35/43] Compiled: NkString.cpp
✓   [36/43] Compiled: NkStringBuilder.cpp
✓   [37/43] Compiled: NkStringHash.cpp
✓   [38/43] Compiled: NkOptional.cpp
✓   [39/43] Compiled: NkStringUtils.cpp
✓   [40/43] Compiled: NkVariant.cpp
✓   [41/43] Compiled: NkResult.cpp
✓   [42/43] Compiled: NkSpan.cpp
✓   [43/43] Compiled: NkStringView.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKContainers.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 16.38s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkAngle.cpp
✓   [2/12] Compiled: NkEulerAngle.cpp
✓   [3/12] Compiled: NkFunctions.cpp
✓   [4/12] Compiled: NkColor.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkRandom.cpp
✓   [7/12] Compiled: NkQuat.cpp
✓   [8/12] Compiled: NkSIMD.cpp
✓   [9/12] Compiled: NkRange.cpp
✓   [10/12] Compiled: NkRectangle.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKMath.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 12.22s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkRecursiveMutex.cpp
✓   [2/12] Compiled: NkMutex.cpp
✓   [3/12] Compiled: NkConditionVariable.cpp
✓   [4/12] Compiled: NkSpinLock.cpp
✓   [5/12] Compiled: NkSemaphore.cpp
✓   [6/12] Compiled: NkSharedMutex.cpp
✓   [7/12] Compiled: NkBarrier.cpp
✓   [8/12] Compiled: NkEvent.cpp
✓   [9/12] Compiled: NkThread.cpp
✓   [10/12] Compiled: NkReaderWriterLock.cpp
✓   [11/12] Compiled: NkLatch.cpp
✓   [12/12] Compiled: NkThreadPool.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKThreading.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.67s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkLogLevel.cpp
✓   [2/14] Compiled: NkLogger.cpp
✓   [3/14] Compiled: NkLogMessage.cpp
✓   [4/14] Compiled: NkLog.cpp
✓   [5/14] Compiled: NkLoggerFormatter.cpp
✓   [6/14] Compiled: NkSink.cpp
✓   [7/14] Compiled: NkRegistry.cpp
✓   [8/14] Compiled: NkAsyncSink.cpp
✓   [9/14] Compiled: NkConsoleSink.cpp
✓   [10/14] Compiled: NkDistributingSink.cpp
✓   [11/14] Compiled: NkDailyFileSink.cpp
✓   [12/14] Compiled: NkFileSink.cpp
✓   [13/14] Compiled: NkNullSink.cpp
✓   [14/14] Compiled: NkRotatingFileSink.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKLogger.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 15.52s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkDirectory.cpp
✓   [2/5] Compiled: NkFileSystem.cpp
✓   [3/5] Compiled: NkFile.cpp
✓   [4/5] Compiled: NkFileWatcher.cpp
✓   [5/5] Compiled: NkPath.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKFileSystem.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkFontDetect.cpp
✓   [2/8] Compiled: NkFontRasterizer.cpp
✓   [3/8] Compiled: NkFontParser.cpp
✓   [4/8] Compiled: NkFontSizeCache.cpp
✓   [5/8] Compiled: NkUtils.cpp
✓   [6/8] Compiled: NkFontAtlas.cpp
✓   [7/8] Compiled: NkFontMesh.cpp
✓   [8/8] Compiled: NkFontEmbedded.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKFont.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 14.67s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkClock.cpp
✓   [2/8] Compiled: NkChrono.cpp
✓   [3/8] Compiled: NkDate.cpp
✓   [4/8] Compiled: NkSystemClock.cpp
✓   [5/8] Compiled: NkDuration.cpp
✓   [6/8] Compiled: NkTimeSpan.cpp
✓   [7/8] Compiled: NkTimeZone.cpp
✓   [8/8] Compiled: NkTimes.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKTime.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.57s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkBinaryStream.cpp
✓   [2/4] Compiled: NkConsoleStream.cpp
✓   [3/4] Compiled: NkStream.cpp
✓   [4/4] Compiled: NkFileStream.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKStream.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.90s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkEvent.cpp
✓   [2/10] Compiled: NkEventDispatcher.cpp
✓   [3/10] Compiled: NkDropSystem.cpp
✓   [4/10] Compiled: NkGamepadMappingPersistence.cpp
✓   [5/10] Compiled: NkEventState.cpp
✓   [6/10] Compiled: NkEventSystem.cpp
✓   [7/10] Compiled: NkKeyboardEvent.cpp
✓   [8/10] Compiled: NkGamepadSystem.cpp
✓   [9/10] Compiled: NkMouseEvent.cpp
✓   [10/10] Compiled: NkWindowEvent.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKEvent.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 20.77s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓   [1/13] Compiled: NkBMPCodec.cpp
✓   [2/13] Compiled: NkGIFCodec.cpp
✓   [3/13] Compiled: NkEXRCodec.cpp
✓   [4/13] Compiled: NkICOCodec.cpp
✓   [5/13] Compiled: NkHDRCodec.cpp
✓   [6/13] Compiled: NkJPEGCodec.cpp
✓   [7/13] Compiled: NkPPMCodec.cpp
✓   [8/13] Compiled: NkPNGCodec.cpp
✓   [9/13] Compiled: NkQOICodec.cpp
✓   [10/13] Compiled: NkTGACodec.cpp
✓   [11/13] Compiled: NkSVGCodec.cpp
✓   [12/13] Compiled: NkWebPCodec.cpp
✓   [13/13] Compiled: NkImage.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKImage.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 18.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [1/9] Compiled: NkLauncher.cpp
✓   [2/9] Compiled: NkDialogs.cpp
✓   [3/9] Compiled: NkContext.cpp
✓   [4/9] Compiled: NkWindowClipboard.cpp
✓   [5/9] Compiled: NkWESystem.cpp
✓   [6/9] Compiled: NkWindowClipboardImage.cpp
✓   [7/9] Compiled: NkWindowCursor.cpp
✓   [8/9] Compiled: NkXLibEventSystem.cpp
✓   [9/9] Compiled: NkXLibWindow.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKWindow.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 14.95s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCanvas                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 31 source file(s)
✓   [1/31] Compiled: NkDX11ComputeContext.cpp
✓   [2/31] Compiled: NkDX11Context.cpp
✓   [3/31] Compiled: NkDX11Renderer2D.cpp
✓   [4/31] Compiled: NkCanvasApp.cpp
✓   [5/31] Compiled: NkDX12ComputeContext.cpp
✓   [6/31] Compiled: NkDX12Context.cpp
✓   [7/31] Compiled: NkDX12Renderer2D.cpp
✓   [8/31] Compiled: NkOpenGLComputeContext.cpp
✓   [9/31] Compiled: NkSoftwareComputeContext.cpp
✓   [10/31] Compiled: NkOpenGLContext.cpp
✓   [11/31] Compiled: NkOpenGLRenderer2D.cpp
✓   [12/31] Compiled: NkSoftwareContext.cpp
✓   [13/31] Compiled: NkSoftwareRenderer2D.cpp
✓   [14/31] Compiled: NkVulkanContext.cpp
✓   [15/31] Compiled: NkVulkanComputeContext.cpp
✓   [16/31] Compiled: NkVulkanRenderer2D.cpp
✓   [17/31] Compiled: NkContextFactory.cpp
✓   [18/31] Compiled: NkGpuPolicy.cpp
✓   [19/31] Compiled: NkRenderer2DTypes.cpp
✓   [20/31] Compiled: NkBatchRenderer2D.cpp
✓   [21/31] Compiled: NkRenderer2DFactory.cpp
✓   [22/31] Compiled: NkFont.cpp
✓   [23/31] Compiled: NkShader.cpp
✓   [24/31] Compiled: NkSprite.cpp
✓   [25/31] Compiled: NkTexture.cpp
✓   [26/31] Compiled: NkShape.cpp
✓   [27/31] Compiled: NkRenderTarget.cpp
✓   [28/31] Compiled: NkRenderTexture.cpp
✓   [29/31] Compiled: NkRenderWindow.cpp
✓   [30/31] Compiled: NkRenderWindowCapture.cpp
✓   [31/31] Compiled: NkUICanvasBackend.cpp
ℹ Linking...
✓ Built: Build/Lib/Debug-Linux/NKCanvas.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 1m0.8s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  16/16
Time:           3m10.7s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```