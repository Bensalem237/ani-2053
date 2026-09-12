# Exercice 2
En tapant les commandes :

```bash
 dir -Recurse -Include *.cpp,*.h -File | Where-Object { $_.FullName -notmatch "\\build\\" } | Get-Content | Measure-Object -Line
```
pour le nombres de lignes, et

```bash
 dir -Recurse -Include *.cpp,*.h -File | Where-Object { $_.FullName -notmatch "\\build\\" } | Get-Content | Measure-Object -Line
```
pour le nombres de fichiers, j'ai obtenu les informations suivantes :

## Observations
Dans le dépot `Nkentseu`, j'ai pu compter **1 623 115** et **3946** fichiers, alors que le livre nous parle de **1 193 385**, et **2 641** fichiers.

## Explication
Cette différence est probablement due à la prise en compte des fichiers en-tete dans chaque sous répertoire du dépot dans mes comptes, sauf pour le dossier `Build`, mais aussi par la présence de nouveaux projets développés avec NkCanvas.