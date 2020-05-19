/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/

void mainkan() {

  TampilJam();
  TampilTanggal();
  TampilSuhu();
  AlarmSholat();

  if (millis() - clkTime > 15000) { //Every 15 seconds, tampilkan tanggal bergerak
    AlarmSholat();
  }

  if (millis() - clkTime > 18000) { //Every 15 seconds, tampilkan tanggal bergerak
    delay(3000);
    AlarmSholat();
    TampilJadwalSholat();
    AlarmSholat();


    clkTime = millis();
  }

}

void JadwalSholat() {

  RtcDateTime now = Rtc.GetDateTime();

  int tahun = now.Year();
  int bulan = now.Month();
  int tanggal = now.Day();

  int dst = 7; // TimeZone

  set_calc_method(ISNA);
  set_asr_method(Shafii);
  set_high_lats_adjust_method(AngleBased);
  set_fajr_angle(20);
  set_isha_angle(18);

  //SETTING LOKASI DAN WAKTU Masjid Miftahul Jannah
  float latitude =  -7.762552;
  float longitude = 110.376463;

  get_prayer_times(tahun, bulan, tanggal, latitude, longitude, dst, times);

}

void TampilJadwalSholat() {

  JadwalSholat();
  lcd.clear();
  char sholat[7];
  char jam[50];
  //char TimeName[][16] = {"     SUBUH","     TERBIT","     DZUHUR","     ASHAR","   TENGGELAM","     MAGRIB","     ISYA'","WA"};
  char TimeName[][8] = {"SUBUH ", "TERBIT", "DZUHUR", "ASHAR ", "TE", "MAGRIB", "ISYA' ", "WA"};
  int hours, minutes;

  for (int i = 0; i < 8; i++) {

    get_float_time_parts(times[i], hours, minutes);

    ihti = 2;
    minutes = minutes + ihti;

    if (minutes >= 60) {
      minutes = minutes - 60;
      hours ++;
    }
    else {
      ;
    }

    if (i == 0 || i == 2 || i == 3 || i == 5 || i == 6) { //Tampilkan hanya Subuh, Dzuhur, Ashar, Maghrib, Isya
      //sprintf(sholat,"%s",TimeName[i]);

      TampilJam2();
      TampilTanggal();
      sprintf(jam, "%s     %02d:%02d", TimeName[i], hours, minutes);
      Serial.println(jam);
      sprintf(jam, "%s", TimeName[i]);
      TeksStatis(jam, 0, 0);
      sprintf(jam, "%02d:%02d", hours, minutes);
      TeksStatis(jam, 0, 1);
      delay(2000);
      lcd.clear();
    }

  }


  //Tambahan Waktu Tanbih (Peringatan 10 menit sebelum mulai puasa) yang biasa disebut Imsak

  get_float_time_parts(times[0], hours, minutes);
  minutes = minutes + ihti;
  if (minutes < 11) {
    minutes = 60 - minutes;
    hours --;
  } else {
    minutes = minutes - 10 ;
  }
  TampilJam2();
  TampilTanggal();
  //  sprintf(jam, "TANBIH     %02d:%02d", hours, minutes);
  //  TeksStatis(jam, 0, 1);
  sprintf(jam, "TANBIH");
  TeksStatis(jam, 0, 0);
  sprintf(jam, "%02d:%02d", hours, minutes);
  TeksStatis(jam, 0, 1);
  delay(2000);
  lcd.clear();
}

void AlarmSholat() {

  RtcDateTime now = Rtc.GetDateTime();

  int Hari = now.DayOfWeek();
  int Hor = now.Hour();
  int Min = now.Minute();
  int Sec = now.Second();

  JadwalSholat();
  int hours, minutes;
  char jam[50];

  // Tanbih Imsak
  get_float_time_parts(times[0], hours, minutes);
  minutes = minutes + ihti;

  if (minutes < 11) {
    minutes = 60 - minutes;
    hours --;
  } else {
    minutes = minutes - 10 ;
  }

  if (Hor == hours && Min == minutes) {
    TeksStatis("     TANBIH      ", 0, 0);
    sprintf(jam, "     %02d:%02d     ", hours, minutes);
    TeksStatis(jam, 0, 1);
    BuzzerPendek();
    delayms = 100;
    for (int i = 0; i < 5; i++) blinks();
    Serial.println("TANBIH");
    delay(60000);
  }

  // Subuh
  get_float_time_parts(times[0], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }

  if (Hor == hours && Min == minutes) {
    TeksStatis("     SUBUH      ", 0, 0);
    sprintf(jam, "     %02d:%02d     ", hours, minutes);
    TeksStatis(jam, 0, 1);
    BuzzerPanjang();
    Serial.println("SUBUH");
    delayms = 100;
    for (int i = 0; i < 5; i++) blinks();
    delay(180000);//180 detik atau 3 menit untuk adzan

    BuzzerPendek();
    value_iqmh = 10;
    Iqomah();
  }

  // Dzuhur
  get_float_time_parts(times[2], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }

  if (Hor == hours && Min == minutes && Hari != 5) {

    TeksStatis("     DZUHUR     ", 0, 0);
    sprintf(jam, "     %02d:%02d     ", hours, minutes);
    TeksStatis(jam, 0, 1);
    BuzzerPanjang();
    Serial.println("DZUHUR");
    delayms = 100;
    for (int i = 0; i < 5; i++) blinks();
    delay(180000);//180 detik atau 3 menit untuk adzan

    BuzzerPendek();
    value_iqmh = 3;
    Iqomah();

  } else if (Hor == hours && Min == minutes && Hari == 5) {

    TeksStatis("     JUM'AT     ", 0, 0);
    sprintf(jam, "     %02d:%02d     ", hours, minutes);
    TeksStatis(jam, 0, 1);
    BuzzerPanjang();
    Serial.println("JUM'AT");
    delayms = 100;
    for (int i = 0; i < 5; i++) blinks();
    delay(180000);//180 detik atau 3 menit untuk adzan

  }

  // Ashar
  get_float_time_parts(times[3], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }

  if (Hor == hours && Min == minutes) {
    TeksStatis("     ASHAR      ", 0, 0);
    sprintf(jam, "     %02d:%02d     ", hours, minutes);
    TeksStatis(jam, 0, 1);
    BuzzerPanjang();
    Serial.println("ASHAR");
    delayms = 100;
    for (int i = 0; i < 5; i++) blinks();
    delay(180000);//180 detik atau 3 menit untuk adzan

    BuzzerPendek();
    value_iqmh = 3;
    Iqomah();
  }

  // Maghrib
  get_float_time_parts(times[5], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }

  if (Hor == hours && Min == minutes) {
    TeksStatis("     MAGHRIB     ", 0, 0);
    sprintf(jam, "     %02d:%02d     ", hours, minutes);
    TeksStatis(jam, 0, 1);
    BuzzerPanjang();
    Serial.println("MAGHRIB");
    delayms = 100;
    for (int i = 0; i < 5; i++) blinks();
    delay(180000);//180 detik atau 3 menit untuk adzan

    BuzzerPendek();
    value_iqmh = 2;
    Iqomah();
  }

  // Isya'
  get_float_time_parts(times[6], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }

  if (Hor == hours && Min == minutes) {
    TeksStatis("      ISYA      ", 0, 0);
    sprintf(jam, "     %02d:%02d     ", hours, minutes);
    TeksStatis(jam, 0, 1);
    BuzzerPanjang();
    Serial.println("ISYA");
    delayms = 100;
    for (int i = 0; i < 5; i++) blinks();
    delay(180000);//180 detik atau 3 menit untuk adzan

    BuzzerPendek();
    value_iqmh = 2;
    Iqomah();
  }

}


//--------------------------------------------------
//IQOMAH

void Iqomah() {

  RtcDateTime now = Rtc.GetDateTime();
  //iqomah----------------------------------
  char iqomah[8];
  int tampil;
  int detik = 0, menit = value_iqmh;
  for (detik = 0; detik >= 0; detik--) {
    delay(1000);
    sprintf(iqomah, "     IQOMAH     ");
    TeksStatis(iqomah, 0, 0);
    sprintf(iqomah, "     %02d:%02d     ", menit, detik);
    TeksStatis(iqomah, 0, 1);
    if (detik <= 0) {
      detik = 60;
      menit = menit - 1;
    } if (menit <= 0 && detik <= 1) {
      BuzzerPendek();
      delayms = 100;
      for (int i = 0; i < 10; i++) blinks();
      lcd.clear();
      TeksStatis("     SHOLAT     ", 0, 0);
      delay(10000);
      for (tampil = 0; tampil < 300 ; tampil++) { //< tampil selama 300 detik waktu saat sholat
        menit = 0;
        detik = 0;
        ///////////////////////
        //now = rtc.now();
        TeksStatis("     SHOLAT     ", 0, 0);
        sprintf(iqomah, "     %02d:%02d      ", now.Hour(), now.Minute());
        TeksStatis(iqomah, 0, 1);
        /////////////////////
        delay (1000);
      }
    }
  }
  lcd.clear();
}

//=============================================================================================
void buildJavascript() {
  //=============================================================================================
  javaScript = "<SCRIPT>\n";
  javaScript += "var xmlHttp=createXmlHttpObject();\n";

  javaScript += "function createXmlHttpObject(){\n";
  javaScript += " if(window.XMLHttpRequest){\n";
  javaScript += "    xmlHttp=new XMLHttpRequest();\n";
  javaScript += " }else{\n";
  javaScript += "    xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');\n"; // code for IE6, IE5
  javaScript += " }\n";
  javaScript += " return xmlHttp;\n";
  javaScript += "}\n";

  javaScript += "function process(){\n";
  javaScript += " if(xmlHttp.readyState==0 || xmlHttp.readyState==4){\n";
  javaScript += "   xmlHttp.open('PUT','xml',true);\n";
  javaScript += "   xmlHttp.onreadystatechange=handleServerResponse;\n";
  javaScript += "   xmlHttp.send(null);\n";
  javaScript += " }\n";
  javaScript += " setTimeout('process()',1000);\n";
  javaScript += "}\n";

  javaScript += "function handleServerResponse(){\n";
  javaScript += " if(xmlHttp.readyState==4 && xmlHttp.status==200){\n";
  javaScript += "   xmlResponse=xmlHttp.responseXML;\n";

  javaScript += "   xmldoc = xmlResponse.getElementsByTagName('rYear');\n";
  javaScript += "   message = xmldoc[0].firstChild.nodeValue;\n";
  javaScript += "   document.getElementById('year').innerHTML=message;\n";

  javaScript += "   xmldoc = xmlResponse.getElementsByTagName('rMonth');\n";
  javaScript += "   message = xmldoc[0].firstChild.nodeValue;\n";
  javaScript += "   document.getElementById('month').innerHTML=message;\n";

  javaScript += "   xmldoc = xmlResponse.getElementsByTagName('rDay');\n";
  javaScript += "   message = xmldoc[0].firstChild.nodeValue;\n";
  javaScript += "   document.getElementById('day').innerHTML=message;\n";

  javaScript += "   xmldoc = xmlResponse.getElementsByTagName('rHour');\n";
  javaScript += "   message = xmldoc[0].firstChild.nodeValue;\n";
  javaScript += "   document.getElementById('hour').innerHTML=message;\n";

  javaScript += "   xmldoc = xmlResponse.getElementsByTagName('rMinute');\n";
  javaScript += "   message = xmldoc[0].firstChild.nodeValue;\n";
  javaScript += "   document.getElementById('minute').innerHTML=message;\n";

  javaScript += "   xmldoc = xmlResponse.getElementsByTagName('rSecond');\n";
  javaScript += "   message = xmldoc[0].firstChild.nodeValue;\n";
  javaScript += "   document.getElementById('second').innerHTML=message;\n";

  javaScript += "   xmldoc = xmlResponse.getElementsByTagName('rTemp');\n";
  javaScript += "   message = xmldoc[0].firstChild.nodeValue;\n";
  javaScript += "   document.getElementById('temp').innerHTML=message;\n";

  javaScript += " }\n";
  javaScript += "}\n";
  javaScript += "</SCRIPT>\n";
}
//=============================================================================================
void buildXML() {
  //=============================================================================================
  RtcDateTime now = Rtc.GetDateTime();
  RtcTemperature temp = Rtc.GetTemperature();
  XML = "<?xml version='1.0'?>";
  XML += "<t>";
  XML += "<rYear>";
  XML += now.Year();
  XML += "</rYear>";
  XML += "<rMonth>";
  XML += now.Month();
  XML += "</rMonth>";
  XML += "<rDay>";
  XML += now.Day();
  XML += "</rDay>";
  XML += "<rHour>";
  if (now.Hour() < 10) {
    XML += "0";
    XML += now.Hour();
  } else {
    XML += now.Hour();
  }
  XML += "</rHour>";
  XML += "<rMinute>";
  if (now.Minute() < 10) {
    XML += "0";
    XML += now.Minute();
  } else {
    XML += now.Minute();
  }
  XML += "</rMinute>";
  XML += "<rSecond>";
  if (now.Second() < 10) {
    XML += "0";
    XML += now.Second();
  } else {
    XML += now.Second();
  }
  XML += "</rSecond>";
  XML += "</rTemp>";
  XML += temp.AsFloatDegC();
  XML += "</rTemp>";
  XML += "</t>";
}

//=============================================================================================
void handleRoot() {
  //=============================================================================================
  buildJavascript();
  IPAddress ip = WiFi.localIP();
  String ipStr = (String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]));

  message = "<!DOCTYPE HTML>";
  message += "<html>";
  message += "<head>";
  message += javaScript;
  message += "<title>JWS Grobak.Net</title>";
  message += "<style> body { font-family: Arial, Helvetica, Sans-Serif; color: green; }";
  message += "h1 {text-align:center;}";
  message += "h5 {text-align:center;}";
  message += "a {text-decoration:none; color:#fff; background:green; padding:10px; border-radius:15px; }";
  message += "p {text-align:center;}";
  message += "table.center { width:80%; margin-left:10%; margin-right:10%;}";
  message += "</style>";
  message += "  </head>";
  message += "  <body onload='process()'>";
  message += "<table class='center'>";
  message += "  <tr>";
  message += "    <th>";
  message += "<h1>JWS Grobak.Net</h1>";
  message += "    </th> ";
  message += "  </tr>";
  message += "  <tr>";
  message += "    <td align='center'>";
  message += "    </td>";
  message += "  </tr>";


  message += "  <tr>";
  message += "    <td align='center'>";
  message += "<span id='year'></span>/<span id='month'></span>/<span id='day'></span>   <span id='hour'></span>:<span id='minute'></span>:<span id='second'></span><BR>";
  message += "    </td>";
  message += "  </tr>";

  message += "  <tr>";
  message += "    <td align='center'>";
  message += "Temp =<span id='temp'></span>C<BR>";
  message += "    </td>";
  message += "  </tr>";

  message += "  <tr>";
  message += "    <td>";
  message += "<h5><a href='/setTime'>Ubah Tanggal dan Jam</a></h5>";
  message += "    </td>";
  message += "  </tr>";

  message += "  <tr>";
  message += "    <td align='center'>";
  message += "<BR>IP  ";
  message += ipStr;
  message += "    </td>";
  message += "  </tr>";
  message += "</table>";

  message += "<BR>";

  message += "";

  message += "</body></html>";

  server.send ( 404 , "text/html", message );
}

//=============================================================================================
void setTime() {
  //=============================================================================================
  buildJavascript();
  message = "<!DOCTYPE HTML>";
  message += "<html>";
  message += "<head>";
  message += javaScript;
  message += "<title>JWS Grobak.Net</title>";
  message += "<style> body { font-family: Arial, Helvetica, Sans-Serif; color: green; }";
  message += "h1 {text-align:center;}";
  message += "h5 {text-align:center;}";
  message += "a {text-decoration:none; color:#fff; background:green; padding:10px; border-radius:15px; }";
  message += "p {text-align:center;}";
  message += "table.center { width:80%; margin-left:10%; margin-right:10%;}";
  message += "</style>";
  message += "  </head>";
  message += "  <body onload='process()'>";/////////////////////////////////////////

  message += "";

  message += "<table class='center'>";
  message += "  <tr>";
  message += "    <th>";
  message += "<h1>Ubah Tanggal dan Jam</h1>";
  message += "    </th> ";
  message += "  </tr>";
  message += "  <tr>";
  message += "    <td align='center'>";
  message += "Tanggal Sekarang  ";
  message += " <BR>   </td>";
  message += "  </tr>";
  message += "  <tr>";
  message += "    <td align='center'>";
  message += "<span id='year'></span>/<span id='month'></span>/<span id='day'></span><BR>";
  message += "    </td>";
  message += "  </tr>";
  message += "  <tr>";
  message += "    <td align='center'>";

  message += "<form >";
  message += "Format tanggal 2017-03-20<br><br>";
  message += "<input type='date' name='date' min='2017-03-20' style='height:75px; width:200px'><br><br>";
  message += "<input type='submit' value='Ubah Tanggal' style='height:75px; width:200px'> ";
  message += "</form>";


  message += "    </td>";
  message += "  </tr>";
  message += "  <tr>";
  message += "    <td align='center'>";
  message += "Jam Tersimpan<BR><span id='hour'></span>:<span id='minute'></span>:<span id='second'></span><BR><BR>";
  message += "    </td>";
  message += "  </tr>";
  message += "  <tr>";
  message += "    <td align='center'>";
  message += "<form >";
  message += "Tentukan Jam<br>";
  message += "<input type='TIME' name='time' style='height:75px; width:200px'><br><br>";
  message += "<input type='submit' value='Ubah Jam' style='height:75px; width:200px'> ";
  message += "</form>";
  message += "    </td>";
  message += "  </tr>";
  message += "  <tr>";
  message += "    <td>";
  message += "<h5><a href='/'>Kembali</a></h5>";
  message += "    </td>";
  message += "  </tr>";
  message += "</table>";


  message += "";

  message += "</body></html>";

  server.send ( 404 , "text/html", message );

  // Tanggal--------------------------------------------------------------------
  if (server.hasArg("date")) {

    uint16_t ano;
    uint8_t mes;
    uint8_t dia;
    Serial.print("ARGdate");
    Serial.println(server.arg("date"));
    String sd = server.arg("date");
    String lastSd;
    ano = ((sd[0] - '0') * 1000) + ((sd[1] - '0') * 100) + ((sd[2] - '0') * 10) + (sd[3] - '0');
    mes = ((sd[5] - '0') * 10) + (sd[6] - '0');
    dia = ((sd[8] - '0') * 10) + (sd[9] - '0');
    if (sd != lastSd) {
      RtcDateTime now = Rtc.GetDateTime();
      uint8_t hour = now.Hour();
      uint8_t minute = now.Minute();
      Rtc.SetDateTime(RtcDateTime(ano, mes, dia, hour, minute, 0));
      lastSd = sd;
    }
    // Serial.println(fa);

    server.send ( 404 , "text", message );
  }//if has date
  // Jam ------------------------------------------------
  if (server.hasArg("time")) {
    Serial.println(server.arg("time"));
    String st = server.arg("time");
    String lastSt;
    uint8_t hora = ((st[0] - '0') * 10) + (st[1] - '0');
    uint8_t minuto = ((st[3] - '0') * 10) + (st[4] - '0');
    if (st != lastSt) {
      RtcDateTime now = Rtc.GetDateTime();
      uint16_t year = now.Year();
      uint8_t month = now.Month();
      uint8_t day = now.Day();
      Rtc.SetDateTime(RtcDateTime(year, month, day, hora, minuto, 0));
      lastSt = st;
    }
    server.send ( 404 , "text", message );

  }//if has time
}
//=============================================================================================
void handleXML() {
  //=============================================================================================
  buildXML();
  server.send(200, "text/xml", XML);
}
//=============================================================================================
void handleNotFound() {
  //=============================================================================================
  String message = "<html><head>";
  message += "<title>JWS Grobak.Net - Halaman tidak ditemukan</title>";
  message += "<style> body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }";
  message += "h1 {text-align:center;}";
  message += "h5 {text-align:center;}";
  message += "a {text-decoration:none; color:#fff; background:green; padding:10px; border-radius:15px; }";
  message += "</style>";
  message += "  </head>";
  message += "  <body>";
  message += "<table style='width:80%'>";
  message += "<tr>";//baris 2
  message += "<th>";//kolom judul
  message += "<h1>Tidak ditemukan</h1>";
  message += "</th>";
  message += "<tr>";//baris 2
  message += "<td>";//kolom isi
  message += "<h5><a href='/'>Kembali</a></h5>";
  message += "<td>";
  message += "</tr>";
  message += "</table>";
  message += "</body></html>";
  message += "";

  server.send ( 404 , "text", message );
}

void initSSID()
{
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  server.on ( "/", handleRoot );
  server.on ( "/setTime", setTime );
  server.on ( "/xml", handleXML) ;
  server.onNotFound ( handleNotFound );

  server.begin();
  Serial.println("HTTP server started");
}
