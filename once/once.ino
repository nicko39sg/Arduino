

//Canal a leer  R/L
int Audio1 = A3;       //Entrada de audio 1
int Audio2 = A6;       //Entrada de audio 2
int r;
int l;

//-----------------------------------------------------
int Vibrator1 = A0;   //Salida a vibrador 1
int Vibrator2 = A1;   //Salida a vibrador 2
int Vibrator3 = A2;   //Salida a vibrador 3

int ledPin = 13;
//-----------------------------------------------------
void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  pinMode(Vibrator1, OUTPUT);
  pinMode(Vibrator2, OUTPUT);
  pinMode(Vibrator3, OUTPUT);
  
  pinMode(Audio1, INPUT);
  pinMode(Audio2, INPUT);
}

void loop() {
  
  r = analogRead(Audio1);
  l = analogRead(Audio2);
   Serial.println(r);
    Serial.println(l);
  
  analogWrite(Vibrator3,l);
  // Serial.println(Vibrator);
  delay(r);
  
}
