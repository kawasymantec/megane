#include <M5StickC.h>
#include "BLEDevice.h"

BLEScan* pBLEScan;

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.setTextColor(BLACK, WHITE);

    BLEDevice::init("");
    pBLEScan = BLEDevice::getScan();
    pBLEScan->setActiveScan(false);
}

void loop() {

    BLEScanResults foundDevices = pBLEScan->start(3);  // スキャンする
    int count = foundDevices.getCount();
            M5.Lcd.fillScreen(WHITE);
            M5.Lcd.setCursor(0,0);
            
            M5.Lcd.printf("COUNT: %d\r\n", count);


    for (int i = 0; i < count; i++) {
        BLEAdvertisedDevice d = foundDevices.getDevice(i);
        if(d.haveServiceUUID()){
          BLEUUID uuid = d.getServiceUUID();
          M5.Lcd.printf("UUID: %s\r\n", uuid.toString().c_str());
        }
        
    }
}

