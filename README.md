NB: les renseignements suivants sont donnés pour une carte Module FireBeetle 2 ESP32-E DFR0654 ([https://www.gotronic.fr/ar-module-firebeetle-esp32-dfr0478-26810.jpg)](https://www.gotronic.fr/art-module-firebeetle-esp32-dfr0478-26810.htm))
En cas de changement de carte, veuillez adapter les paramètres 


# Lecteur_RFID_Externe
Création d'un lecteur RFID Externe bluetooth compatible avec App Inventor. Après la lecture du tag rfid, le lecteur envoi l'UUID du tag à la tablette par bluetooth

# Software
## Etape 1: configurer l'IDE Arduino pour communiquer avec ma carte firebeetle ESP32:

Veuillez suivre la procédure DFROBOT 8 : https://wiki.dfrobot.com/FireBeetle_Board_ESP32_E_SKU_DFR0654 

1) Installer l'IDE

2) Configurer l'IDE pour la carte en ajoutant l'URL Json : https://espressif.github.io/arduino-esp32/package_esp32_index.json

3) Charger la carte ESP32 et selectionner Fire!beetle 2 ESP32-E

## Etape 2 : Installer la bibliothèque RC522

4) Ouvrez l’IDE Arduino et aller dans Croquis > Inclure une bibliothèque > Gérer les bibliothèques

5) Dans le gestionnaire de bibliothèques, rechercher « MFRC522 » et installer MFRC522 

6) Fermer la fenêtre une fois l’installation terminée.

## Etape 3: ouvrir le fichier .ino disponible sur cette page et le téléverser sur la carte (flèche "-> " dans l'IDE)


# Harware
## Matériel nécessaire:
Matériel trouvé chez [Gotronic.fr](https://www.gotronic.fr/)
	
	 Module FireBeetle 2 ESP32-E DFR0654 (ref 37420)
		
	 Buzzer SV4 (ref 5465)
		
	 Led 5 mm 5V Rouge + Verte (ref 3790, 3792)
		
	 Support led plastique 5 mm (ref LD501A)
		
	 Module RFID TAG 13,56 MHz GT138 (ref 35190)
		
	 Interrupteur R1933A (ref 7050)
		
	 Boîtiers série G400 (ref 11712)
	 	
	  Fil de câblage souple 0,14 mm²x10m (ref 49097)
		
	 Gaine thermorétractable 1,6 mm (ref 8840)

Si vous souhaitez y intégrer une batterie interne, vous devez ajouter:

	Accu LiPo 3,7 Vcc 1000 mAh PR523450 (ref 9742)
 
	Carte LiPo Rider Plus 106990290 (ref 36778)





