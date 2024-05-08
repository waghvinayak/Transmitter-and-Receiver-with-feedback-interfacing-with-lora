//TRANSMITTER WITH FEEDBACK
#include <SoftwareSerial.h>

SoftwareSerial lora(2, 3);

void setup()
{
  Serial.begin(9600);
  lora.begin(9600);

  lora.println("AT+SEND=17,4,AUTO");
  Serial.println("AT+SEND=17,4,AUTO");
  delay(1000);

  if (lora.available()) {
    String receivedData = lora.readString(); // Read data from LoRa module

    // Print received data to serial monitor
    Serial.println(receivedData);

    // Check if receivedData equals "HI"
    if (receivedData.indexOf("A_DONE") != -1) {
      lora.println("AT+SEND=18,4,AUTO");
      Serial.println("AT+SEND=18,4,AUTO");
      delay(2000); // Delay for 2 seconds
    }
  }

  if (lora.available()) {
    String receivedData = lora.readString(); // Read data from LoRa module

    // Print received data to serial monitor
    Serial.println(receivedData);

    // Check if receivedData equals "HI"
    if (receivedData.indexOf("A_DONE") != -1) {
     
      Serial.println("A_DONE");
      delay(2000); // Delay for 2 seconds
    }
  }
    
}

void loop()
{
  
}
