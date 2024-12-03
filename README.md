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

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/8881945/30cfa182-7ad2-4d0c-a551-ae7f567f2063/paste.txt
[2] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/8881945/0f010cb3-85d6-49de-b0b2-ac30bddb7869/paste.txt
[3] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/8881945/5d10a830-2180-470e-9b6d-ee55314b5e31/paste-2.txt
