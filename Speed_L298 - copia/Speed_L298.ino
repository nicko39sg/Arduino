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
int Dato;  //Recoge dato por puerto serie

  //PID
  int PID =0;                      //PID desactivado al Inicio
  #define CNY70_M_DAR      2                      
  #define CNY70_M_DAB      3 
  #define CNY70_M_IAR      2                      
  #define CNY70_M_IAB      3

  //Motor 1
  int speed_req1 = 80;             // Set Point
  int speed_act1 = 0;              //Valor Actual
  int PWM_val1 = 0;                                                             
  volatile long count = 0;         //Revolution counter
  volatile int count1 = 0;         //Revolution counter for position
  float Kp1 = 0.4;                 //Setting Kp 
  float Kd1 = 1;                   //Setting Kd
  
//Velocidades
int GlobalSpeed   = 125;
int GlobalSpeedB2 = 125;
int GlobalSpeedA2 = 125;
int GlobalSpeedB1 = 125;
int GlobalSpeedA1 = 125;



//Motor Derecha-Arriba               (1)
int dir_IN3_2    = 30;   //Morado
int dir_IN4_2    = 28;   //Gris
int speed_EN_B_2 = 6;    //Blanco

//Motor Derecha-Abajo                (2)
int dir_IN1_2    = 24;   //Verde
int dir_IN2_2    = 26;   //Azul
int speed_EN_A_2 = 7;    //Amarillo

//Motor Izquierda-Arriba             (3)
int dir_IN3_1    = 29;   //Morado
int dir_IN4_1   = 27;    //Gris
int speed_EN_B_1 = 8;    //Blanco

//Motor Izquierda-Abajo              (4)
int dir_IN1_1    = 23;   //Verde
int dir_IN2_1    = 25;   //Azul
int speed_EN_A_1 = 9;    //Amarillo


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {  
  
// Inicializamos comunicacion serie
Serial.begin(115600);

Serial.println("");

  //Encoder para el PID
  pinMode(CNY70_M_DAR, INPUT);                                                     
  pinMode(CNY70_M_DAB, INPUT);
  pinMode(CNY70_M_IAR, INPUT);                                                     
  pinMode(CNY70_M_IAB, INPUT);
  
  //Activamos Los Encoder
  digitalWrite(CNY70_M_DAR, HIGH);                     
  digitalWrite(CNY70_M_DAB, HIGH);                     
  digitalWrite(CNY70_M_IAR, HIGH);
  digitalWrite(CNY70_M_IAB, HIGH);


//Definimos los pines del L298N Dual H-Bridge Motor Controller 

  //Motor Derecha-Arriba               (1)
  pinMode(dir_IN3_2,    OUTPUT);
  pinMode(dir_IN4_2,    OUTPUT);
  pinMode(speed_EN_B_2, OUTPUT);

  //Motor Derecha-Abajo                (2)
  pinMode(dir_IN1_2,    OUTPUT);
  pinMode(dir_IN2_2,    OUTPUT);
  pinMode(speed_EN_A_2, OUTPUT);

  //Motor Izquierda-Arriba             (3)
  pinMode(dir_IN3_1,    OUTPUT);
  pinMode(dir_IN4_1,    OUTPUT);
  pinMode(speed_EN_B_1, OUTPUT);

  //Motor Izquierda-Abajo              (4)
  pinMode(dir_IN1_1,    OUTPUT);
  pinMode(dir_IN2_1,    OUTPUT);
  pinMode(speed_EN_A_1, OUTPUT);

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
 
 if (Serial.available() > 0) {
   
     Dato = Serial.read();
     Serial.flush();
     
switch (Dato) {
  
      case 'w'://Hacia Delante
      
        Serial.println("Hacia Delante");
 
        analogWrite(speed_EN_B_2, GlobalSpeedB2);
        analogWrite(speed_EN_A_2, GlobalSpeedA2);
        analogWrite(speed_EN_B_1, GlobalSpeedB1);
        analogWrite(speed_EN_A_1, GlobalSpeedA1);
        
        //Motor Derecha-Arriba               (1) 
        digitalWrite(dir_IN3_2, HIGH);
        digitalWrite(dir_IN4_2, LOW);
        //Motor Derecha-Abajo                (2) 
        digitalWrite(dir_IN1_2, HIGH);
        digitalWrite(dir_IN2_2, LOW);
        //Motor Izquierda-Arriba             (3)
        digitalWrite(dir_IN3_1, HIGH);
        digitalWrite(dir_IN4_1, LOW);
        //Motor Izquierda-Abajo              (4) 
        digitalWrite(dir_IN1_1, HIGH);
        digitalWrite(dir_IN2_1, LOW);
        
      break;
        
      case 's'://Hacia Atras

        Serial.println("Hacia Atras");
       
        analogWrite(speed_EN_B_2, GlobalSpeedB2);
        analogWrite(speed_EN_A_2, GlobalSpeedA2);
        analogWrite(speed_EN_B_1, GlobalSpeedB1);
        analogWrite(speed_EN_A_1, GlobalSpeedA1);
        
        //Motor Derecha-Arriba               (1) 
        digitalWrite(dir_IN3_2, LOW);
        digitalWrite(dir_IN4_2, HIGH);
        //Motor Derecha-Abajo                (2)
        digitalWrite(dir_IN1_2, LOW);
        digitalWrite(dir_IN2_2, HIGH);
        //Motor Izquierda-Arriba             (3)
        digitalWrite(dir_IN3_1, LOW);
        digitalWrite(dir_IN4_1, HIGH);
        //Motor Izquierda-Abajo              (4)
        digitalWrite(dir_IN1_1, LOW);
        digitalWrite(dir_IN2_1, HIGH);
       
      break;
        
      case 'a'://Izquierda
          
        Serial.println("Izquierda");      
      
        analogWrite(speed_EN_B_2, GlobalSpeedB2);
        analogWrite(speed_EN_A_2, GlobalSpeedA2);
        analogWrite(speed_EN_B_1, GlobalSpeedB1);
        analogWrite(speed_EN_A_1, GlobalSpeedA1);
        
        //Motor Derecha-Arriba               (1) 
        digitalWrite(dir_IN3_2, LOW);
        digitalWrite(dir_IN4_2, HIGH);
        //Motor Derecha-Abajo                (2) 
        digitalWrite(dir_IN1_2, LOW);
        digitalWrite(dir_IN2_2, HIGH);
        //Motor Izquierda-Arriba             (3)
        digitalWrite(dir_IN3_1, LOW);
        digitalWrite(dir_IN4_1, HIGH);
        //Motor Izquierda-Abajo              (4)
        digitalWrite(dir_IN1_1, LOW);
        digitalWrite(dir_IN2_1, HIGH);
       
      break;
        
      case 'd'://Derecha
      
        Serial.println("Derecha"); 
      
        analogWrite(speed_EN_B_2, GlobalSpeedB2);
        analogWrite(speed_EN_A_2, GlobalSpeedA2);
        analogWrite(speed_EN_B_1, GlobalSpeedB1);
        analogWrite(speed_EN_A_1, GlobalSpeedA1);
        
        //Motor Derecha-Arriba               (1) 
        digitalWrite(dir_IN3_2, LOW);
        digitalWrite(dir_IN4_2, HIGH);
        //Motor Derecha-Abajo                (2) 
        digitalWrite(dir_IN1_2, LOW);
        digitalWrite(dir_IN2_2, HIGH);
        //Motor Izquierda-Arriba             (3)
        digitalWrite(dir_IN3_1, LOW);
        digitalWrite(dir_IN4_1, HIGH);
        //Motor Izquierda-Abajo              (4)
        digitalWrite(dir_IN1_1, LOW);
        digitalWrite(dir_IN2_1, HIGH);
        
      break;
        
      case 'e'://Rotar Derecha
      
        Serial.println("Rotar Derecha");
       
        analogWrite(speed_EN_B_2, GlobalSpeedB2);
        analogWrite(speed_EN_A_2, GlobalSpeedA2);
        analogWrite(speed_EN_B_1, GlobalSpeedB1);
        analogWrite(speed_EN_A_1, GlobalSpeedA1);
        
        //Motor Derecha-Arriba               (1) 
        digitalWrite(dir_IN3_2, LOW);
        digitalWrite(dir_IN4_2, HIGH);
        //Motor Derecha-Abajo                (2)
        digitalWrite(dir_IN1_2, LOW);
        digitalWrite(dir_IN2_2, HIGH);
        //Motor Izquierda-Arriba             (3)
        digitalWrite(dir_IN3_1, LOW);
        digitalWrite(dir_IN4_1, HIGH);
        //Motor Izquierda-Abajo              (4)
        digitalWrite(dir_IN1_1, LOW);
        digitalWrite(dir_IN2_1, HIGH);
      break;
        
      case 'q'://Rotar Izquierda
      
        Serial.println("Rotar Izquierda");
      
        analogWrite(speed_EN_B_2, GlobalSpeedB2);
        analogWrite(speed_EN_A_2, GlobalSpeedA2);
        analogWrite(speed_EN_B_1, GlobalSpeedB1);
        analogWrite(speed_EN_A_1, GlobalSpeedA1);
        
        //Motor Derecha-Arriba               (1) 
        digitalWrite(dir_IN3_2, LOW);
        digitalWrite(dir_IN4_2, HIGH);
        //Motor Derecha-Abajo                (2) 
        digitalWrite(dir_IN1_2, LOW);
        digitalWrite(dir_IN2_2, HIGH);
        //Motor Izquierda-Arriba             (3)
        digitalWrite(dir_IN3_1, LOW);
        digitalWrite(dir_IN4_1, HIGH);
        //Motor Izquierda-Abajo              (4)
        digitalWrite(dir_IN1_1, LOW);
        digitalWrite(dir_IN2_1, HIGH);
        
      break;
        
      case '1'://Speed UP
      
          if (PID =0){
            Serial.println("Speed UP");
      
            if (GlobalSpeed < GlobalSpeed){
        
              GlobalSpeed = GlobalSpeed + 25;
        
              GlobalSpeedB2 = GlobalSpeed;
              GlobalSpeedA2 = GlobalSpeed;
              GlobalSpeedB1 = GlobalSpeed;
              GlobalSpeedA1 = GlobalSpeed;
        
              //TEST
               Serial.print("SPB2:"); Serial.println(GlobalSpeedB2);
               Serial.print("SPA2:"); Serial.println(GlobalSpeedA2);
               Serial.print("SPB1:"); Serial.println(GlobalSpeedB1);
               Serial.print("SPA1:"); Serial.println(GlobalSpeedA1);
         
      break;                             }
    
            else{
            Serial.println("Speep MAX");  
      break;    }
                    }
      
        else{
      Serial.println("Error PID is ON");  
      break;} 
        
      case '2'://Speed Down

          if (PID =0){
            Serial.println("Speed Down");
      
            if (GlobalSpeed < GlobalSpeed){
        
              GlobalSpeed = GlobalSpeed + 25;
        
              GlobalSpeedB2 = GlobalSpeed;
              GlobalSpeedA2 = GlobalSpeed;
              GlobalSpeedB1 = GlobalSpeed;
              GlobalSpeedA1 = GlobalSpeed;
        
              //TEST
               Serial.print("SPB2:"); Serial.println(GlobalSpeedB2);
               Serial.print("SPA2:"); Serial.println(GlobalSpeedA2);
               Serial.print("SPB1:"); Serial.println(GlobalSpeedB1);
               Serial.print("SPA1:"); Serial.println(GlobalSpeedA1);
         
      break;                             }
    
            else{
            Serial.println("Speep LOW");  
      break;    }
                    }
      
        else{
      Serial.println("Error PID is ON");  
      break;} 
      
      
      case '3'://Activacion de PID
      
        if (PID = 0){
          Serial.println("PID ON ");
          PID = 1;
      break;        }
      
        else{
          Serial.println("PID OFF");
          PID = 0;
      break;}
        
      
      default:{
       Serial.println("ERROR Comando No registrado");     
              }
        
  }        
 }
}

