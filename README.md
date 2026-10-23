# 🌱 Awalé en C

Implémentation en console du jeu d'**Awalé**, jeu de stratégie traditionnel africain, écrite en langage C.

Projet réalisé en première année de cycle pré-ingénieur à **UniLaSalle Amiens** (module *Algorithme I1*, 2023), à deux, en 16 heures de cours.

> 👥 **Auteurs** : Corentin Nicole · Dorian Eugene

---

## 📸 Aperçu

```
┌-------------------------------------┐
|--[4]---[4]---[4]---[4]---[4]---[4]--|    <== Joueur 1
├-------------------------------------┤
|--[4]---[4]---[4]---[4]---[4]---[4]--|    <== Joueur 2
└-------------------------------------┘

JOUEUR 1 PTS : 0 / JOUEUR 2 PTS : 0
```

---

## 🎯 Fonctionnalités

- Menu principal : afficher les règles, lancer une partie, quitter
- Partie à deux joueurs sur le même terminal (tour par tour)
- Affichage du plateau et des scores après chaque coup
- Vérification des saisies (case dans son camp, non vide)
- Calcul du score final et annonce du vainqueur (ou de l'égalité)

---

## 🚀 Compilation et lancement

Prérequis : un compilateur C (GCC ou Clang).

```bash
# Compilation
gcc -Wall -Wextra -o awale awale.c

# Lancement
./awale          # Linux / macOS
awale.exe        # Windows
```

> 💡 Le programme utilise des accents et des caractères de dessin (`┌ ├ └`). Sous Windows, si l'affichage est cassé, exécute `chcp 65001` dans le terminal avant de lancer le jeu.

---

## 🕹️ Comment jouer

Le plateau est un tableau de 12 cases. Chaque joueur contrôle une rangée de 6 cases :

```
|--[N°1]----[N°2]----[N°3]----[N°4]---[N°5]---[N°6]--|    <== Joueur 1
|--[N°12]---[N°11]---[N°10]---[N°9]---[N°8]---[N°7]--|    <== Joueur 2
```

1. Au départ, chaque case contient **4 graines**.
2. À son tour, on choisit une case **de son camp** contenant au moins une graine, et on saisit son numéro.
3. Les graines de cette case sont **semées une par une** dans les cases suivantes.
4. Quand une case adverse contenant 1 ou 2 graines reçoit une graine (elle en compte alors **2 ou 3**), elle est **capturée** : ses graines vont dans le score du joueur.
5. La partie s'arrête quand un joueur n'a plus de graines dans sa rangée. Les graines restantes sont ajoutées au score du joueur dont elles occupent la rangée.
6. Le joueur avec le plus de graines gagne.

---

## 🗂️ Structure du code

| Fonction | Rôle |
|---|---|
| `bienvenue()` | Message d'accueil |
| `affiche_regle()` | Affiche les règles du jeu |
| `affiche_plateau()` | Affiche le plateau |
| `affichage()` | Affiche les scores des deux joueurs |
| `remplissage_tab()` | Initialise le plateau (4 graines par case) |
| `jouer_()` | Cœur du jeu : semis des graines, captures, mise à jour des scores |
| `boucle()` | Gère la circularité du plateau |
| `retirer_grn()` | Détermine si une case est capturée ou reçoit une graine |
| `ajt_pts()` / `sauv_()` | Calcul des points gagnés lors d'une capture |
| `verif_j1()` / `verif_j2()` | Validation de la saisie de chaque joueur |
| `nb_pts_total()` | Calcul du score final (captures + graines restantes) |
| `victoire_points()` | Annonce du vainqueur |
| `menu()` | Menu principal et boucle de partie |

Les algorigrammes (réalisés avec Lucidchart) et le rapport complet du projet sont dans le dossier [`docs/`](docs/).

---

## ⚠️ Limites connues

Ce projet étant un travail de première année, il simplifie certaines règles de l'Awalé officiel :

- la capture est testée à **chaque graine semée** dans le camp adverse, et non uniquement sur la dernière graine ;
- pas de capture en chaîne (cases précédentes consécutives de 2 ou 3 graines) ;
- pas de règle d'obligation de « nourrir » l'adversaire ni de case de départ sautée lors d'un semis de 12 graines ou plus ;
- une saisie non numérique peut bloquer la lecture (`scanf`) ;
- les cases à deux chiffres décalent légèrement l'affichage du plateau.

---

## 🔭 Pistes d'amélioration

- Saisie des pseudos des joueurs
- Affichage des prises de graines (ex. « prise double »)
- Découpage des grosses fonctions (`jouer_()`, `menu()`)
- Respect complet des règles officielles
- Mode solo contre une IA, puis interface graphique
