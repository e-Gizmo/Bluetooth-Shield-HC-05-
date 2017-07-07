#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
// 2013:3:40964

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.println("Ready for configuration...");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

char a=0;
char b=0;
void loop() // run over and over
{
  mySerial.listen();
  if (mySerial.available()){
    a = mySerial.read();
    Serial.print(a);
  }

  if (Serial.available()){
    b = Serial.read();
    Serial.print(b);
    mySerial.print(b);
  }
}

