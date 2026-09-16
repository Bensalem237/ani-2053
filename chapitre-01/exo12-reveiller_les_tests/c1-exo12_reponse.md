# Exercice 12

## 1. Ligne désactivant la compilation et l'exécution des tests

Dans le fichier Nkentseu.jenga, la désactivation des tests unitaires est gérée au niveau de la déclaration du workspace : 
```python
Pythondutc(enable=True)
dute(enable=True)
```
* **dutc(enable=True) :** Disable Unit Test Compile — Force la désactivation de la compilation des projets de tests unitaires.
* **dute(enable=True) :** Disable Unit Test Execution — Force la désactivation de l'exécution automatique des tests lors du build.  Pour autoriser à nouveau la compilation et l'exécution des tests dans le workspace, il faut passer ces paramètres à False (ou commenter ces deux lignes) : 
```python
dutc(enable=False)
dute(enable=False)
```
## 2. Commande de lancement d'une suite de tests
Après avoir réactivé les tests dans Nkentseu.jenga, j'ai lancé l'exécution des tests d'un module (par exemple NKMath ou NKCore) via le terminal : 
```bash
Bashjenga test --project NKMath
```

## 3. Bilan d'exécution
Nombre de suites de tests existantes : 8
Nombre de suites exécutées : 8
Nombre de suites qui passent (réussies) : 8