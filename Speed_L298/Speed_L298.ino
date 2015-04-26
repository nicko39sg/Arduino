// Motor 1
int dir1PinA = 8;
int dir2PinA = 9;
int speedPinA = 10; //PWM Para controlar la velocidad
int speed1 =0;

// Motor 2
int dir1PinB = 11;
int dir2PinB = 12;
int speedPinB = 13; //PWM Para controlar la velocidad
int speed2= 0;

//Sensor 1
int trigPin1=3; 
int echoPin1=2;
float pingTime1;  //tiempo que tarda el eco
float targetDistancia1; 
float velocidadSonido1=776.5;

//Sensor 2
int trigPin2=5; 
int echoPin2=4;
float pingTime2;  //tiempo que tarda el eco
float targetDistancia2; 
float velocidadSonido2=776.5;

//Star
int Star = 7;


//Luz Semaforo de inicio
 int Rojo = 45;
 int Amarillo =47;
 int Verde =49;
 int Sonido =46;
 int contador =0;

void setup() {  
// Inicializamos comunicacion serie
Serial.begin(9600);

//Definimos los pines del L298N Dual H-Bridge Motor Controller 

pinMode(dir1PinA,OUTPUT);
pinMode(dir2PinA,OUTPUT);
pinMode(speedPinA,OUTPUT);
pinMode(dir1PinB,OUTPUT);
pinMode(dir2PinB,OUTPUT);
pinMode(speedPinB,OUTPUT);

//Definimos los Pines del Sensor de distancia HC-SR04

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);


//Definimos un start
pinMode(Star, INPUT);

//Definimos los Leds del Semaforo

pinMode(Rojo,OUTPUT);
pinMode(Amarillo,OUTPUT);
pinMode(Verde,OUTPUT);
pinMode(Sonido,OUTPUT);
}

void loop() {
  
  
  
  
//Configuracion de star

//int estado = digitalRead(Star);

//if (estado == 0){
  
// Configuracion De Luces

if (contador == 0){
Serial.println("lets star");
analogWrite(speedPinA, 0);//Sets speed variable via PWM 
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, LOW);
analogWrite(speedPinB, 0);//Sets speed variable via PWM 
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, LOW);
digitalWrite(Rojo,HIGH);
Serial.println("Preparados");

delay(2000);
digitalWrite(Amarillo,HIGH);
Serial.println("Calentando Motores");
delay(2000);
digitalWrite(Verde,HIGH);
Serial.println("YA!!!! YA!!!");
delay(100);


digitalWrite(Sonido,HIGH);
delay(1000);
digitalWrite(Sonido,LOW);
digitalWrite(Rojo,LOW);
digitalWrite(Amarillo,LOW);
digitalWrite(Verde,LOW);
contador = 1;
}
 
//Control con los sensores de distacia HC-SR04
digitalWrite(trigPin1, LOW);
//digitalWrite(trigPin2, LOW);
delayMicroseconds(2000); 
digitalWrite(trigPin1, HIGH);
//digitalWrite(trigPin2, HIGH); 
delayMicroseconds(15); 
digitalWrite(trigPin1, LOW); 
//digitalWrite(trigPin2, LOW); 
delayMicroseconds(10); 



//Calculo de distacia de los sensores

pingTime1 = pulseIn(echoPin1, HIGH);
//pingTime2 = pulseIn(echoPin2, HIGH); 
 
pingTime1=pingTime1/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
pingTime1=pingTime1/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
targetDistancia1= velocidadSonido1 * pingTime1; 
targetDistancia1=targetDistancia1/2; 
targetDistancia1= targetDistancia1*63360;    //Convert miles to inches by multipling by 63360 (inches per mile)
  
   //digitalWrite(trigPin1, LOW);
digitalWrite(trigPin2, LOW);
delayMicroseconds(2000); 
//digitalWrite(trigPin1, HIGH);
digitalWrite(trigPin2, HIGH); 
delayMicroseconds(15); 
//digitalWrite(trigPin1, LOW); 
digitalWrite(trigPin2, LOW); 
delayMicroseconds(10); 
   
pingTime2 = pulseIn(echoPin2, HIGH); 
   
pingTime2=pingTime2/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second) 
pingTime2=pingTime2/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
targetDistancia2= velocidadSonido2 * pingTime2; 
targetDistancia2=targetDistancia2/2; 
targetDistancia2= targetDistancia2*63360;    //Convert miles to inches by multipling by 63360 (inches per mile)

Serial.print("Distancia al objetivo del sensor 1: ");
Serial.print(targetDistancia1);
Serial.println("inches");

Serial.print("Distancia al objetivo del sensor 2: ");
Serial.print(targetDistancia2);
Serial.println("inches");

//Calculo de las velocidades de los Motores
speed1 = (106./7.) * targetDistancia1 + 37;
speed2 = (106./7.) * targetDistancia2 + 37;

//Limitador de velocidad maxima y minima
/*
if (speed1 > 255){
  speed1 = 230;
}
if (speed2 > 255){
  speed1 = 230;
}

if (speed1 < 50){
  speed1 = 100;
}
if (speed2 > 50){
  speed2 = 100;
}
*/

//Motor 1
analogWrite(speedPinA, speed1);//Sets speed variable via PWM 
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.print("Motor 1---");
Serial.print(speed1);
Serial.println("   "); 

//Motor 2
analogWrite(speedPinB, speed2);//Sets speed variable via PWM 
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.print("Motor 2---"); 
Serial.print(speed2);
Serial.println("   ");


}
/*else{
Serial.println("Come on");
analogWrite(speedPinA, 0);//Sets speed variable via PWM 
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, LOW);
analogWrite(speedPinB, 0);//Sets speed variable via PWM 
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, LOW);
  }*/

/*Control manual
if (Serial.available() > 0) {
int inByte = Serial.read();
int speed; // Local variable

switch (inByte) {

//______________Motor 1______________

case '1': // Motor 1 Forward
analogWrite(speedPinA, 255);//Sets speed variable via PWM 
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Motor 1 Forward"); // Prints out â€œMotor 1 Forwardâ€ on the serial monitor
Serial.println("   "); // Creates a blank line printed on the serial monitor
break;

case '2': // Motor 1 Stop (Freespin)
analogWrite(speedPinA, 0);
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Motor 1 Stop");
Serial.println("   ");
break;

case '3': // Motor 1 Reverse
analogWrite(speedPinA, 255);
digitalWrite(dir1PinA, HIGH);
digitalWrite(dir2PinA, LOW);
Serial.println("Motor 1 Reverse");
Serial.println("   ");
break;

//______________Motor 2______________

case '4': // Motor 2 Forward
analogWrite(speedPinB, 100);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.println("Motor 2 Forward");
Serial.println("   ");
break;

case '5': // Motor 1 Stop (Freespin)
analogWrite(speedPinB, 0);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.println("Motor 2 Stop");
Serial.println("   ");
break;

case '6': // Motor 2 Reverse
analogWrite(speedPinB, 255);
digitalWrite(dir1PinB, HIGH);
digitalWrite(dir2PinB, LOW);
Serial.println("Motor 2 Reverse");
Serial.println("   ");
break;

default:
// turn all the connections off if an unmapped key is pressed:
for (int thisPin = 2; thisPin < 11; thisPin++) {
digitalWrite(thisPin, LOW);
}
  }
    }
      }*/
      
