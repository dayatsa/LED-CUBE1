#include "PrayerTimes.h"
#include <Wire.h> // must be included here so that Arduino library object file references work
#include <RtcDS3231.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#define countof(a) (sizeof(a) / sizeof(a[0]))
#define MAX     30
#define TINGGI  25


// Konstruk object LCD dengan alamat I2C
// Ganti 0x3F sesuai dengan alamat I2C modul kalian
// Jika tidak tahu dapat menggunakan LCD I2C Scanner
LiquidCrystal_I2C lcd(0x27, 16, 2);
RtcDS3231<TwoWire> Rtc(Wire);


// Ubah nama hari dan nama bulan
char weekDay[][3] = {"AH", "SN", "SL", "RB", "KM", "JM", "SB", "AH"};
char monthYear[][4] = { " ", "JAN", "FEB", "MAR", "APR", "MEI", "JUN", "JUL", "AGU", "SEP", "OKT", "NOV", "DES" };

// Inisiasi Jadwal Sholat
double times[sizeof(TimeName) / sizeof(char*)];
int ihti = 2;   // Koreksi Waktu Menit Jadwal Sholat
int value_iqmh;  // Waktu Iqomah 10 menit

// Set Wifi SSID dan Password
#ifndef APSSID
#define APSSID "AndroidAP"
#define APPSK  "haijugama"
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

char datestring[20];
String message, javaScript, XML;

ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

char data[] = "www.tokobaguskerenasik.com";

// BUZZER
uint8_t buzzer = 15;
uint8_t GPIO_Pin = 0;


int updCnt = 0;
long clkTime = 0;
bool fungsi = true;




int latchPin = 13;
int clockPin = 12;
int dataPin = 14;
//int buz = 15;

int numOfRegisters = 4;
byte* registerState;
int delayms = 100;
int jamsekarang = 0;
bool tampilcube = false;





void setup() {
  Serial.begin(115200);
  //  //  initSSID();
  initCube();
  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);
  initRTC();
  lcd.begin();
  pinMode(buzzer, OUTPUT);
  BuzzerPendek();
  brandCube();
  Branding();
  lcd.clear();
  TeksStatis("      HELLO     ", 0, 0);
  TeksStatis("      CAYU      ", 0, 1);
  helloCayu();
  lcd.clear();
  allOff();
  pinMode(GPIO_Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(GPIO_Pin), IntCallback, FALLING);
}

void loop() {


  //  n(28);
//  hbdcayu();
  //  cayuJalan();
  //
    if (fungsi) mainkan();
    else {
      BuzzerPanjang();
      cube();
      fungsi = true;
    }
}



ICACHE_RAM_ATTR void IntCallback() {
  fungsi = false;
  //  delay(100);
  //  delay(100);
  //  Serial.print("Stamp(ms): ");
  //  Serial.println(millis());
  //  BuzzerPanjang();
  //  delay(100);
}
