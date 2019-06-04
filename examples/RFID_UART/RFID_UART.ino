// RFID_UART.ino

#include <SeeedRFID.h>
#include <SoftwareSerial.h>

#define RFID_RX_PIN 10
#define RFID_TX_PIN 11

// #define TEST

SoftwareSerial RFIDSerial = SoftwareSerial(RFID_RX_PIN, RFID_TX_PIN);
SeeedRFID      RFID       = SeeedRFID(RFIDSerial);
RFIDdata       tag;


void setup()
{
  Serial.begin(57600);
  RFIDSerial.begin(9600);
  Serial.println("RFID Test..");
}


void loop()
{
  if (RFID.isAvailable())
  {
    tag = RFID.data();
    Serial.print("RFID card number: ");
    Serial.println(RFID.cardNumber());
#ifdef TEST
    Serial.print("RFID raw data: ");
    for (int i = 0; i < tag.dataLen; i++)
    {
      Serial.print(tag.raw[i], HEX);
      Serial.print('\t');
    }
#endif
  }
}

