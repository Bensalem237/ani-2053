# Démonstration 4 : Le meme programme sur deux systèmes

## 1. Environnements de Test Comparés
Le même code source applicatif (développé à l'aide de `nkentseu::NkWindow`) a été compilé et exécuté sur deux environnements distincts :
1. **Système A :** Windows 11 (Backend natif `NkWin32Window`)
2. **Système B :** Linux Ubuntu via X11 (Backend natif `NkXLibWindow`)

## 2. Variations Observées

Sans aucune modification du code source utilisateur, les divergences suivantes ont été observées en cours d'exécution :

### A. Intégration du Presse-papiers (Clipboard API)
* **Sous Windows :** Liaison matérielle et logicielle totale avec l'OS. Le texte transformé en majuscules est accessible par toutes les autres applications de la machine hôte.
* **Sous Linux :** Le framework bascule automatiquement sur son implémentation de secours (**Fallback**). Le presse-papiers est confiné à une variable statique partagée.

### B. Esthétique et Architecture des Dialogues Système
* **Sous Windows :** Affichage instantané des fenêtres de dialogue Win32 standards, totalement fluides et rattachées de manière modale à la fenêtre parente.
* **Sous Linux :** Le module délègue visuellement l'affichage à l'utilitaire système `zenity`. Ce changement de sous-couche se traduit par l'apparition d'avertissements de rendu spécifiques dans le terminal (messages GTK de focus transitoire) et l'adoption automatique du thème de fenêtres de la distribution Linux.

### C. Gestion des Événements et Cycle de vie
Les structures d'identifiants de fenêtres (`NkWindowId`) et le routage des messages souris passent d'un système de boucles de messages Windows (`HWND` / `WndProc`) à une file d'événements réseau X11 (`XEvent`), sans que la boucle principale `while (window.IsOpen())` du programme n'ait eu besoin d'être réécrite.