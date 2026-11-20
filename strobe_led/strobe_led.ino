const int jumlahLED = 5;
const int pinLED[jumlahLED] = {8, 9, 10, 11, 12};

void setup() {
  for (int i = 0; i < jumlahLED; i++) {
    pinMode(pinLED[i], OUTPUT);
    digitalWrite(pinLED[i], LOW);
  }
  randomSeed(analogRead(A0)); 
}

void loop() {
  int modePilihan = random(0, 4); 

  switch (modePilihan) {
    case 0: strobeSerempak(); break;
    case 1: kedipAcakSatuSatu(); break;
    case 2: kedipAcakBeberapa(); break;
    case 3: sapuanCepat(); break;
  }
}


void strobeSerempak() {
  int jumlahKedip = random(3, 8);
  for (int k = 0; k < jumlahKedip; k++) {
    semuaLED(HIGH);
    delay(random(30, 80));
    semuaLED(LOW);
    delay(random(30, 80));
  }
}


void kedipAcakSatuSatu() {
  int jumlahLangkah = random(5, 12);
  for (int k = 0; k < jumlahLangkah; k++) {
    int pilih = random(0, jumlahLED);
    digitalWrite(pinLED[pilih], HIGH);
    delay(random(40, 100));
    digitalWrite(pinLED[pilih], LOW);
    delay(random(10, 40));
  }
}

void kedipAcakBeberapa() {
  int jumlahLangkah = random(4, 9);
  for (int k = 0; k < jumlahLangkah; k++) {
    for (int i = 0; i < jumlahLED; i++) {
      digitalWrite(pinLED[i], random(0, 2)); 
    }
    delay(random(50, 120));
  }
  semuaLED(LOW);
}

void sapuanCepat() {
  int putaran = random(1, 3);
  for (int p = 0; p < putaran; p++) {
    for (int i = 0; i < jumlahLED; i++) {
      semuaLED(LOW);
      digitalWrite(pinLED[i], HIGH);
      delay(random(25, 60));
    }
    for (int i = jumlahLED - 1; i >= 0; i--) {
      semuaLED(LOW);
      digitalWrite(pinLED[i], HIGH);
      delay(random(25, 60));
    }
  }
  semuaLED(LOW);
}

void semuaLED(int status) {
  for (int i = 0; i < jumlahLED; i++) {
    digitalWrite(pinLED[i], status);
  }
}
