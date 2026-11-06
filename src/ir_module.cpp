#include "ir_module.h"

void setupIR() {
    pinMode(IR_TX_PIN, OUTPUT);
    digitalWrite(IR_TX_PIN, LOW);
    pinMode(IR_RX_PIN, INPUT);
}

void enviarSenalIR() {
    for (int i = 0; i < 190; i++) {
        digitalWrite(IR_TX_PIN, HIGH);
        delayMicroseconds(13);
        digitalWrite(IR_TX_PIN, LOW);
        delayMicroseconds(13);
    }
}

bool leerSenalIR() {
    return (digitalRead(IR_RX_PIN) == LOW);
}

void flujoInfrarrojo(bool &enSubMenu) {
    if (leerSenalIR()) {
        enviarSenalIR();
    }
    // Si la palanca/botón desactiva el submenú:
    // enSubMenu = false;
}