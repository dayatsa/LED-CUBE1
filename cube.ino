int cayuC[][5] =
{
  {0, 1, 1, 1, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 1, 1, 0}
};

int cayuA[][5] =
{
  {0, 1, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0}
};

int cayuY[][5] =
{
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

int cayuU[][5] =
{
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0}
};

int hbdH[][5] =
{
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0}
};

int hbdB[][5] =
{
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0}
};

int hbdD[][5] =
{
  {0, 0, 0, 1, 0},
  {0, 0, 0, 1, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0}
};


int angka1[][5] =
{
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

int angka6[][5] =
{
  {0, 1, 1, 1, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0}
};



int desE[][5] =
{
  {0, 1, 1, 1, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 1, 1, 0}
};

int desS[][5] =
{
  {0, 1, 1, 1, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 1, 0},
  {0, 1, 1, 1, 0}
};

int hurufL[][5] =
{
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 1, 1, 1, 0}
};


int hurufO[][5] =
{
  {0, 1, 1, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 0, 1, 0},
  {0, 1, 1, 1, 0}
};

int kedip[][5] =
{
  {0, 1, 0, 1, 0},
  {1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0},
  {1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0}
};

int smile[][5] =
{
  {0, 0, 0, 1, 0},
  {0, 1, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 1, 0, 0, 1},
  {0, 0, 0, 1, 0}
};


void helloCayu() {
  delayms = 120;
  n(29);
  jalan(hbdH);
  jalan(desE);
  jalan(hurufL);
  jalan(hurufL);
  jalan(hurufO);
  delay(100);
  cayuJalan();
  delay(100);
  jalan(smile);
  delay(100);
}


void hbdcayu() {
  delayms = 120;
  n(29);
  jalan(hbdH);
  jalan(hbdB);
  jalan(hbdD);
  delay(100);
  cayuJalan();
  delay(100);
  jalan(angka1);
  jalan(angka6);
  delay(100);
  jalan(hbdD);
  jalan(desE);
  jalan(desS);
  delay(100);
  jalan(smile);
  delay(100);
}


void cayuJalan() {
  jalan(cayuC);
  //  delay(50);
  jalan(cayuA);
  //  delay(50);
  jalan(cayuY);
  //  delay(50);
  jalan(cayuU);
  //  delay(50);
}



void jalan(int data[5][5]) {
  int buf[5][5];
  for (int k = 4; k >= -3; k--) {
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if (k >= 0) {
          if (j - k < 0 ) buf[i][j] = 0;
          else buf[i][j] = data[i][j - k];
        }
        else if (k < 0) {
          if (j + k < 0 ) buf[i][k + 5] = 0;
          else
            buf[i][j + k] = data[i][j];
        }
      }
    }
    transferReg(buf);
    delay(delayms);
  }
}


void transferReg(int data[5][5]) {
  int num = 0;
  for (int i = 0; i < 5; i++)
  {
    num = i;
    for (int j = 0; j < 5; j++)
    {
      regWrite(num, data[i][j]);
      num += 5;
    }
  }
}




void initCube() {
  //Initialize array
  registerState = new byte[numOfRegisters];
  for (size_t i = 0; i < numOfRegisters; i++) {
    registerState[i] = 0;
  }

  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}



void cube() {
  //  allOff();
  for (int i = 29; i >= 26 ; i--) {
    n(i);
    n(i - 1);
    delay(100);
    f(i);
    f(i - 1);
  }
  delay(100);
  allOff();
  TeksStatis("      HAPPY     ", 0, 0);
  TeksStatis("     BIRTHDAY   ", 0, 1);
  //  void loop() {
  //  while (1) {
  //    for (int i = 100; i > 30; i -= 10) {
  //      delayms = 120;
  //      hujan();
  //    }
  //    //
  //  }
  //  for (int i = 800; i > 700; i -= 100) {
  //    delayms = i;
  //    ulangTahun();
  //  }
  hbdcayu();

  TeksStatis("  SELAMAT HARI  ", 0, 0);
  TeksStatis("     LAHIR      ", 0, 1);

  for (int i = 100; i > 30; i -= 10) {
    delayms = 170;
    hujan();
  }

  TeksStatis("    CATUR AYU   ", 0, 0);
  TeksStatis("     CAD :)     ", 0, 1);

  //  buzzer();
  n(25); n(26); n(27); n(28); n(29);
  for (int i = 120; i > 80; i -= 10) {
    delayms = i;
    jalan(kedip);
  }

  for (int i = 100; i > 30; i -= 10) {
    delayms = i;
    meluap();
  }
  //  buzzer();

  for (int i = 500; i > 10; i -= 2) {
    delayms = 20;
    randomCube();
  }
  //  buzzer();

  for (int i = 100; i > 60; i -= 10) {
    delayms = i;
    berputarPutar();
  }
  //  buzzer();

  for (int i = 100; i > 50; i -= 10) {
    delayms = i;
    geserGeser();
  }
  //  buzzer();
  for (int i = 30; i > 20; i -= 10) {
    delayms = i;
    muterMuter(i);
  }
  //  buzzer();
  for (int i = 50; i > 10; i -= 10) {
    delayms = i;
    mekarMekar();
  }
  //  buzzer();
  for (int i = 100; i > 10; i -= 10) {
    delayms = i;
    blinks();
  }
  //  buzzer();
  lcd.clear();
  tampilcube = true;

}


void tampilCube(int jam) {
  //  allOff();
  for (int i = 29; i >= 26 ; i--) {
    n(i);
    n(i - 1);
    delay(80);
    f(i);
    f(i - 1);
  }
  delay(80);
  if (jam > 12) jam -= 12;
  switch (jam) {
    case 1: {
        satu();
        break;
      }
    case 2: {
        dua();
        break;
      }
    case 3: {
        tiga();
        break;
      }
    case 4: {
        empat();
        break;
      }
    case 5: {
        lima();
        break;
      }
    case 6: {
        enam();
        break;
      }
    case 7: {
        tujuh();
        break;
      }
    case 8: {
        delapan();
        break;
      }
    case 9: {
        sembilan();
        break;
      }
    case 10: {
        sepuluh();
        break;
      }
    case 11: {
        sebelas();
        break;
      }
    case 12: {
        duabelas();
        break;
      }
  }

  for (int i = 25; i <= 29; i++) {
    n(i);
    n(i - 1);
    delay(80);
    if (i < 29) {
      f(i);
      f(i - 1);
    }
    f(28);
  }
}

void satu() {
  f(0); n(5); f(10); f(15); f(20);
  f(1); n(6); f(11); f(16); f(21);
  f(2); n(7); f(12); f(17); f(22);
  f(3); n(8); f(13); f(18); f(23);
  f(4); n(9); f(14); f(19); f(24);
}

void dua() {
  f(0); n(5); n(10); n(15); f(20);
  f(1); f(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); f(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
}

void tiga() {
  f(0); n(5); n(10); n(15); f(20);
  f(1); f(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); f(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
}

void empat() {
  f(0); n(5); f(10); n(15); f(20);
  f(1); n(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); f(8); f(13); n(18); f(23);
  f(4); f(9); f(14); n(19); f(24);
}

void lima() {
  f(0); n(5); n(10); n(15); f(20);
  f(1); n(6); f(11); f(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); f(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
}

void enam() {
  f(0); n(5); n(10); n(15); f(20);
  f(1); n(6); f(11); f(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
}

void tujuh() {
  f(0); n(5); n(10); n(15); f(20);
  f(1); f(6); f(11); n(16); f(21);
  f(2); f(7); f(12); n(17); f(22);
  f(3); f(8); f(13); n(18); f(23);
  f(4); f(9); f(14); n(19); f(24);
}

void delapan() {
  f(0); n(5); n(10); n(15); f(20);
  f(1); n(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
}

void sembilan() {
  f(0); n(5); n(10); n(15); f(20);
  f(1); n(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); f(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
}

void sepuluh() {
  n(0); f(5); n(10); n(15); n(20);
  n(1); f(6); n(11); f(16); n(21);
  n(2); f(7); n(12); f(17); n(22);
  n(3); f(8); n(13); f(18); n(23);
  n(4); f(9); n(14); n(19); n(24);
}

void sebelas() {
  n(0); f(5); n(10); f(15); f(20);
  n(1); f(6); n(11); f(16); f(21);
  n(2); f(7); n(12); f(17); f(22);
  n(3); f(8); n(13); f(18); f(23);
  n(4); f(9); n(14); f(19); f(24);
}

void duabelas() {
  n(0); f(5); n(10); n(15); n(20);
  n(1); f(6); f(11); f(16); n(21);
  n(2); f(7); n(12); n(17); n(22);
  n(3); f(8); n(13); f(18); f(23);
  n(4); f(9); n(14); n(19); n(24);
}


void brandCube() {
  delayms = 200;
  blinks();
  blinks();
  delay(50);
  f(0); f(5); n(10); f(15); f(20);
  f(1); n(6); n(11); n(16); f(21);
  n(2); n(7); n(12); n(17); n(22);
  f(3); n(8); n(13); n(18); f(23);
  f(4); f(9); n(14); f(19); f(24);

  //  n(25); f(26); f(27); f(28); f(29);
  int count = 29;
  for (int i = 25; i <= count; i++) {
    n(i);
    delay(50);
    f(i);
    if (count == i) {
      n(i);
      delay(200);
      count -= 1;
      i = 24;
      if (count == 25) {
        n(25);
        delay(200);
        break;
      }
    }
  }

  for (int i = 29; i >= 25; i--) {
    f(i);
    delay(50);
  }
  allOff();

  n(0); n(5); f(10); n(15); n(20);
  n(1); f(6); f(11); f(16); n(21);
  f(2); f(7); f(12); f(17); f(22);
  n(3); f(8); f(13); f(18); n(23);
  n(4); n(9); f(14); n(19); n(24);
  for (int i = 25; i < 30; i++) {
    n(i);
    delay(50);
  }
  delay(100);
  delayms = 30;
  meluap();
  allOff();
}


void meluap() {
  allOff();
  f(0); f(5); f(10); f(15); f(20);
  f(1); n(6); n(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); n(13); n(18); f(23);
  f(4); f(9); f(14); f(19); f(24);

  n(25); f(26); f(27); f(28); f(29);
  delay(delayms);

  n(25); n(26); f(27); f(28); f(29);
  delay(delayms);

  f(25); n(26); n(27); f(28); f(29);
  delay(delayms);

  f(25); f(26); n(27); n(28); f(29);
  delay(delayms);

  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);

  n(0); n(5); n(10); n(15); n(20);
  n(1); n(6); n(11); n(16); n(21);
  n(2); n(7); f(12); n(17); n(22);
  n(3); n(8); n(13); n(18); n(23);
  n(4); n(9); n(14); n(19); n(24);

  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);

  f(25); f(26); n(27); n(28); f(29);
  delay(delayms);

  f(25); n(26); n(27); f(28); f(29);
  delay(delayms);

  n(25); n(26); f(27); f(28); f(29);
  delay(delayms);

  n(25); f(26); f(27); f(28); f(29);
  delay(delayms);
}




void randomCube() {
  int kolom;
  int layer;

  kolom = random(30);
  //  layer = random(5) + 25;
  n(kolom);
  //  n(layer);
  delay(delayms);

  kolom = random(30);
  //  layer = random(5) + 25;
  f(kolom);
  //  f(layer);
  delay(delayms);
}

void hujan() {
  int a, b, c, d, e;

  a = random(25); b = random(25); c = random(25); d = random(25); e = random(25);
  n(a); n(b); n(c); n(d); n(e);

  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);

  a = random(25); b = random(25); c = random(25); d = random(25); e = random(25);
  f(a); f(b); f(c); f(d); f(e);

  f(25); f(26); n(27); n(28); f(29);
  delay(delayms - 10);

  a = random(25); b = random(25); c = random(25); d = random(25); e = random(25);
  n(a); n(b); n(c); n(d); n(e);

  f(25); n(26); n(27); f(28); f(29);
  delay(delayms - 20);

  a = random(25); b = random(25); c = random(25); d = random(25); e = random(25);
  f(a); f(b); f(c); f(d); f(e);

  n(25); n(26); f(27); f(28); f(29);
  delay(delayms - 30);

  a = random(25); b = random(25); c = random(25); d = random(25); e = random(25);
  n(a); n(b); n(c); n(d); n(e);

  n(25); f(26); f(27); f(28); f(29);
  delay(delayms - 40);
}

void ulangTahun() {
  HBD();
  delay(100);
  CAYU();
  delay(100);
  DES16();
  delay(100);
}

void DES16() {
  //1
  n(0); f(5); n(10); n(15); n(20);
  n(1); f(6); n(11); f(16); f(21);
  n(2); f(7); n(12); n(17); n(22);
  n(3); f(8); n(13); f(18); n(23);
  n(4); f(9); n(14); n(19); n(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);

  //      //6
  //  f(0); n(5); n(10); n(15); f(20);
  //  f(1); n(6); f(11); f(16); f(21);
  //  f(2); n(7); n(12); n(17); f(22);
  //  f(3); n(8); f(13); n(18); f(23);
  //  f(4); n(9); n(14); n(19); f(24);
  //  f(25); f(26); f(27); n(28); n(29);
  //  delay(delayms);
  //  allOff();
  //  delay(delayms/3);

  //D
  f(0); f(5); f(10); n(15); f(20);
  f(1); f(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);

  //E
  f(0); n(5); n(10); n(15); f(20);
  f(1); n(6); f(11); f(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); f(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);

  //S
  f(0); n(5); n(10); n(15); f(20);
  f(1); n(6); f(11); f(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); f(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);

}

void CAYU() {
  //C
  f(0); f(5); f(10); f(15); f(20);
  f(1); n(6); n(11); n(16); f(21);
  f(2); n(7); f(12); f(17); f(22);
  f(3); n(8); f(13); f(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);

  //A
  f(0); n(5); n(10); n(15); f(20);
  f(1); n(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); n(18); f(23);
  f(4); n(9); f(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);

  //y
  f(0); n(5); f(10); n(15); f(20);
  f(1); n(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); f(8); n(13); f(18); f(23);
  f(4); f(9); n(14); f(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);


  //u
  f(0); f(5); f(10); f(15); f(20);
  f(1); n(6); f(11); n(16); f(21);
  f(2); n(7); f(12); n(17); f(22);
  f(3); n(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);
}


void HBD() {

  //H
  f(0); n(5); f(10); n(15); f(20);
  f(1); n(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); n(18); f(23);
  f(4); n(9); f(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);

  //B
  f(0); n(5); f(10); f(15); f(20);
  f(1); n(6); f(11); f(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);

  //D
  f(0); f(5); f(10); n(15); f(20);
  f(1); f(6); f(11); n(16); f(21);
  f(2); n(7); n(12); n(17); f(22);
  f(3); n(8); f(13); n(18); f(23);
  f(4); n(9); n(14); n(19); f(24);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  allOff();
  delay(delayms / 3);
}

void keBawah() {
  f(25); f(26); f(27); f(28); n(29);
  delay(delayms);
  f(25); f(26); f(27); n(28); n(29);
  delay(delayms);
  f(25); f(26); n(27); n(28); n(29);
  delay(delayms);
  f(25); n(26); n(27); n(28); n(29);
  delay(delayms);
  n(25); n(26); n(27); n(28); n(29);
  delay(delayms);
}

void layerAll() {
  n(25); n(26); n(27); n(28); n(29);
}

void geserBawah() {
  f(25); f(26); f(27); f(28); n(29);
  delay(delayms);
  f(25); f(26); f(27); n(28); f(29);
  delay(delayms);
  f(25); f(26); n(27); f(28); f(29);
  delay(delayms);
  f(25); n(26); f(27); f(28); f(29);
  delay(delayms);
  n(25); f(26); f(27); f(28); f(29);
  delay(delayms);
}

void berputarPutar() {
  n(25); n(26); n(27); n(28); n(29);
  berputar();

  f(25); n(26); n(27); n(28); f(29);
  berputar();

  f(25); f(26); n(27); f(28); f(29);
  berputar();

  f(25); n(26); n(27); n(28); f(29);
  berputar();

  n(25); n(26); n(27); n(28); n(29);
  berputar();

  n(25); n(26); f(27); n(28); n(29);
  berputar();

  n(25); f(26); f(27); f(28); n(29);
  berputar();

  n(25); n(26); f(27); n(28); n(29);
  berputar();
}


void berputar() {
  n(12);

  n(2); n(7); n(17); n(22);
  delay(delayms);
  f(2); f(7); f(17); f(22);

  n(4); n(8); n(16); n(20);
  delay(delayms);
  f(4); f(8); f(16); f(20);

  n(10); n(11); n(13); n(14);
  delay(delayms);
  f(10); f(11); f(13); f(14);

  n(0); n(6); n(18); n(24);
  delay(delayms);
  f(0); f(6); f(18); f(24);

  allOff();
}

void mekarMekar() {
  mekar();
  nutup();
}
void mekar() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  regWrite(12, HIGH);
  delay(delayms * 2);

  for (int i = 6; i < 16; i += 5) {
    regWrite(i, HIGH);
  }
  for (int i = 16; i < 18; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 18; i >= 8; i -= 5) {
    regWrite(i, HIGH);
  }
  for (int i = 7; i >= 6; i--) {
    regWrite(i, HIGH);
  }
  delay(delayms * 2);

  for (int i = 0; i < 20; i += 5) {
    regWrite(i, HIGH);
  }
  for (int i = 20; i < TINGGI; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 24; i >= 4; i -= 5) {
    regWrite(i, HIGH);
  }
  for (int i = 4; i >= 0; i--) {
    regWrite(i, HIGH);
  }
  delay(delayms * 2);
}


void nutup() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }

  for (int i = 0; i < 20; i += 5) {
    regWrite(i, LOW);
  }
  for (int i = 20; i < TINGGI; i++) {
    regWrite(i, LOW);
  }
  for (int i = 24; i >= 4; i -= 5) {
    regWrite(i, LOW);
  }
  for (int i = 4; i >= 0; i--) {
    regWrite(i, LOW);
  }
  delay(delayms * 2);

  for (int i = 6; i < 16; i += 5) {
    regWrite(i, LOW);
  }
  for (int i = 16; i < 18; i++) {
    regWrite(i, LOW);
  }
  for (int i = 18; i >= 8; i -= 5) {
    regWrite(i, LOW);
  }
  for (int i = 7; i >= 6; i--) {
    regWrite(i, LOW);
  }
  delay(delayms * 2);

  regWrite(12, LOW);
  delay(delayms * 2);
}


void muterMuter(int j) {
  for (int layer = TINGGI; layer < MAX; layer++) {
    for (int k = TINGGI; k < MAX; k++) {
      if (k == layer) {
        regWrite(k, HIGH);
      }
      else {
        regWrite(k, LOW);
      }
    }
    for (int i = 0; i < 20; i += 5) {
      regWrite(i, HIGH);
      delay(j);
      regWrite(i, LOW);
    }
    for (int i = 20; i < TINGGI; i++) {
      regWrite(i, HIGH);
      delay(j);
      regWrite(i, LOW);
    }
    for (int i = 24; i >= 4; i -= 5) {
      regWrite(i, HIGH);
      delay(j);
      regWrite(i, LOW);
    }
    for (int i = 4; i >= 0; i--) {
      regWrite(i, HIGH);
      delay(j);
      regWrite(i, LOW);
    }
    j -= 2;
  }

  for (int layer = MAX - 1; layer >= TINGGI; layer--) {
    for (int k = TINGGI; k < MAX; k++) {
      if (k == layer) {
        regWrite(k, HIGH);
      }
      else {
        regWrite(k, LOW);
      }
    }
    for (int i = 6; i < 16; i += 5) {
      regWrite(i, HIGH);
      delay(j);
      regWrite(i, LOW);
    }
    for (int i = 16; i < 18; i++) {
      regWrite(i, HIGH);
      delay(j);
      regWrite(i, LOW);
    }
    for (int i = 18; i >= 8; i -= 5) {
      regWrite(i, HIGH);
      delay(j);
      regWrite(i, LOW);
    }
    for (int i = 7; i >= 6; i--) {
      regWrite(i, HIGH);
      delay(j);
      regWrite(i, LOW);
    }
    j -= 2;
  }

  for (int layer = TINGGI; layer < MAX; layer++) {
    regWrite(12, HIGH);
    regWrite(layer, HIGH);
    delay(j);
    j -= 2;
  }
  regWrite(12, LOW);
  delay(100);
}




//void buzzer() {
//  digitalWrite(buzzer, HIGH);
//  delay(100);
//  digitalWrite(buzzer, LOW);
//  delay(100);
//}


void blinks() {
  allOn();
  delay(delayms);
  allOff();
  delay(delayms);
}

void allOn() {
  for (int i = 0; i < MAX; i++) {
    regWrite(i, HIGH);
  }
}

void allOff() {
  for (int i = 0; i < MAX; i++) {
    regWrite(i, LOW);
  }
}


void geserGeser() {
  barisJalanKanan();
  kolomMaju();
  barisJalanKiri();
  kolomMundur();
  allOff();
}


void kolomMaju() {
  kolom5();
  delay(delayms);
  kolom4();
  delay(delayms);
  kolom3();
  delay(delayms);
  kolom2();
  delay(delayms);
  kolom1();
  delay(delayms);
}


void kolomMundur() {
  kolom1();
  delay(delayms);
  kolom2();
  delay(delayms);
  kolom3();
  delay(delayms);
  kolom4();
  delay(delayms);
  kolom5();
  delay(delayms);
}


void kolom1() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  int j = 0;
  for (int i = 0; i < 25; i++) {
    if (i == j) {
      regWrite(i, HIGH);
      j += 5;
    }
    else {
      regWrite(i, LOW);
    }
  }
}
void kolom2() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  int j = 1;
  for (int i = 0; i < 25; i++) {
    if (i == j) {
      regWrite(i, HIGH);
      j += 5;
    }
    else {
      regWrite(i, LOW);
    }
  }
}

void kolom3() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  int j = 2;
  for (int i = 0; i < 25; i++) {
    if (i == j) {
      regWrite(i, HIGH);
      j += 5;
    }
    else {
      regWrite(i, LOW);
    }
  }
}

void kolom4() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  int j = 3;
  for (int i = 0; i < 25; i++) {
    if (i == j) {
      regWrite(i, HIGH);
      j += 5;
    }
    else {
      regWrite(i, LOW);
    }
  }
}

void kolom5() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  int j = 4;
  for (int i = 0; i < 25; i++) {
    if (i == j) {
      regWrite(i, HIGH);
      j += 5;
    }
    else {
      regWrite(i, LOW);
    }
  }
}


void barisJalanKanan() {
  baris1();
  delay(delayms);
  baris2();
  delay(delayms);
  baris3();
  delay(delayms);
  baris4();
  delay(delayms);
  baris5();
  delay(delayms);
}

void barisJalanKiri() {
  baris5();
  delay(delayms);
  baris4();
  delay(delayms);
  baris3();
  delay(delayms);
  baris2();
  delay(delayms);
  baris1();
  delay(delayms);
}


void baris1() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 0; i < 5; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 5; i < TINGGI; i++) {
    regWrite(i, LOW);
  }
}

void baris2() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 5; i < 10; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 10; i < TINGGI; i++) {
    regWrite(i, LOW);
  }
  for (int i = 0; i < 5; i++) {
    regWrite(i, LOW);
  }
}

void baris3() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 10; i < 15; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 15; i < TINGGI; i++) {
    regWrite(i, LOW);
  }
  for (int i = 0; i < 10; i++) {
    regWrite(i, LOW);
  }
}

void baris4() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 15; i < 20; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 20; i < TINGGI; i++) {
    regWrite(i, LOW);
  }
  for (int i = 0; i < 15; i++) {
    regWrite(i, LOW);
  }
}

void baris5() {
  for (int i = TINGGI; i < MAX; i++) {
    regWrite(i, HIGH);
  }
  for (int i = 20; i < 25; i++) {
    regWrite(i, HIGH);
  }
  //  for (int i = 10; i < TINGGI; i++) {
  //    regWrite(i, LOW);
  //  }
  for (int i = 0; i < 20; i++) {
    regWrite(i, LOW);
  }
}

void n(int pin) {
  regWrite(pin, HIGH);
}

void f(int pin) {
  regWrite(pin, LOW);
}

void regWrite(int pin, bool state) {
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);

  //Begin session
  digitalWrite(latchPin, LOW);

  for (int i = 0; i < numOfRegisters; i++) {
    //Get actual states for register
    byte* states = &registerState[i];

    //Update state
    if (i == reg) {
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin, clockPin, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin, HIGH);
}
