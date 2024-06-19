#include <SPI.h>
#include <MFRC522.h>
#include "BluetoothSerial.h"

#define SS_PIN 21 //lecteur RC522
#define RST_PIN 22 //lecteur RC522
#define BUZZER_PIN 25
#define BLUE_LED 13
#define GREEN_LED 14

MFRC522 rfid(SS_PIN, RST_PIN); // Instance de la classe
MFRC522::MIFARE_Key key; 
BluetoothSerial SerialBT;
bool bluetoothConnected = true; // Variable pour suivre l'état de la connexion Bluetooth
int ledState = HIGH; // État de la LED Bleue

void tone(byte pin, int freq) {
  ledcSetup(0, 2000, 8); // Configuration du bip
  ledcAttachPin(BUZZER_PIN, 0); // Attacher le canal 0 à la broche BUZZER_PIN
  ledcWriteTone(0, freq); // Jouer bip
}

void noTone() {
  ledcWrite(0, 0); // Arrêter la tonalité
}

void setup() { 
  Serial.begin(115200);
  SerialBT.begin("Box_001"); // Nom du Bluetooth
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init RC522
  pinMode(BLUE_LED, OUTPUT); // Led Bleue Bluetooth
  pinMode(GREEN_LED, OUTPUT); // Led Verte

  //**************Fin Phase d'initialisation
  tone(25, 3000);
  digitalWrite(GREEN_LED, HIGH); // Led verte allumée puis éteinte
  delay(300);
  digitalWrite(GREEN_LED, LOW);
  noTone();
}

void loop() {
  handleBluetooth();  // Fonction pour la gestion de la communication Bluetooth
  
  readRFID(); // Lire la carte RFID si présente
 
}

// Convertir l'UUID en Hex. 
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    SerialBT.print(buffer[i] < 0x10 ? "0" : "");
    SerialBT.print(buffer[i], HEX);
    Serial.print(buffer[i] < 0x10 ? "0" : "");
    Serial.print(buffer[i], HEX);
  }
}

void handleBluetooth() {
  bluetoothConnected = SerialBT.connected(); // Vérifie l'état de la connexion

  if (bluetoothConnected) {
    digitalWrite(BLUE_LED, HIGH); // Éteint la LED interne si le Bluetooth est connecté
  } else {
    // Fait clignoter la LED si le Bluetooth n'est pas connecté
    if (millis() % 1000 < 500) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(BLUE_LED, ledState);
  }

  delay(20);
}
void readRFID() {
  if (rfid.PICC_IsNewCardPresent()) {
    // Vérification si le NUID a été lu 
    if (rfid.PICC_ReadCardSerial()) {
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      printHex(rfid.uid.uidByte, rfid.uid.size);
      SerialBT.println(); // Envoi Bluetooth
      Serial.println(); // Saut à la ligne; configurer App Inventor en delimiter 10
      tone(BUZZER_PIN, 3000); // Son
      digitalWrite(GREEN_LED, HIGH); // Led allumée
      delay(300); // Durée allumage
      digitalWrite(GREEN_LED, LOW); // Éteindre Led
      delay(1);
      noTone(); // Couper son 

      rfid.PICC_HaltA(); // Arrêt lecture TAG
    }
  }
}
