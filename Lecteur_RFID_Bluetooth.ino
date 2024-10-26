#include <SPI.h>
#include <MFRC522.h>
#include "BluetoothSerial.h"

#define SS_PIN 21 //lecteur RC522
#define RST_PIN 22 //lecteur RC522
#define BUZZER_PIN 25
#define BLUE_LED 13
#define GREEN_LED 14

MFRC522 rfid(SS_PIN, RST_PIN); // Utilisation de MFRC522
BluetoothSerial SerialBT;
bool bluetoothConnected = false;
int ledState = LOW;

void setup() { 
  Serial.begin(115200);
  SerialBT.begin("Box_001"); // Nom du Bluetooth
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  tone(BUZZER_PIN, 3000); // Son initial
  digitalWrite(GREEN_LED, HIGH);
  delay(300);
  digitalWrite(GREEN_LED, LOW);
  noTone(BUZZER_PIN);
}

void loop() {
  handleBluetooth();  // Gestion de la communication Bluetooth
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
  bluetoothConnected = SerialBT.hasClient(); // Vérifie connexion BLE
  
  if (bluetoothConnected) {
    digitalWrite(BLUE_LED, HIGH); // Allume LED si connecté
  } else {
    ledState = (millis() % 1000 < 500) ? HIGH : LOW;
    digitalWrite(BLUE_LED, ledState);
  }
  delay(20);
}

void readRFID() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    printHex(rfid.uid.uidByte, rfid.uid.size);
    SerialBT.println(); // Envoi Bluetooth
    Serial.println(); // Saut à la ligne
    tone(BUZZER_PIN, 3000); // Son
    digitalWrite(GREEN_LED, HIGH); // LED allumée
    delay(300); // Durée allumage
    digitalWrite(GREEN_LED, LOW); // Éteindre LED
    noTone(BUZZER_PIN); // Couper son 

    rfid.PICC_HaltA(); // Arrêt lecture TAG
  }
}
