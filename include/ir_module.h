#ifndef IR_MODULE_H
#define IR_MODULE_H

#include <Arduino.h>

#define IR_TX_PIN 4
#define IR_RX_PIN 13

void setupIR();
void enviarSenalIR();
bool leerSenalIR();
void flujoInfrarrojo(bool &enSubMenu); // <- Agrega esta línea si no estaba

#endif