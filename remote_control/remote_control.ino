// Hiep Le
// The following code is designed for a simple TV remote control with 5 buttons:
// POWER, CHANNEL+, CHANNEL-, VOLUME+, and VOLUME-
// This is based on a tutorial on SparkFun. For detailed schematic and tutorial, visit
// https://learn.sparkfun.com/tutorials/ir-communication/transmitting-ir-example

#include <IRremote.h>

// IR led should be connected to the following pin
#define IR_PIN 12

// buttons on remote should be connected to the following pins
#define POWER_BUTTON A0
#define CHANNEL_PLUS A1
#define CHANNEL_MINUS A2
#define VOLUME_PLUS A3
#define VOLUME_MINUS A4

IRsend transmitter;

void setup() {

  // setup pins
  pinMode(IR_PIN, OUTPUT);
  pinMode(POWER_BUTTON, INPUT_PULLUP);
  pinMode(CHANNEL_PLUS, INPUT_PULLUP);
  pinMode(CHANNEL_MINUS, INPUT_PULLUP);
  pinMode(VOLUME_PLUS, INPUT_PULLUP);
  pinMode(VOLUME_MINUS, INPUT_PULLUP);

  // set up terminal communication (optional)
  Serial.begin(9600);
}

void loop() {

  // a signal is sent corresponding to the button pressed
  // note that the receiver must be configured to expect the specific signal
  // in the case, hex code a10 for power on/off, hex code a20 for channel plus
  // hex code a30 for channel minus, a40 for volume up, and a50 for volume down
  if (digitalRead(POWER_BUTTON) == 0) {
    irsend.sendSony(0xa10, 12);
    delay(500);
  } else if (digitalRead(CHANNEL_PLUS) == 0) {
    irsend.sendSony(0xa20, 12);
    delay(500);
  } else if (digitalRead(CHANNEL_MINUS) == 0) {
    irsend.sendSony(0xa30, 12);
    delay(500);
  } else if (digitalRead(VOLUME_PLUS) == 0) {
    irsend.sendSony(0xa40, 12);
    delay(500);
  } else if (digitalRead(VOLUME_MINUS) == 0) {
    irsend.sendSony(0xa50, 12);
    delay(500);
  }
  
}

