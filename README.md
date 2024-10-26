# Lecteur RFID Externe Bluetooth

Ce projet permet de créer un lecteur RFID Bluetooth compatible avec App Inventor. Après la lecture d'un tag RFID, l'appareil envoie l'UUID du tag à une tablette via Bluetooth.

### Matériel recommandé
Cette configuration est conçue pour une carte **FireBeetle 2 ESP32-E DFR0654**. En cas d’utilisation d'une autre carte, les paramètres devront être ajustés.  
![FireBeetle 2 ESP32-E](https://www.gotronic.fr/ar-module-firebeetle-esp32-dfr0478-26810.jpg)

## Table des matières
1. [Pré-requis Logiciel](#logiciel)
2. [Matériel Requis](#matériel)
3. [Configuration et Installation](#installation)
4. [Personnalisation Bluetooth](#bluetooth)

---

## 1. Pré-requis Logiciel <a name="logiciel"></a>

### Configuration de l'IDE Arduino pour la carte FireBeetle ESP32
Suivez les étapes ci-dessous pour configurer l'IDE Arduino afin de travailler avec la carte FireBeetle 2 ESP32-E :
1. **Installer l’IDE Arduino**
2. **Ajouter le support ESP32** : dans Arduino, allez dans *Fichier > Préférences* et ajoutez l'URL JSON suivante pour le support de la carte : https://espressif.github.io/arduino-esp32/package_esp32_index.json
3.  **Charger la carte ESP32** : une fois le package installé, sélectionnez *Outils > Type de carte > FireBeetle 2 ESP32-E* dans l’IDE.

### Installation de la bibliothèque MFRC522
Pour activer le lecteur RFID, suivez ces étapes pour installer et configurer la bibliothèque MFRC522 :
1. Ouvrez l’IDE Arduino, puis allez dans *Croquis > Inclure une bibliothèque > Gérer les bibliothèques*.
2. Dans le gestionnaire de bibliothèques, recherchez **MFRC522** et installez la version disponible. ([GitHub](https://github.com/miguelbalboa/rfid))
3. **Modification du fichier `MFRC522Extended.cpp`** :
- Accédez au fichier situé dans `Documents > Arduino > Libraries > MFRC522 > src > MFRC522Extended.cpp`.
- À l’aide d’un éditeur de texte (ex. Notepad++), remplacez les lignes 824 et 847 par :
  ```cpp
  if (backData && (backLen != nullptr)) {
  ```
4. Fermez l’éditeur après avoir effectué les modifications.

5. **Ouverture et téléversement du programme** : ouvrez le fichier `.ino` fourni sur cette page et téléversez-le sur la carte en cliquant sur la flèche "→" dans l'IDE Arduino.

### Personnalisation du Bluetooth <a name="bluetooth"></a>
Pour renommer le périphérique Bluetooth :
- Modifiez la ligne suivante dans le fichier `.ino` :
  ```cpp
  SerialBT.begin("Box_001"); // Nom du Bluetooth
  ```
- Remplacez `"Box_001"` par le nom souhaité.

---

## 2. Matériel Requis <a name="matériel"></a>
Voici la liste du matériel nécessaire pour assembler ce projet, disponible chez [Gotronic.fr](https://www.gotronic.fr/).

| Composant                                   | Référence          |
|---------------------------------------------|--------------------|
| **Carte FireBeetle 2 ESP32-E**              | DFR0654 (ref 37420) |
| **Buzzer SV4**                              | ref 5465          |
| **LED 5 mm Rouge et Verte**                 | ref 3790, 3792    |
| **Support LED plastique 5 mm**              | LD501A            |
| **Module RFID TAG 13,56 MHz**               | GT138 (ref 35190) |
| **Interrupteur**                            | R1933A (ref 7050) |
| **Boîtier G400**                            | ref 11712         |
| **Fil de câblage souple 0,14 mm² x 10m**    | ref 49097         |
| **Gaine thermorétractable 1,6 mm**          | ref 8840          |

### Option : Ajout d'une batterie interne
Pour une alimentation autonome, vous pouvez ajouter :
- **Batterie LiPo 3,7 Vcc 1000 mAh** : ref 9742
- **Carte LiPo Rider Plus** : ref 36778

---

## 3. Configuration et Installation <a name="installation"></a>

Une fois le matériel assemblé, suivez les étapes d'installation ci-dessus pour la configuration logicielle et le téléversement du programme dans la carte FireBeetle. Assurez-vous de vérifier chaque composant pour une communication Bluetooth fluide avec l’application mobile.

---

N'hésitez pas à soumettre des *issues* ou des *pull requests* pour toute amélioration. Bon projet !

