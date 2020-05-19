void Branding() {
  TeksStatis("     JWSCAY", 0, 0);
  delay(2000);
  TeksStatis("     VER.1", 0, 1);
  delay(2000);
}


void printLcd(const RtcDateTime& dt)
{
  char datestring[20];

  snprintf_P(datestring, countof(datestring), PSTR("   %02u/%02u/%04u"),
             dt.Month(),
             dt.Day(),
             dt.Year() );
  Serial.print(datestring);
  lcd.setCursor(0, 1);
  lcd.print(datestring);

  snprintf_P(datestring, countof(datestring), PSTR("    %02u:%02u:%02u"),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  Serial.print(datestring);
  lcd.setCursor(0, 0);
  lcd.print(datestring);
}

//-----------------------------------------------------
//Menampilkan Jam

void TampilJam() {

  RtcDateTime now = Rtc.GetDateTime();

  char jam[8];
  int waktu = now.Hour();
//  waktu = waktu%10;

  sprintf(jam, "%02d:%02d:%02d",    //%02d print jam dengan format 2 digit
          now.Hour(),       //get hour method
          now.Minute(),     //get minute method
          now.Second()      //get second method
         );

  Serial.println(jam);    //print the string to the serial port
  if (jamsekarang != waktu || tampilcube) {
    tampilCube(waktu);
    jamsekarang = waktu;
    tampilcube = false;
  }
  TeksStatis(jam, 8, 0);
  Serial.println(waktu);

  delay(1000);            //second delay

}

void TampilJam2() {

  RtcDateTime now = Rtc.GetDateTime();

  char jam[8];

  sprintf(jam, "%02d:%02d:%02d",    //%02d print jam dengan format 2 digit
          now.Hour(),       //get hour method
          now.Minute(),     //get minute method
          now.Second()      //get second method
         );

  Serial.println(jam);    //print the string to the serial port

  TeksStatis(jam, 8, 0);

  //second delay

}


//-----------------------------------------------------
//Menampilkan Tanggal

void TampilTanggal() {

  RtcDateTime now = Rtc.GetDateTime();

  char tanggal[18];

  //  sprintf(tanggal, " %s,%02d %s %04u",             //%02d allows to print an integer with leading zero 2 digit to the string, %s print sebagai string
  //                  weekDay[now.DayOfWeek()],   //ambil method hari dalam format lengkap
  //                  now.Day(),                 //get day method
  //                  monthYear[now.Month()],
  //                  now.Year()//get month method
  //  );
  sprintf(tanggal, "%02d/%02d/%04u",             //%02d allows to print an integer with leading zero 2 digit to the string, %s print sebagai string
          //                  now.DayOfWeek(),   //ambil method hari dalam format lengkap
          now.Day(),                 //get day method
          now.Month(),
          now.Year()//get month method
         );

  Serial.println(tanggal);    //print the string to the serial port

  TeksStatis(tanggal, 6, 1);
  //delay(3000);

}

//-----------------------------------------------------
//Menampilkan Suhu

void TampilSuhu() {

  RtcTemperature temp = Rtc.GetTemperature();
  int celsius = temp.AsFloatDegC();
  char suhu[2];
  int koreksisuhu = 2; // Perkiraan selisih suhu ruangan dan luar ruangan

  sprintf(suhu, "SUHU");
  TeksStatis(suhu, 0, 0);
  sprintf(suhu, "%dC", celsius - koreksisuhu);
  TeksStatis(suhu, 0, 1);

}

void TeksStatis(String text, int kolom, int baris) {
  lcd.setCursor(kolom, baris);
  lcd.print(text);
}


void scrollText(String text, int baris)
{
  unsigned int i = text.length();
  lcd.setCursor(0, baris);
  lcd.print(text);
  for (int n = 0; n < i; n++)
  {

    lcd.scrollDisplayLeft();
    delay(500);

  }
  lcd.clear();
  while (1);

  //  while(text[i] != '\0')
  //  {
  //    lcd.print(text);
  ////    if(i>=16)
  ////    {
  //      lcd.command(0x18);
  ////    }
  //    delay(500);
  //    i++;
  //  }
  lcd.clear();
}

//----------------------------------------------------------------------
// BUNYIKAN BEEP BUZZER

void BuzzerPanjang() {
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(50);
}

void BuzzerPendek() {
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(50);
}
