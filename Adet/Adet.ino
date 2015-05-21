/*************************************************************************
/
/
/
/
/
/
/
/
/
/
/
/
/
/
/
/
/
/
**************************************************************************/
//Variables 
int Dato;
int GlobalSpeed = 125;


//Motor Derecha-Arriba 
int dir_IN3.2    = 30;   //Morado
int dir_IN4.2    = 28;   //Gris
int speed_EN.B.2 = 6;    //Blanco
int CNY70_M.DAR  = 0;

//Motor Derecha-Abajo 
int dir_IN1.2    = 24;   //Verde
int dir_IN2.2    = 26;   //Azul
int speed_EN.A.2 = 7;    //Amarillo
int CNY70_M.DAB  = 0;

//Motor Izquierda-Arriba
int dir_IN3.1    = 29;   //Morado
int dir_IN4.1   = 27;    //Gris
int speed_EN.B.1 = 8;    //Blanco
int CNY70_M.IAR  = 0;

//Motor Izquierda-Abajo 
int dir_IN1.1    = 23;   //Verde
int dir_IN2.1    = 25;   //Azul
int speed_EN.A.1 = 9;    //Amarillo
int CNY70_M.IAB  = 0;



void setup() {  
  
// Inicializamos comunicacion serie
Serial.begin(9600);

//Definimos los pines del L298N Dual H-Bridge Motor Controller 

//Motor Derecha-Arriba 
pinMode(dir_IN3.2,    OUTPUT);
pinMode(dir_IN4.2,    OUTPUT);
pinMode(speed_EN.B.2, OUTPUT);
pinMode(CNY70_M.DAR,   INPUT);

//Motor Derecha-Abajo 
pinMode(dir_IN1.2,    OUTPUT);
pinMode(dir_IN2.2,    OUTPUT);
pinMode(speed_EN.A.2, OUTPUT);
pinMode(CNY70_M.DAB,   INPUT);

//Motor Izquierda-Arriba
pinMode(dir_IN3.1,    OUTPUT);
pinMode(dir_IN4.1,    OUTPUT);
pinMode(speed_EN.B.1, OUTPUT);
pinMode(CNY70_M.IAR,   INPUT);

//Motor Izquierda-Abajo 
pinMode(dir_IN1.1,    OUTPUT);
pinMode(dir_IN2.1,    OUTPUT);
pinMode(speed_EN.A.1, OUTPUT);
pinMode(CNY70_M.IAB,   INPUT);

}

void loop() {
 
 if (Serial.available() > 0) {

switch (Dato = Serial.read()) {
  
      case 'w'://Hacia Delante
Serial.println("Hacia Delante");
 
        analogWrite(speed_EN.B.2, 255);
        analogWrite(speed_EN.A.2, 255);
        analogWrite(speed_EN.B.1, 255);
        analogWrite(speed_EN.A.1, 255);
        
        //Motor Derecha-Arriba 
        digitalWrite(dir_IN3.2, HIGH);
        digitalWrite(dir_IN4.2, LOW);
        //Motor Derecha-Abajo 
        digitalWrite(dir_IN1.2, HIGH);
        digitalWrite(dir_IN2.2, LOW);
        //Motor Izquierda-Arriba
        digitalWrite(dir_IN3.1, HIGH);
        digitalWrite(dir_IN4.1, LOW);
        //Motor Izquierda-Abajo 
        digitalWrite(dir_IN1.1, HIGH);
        digitalWrite(dir_IN2.1, LOW);
        
      break;
        
      case 's'://Hacia Atras
Serial.println("Hacia Atras");
       
        analogWrite(speed_EN.B.2, 255);
        analogWrite(speed_EN.A.2, 255);
        analogWrite(speed_EN.B.1, 255);
        analogWrite(speed_EN.A.1, 255);
        
        //Motor Derecha-Arriba 
        digitalWrite(dir_IN3.2, LOW);
        digitalWrite(dir_IN4.2, HIGH);
        //Motor Derecha-Abajo 
        digitalWrite(dir_IN1.2, LOW);
        digitalWrite(dir_IN2.2, HIGH);
        //Motor Izquierda-Arriba
        digitalWrite(dir_IN3.1, LOW);
        digitalWrite(dir_IN4.1, HIGH);
        //Motor Izquierda-Abajo 
        digitalWrite(dir_IN1.1, LOW);
        digitalWrite(dir_IN2.1, HIGH);
       
      break;
        
      case 'a'://Izquierda
Serial.println("Izquierda");      
      
        analogWrite(speed_EN.B.2, 255);
        analogWrite(speed_EN.A.2, 255);
        analogWrite(speed_EN.B.1, 255);
        analogWrite(speed_EN.A.1, 255);
        
        //Motor Derecha-Arriba 
        digitalWrite(dir_IN3.2, LOW);
        digitalWrite(dir_IN4.2, HIGH);
        //Motor Derecha-Abajo 
        digitalWrite(dir_IN1.2, LOW);
        digitalWrite(dir_IN2.2, HIGH);
        //Motor Izquierda-Arriba
        digitalWrite(dir_IN3.1, LOW);
        digitalWrite(dir_IN4.1, HIGH);
        //Motor Izquierda-Abajo 
        digitalWrite(dir_IN1.1, LOW);
        digitalWrite(dir_IN2.1, HIGH);
       
      break;
        
      case 'd'://Derecha
Serial.println("Derecha"); 
      
        analogWrite(speed_EN.B.2, 255);
        analogWrite(speed_EN.A.2, 255);
        analogWrite(speed_EN.B.1, 255);
        analogWrite(speed_EN.A.1, 255);
        
        //Motor Derecha-Arriba 
        digitalWrite(dir_IN3.2, LOW);
        digitalWrite(dir_IN4.2, HIGH);
        //Motor Derecha-Abajo 
        digitalWrite(dir_IN1.2, LOW);
        digitalWrite(dir_IN2.2, HIGH);
        //Motor Izquierda-Arriba
        digitalWrite(dir_IN3.1, LOW);
        digitalWrite(dir_IN4.1, HIGH);
        //Motor Izquierda-Abajo 
        digitalWrite(dir_IN1.1, LOW);
        digitalWrite(dir_IN2.1, HIGH
        
      break;
        
      case 'e'://Rotar Derecha
Serial.println("Rotar Derecha");
       
        analogWrite(speed_EN.B.2, 255);
        analogWrite(speed_EN.A.2, 255);
        analogWrite(speed_EN.B.1, 255);
        analogWrite(speed_EN.A.1, 255);
        
        //Motor Derecha-Arriba 
        digitalWrite(dir_IN3.2, LOW);
        digitalWrite(dir_IN4.2, HIGH);
        //Motor Derecha-Abajo 
        digitalWrite(dir_IN1.2, LOW);
        digitalWrite(dir_IN2.2, HIGH);
        //Motor Izquierda-Arriba
        digitalWrite(dir_IN3.1, LOW);
        digitalWrite(dir_IN4.1, HIGH);
        //Motor Izquierda-Abajo 
        digitalWrite(dir_IN1.1, LOW);
        digitalWrite(dir_IN2.1, HIGH);
      break;
        
      case 'q'://Rotar Izquierda
Serial.println("Rotar Izquierda");
      
        analogWrite(speed_EN.B.2, 255);
        analogWrite(speed_EN.A.2, 255);
        analogWrite(speed_EN.B.1, 255);
        analogWrite(speed_EN.A.1, 255);
        
        //Motor Derecha-Arriba 
        digitalWrite(dir_IN3.2, LOW);
        digitalWrite(dir_IN4.2, HIGH);
        //Motor Derecha-Abajo 
        digitalWrite(dir_IN1.2, LOW);
        digitalWrite(dir_IN2.2, HIGH);
        //Motor Izquierda-Arriba
        digitalWrite(dir_IN3.1, LOW);
        digitalWrite(dir_IN4.1, HIGH);
        //Motor Izquierda-Abajo 
        digitalWrite(dir_IN1.1, LOW);
        digitalWrite(dir_IN2.1, HIGH);
        
      break;
        
      case '1'://Speed UP
Serial.println("Speed UP");
      
      if (GlobalSpeed < 255){
        
        GlobalSpeed = GlobalSpeed + 20; 
        
      break;
      }
    
      else{
      Serial.println("Speep MAX");  
      break;}
        
      case '2'://Speed Down
Serial.println("Speed Down");
      
      if (GlobalSpeed > 0){
      
        GlobalSpeed = GlobalSpeed - 20;
       
      break;
      }
      
      else{
      Serial.println("Speed LOW");
      break;}
        
      
      default:
       
        for (int thisPin = 2; thisPin < 7; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
        
  }        
 }
}

