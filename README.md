# Bluetooth-Shield-HC-05-

###### Supporting Documents
http://www.e-gizmo.com/oc/index.php?route=product/product&product_id=494&search=Bluetooth
Employing our latest EGBT-04 series low cost bluetooth module, the Bluetooth shield is likewise available in low cost version: Master and Slave functions. Class 2 Bluetooth shield with SPP profile functioning as UART port wireless cable replacement. 
![Imgur](http://i.imgur.com/FwYOv3i.jpg)

#### Wiring Connections

gizDuino | BT Shield
------------ | -------------
RX0 | RXD
TX0 | TXD
GND | GND
+5V | +5V (Select INT)
-|*important: Put a jumper on MODE (S4)

![Imgur](http://i.imgur.com/Pyurk4c.jpg)

#### Sample Code (For Configuration  - send an AT commands)
```javascript
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
// 2013:3:40964

void setup()  
{
  Serial.begin(9600);
  Serial.println("Ready for configuration...");
  mySerial.begin(9600);
}

char a=0;
char b=0;
void loop()
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
```

#### Serial Monitor
Set the Baudrate according from the code. Default **9600** and **Both NL & CR**
![Imgur](http://i.imgur.com/BJNGIF4.png)

### Some Helpful AT commands (Troubleshooting)
##### For TEST
Command | Response | Parameter
------------ | -------------| -------------|
**AT** | OK |-|
**AT+RESET** | OK   (for Resetting the module)|-|
**AT+VERSION?** | OK | Version Number ex. +Version: 2.0 -20100601
**AT+ROLE?** | +ROLE:<param> OK (Select INT) | 0 - Slave role, 1- Master role, 2 - slave-loop role: default:0
**AT+UART?** | +UART:<param> OK |ex. +UART:9600,0,0 OK|

More At commands: http://e-gizmo.com/oc/kits%20documents/Bluetooth%20Shield/EGBT-045MS-046S%20Bluetooth%20Module%20Manual%20rev%201r0.pdf
- For Technical Support, Kindly email us at egizmo.technical@gmail.com
