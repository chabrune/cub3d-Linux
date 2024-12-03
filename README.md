# 🎮 Cub3D - Raycaster inspiré de Wolfenstein 3D

Un moteur 3D minimaliste utilisant la technique du raycasting, inspiré du légendaire Wolfenstein 3D.

## 🎯 Description

Cub3D est une implémentation d'un moteur de rendu 3D utilisant la technique du raycasting. Le projet permet de créer une vue dynamique dans un labyrinthe texturé.

## 🛠️ Fonctionnalités

### Contrôles
- **W A S D** : Déplacement
- **← →** : Rotation caméra
- **ESC** : Quitter

### Rendu
- Textures différentes pour chaque orientation (Nord, Sud, Est, Ouest)
- Couleurs distinctes pour sol et plafond
- Vue subjective fluide
- Gestion des collisions

### Format de Carte (.cub)
| Symbole | Description |
|---------|-------------|
| 1 | Mur |
| 0 | Espace vide |
| N/S/E/W | Position et orientation de départ |

## ⚙️ Spécifications Techniques

### Parsing
- Validation de carte
- Gestion des textures
- Configuration des couleurs RGB
- Gestion des erreurs

### Performance
- Optimisation du raycasting
- Gestion fluide des mouvements
- Pas de fuites mémoire

## 🌟 Bonus
- Minimap
- Collisions avec les murs
- Portes
- Sprites animés
- Rotation à la souris

---
*Projet réalisé dans le cadre du cursus de l'école 42* 🚀
