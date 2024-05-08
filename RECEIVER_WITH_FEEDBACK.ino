//RECEIVER WITH FEEDBACK
#include <SoftwareSerial.h>

SoftwareSerial LoRaSerial(2, 3); // RX, TX for LoRa module

void setup() {
  Serial.begin(9600); // Initialize serial communication
  LoRaSerial.begin(9600); // Initialize LoRa serial communication
}

void loop() {
  if (LoRaSerial.available()) {
    String receivedData = LoRaSerial.readString(); // Read data from LoRa module

    // Print received data to serial monitor
    Serial.println(receivedData);

    // Check if receivedData equals "HI"
    if (receivedData.indexOf("AUTO") != -1) {
      LoRaSerial.println("AT+SEND=21,6,A_DONE");
      Serial.println("AT+SEND=21,6,A_DONE");
      delay(2000); // Delay for 2 seconds
    }
  }
}
