const int pinDigital = 12;

int valeurDigital = 0;
int i = -1;
float mean = 0;
unsigned long temp1 = 0;
unsigned long temp2 = 0;
float delta = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pinDigital, INPUT_PULLUP); // IMPORTANT !
}

void loop() {

  valeurDigital = digitalRead(pinDigital);

  if (valeurDigital == 1) { 
    temp2 = millis();

    delta = temp2 - temp1;

    i++;

    if (i >= 1 && delta > 0) {
      mean += ((float)delta - mean) / i;
      Serial.println((float)1000 / mean);
    }

    // attendre relâchement
    while (digitalRead(pinDigital) == 1) {}

    temp1 = millis();
  }
}
