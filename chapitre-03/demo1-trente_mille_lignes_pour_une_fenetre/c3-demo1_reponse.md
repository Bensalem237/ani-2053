# Démonstration 1 : Trente mille lignes pour une fenetre

# 1. Le nombre de fichiers et de lignes du module

L'objectif était d'utiliser des commandes pour calculer le nombre exact de :

* Fichiers source

```bash
find . -type f \( -name "*.h" -o -name "*.cpp" \) | wc -l
```

**Résultat :**
```
109
```

* Lignes de code

```bash
find . -type f \( -name "*.h" -o -name "*.cpp" \) -exec cat {} + | wc -l
```

**Résultat :**
```
30611
```

## 2. La liste des backends de plateforme

L'objectif ici était d'utiliser une commande pour compter le nombre de backends de plateforme que le module utilise

```bash
find src/NKWindow/Platform/ -mindepth 1 -maxdepth 1 -type d | wc -l
```

**Résultat :**
```
14
```

## 3. Suivi d'un appel public dans deux backends

L'objectif ici était de choisir une méthode du module.

```cpp
void SetTitle(const NkString &title);
```

Et de suivre son implémentation dans deux backends différents :

### Implémentation 1 (Backend Win32)

```cpp
// Kernel/Runtime/NKWindow/src/NKWindow/Platform/Win32/NkWin32Window.cpp
void NkWindow::SetTitle(const NkString &t) {
	mConfig.title = t;
	if (mData.mHwnd) {
		SetWindowTextW(mData.mHwnd, NkUtf8ToWide(t).CStr());
		// La synchronisation est déjà faite via la modification de mConfig
	}
}
```

### Implémentation 2 (Backend Linux XLib)

```cpp
// Kernel/Runtime/NKWindow/src/NKWindow/Platform/XLib/NkXLibWindow.cpp
void NkWindow::SetTitle(const NkString &title) {
	mConfig.title = title;
	if (mData.mDisplay && mData.mXid) {
		XStoreName(mData.mDisplay, mData.mXid, title.CStr());
	}
}
```

### Analyse de l'abstraction
* **Ce qui est identique :** L'interface publique de la méthode, sa signature, le type de paramètre reçu et la mise à jour de la configuration générique.
* **Ce qui change :** Les types de handles de fenêtres stockés en mémoire et les fonctions systèmes de bas niveau appelées pour modifier l'état graphique.

**Définition de l'absorption du module :**  
Le module `NKWindow` absorbe l'hétérogénéité des API graphiques bas niveau propres à chaque système d'exploitation en encapsulant leurs types de données natifs sous une structure opaque unique. Il unifie le traitement des chaînes de caractères et les mécanismes de rafraîchissement d'affichage qui diffèrent fondamentalement entre l'architecture de Windows et celle de Linux. Grâce à cette abstraction, le reste du moteur graphique consomme une interface logicielle unique et portable sans jamais se soucier des spécificités de la plateforme d'exécution.