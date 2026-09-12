# Exercice 8
Afin d'obtenir le vrai temps de construction pour chaque configuration, j'ai décidé d'utiliser la commande
```bash
jenga clear
```
avant chaque construction pour vider le cache. Car effectuer directement deux constructions de suite comprometrait les données de temps obtenues comme nous l'avons vus dans l'exercice précedent.

## Configuration Debug
J'ai d'abord construit le projet `MonEssai` avec la configuration `Debug` avec la commande :

```bash
jenga build --project MonEssai --config Debug
```
Le temps de construction était de **54,02s** comme observé dans le terminal :

```bash
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  17/17
Time:           54.02s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
Ensuite, j'ai utilisé la commande

```bash
ls -lh Build/Bin/Debug-linux-x86_64/MonEssai/MonEssai
```
pour obtenir la taille du fichier binaire qui est de **568Ko** comme j'ai pu observer dans le terminal :

```bash
-rwxrwxr-x 1 ben-salem ben-salem 568K Sep 12 22:01 ../../Build/Bin/Debug-Linux/MonEssai/MonEssai
```

## Configuration Release

```bash
jenga build --project MonEssai --config Release
```
Le temps de construction était de **54,66s** (Surprenant, puisqu'il est plus long que le temps de Debug, bien que j'ai fait plusieurs essais) comme j'ai pu l'observer dans le terminal

```bash
════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  17/17
Time:           46.42s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
La taille du fichier était de **76Ko** comme j'ai pu l'observer dans le terminal

```bash
-rwxrwxr-x 1 ben-salem ben-salem 76K Sep 12 22:01 ../../Build/Bin/Release-Linux/MonEssai/MonEssai
```

## Resume

1. **Tableau comparatif des 4 nombres**

| Configuration | Temps de construction | Taille du binaire |
| :--- | :--- | :--- |
| **Debug** | 54.02s | 568Ko |
| **Release** | 46.42s | 76Ko |

---

2. **Explication des résultats par le fichier `.jenga`**

Les 4 nombres mesurés ci-dessus s'expliquent directement par les instructions suivantes du fichier `MonEssai.jenga` :

```python
with filter("config: Debug") :
    defines(["_DEBUG"]); optimize("Off"); symbols(True)

with filter("config: Release") :
    defines(["NDEBUG"]); optimize("Speed"); symbols(False)
```