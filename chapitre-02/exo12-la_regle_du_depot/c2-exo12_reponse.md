# Exercice 12 : La règle du dépot

**Voici les règles git du dépot :**

## Nommage des branches

* Le format standard de nommage des fichier sera **`<type>/<courte-description>`**

* ⚠️ Avec des tirets entre les mots et des lettres minuscules uniquement.

* ⚠️ Pas d'espacement entre les mots, ni de caractes spéciaux.

* Nous utiliseront les types suivants pour les taches spécifiées :
    * **feature**  pour l'ajout de nouvelles fonctionnalités.
    * **fix**  pour la correction d'un bug.
    * **hotfix** pour la correction d'un bug urgent.
    * **chore** pour une tache de maintenance.
    * **refactor** pour du refactoring du code sans modification fonctionnelle.
    * **release** pour preparer un version à publier.

## Contenu d'un commit

* Les commits seront structurés comme suit :

```
<type>(<portée>): <description courte>

[corps du message]

[pied de page]
```

* **⚠️ Règles à respecter :**
    * Séparer le sujet du corps par une ligne blanche.
    * Limiter le nombre de caractères du sujet à **50 max**.
    * Ne pas mettre de point à la fin de la ligne du sujet.
    * Utiliser l'impératif ou le present dans le sujet.
    * Liniter le monbre de caractères du corps à **72 max**.
    * Utiliser le corps pour indiquer le quoi et le pourquoi, et non pas le comment.

## Les relectures

Toutes les relectures seront effectuées par le chef d'équipe.

## Les interdits

1. **Laisser de grands blocs de code morts ou commentés.** Git conserve déja l'historique donc le code mort doit. etre supprimé.

2. **Pousser des dossiers de configuration locale.** On doit les inscrire dans le `.gitignore`.

3. **Mélange de sujets dans un commit.**

4. **Faire des commits directement sur la branche principale**

## Ce qui se passe quand la branche principale est cassée

1. **Arreter de merge comme cela pourrait rendre le diagnostic plus difficile.**

2. **Identifier le commit fautif (`git log --oneline -n 10`, ou `git bisect` si le commit est difficile à retrouver).**

3. **Ouvrir une branche de type hotfix.**

4. **Annuler le commit fautif `git revert <id_du_commit_fautif>`.**

5. **Lancer un pull request et fusionner immédiatement.**

6. **Pas de chase aux sorcière. Casser la branche principale peut arriver à tout le monde, l'erreur est humaine**

7. **Tout le monde endosse la responsabilité, ce n'est pas seulement le problème de celui qui a cassé la branche principale.