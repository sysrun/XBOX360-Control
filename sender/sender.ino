/*
 Example sketch for the Xbox 360 USB library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or 
 send me an e-mail:  kristianl@tkjelectronics.com
 */

#define RIGHTHATDEADCENTER 7500

#include <XBOXUSB.h>
USB Usb;
XBOXUSB Xbox(&Usb);

void setup() {
  Serial.begin(115200);

  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while(1); //halt
  }  
  Serial.print(F("\r\nXBOX USB Library Started"));
}

int state = 0;

void loop() {
  Usb.Task();
  if(Xbox.Xbox360Connected) {
    //Serial.println(Xbox.getAnalogHat(RightHatY));
    int rightHatX = getRightHatX(-128,128);
    int rightHatY = getRightHatY(-128,128);
    /*
    Serial.print(rightHatX);
    Serial.print(" - ");
    Serial.print(rightHatY);    
    Serial.println();
    */
    if(Xbox.buttonPressed) {
      if(Xbox.getButton(XBOX)) {
        if (state==4)
          state=0;
        else
          state++; 
      }
    }
    
    switch(state) {
      case 0: Xbox.setLedOff(); break;
      case 1: Xbox.setLedOn(LED1); break;
      case 2: Xbox.setLedOn(LED2); break;
      case 3: Xbox.setLedOn(LED4); break;
      case 4: Xbox.setLedOn(LED3); break;
    }

  }
  delay(2);
}
