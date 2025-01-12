/*
 * Header File
 * kuroli.h
*/

#ifndef KUROLI_H
#define KUROLI_H

#include "Arduino.h"
#include <Wire.h>
#include "src/lcd/LiquidCrystal_I2C.h"
#include "src/ina219/Adafruit_INA219.h"
#include "src/hcsr04/HCSR04.h"
#include <SPI.h>
#include <SD.h>

struct structKuroli {
  float pwmGas; //besar sinyal pwm gas tangan
  //tambah yg lain di sini
};

struct structIna219 {
  float shuntVoltage; //mV
  float busVoltage; //V
  float current; //mA
  float loadVoltage; //V
  float power; //mW
};

class Kuroli {
  public:
    Kuroli(byte GAS);

    void sdInit(const byte chipSelect);
    void sdWrite(structIna219 *_structIna219, structKuroli *_structKuroli);
    void serialLog(structIna219 *_structIna219, structKuroli *_structKuroli);
    void displayInit(const byte kolom, const byte baris);
    void inaInit();
    void readIna219(structIna219 *_structIna219);
    void textIna219(structIna219 *_structIna219);
  
  private:
    //parameter Kuroli()
    LiquidCrystal_I2C *_lcd;
    Adafruit_INA219 *_ina;
    HCSR04 *_hc;

    byte TRIG=5, ECHO=6;
    byte GAS;
};

#endif