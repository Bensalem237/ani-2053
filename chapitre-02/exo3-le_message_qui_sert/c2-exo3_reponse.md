# Exercice 3 : Le message qui sert

Pour obtenir les trois commits et leurs messages, j'ai tapé la commande suivante
```bash
git log -n 3
```

## Premier commit
```
commit 6fb634fcd23141392b32df4a79c741aa7bfcacb3 (HEAD -> papa, main)
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Sep 10 18:29:53 2026 +0100

    NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle
    
    Le web tenait jusqu'ici en une case de la phase 9 : « Portage tactile/web (le
    moteur le permet) ». Il a maintenant une DATE et un USAGE.
    
    Rodolf, le 10 septembre 2026 : la SESSION NORMALE de RIHEN Academy se compose sur
    la plateforme, en salle surveillee, sur des epreuves de trois heures minimum, a
    la mi-janvier. « Si NKCode fonctionne sur le web, alors ca va ouvrir une page
    pour NKCode ou coder. » Cinquante machines dont on ne maitrise aucune, ou une
    page.
    
    CE N'EST PAS UN PORTAGE, C'EST UNE SEPARATION. Compiler du C++ natif dans un
    onglet est impossible -- bac a sable du navigateur, pas limite de Nkentseu -- or
    c'est la raison d'etre de NKCode. La phase decolle donc ce qui EDITE de ce qui
    CONSTRUIT, et cette separation vaut aussi en natif : construction distante, ferme
    de compilation, integration continue. On ne travaille pas « pour le web », on
    separe deux choses qui n'auraient jamais du etre soudees.
    
    LA MOITIE MANQUANTE EXISTE DEJA. L'executeur de RIHEN Academy -- conteneur
    jetable, sans reseau, en lecture seule, non root, plafonne -- porte clang++,
    g++, make, cmake, Jenga et le kit Nkentseu. Mesure le 10 septembre : 2,7 secondes
    de mediane sur les 200 dernieres corrections.
    
    ET LE TERRAIN EST PLUS PREPARE QU'ON NE CROIT. NKWindow a un backend Emscripten
    REEL (2424 lignes contre 3384 pour Win32, retouche le 1er septembre) ; NKCanvas a
    un backend logiciel qui n'exige aucun GPU ; et la lecon de la boucle est deja
    apprise sur GemCrush -- « LA BOUCLE CEDE LA MAIN, sans quoi l'onglet Web gele ».
    
    L'ETAPE 0 EST DE MESURER LE POIDS, avant toute architecture. Un IDE en
    WebAssembly peut peser des dizaines de megaoctets, et les etudiants sont au
    Cameroun, souvent en donnees mobiles. C'est la seule etape dont le resultat peut
    annuler les suivantes : il vaut infiniment mieux l'apprendre en septembre qu'en
    janvier.

```

* **Dit-il ce qu'il fait?** Oui.
    * Dans ce message, l'auteur du message nous indique clairement l'objectif du commit. Il commence par poser le problème / l'en jeu : `"Compiler du C++ natif dans un onglet est impossible..."`.
    * Ensuite il détaille les moyens dont il dispose : `"LA MOITIE MANQUANTE EXISTE DEJA"`, et l'étendu des implémentations déja mises en place pour résoudre le problème dans ce commit : `"L'ETAPE 0"`.

* **Porte-t-il un seul sujet?** Oui, le message du commit porte uniquement sur l'intégration de NKCode dans la plateforme d'évaluation en ligne de Rihen Academy.

## Deuxième commit

```
commit c1c815ffceffc3b66d7661b1ebdf6ec2d23c6b6a
Author: LeTeguis <69282466+LeTeguis@users.noreply.github.com>
Date:   Thu Sep 10 17:48:09 2026 +0100

    CI : les huit epinglages de Jenga passent par JENGA_VERSION (#87)
    
    * CI : les huit epinglages de Jenga passent par JENGA_VERSION
    
    Le 8 septembre, build-remote.yml a cesse d'ecrire la version de Jenga a la
    main et s'est mis a lire Applications/NKCode/JENGA_VERSION. Les TROIS AUTRES
    workflows sont restes epingles sur `feat/evenement-avertissement`, une branche
    figee en Jenga 2.4.0. La source unique n'en etait donc pas une.
    
    Tant que NKCode n'employait aucune fonction recente, rien ne le revelait. La
    ligne beta.11 a rejoint main (PR #86), NKCode.jenga y emploie appurl(), et les
    douze jobs de build-gemcrush et build-jeux-plateau se sont arretes net sur :
    
        Error loading workspace: name 'appurl' is not defined
        Multi-platform C/C++ Build System v2.4.0
    
    Un message qui ne prononce jamais le mot « Jenga » et laisse croire a une
    faute dans le fichier de projet. La version etait imprimee juste dessous,
    personne ne l'a regardee.
    
    Chacun des neuf jobs lit desormais JENGA_VERSION avant de cloner Jenga, et
    s'epingle sur le tag correspondant. Verifie apres coup : YAML valide partout,
    et dans chaque job le clonage de Nkentseu precede la lecture, qui precede le
    clonage de Jenga.
    
    Le numero n'existe plus qu'a UN endroit. Une release de Jenga se propage en
    changeant une ligne, et un nom de branche remis ici redeviendrait la meme
    panne.
    
    * CI jeux de plateau : libasound2-dev manquait, quatre erreurs par jeu
    
    Une fois l'epinglage de Jenga corrige, les trois jobs Linux sont alles bien
    plus loin et se sont arretes sur de VRAIES erreurs de compilation :
    
        NkAudioBackends.cpp:31:10: fatal error: 'alsa/asoundlib.h' file not found
        NkAudioCapture.cpp:...:10: fatal error: 'alsa/asoundlib.h' file not found
    
    NkDames, NkEchecs et NkLudo dependent de NKAudio, dont le filtre Linux lie
    `asound`. Le workflow installait X11 et GL, jamais ALSA. build-gemcrush.yml
    l'installait deja, avec un commentaire qui dit exactement pourquoi : cette
    ligne-la n'a simplement jamais ete recopiee ici.
    
    build-macos.yml n'en a pas besoin : son job Linux construit NkRef, qui ne
    depend d'aucun audio. Verifie plutot que suppose.
```

* **Dit-t-il ce qu'il fait?** Oui.
    * L'auteur dans ce message Indique clairement les problèmes qui existaient dans le projet et les causes de ces problèmes : `"build-remote.yml a cesse d'ecrire la version de Jenga a la main et s'est mis a lire Applications/NKCode/JENGA_VERSION... ...Un message qui ne prononce jamais le mot « Jenga » et laisse croire a une faute dans le fichier de projet."`. 
    * Puis il indique la solution qui a été appliquée : `"Chacun des neuf jobs lit desormais JENGA_VERSION avant de cloner Jenga, et s'epingle sur le tag correspondant..."`.
    * Ensuite, il informe les utilisateurs qu'une fois l'epinglage de Jenga corrige, les erreurs liés à `alsa/asoundlib.h` sont des purs erreurs de compilation causés par l'abscence de la librairie `ASLA` dont l'installation n'est pas géré par son système.

* **Porte-t-il sur un seul sujet?** Oui. Bien qu'on ait l'impression que le message adresse deux problèmes, il ne résout en effet qu'un seul problème et explique le résultat qui en découle.

## Troisieme commit

```
commit 432850100b391c2251ec9bcb5a7e8d41afe0709e (origin/fix/nktraits-portable)
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Thu Sep 10 16:24:50 2026 +0100

    NkTraits : demander a la primitive si elle existe, pas au compilateur qui il est
    
    Neuf blocs s'ouvraient sur la meme condition :
    
        #if defined(__clang__) || defined(__GNUC__) || defined(_MSC_VER)
    
    Elle demande QUI est le compilateur au lieu de demander SI la primitive existe,
    et les deux ne sont pas la meme question. GCC definit __GNUC__, il entrait donc
    dans la branche des intrinseques -- mais g++ 12 ne connait pas
    __is_trivially_destructible. Sur les onze primitives de ce fichier, dix
    compilent avec g++ 12.2 et celle-la est refusee : il a suffi d'elle pour rendre
    NKCore dependant de clang, et avec lui tout ce qui l'inclut.
    
    Les branches de repli etaient pires que le defaut qu'elles couvraient. Elles ne
    sont pas conservatrices, elles sont fausses :
    
        NkIsTriviallyDestructible = true      <- pour TOUT type, destructeur compris
        NkIsBaseOf                : NkFalseType
        NkIsPolymorphic           : NkFalseType
        NkIsEmpty                 : sizeof(T) == 1
    
    La premiere est la dangereuse : un conteneur qui s'y fie saute les destructeurs.
    Un compilateur inconnu ne recevait pas une erreur, il recevait des fuites
    silencieuses -- et une reponse fausse coute toujours plus cher qu'un refus de
    compiler.
    
    Cascade a trois niveaux :
    
        1. la primitive, si le compilateur la porte      le plus direct
        2. std::, si <type_traits> est la                exact, et partout
        3. l'approximation existante                     pre-C++11 seulement
    
    Le niveau 2 n'est pas une concession au principe « sans dependance STL » annonce
    en tete de fichier : l'inclusion conditionnelle de <type_traits> existe DEJA
    « pour les fallbacks », et le fichier s'en sert quarante-neuf fois. On suit son
    motif, on n'en invente pas un second.
    
    MSVC est traite avant __has_builtin : il porte ces intrinseques depuis VS2015
    mais n'a __has_builtin que depuis VS2022, et repondrait « non » a des primitives
    qu'il possede. zig c++ EST clang, il suit clang sans rien de special.
    
    Eprouve dans l'image de correction de RIHEN Academy, meme montage des deux
    cotes, sur treize proprietes dont les valeurs attendues sont celles du standard
    et non celles d'une implementation :
    
        avant   g++ 12.2 REFUSE      clang++ 14 compile
        apres   g++ 12.2 compile     clang++ 14 compile     13/13 justes chacun
```

* **Dit-il ce qu'il fait?** Oui
    * L'auteur explique clairement le problème rencontré dans NKTraits :`"Elle demande QUI est le compilateur au lieu de demander SI la primitive existe"`. Et les problèmes qui se cachaient dessous.
    * Ensuite, il explique les mesures qui ont été mises en place dans le commit pour résoudre les problèmes (`"Cascade a trois niveaux"`).
* **Porte-t-il un seul sujet?** Oui, il porte sur un seul sujet car tous les autres problèmes relevés dans le message tombent sous le problème principal.

## Récriture du message du premier commit

NKCode : Intégration du web

Ben-salem, le 19 septembre 2026 : Le Web sort de se phase de polissage pour etre implémenté dans la platforme Rihen Academy au vu de la SESSION NORMALE de mi-janvier ou les étudiants vont devoir coder et compiler leur code sur la plateforme en ligne

CE N'EST PAS UN PORTAGE, C'EST UNE SEPARATION. Au vu de l'incapacité d'un navigateur à traduire du C++ natif, il est question ici de séparer ce qui édite de ce qui compile en deux couches distictes.

LA MOITIE MANQUANTE EXISTE DEJA. L'executeur de RIHEN Academy qui est un conteneur jetable, sans reseau, en lecture seule, non root, plafonne possède déja clang++, g++, make, cmake, Jenga et le kit Nkentseu. Mesuré le 10 septembre : 2,7 secondes de mediane sur les 200 dernieres corrections.

ET LE TERRAIN EST PLUS PREPARE QU'ON NE CROIT. NKWindow a un backend Emscripten
REEL (2424 lignes contre 3384 pour Win32, retouche le 1er septembre) ; NKCanvas a
un backend logiciel qui n'exige aucun GPU ; et la lecon de la boucle est deja
apprise sur GemCrush -- « LA BOUCLE CEDE LA MAIN, sans quoi l'onglet Web gele ».

L'ETAPE 0 EST DE MESURER LE POIDS, avant toute architecture, la première chose à faire serait de considérer les enjeux de cette methode. En effet, un IDE en WebAssembly peut peser des dizaines de megaoctets. de ce fait les problèmes de connexion internet sont à considérer.