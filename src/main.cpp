// #include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   int result = myFunction(2, 3);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }
#include <Arduino.h>
#include <Wire.h>
#include "joystick_module.h"
#include "display_module.h"
#include "nfc_module.h"
#include "ir_module.h"
#include "sd_module.h"
#include "wifi_module.h"
#include "bt_module.h"
#include "sleep_module.h"

const int NUM_ITEMS = 4;
String menuItems[NUM_ITEMS] = {"RFID / NFC", "Infrarrojo IR", "WiFi", "Bluetooth"};

int indiceActual = 0;     
bool dentroDeOpcion = false; 

void setup() {
  Serial.begin(115200);
  Wire.begin();
  setupJoystick();
  setupDisplay();
  setupNFC();
  setupSD(); 
  setupIR();
}

void loop() {
  actualizarJoystick(indiceActual, dentroDeOpcion, NUM_ITEMS);

  if (dentroDeOpcion && indiceActual == 0) {
      flujoNFC(dentroDeOpcion);
  }
  else if (dentroDeOpcion && indiceActual == 1) {
      flujoInfrarrojo(dentroDeOpcion);
  }
  else if (dentroDeOpcion && indiceActual == 2) {
      flujoWiFi(dentroDeOpcion);
  }
  else if (dentroDeOpcion && indiceActual == 3) {
      flujoBluetooth(dentroDeOpcion);
  }
  else {
      // Menú principal
      dibujarPantalla(indiceActual, dentroDeOpcion, menuItems, NUM_ITEMS);
      
      // Envía a pantalla el menú actualizado
      display.sendBuffer();
      
      delay(50);
  }
}