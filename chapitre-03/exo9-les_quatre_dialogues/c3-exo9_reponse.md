# Exercice 9 : Les quatres dialogues

L'objectif était d'implémenter les quatre boites de dialogue natives fournies par l'API `NkDialogs`, et de vérifier les annulations des utilisateurs sans plantage du programme.

Les quatre boites de dialogue implémentées sont :
* `NkDialogs::OpenFileDialog()`
* `NkDialogs::SaveFileDialog()`
* `NkDialogs::OpenFolderDialog()`
* `NkDialogs::OpenMessageBox()`

## Gestion de l'annulation

L'API `NkDialogs` du moteur renvoie une structure de type `NkDialogResult` afin traiter les entrées invalides des utilisateurs. J'ai implémenté des vérifications strictes à l'aide du booléen `.confirmed`.

**Exemple**
```cpp
nkentseu::NkDialogResult r1 = nkentseu::NkDialogs::OpenFileDialog("*.docx;*.txt;*.pdf", "Ouvrir un document");

if (!r1.confirmed) {
    logger.Info("[Dialog] Ouverture de fichier annulee.");
} else logger.Info("[Dialog] Fichier ouvert avec succes : {0}", r1.path.CStr());
```


## Résultat

**Log :**

```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window
     /home/ben-salem/Documents/COURSES/ENSPY/AN-ING2/ANI-2053/EXOS/FirstWindow/Build/Bin/Debug-Linux/Window/Window
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-28 04:48:08.183] [INF] [default] [main.cpp:37 in nkmain] -> [Dialog] Tentative d'ouverture de fichier.
Gtk-Message: 04:48:08.606: GtkDialog mapped without a transient parent. This is discouraged.
[2026-09-28 04:48:22.411] [INF] [default] [main.cpp:43 in nkmain] -> [Dialog] Fichier ouvert avec succes : /home/ben-salem/Documents/COURSES/FRANCAIS/conjugaisons.pdf
[2026-09-28 04:48:29.038] [INF] [default] [main.cpp:37 in nkmain] -> [Dialog] Tentative d'ouverture de fichier.
Gtk-Message: 04:48:29.393: GtkDialog mapped without a transient parent. This is discouraged.
[2026-09-28 04:48:34.231] [INF] [default] [main.cpp:42 in nkmain] -> [Dialog] Ouverture de fichier annulee.
[2026-09-28 04:48:37.729] [INF] [default] [main.cpp:50 in nkmain] -> [Dialog] Tentative d'ouverture d'un fichier.
Warning: --confirm-overwrite is deprecated and will be removed in a future version of zenity. Ignoring.
Gtk-Message: 04:48:38.103: GtkDialog mapped without a transient parent. This is discouraged.
[2026-09-28 04:49:36.599] [INF] [default] [main.cpp:56 in nkmain] -> [Dialog] Fichier sauvegarde avec succes : /home/ben-salem/Documents/COURSES/HTML_CSS_JS/0_Assigning property values, Cascading, and Inheritance.pdf
[2026-09-28 04:50:02.793] [INF] [default] [main.cpp:50 in nkmain] -> [Dialog] Tentative d'ouverture d'un fichier.
Warning: --confirm-overwrite is deprecated and will be removed in a future version of zenity. Ignoring.
Gtk-Message: 04:50:03.150: GtkDialog mapped without a transient parent. This is discouraged.
[2026-09-28 04:50:05.030] [INF] [default] [main.cpp:55 in nkmain] -> [Dialog] Sauvegarde de fichier annulee.
[2026-09-28 04:50:08.761] [INF] [default] [main.cpp:63 in nkmain] -> [Dialog] Tentative d'ouverture d'un dossier.
Gtk-Message: 04:50:09.120: GtkDialog mapped without a transient parent. This is discouraged.
[2026-09-28 04:50:16.720] [INF] [default] [main.cpp:69 in nkmain] -> [Dialog] Dossier selectionne avec succes : /home/ben-salem/Documents/COURSES/HTML_CSS_JS
[2026-09-28 04:50:20.047] [INF] [default] [main.cpp:63 in nkmain] -> [Dialog] Tentative d'ouverture d'un dossier.
Gtk-Message: 04:50:20.394: GtkDialog mapped without a transient parent. This is discouraged.
[2026-09-28 04:50:22.105] [INF] [default] [main.cpp:68 in nkmain] -> [Dialog] Ouverture de dossier annulee.
[2026-09-28 04:50:24.325] [INF] [default] [main.cpp:76 in nkmain] -> [Dialog] Tentative d'affichage du message.
[2026-09-28 04:50:27.246] [INF] [default] [main.cpp:78 in nkmain] -> [Dialog] Message affiche avec succes.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (149.30s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

* Les fenetres s'ouvent correctement et les annulations se font correctement sans plantage du programme.

* Les deux message d'erreur observés :
    * `Gtk-Message: 04:48:29.393: GtkDialog mapped without a transient parent. This is discouraged.` est un message d'erreur renvoyé par GTK indiquant que la fenetre de dialogue n'est pas liée à son parent par le moteur.
    * `Warning: --confirm-overwrite is deprecated and will be removed in a future version of zenity. Ignoring.` indique que le moteur utilise l'utilitaire `zenity` pour créer les boites de dialogue système, et qu'il utilise l'option --confirm-overwrite qui est devenue obsolète, vu que l'écrasement est désormais géré par l'OS.
Ces messages n'indiquent donc aucunément une erreur du programme.

En conclusion, j'ai réussi à implémenter les boites de dialogues natives fournies par le moteur sans problème de plantage.