# Exercice 9 : L'histoire d'un fichier

fichier choisi : **Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp**

## Historique

J'ai obtenu l'historique des commits du fichier grace à la commande suivante

```
git log --oneline -- Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp
```

**Sortie :**
```
addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)
5acdfe58 RebuildEdges : de super-quadratique a lineaire, et Catmull-Clark cesse de dependre de l ordre des seaux
f20dacbb Les cinq modificateurs et SpinSelected transportent le materiau -- le trou etait dans le BANC, et la mesure de cout a trouve autre chose que ce qu elle cherchait
fb0bc119 POINT DE REPRISE (coupure de courant) : chanfrein et extrusion d aretes heritent des faces VOISINES -- etat non verifie, ni compile ni mesure
4881bf4a NkEditMesh : l ombrage par face HERITE DE SA MERE, par la MEME entree que le materiau -- et la note qui disait qu il survivait deja etait fausse
8924f483 NkEditMesh : la regle de fusion du materiau est cablee (dominant par l aire, egalite par l indice le plus bas) -- et la MESURE a deplace le probleme : la decimation ne fusionnait rien, elle EFFACAIT tout
5e3b8f0f NkEditMesh : huit operations de plus transportent le materiau par face (12 au total) -- et TROIS refusees avec leur raison : dissolve et bevel fusionnent ou creent des faces sans face mere, alignement non prouvable
1fb809ce NkEditMesh : le materiau par face survit a SIX operations de plus -- suppression, faire-face, extrusion de sommets, coupe de boucle, coupe par plan, revolution. 7 cas matops/, tous rouges avant (slot1 -> 0)
c0dd45a2 NKRenderer/Mesh : le materiau par face survit aussi a la SOUDURE (cas mat/survie-soudure, rouge avant : slot1 2->0 avec 24->8 sommets)
942fae39 NKRenderer/Mesh : materiau PAR FACE facon Blender -- index sur Face, slots sur le maillage, sous-mailles DEDUITES, et survie prouvee a la subdivision/Catmull/extrusion (11 cas de banc, rouges avant)
332ae4f8 NK3DModeler : refonte d'interface, import OBJ, selection liee et mode objet (#62)
51a8d845 14 modificateurs de plus : 3 -> 17 types, 36 parametres animables
f0a1a84c Pile de modificateurs : empiler, reordonner, dupliquer, retirer, APPLIQUER — et tout parametre adressable par NOM
664af37e Subdivision Surface : vraie CATMULL-CLARK — le modificateur ne lissait rien
7496f362 BMesh etape 2 : cycle RADIAL et cycle DISQUE — le non-manifold cesse d'etre invisible
0ccdc02f Merge At First / At Last suivent enfin l'ORDRE DES GESTES, plus l'ordre des indices
6f218b4f Proportional editing + symetrie de maillage (LOT 5)
bc8f3f35 Extrude : variantes Along Normals et To Cursor (LOT 4)
8c11624c Merge : At Cursor, Collapse et By Distance, facon Blender
afcefb78 BMesh etape 1 : l'arete devient une entite — F sur 2 sommets cree un segment
ed80d5b8 Edition : l'aller-retour redonne le maillage a l'identique
b11713fb Edition : l'ombrage smooth survit a un aller-retour en mode edition
d7b759f0 fix(editmode): clignotement wireframe (ring par frame), souris capturee en modal, face F correcte, slide loop cut, apercu -35%
b7cf176d feat(editmode): pick fiable sous tout angle, wireframe n-gon toute la scene, cadre modal interactif + To Sphere / Shrink-Fatten
5d7ffaa1 fix(editmode): artefacts de carres blancs qui masquaient l'objet (overlay explose pres du plan near)
ca0bca7d feat(editmode): bevel, inset, edge split, spin, dissolve + enregistrement des apps NKAI manquantes
417093ae feat(editmode): ombrage Flat/Smooth par face + les 5 points de pivot Blender (avec curseur 3D)
e6580e2d fix(editmode): AABB monde du mesh edite (cage plus detachee) + boucle Alt+clic correcte (regles de valence)
cabdcb38 feat(editmode): outils de selection facon Blender (boucle Alt+clic, rectangle, lasso, cercle)
35d10cd4 fix(editmode): soudure topologique (loop cut fait le tour), selection vertex visible, gizmo ne bloque plus le clic
2cf4a9f6 feat(editmode): wireframe n-gon (plus de diagonale quad), viz Blender (fill orange faces), orientation Normal, extrude verts/edges
bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
9373b69d feat(editor): stack de modificateurs NON-DESTRUCTIF (Mirror/Array/Subsurf) — NkModifierStack::Evaluate + apercu live (F7/F8/F9 ajouter, F10 vider)
c4bba029 feat(editor): rejeu P PAS-A-PAS (une commande/appui, reconstruction visible) + serialisation binaire du journal (NkMeshEditRecorder Serialize/Deserialize)
6e9c005e feat(editor): couche de commandes SCRIPTABLE — NkMeshEditCommand (donnee) + NkMeshEditRecorder (journal/rejeu depuis base) ; fondation modificateurs + donnees IA
fa0c9d9c feat(editor): undo/redo d'edition (NkEditHistory memento) + historisation des 7 commandes + deplacement de sommets
6c8153a6 refactor(editor): couche de commandes d'edition dans NkEditMesh (ops parametrees, base undo/modificateurs/IA)
ba3b0507 feat(editor): editeur de maillage facon Blender + structure n-gon half-edge (NkEditMesh) (#21)
```

## Reconstitution du fichier initial

Pour reconstituer le fichier initial, j'ai tapé la commande suivante

```bash
git show ba3b0507:Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp > fichier_origine.cpp
```

Ensuite, je l'ai récupéré dans la racine du projet.

Voici le contenu initial du fichier
```cpp
// =============================================================================
// NkEditMesh.cpp — NKRenderer — maillage éditable demi-arête (n-gon)
// =============================================================================
#include "NkEditMesh.h"
#include "NKContainers/Associative/NkHashMap.h"

namespace nkentseu {
    namespace renderer {

        void NkEditMesh::BuildFromIndexed(const NkVertex3D* v, uint32 vc,
                                          const uint32* idx, uint32 ic, bool quadify) {
            Clear();
            verts.Resize(vc);
            for (uint32 i=0;i<vc;i++){
                verts[i].pos=v[i].pos; verts[i].normal=v[i].normal; verts[i].uv=v[i].uv;
                verts[i].hedge=NK_EM_INVALID; verts[i].sel=0;
            }
            const uint32 triCount = ic/3;
            faces.Reserve(triCount);
            hedges.Reserve(ic);
            for (uint32 t=0;t<triCount;t++){
                const uint32 a=idx[t*3], b=idx[t*3+1], c=idx[t*3+2];
                const NkEmId f  = (NkEmId)faces.Size();
                const NkEmId h0 = (NkEmId)hedges.Size(), h1=h0+1, h2=h0+2;
                Hedge e0,e1,e2;
                e0.origin=a; e0.next=h1; e0.face=f;
                e1.origin=b; e1.next=h2; e1.face=f;
                e2.origin=c; e2.next=h0; e2.face=f;
                hedges.PushBack(e0); hedges.PushBack(e1); hedges.PushBack(e2);
                Face fc; fc.hedge=h0; fc.alive=1; faces.PushBack(fc);
                if (verts[a].hedge==NK_EM_INVALID) verts[a].hedge=h0;
                if (verts[b].hedge==NK_EM_INVALID) verts[b].hedge=h1;
                if (verts[c].hedge==NK_EM_INVALID) verts[c].hedge=h2;
            }
            LinkTwins();
            RecomputeNormals();
            if (quadify) Quadify();
        }

        uint32 NkEditMesh::FaceSize(NkEmId f) const {
            if (f>=(NkEmId)faces.Size() || !faces[f].alive) return 0;
            const NkEmId start=faces[f].hedge; if (start==NK_EM_INVALID) return 0;
            NkEmId h=start; uint32 n=0, guard=0;
            do { ++n; h=hedges[h].next; if(++guard>100000u) break; } while(h!=start && h!=NK_EM_INVALID);
            return n;
        }

        void NkEditMesh::Quadify(float32 coplanarDot) {
            // Paires de triangles CONSÉCUTIFS (issus de la triangulation quad-par-quad).
            for (uint32 f1=0; f1+1<(uint32)faces.Size(); f1+=2){
                const uint32 f2=f1+1;
                if (!faces[f1].alive || !faces[f2].alive) continue;
                if (FaceSize(f1)!=3 || FaceSize(f2)!=3) continue;
                if (faces[f1].normal.Dot(faces[f2].normal) < coplanarDot) continue;
                // Demi-arête partagée h (dans f1) dont le twin est dans f2.
                NkEmId h=NK_EM_INVALID, start=faces[f1].hedge, hh=start; uint32 guard=0;
                do { const NkEmId tw=hedges[hh].twin;
                     if (tw!=NK_EM_INVALID && hedges[tw].alive && hedges[tw].face==f2){ h=hh; break; }
                     hh=hedges[hh].next; } while(hh!=start && ++guard<100000u);
                if (h==NK_EM_INVALID) continue;            // triangles non adjacents
                const NkEmId tw=hedges[h].twin;
                const NkEmId hA=hedges[h].next,  hB=hedges[hA].next;   // f1 : b->c, c->a
                const NkEmId hC=hedges[tw].next, hD=hedges[hC].next;   // f2 : a->d, d->b
                hedges[hB].next=hC; hedges[hD].next=hA;                // recoud la boucle quad
                hedges[hA].face=f1; hedges[hB].face=f1; hedges[hC].face=f1; hedges[hD].face=f1;
                faces[f1].hedge=hA; faces[f2].alive=0;
                const uint32 a=hedges[h].origin, b=hedges[tw].origin;
                hedges[h].alive=0; hedges[tw].alive=0;
                hedges[h].face=NK_EM_INVALID; hedges[tw].face=NK_EM_INVALID;
                verts[a].hedge=hC; verts[b].hedge=hA;                  // repointe (h/tw morts)
            }
            RecomputeNormals();
        }

        void NkEditMesh::LinkTwins() {
            NkHashMap<uint64, NkEmId> map; map.Reserve((uint32)hedges.Size());
            for (uint32 h=0; h<(uint32)hedges.Size(); ++h){
                const uint32 o = hedges[h].origin;
                const uint32 d = hedges[hedges[h].next].origin;
                const uint64 opp = ((uint64)d<<32) | (uint64)o;   // demi-arête opposée (d->o)
                NkEmId* found = map.Find(opp);
                if (found){ hedges[h].twin = *found; hedges[*found].twin = h; }
                else       { map.InsertOrAssign(((uint64)o<<32)|(uint64)d, h); }
            }
        }

        void NkEditMesh::GetFaceVerts(NkEmId f, NkVector<NkEmId>& out) const {
            out.Clear();
            if (f>=(NkEmId)faces.Size()) return;
            const NkEmId start = faces[f].hedge;
            if (start==NK_EM_INVALID) return;
            NkEmId h=start; uint32 guard=0;
            do {
                out.PushBack(hedges[h].origin);
                h = hedges[h].next;
                if (++guard > 100000u) break;      // garde-fou (topologie cassée)
            } while (h!=start && h!=NK_EM_INVALID);
        }

        void NkEditMesh::RecomputeNormals() {
            for (uint32 i=0;i<(uint32)verts.Size();++i) verts[i].normal = {0.f,0.f,0.f};
            NkVector<NkEmId> loop;
            for (uint32 f=0; f<(uint32)faces.Size(); ++f){
                if (!faces[f].alive) continue;
                loop.Clear(); GetFaceVerts(f, loop);
                if (loop.Size()<3) continue;
                const NkVec3f p0=verts[loop[0]].pos, p1=verts[loop[1]].pos, p2=verts[loop[2]].pos;
                NkVec3f n = (p1-p0).Cross(p2-p0);          // pondéré par l'aire (non normalisé)
                float32 l=n.Len(); faces[f].normal = (l>1e-8f)? n*(1.f/l) : NkVec3f{0.f,1.f,0.f};
                for (uint32 k=0;k<(uint32)loop.Size();++k) verts[loop[k]].normal = verts[loop[k]].normal + n;
            }
            for (uint32 i=0;i<(uint32)verts.Size();++i){
                float32 l=verts[i].normal.Len();
                verts[i].normal = (l>1e-8f)? verts[i].normal*(1.f/l) : NkVec3f{0.f,1.f,0.f};
            }
        }

        void NkEditMesh::GetUniqueEdges(NkVector<uint32>& outPairs) const {
            outPairs.Clear();
            for (uint32 h=0; h<(uint32)hedges.Size(); ++h){
                if (!hedges[h].alive) continue;         // arête interne dissoute (quadify)
                const NkEmId tw = hedges[h].twin;
                if (tw==NK_EM_INVALID || h < tw){       // une seule des deux demi-arêtes
                    const uint32 o = hedges[h].origin;
                    const uint32 d = hedges[hedges[h].next].origin;
                    outPairs.PushBack(o); outPairs.PushBack(d);
                }
            }
        }

        void NkEditMesh::Triangulate(NkVector<NkVertex3D>& outV, NkVector<uint32>& outIdx,
                                     NkVector<NkEmId>& outTriFace) const {
            outV.Clear(); outIdx.Clear(); outTriFace.Clear();
            outV.Resize((uint32)verts.Size());
            for (uint32 i=0;i<(uint32)verts.Size();++i){
                NkVertex3D nv{};
                nv.pos=verts[i].pos; nv.normal=verts[i].normal; nv.tangent={1.f,0.f,0.f};
                nv.uv=verts[i].uv; nv.uv2={0.f,0.f}; nv.color=0xFFFFFFFFu;
                outV[i]=nv;
            }
            NkVector<NkEmId> loop;
            for (uint32 f=0; f<(uint32)faces.Size(); ++f){
                if (!faces[f].alive) continue;
                loop.Clear(); GetFaceVerts(f, loop);
                if (loop.Size()<3) continue;
                for (uint32 i=1; i+1<(uint32)loop.Size(); ++i){   // éventail
                    outIdx.PushBack(loop[0]); outIdx.PushBack(loop[i]); outIdx.PushBack(loop[i+1]);
                    outTriFace.PushBack((NkEmId)f);
                }
            }
        }

        void NkEditMesh::ToPolygons(NkVector<NkVertex3D>& ov, NkVector<uint32>& ofaceStart,
                                    NkVector<uint32>& ofaceVerts) const {
            ov.Resize((uint32)verts.Size());
            for (uint32 i=0;i<(uint32)verts.Size();++i){
                NkVertex3D nv{};
                nv.pos=verts[i].pos; nv.normal=verts[i].normal; nv.tangent={1.f,0.f,0.f};
                nv.uv=verts[i].uv; nv.uv2={0.f,0.f}; nv.color=0xFFFFFFFFu;
                ov[i]=nv;
            }
            ofaceStart.Clear(); ofaceVerts.Clear();
            ofaceStart.PushBack(0);
            NkVector<NkEmId> loop;
            for (uint32 f=0; f<(uint32)faces.Size(); ++f){
                if (!faces[f].alive) continue;
                loop.Clear(); GetFaceVerts(f, loop);
                if (loop.Size()<3) continue;
                for (uint32 k=0;k<(uint32)loop.Size();++k) ofaceVerts.PushBack(loop[k]);
                ofaceStart.PushBack((uint32)ofaceVerts.Size());
            }
        }

        void NkEditMesh::BuildFromPolygons(const NkVertex3D* v, uint32 vc,
                                           const uint32* faceStart, uint32 faceCount, const uint32* faceVerts) {
            Clear();
            verts.Resize(vc);
            for (uint32 i=0;i<vc;++i){
                verts[i].pos=v[i].pos; verts[i].normal=v[i].normal; verts[i].uv=v[i].uv;
                verts[i].hedge=NK_EM_INVALID; verts[i].sel=0;
            }
            for (uint32 f=0; f<faceCount; ++f){
                const uint32 s=faceStart[f], e=faceStart[f+1], n=e-s;
                if (n<3) continue;
                const NkEmId h0=(NkEmId)hedges.Size();
                for (uint32 k=0;k<n;++k){
                    Hedge he; he.origin=faceVerts[s+k]; he.next=h0+((k+1)%n); he.face=(NkEmId)faces.Size(); he.alive=1;
                    hedges.PushBack(he);
                    if (verts[faceVerts[s+k]].hedge==NK_EM_INVALID) verts[faceVerts[s+k]].hedge=h0+k;
                }
                Face fc; fc.hedge=h0; fc.alive=1; faces.PushBack(fc);
            }
            LinkTwins();
            RecomputeNormals();
        }

    } // namespace renderer
} // namespace nkentseu
```

## Les trois moments ou le fichier a le plus changé

Pour connaitre les trois commits ou le fichier a subi le plus de transformations, j'ai utilisé la commande suivante

```bash
git log --stats --oneline -- Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp
```

**sortie :**
```
addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 1144 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++--------
 1 file changed, 1014 insertions(+), 130 deletions(-)
5acdfe58 RebuildEdges : de super-quadratique a lineaire, et Catmull-Clark cesse de dependre de l ordre des seaux
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 29 ++++++++++++++++++++++++++---
 1 file changed, 26 insertions(+), 3 deletions(-)
f20dacbb Les cinq modificateurs et SpinSelected transportent le materiau -- le trou etait dans le BANC, et la mesure de cout a trouve autre chose que ce qu elle cherchait
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 199 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++--------
 1 file changed, 178 insertions(+), 21 deletions(-)
fb0bc119 POINT DE REPRISE (coupure de courant) : chanfrein et extrusion d aretes heritent des faces VOISINES -- etat non verifie, ni compile ni mesure
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 207 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-----
 1 file changed, 193 insertions(+), 14 deletions(-)
4881bf4a NkEditMesh : l ombrage par face HERITE DE SA MERE, par la MEME entree que le materiau -- et la note qui disait qu il survivait deja etait fausse
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 195 ++++++++++++++++++++++++++++++++++++++++++++++--------------------------
 1 file changed, 124 insertions(+), 71 deletions(-)
8924f483 NkEditMesh : la regle de fusion du materiau est cablee (dominant par l aire, egalite par l indice le plus bas) -- et la MESURE a deplace le probleme : la decimation ne fusionnait rien, elle EFFACAIT tout
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 225 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++---
 1 file changed, 217 insertions(+), 8 deletions(-)
5e3b8f0f NkEditMesh : huit operations de plus transportent le materiau par face (12 au total) -- et TROIS refusees avec leur raison : dissolve et bevel fusionnent ou creent des faces sans face mere, alignement non prouvable
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 25 ++++++++++++++++++++-----
 1 file changed, 20 insertions(+), 5 deletions(-)
1fb809ce NkEditMesh : le materiau par face survit a SIX operations de plus -- suppression, faire-face, extrusion de sommets, coupe de boucle, coupe par plan, revolution. 7 cas matops/, tous rouges avant (slot1 -> 0)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 89 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-------------
 1 file changed, 74 insertions(+), 15 deletions(-)
c0dd45a2 NKRenderer/Mesh : le materiau par face survit aussi a la SOUDURE (cas mat/survie-soudure, rouge avant : slot1 2->0 avec 24->8 sommets)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 11 +++++++++--
 1 file changed, 9 insertions(+), 2 deletions(-)
942fae39 NKRenderer/Mesh : materiau PAR FACE facon Blender -- index sur Face, slots sur le maillage, sous-mailles DEDUITES, et survie prouvee a la subdivision/Catmull/extrusion (11 cas de banc, rouges avant)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 144 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-----
 1 file changed, 135 insertions(+), 9 deletions(-)
332ae4f8 NK3DModeler : refonte d'interface, import OBJ, selection liee et mode objet (#62)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 131 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 131 insertions(+)
51a8d845 14 modificateurs de plus : 3 -> 17 types, 36 parametres animables
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 582 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 582 insertions(+)
f0a1a84c Pile de modificateurs : empiler, reordonner, dupliquer, retirer, APPLIQUER — et tout parametre adressable par NOM
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 207 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 207 insertions(+)
664af37e Subdivision Surface : vraie CATMULL-CLARK — le modificateur ne lissait rien
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 269 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
 1 file changed, 268 insertions(+), 1 deletion(-)
7496f362 BMesh etape 2 : cycle RADIAL et cycle DISQUE — le non-manifold cesse d'etre invisible
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 205 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++---
 1 file changed, 198 insertions(+), 7 deletions(-)
0ccdc02f Merge At First / At Last suivent enfin l'ORDRE DES GESTES, plus l'ordre des indices
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 92 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++------
 1 file changed, 85 insertions(+), 7 deletions(-)
6f218b4f Proportional editing + symetrie de maillage (LOT 5)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 157 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 157 insertions(+)
bc8f3f35 Extrude : variantes Along Normals et To Cursor (LOT 4)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 61 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++--
 1 file changed, 59 insertions(+), 2 deletions(-)
8c11624c Merge : At Cursor, Collapse et By Distance, facon Blender
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 132 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-----
 1 file changed, 124 insertions(+), 8 deletions(-)
afcefb78 BMesh etape 1 : l'arete devient une entite — F sur 2 sommets cree un segment
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 153 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 153 insertions(+)
ed80d5b8 Edition : l'aller-retour redonne le maillage a l'identique
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 96 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-------------
 1 file changed, 80 insertions(+), 16 deletions(-)
b11713fb Edition : l'ombrage smooth survit a un aller-retour en mode edition
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 25 +++++++++++++++++++++++++
 1 file changed, 25 insertions(+)
d7b759f0 fix(editmode): clignotement wireframe (ring par frame), souris capturee en modal, face F correcte, slide loop cut, apercu -35%
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 130 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-----
 1 file changed, 121 insertions(+), 9 deletions(-)
b7cf176d feat(editmode): pick fiable sous tout angle, wireframe n-gon toute la scene, cadre modal interactif + To Sphere / Shrink-Fatten
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 174 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
 1 file changed, 173 insertions(+), 1 deletion(-)
5d7ffaa1 fix(editmode): artefacts de carres blancs qui masquaient l'objet (overlay explose pres du plan near)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 33 ++++++++++++++++++++++++++++++++-
 1 file changed, 32 insertions(+), 1 deletion(-)
ca0bca7d feat(editmode): bevel, inset, edge split, spin, dissolve + enregistrement des apps NKAI manquantes
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 1248 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
 1 file changed, 1247 insertions(+), 1 deletion(-)
417093ae feat(editmode): ombrage Flat/Smooth par face + les 5 points de pivot Blender (avec curseur 3D)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 194 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----
 1 file changed, 184 insertions(+), 10 deletions(-)
e6580e2d fix(editmode): AABB monde du mesh edite (cage plus detachee) + boucle Alt+clic correcte (regles de valence)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 180 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++--------------
 1 file changed, 147 insertions(+), 33 deletions(-)
cabdcb38 feat(editmode): outils de selection facon Blender (boucle Alt+clic, rectangle, lasso, cercle)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 93 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 93 insertions(+)
35d10cd4 fix(editmode): soudure topologique (loop cut fait le tour), selection vertex visible, gizmo ne bloque plus le clic
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 94 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++--------
 1 file changed, 84 insertions(+), 10 deletions(-)
2cf4a9f6 feat(editmode): wireframe n-gon (plus de diagonale quad), viz Blender (fill orange faces), orientation Normal, extrude verts/edges
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 270 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++---------
 1 file changed, 237 insertions(+), 33 deletions(-)
bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 1954 ++++++++++++++++++++++++++++++++++++++++++++++-------------------------
 1 file changed, 1273 insertions(+), 681 deletions(-)
9373b69d feat(editor): stack de modificateurs NON-DESTRUCTIF (Mirror/Array/Subsurf) — NkModifierStack::Evaluate + apercu live (F7/F8/F9 ajouter, F10 vider)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 62 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 62 insertions(+)
c4bba029 feat(editor): rejeu P PAS-A-PAS (une commande/appui, reconstruction visible) + serialisation binaire du journal (NkMeshEditRecorder Serialize/Deserialize)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 65 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 65 insertions(+)
6e9c005e feat(editor): couche de commandes SCRIPTABLE — NkMeshEditCommand (donnee) + NkMeshEditRecorder (journal/rejeu depuis base) ; fondation modificateurs + donnees IA
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 39 +++++++++++++++++++++++++++++++++++++++
 1 file changed, 39 insertions(+)
fa0c9d9c feat(editor): undo/redo d'edition (NkEditHistory memento) + historisation des 7 commandes + deplacement de sommets
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 36 ++++++++++++++++++++++++++++++++++++
 1 file changed, 36 insertions(+)
6c8153a6 refactor(editor): couche de commandes d'edition dans NkEditMesh (ops parametrees, base undo/modificateurs/IA)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 289 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 289 insertions(+)
ba3b0507 feat(editor): editeur de maillage facon Blender + structure n-gon half-edge (NkEditMesh) (#21)
 Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 198 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
1 file changed, 198 insertions(+)
```

On peut voir que le fichier a subi le plus de modifications dans les commits suivants :

```
bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 1954 modifications
```

```
ca0bca7d feat(editmode): bevel, inset, edge split, spin, dissolve + enregistrement des apps NKAI manquantes
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 1248 modifications
```

```
addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)
Kernel/Runtime/NKRenderer/src/NKRenderer/Mesh/NkEditMesh.cpp | 1144 modifications
```

Les messages donnent des raisons claires pour ces grands nombres de changements

1. **Commit bdda350a** : Le message indique que le code n'a pas subi de modifications fonctionnelles, mais un reformatage complet du code. Ceci veut dire que prèsque chaque ligne du code a probablement été modifiée (formatée).

2. **Commit ca0bca7d** : Ce message nous informe d'un majeur développement fonctionnel du projet (bevel, inset...) ceci peut expliquer le grand nombre de modifications.

3. **Commit addf709d** : Ce message informe de la fusion avec un autre module développé en parallèle. Ce qui peut indiquer le grand nombre de changements.