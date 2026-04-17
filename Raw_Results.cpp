const int pinDigital = A3;

int valeurDigital = 0;
float mean = 0;
unsigned long temp1 = 0;
unsigned long temp2 = 0;
float delta = 0;
float lambda = 0;
char c;

void setup() {
  Serial.begin(9600);
  Serial.println("temps_ms,lambda_Hz");

  pinMode(pinDigital, INPUT_PULLUP); // IMPORTANT !
}

void loop() {

  valeurDigital = digitalRead(pinDigital);

  if (valeurDigital == 1) { 
    temp2 = millis();

    delta = temp2 - temp1;
    lambda = 1000.0 / delta;

    Serial.print(temp2);
    Serial.print(",");
    Serial.println(lambda);
    char c = Serial.read();
    if (c == 'q') {
      Serial.println("Q reçu, boucle infinie !");
      while (true) {
        // boucle infinie
      }
    }

    // attendre relâchement
    while (digitalRead(pinDigital) == 1) {}

    temp1 = millis();
  }
}
