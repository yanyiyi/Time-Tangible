////#include <Ultrasonic.h>
//#define TRIGGER_PIN  8
//#define ECHO_PIN     9
////Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
char val; // Data received from the serial port
int ledPin = 13; // Set the pin to digital I/O 13
boolean ledState = LOW; //to toggle our LED

int cellPin = A4;
int cellPin1 = A3;
int cellPin2 = A2;
int cellPin3 = A1;
int cellPin4 = A0;
int cellPin5 = A5;
int cellPin6 = A6;
int cellPin7 = A7;
int cellPin8 = A8;
int cellPin9 = A9;
int cellPin10 = A10;
int cellPin11 = A11;
int cellPin12 = A12;
int cellPin13 = A13;
int cellPin14 = A14;
int cellPin15 = A15;

int photocellVal = 0; // photocell variable
int photocellVal1 = 0;
int photocellVal2 = 0;
int photocellVal3 = 0;
int photocellVal4 = 0;
int photocellVal5 = 0;
int photocellVal6 = 0;
int photocellVal7 = 0;
int photocellVal8 = 0;
int photocellVal9 = 0;
int photocellVal10 = 0;
int photocellVal11 = 0;
int photocellVal12 = 0;
int photocellVal13 = 0;
int photocellVal14 = 0;
int photocellVal15 = 0;

int dig22 = 22;
int dig24 = 24;
int dig26 = 26;
int dig28 = 28;
int dig30 = 30;

int dig13 = 13;
int dig12 = 12;
int dig11 = 11;
int dig10 = 10;
int dig09 = 9;
int dig08 = 8;
//const int trig = 5;
//const int ech = 6;
//const int inter_time = 1000;
int time = 0;



void setup() {
  Serial.begin(9600);
  //pinMode(trig, OUTPUT);
  //pinMode(ech, INPUT);
  pinMode(dig22, INPUT);
  pinMode(dig24, INPUT);
  pinMode(dig26, INPUT);
  pinMode(dig28, INPUT);
  pinMode(dig30, INPUT);
  pinMode(dig13, OUTPUT);
  pinMode(dig12, OUTPUT);
  pinMode(dig11, OUTPUT);
  pinMode(dig10, OUTPUT);
  pinMode(dig09, OUTPUT);
  pinMode(dig08, OUTPUT);
  digitalWrite(dig13, LOW) ;
  digitalWrite(dig12, LOW) ;
  digitalWrite(dig11, LOW) ;
  digitalWrite(dig10, LOW) ;
  digitalWrite(dig09, LOW) ;
  digitalWrite(dig08, LOW) ;
  establishContact();  // send a byte to establish contact until receiver responds 
}

void establishContact() {
  while (Serial.available() <= 0) {
     Serial.println("A");   // send a capital A
  delay(300);
  }
}


void Dim(){

digitalWrite(dig08, LOW) ;
digitalWrite(dig09, LOW) ;
digitalWrite(dig10, LOW) ;
digitalWrite(dig11, LOW) ;
digitalWrite(dig12, LOW) ;

}

void loop()
{
  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
    
    if(val == '1') //if we get a 1
    {

         Dim();

         for( int i = 0;i <255 ;i+=10) {
          analogWrite(dig08, i) ;
          delay(20);
         }
          
    }
    
    if(val == '2') //if we get a 1
    {
 Dim();
          for( int i = 0;i <255 ;i+=10) {
          analogWrite(dig09, i) ;
          delay(20);
         }
    }
    if(val == '3') //if we get a 1
    {
  Dim();
          for( int i = 0;i <255 ;i+=10) {
          analogWrite(dig10, i) ;
          delay(20);
         }
    }
    if(val == '4') //if we get a 1
    {

  Dim();
          for( int i = 0;i <255 ;i+=10) {
          analogWrite(dig11, i) ;
          delay(20);
         }
    }
    if(val == '5') //if we get a 1
    {

  Dim();
         for( int i = 0;i <255 ;i+=10) {
          analogWrite(dig12, i) ;
          delay(20);
         }
    }
    delay(50);
  } 
    else {

      
   



  
  //float cmMsec, inMsec;
  //int cmN;
  //long microsec = ultrasonic.timing();
  //cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
  //cmN = int(cmMsec);

int switchStatus1 = digitalRead(dig22);
int switchStatus2 = digitalRead(dig24);
int switchStatus3 = digitalRead(dig26);
int switchStatus4 = digitalRead(dig28);
int switchStatus5 = digitalRead(dig30);


  
  // 讀取光敏電阻並輸出到 Serial Port 
  photocellVal = analogRead(cellPin);
  photocellVal1 = analogRead(cellPin1);
  photocellVal2 = analogRead(cellPin2);
  photocellVal3 = analogRead(cellPin3);
  photocellVal4 = analogRead(cellPin4);
  
//  photocellVal5 = analogRead(cellPin5);  
//  photocellVal6 = analogRead(cellPin6);  
//  photocellVal7 = analogRead(cellPin7);
//  photocellVal8 = analogRead(cellPin8);  
//  photocellVal9 = analogRead(cellPin9); 
//  photocellVal10 = analogRead(cellPin10);
//  photocellVal11 = analogRead(cellPin11);
//  photocellVal12 = analogRead(cellPin12);
//  photocellVal13 = analogRead(cellPin13);
//  photocellVal14 = analogRead(cellPin14);
//  photocellVal15 = analogRead(cellPin15);
Serial.print("6,");
Serial.print(switchStatus1); //left1
  Serial.print(",");
Serial.print(switchStatus3); //left2
  Serial.print(",");  
Serial.print(switchStatus5); //left3
  Serial.print(",");
Serial.print(switchStatus4); //left4
  Serial.print(",");
  Serial.print(switchStatus2); //left5
Serial.print(",");
  Serial.print(photocellVal);
  Serial.print(",");
  Serial.print(photocellVal1);
  Serial.print(",");
  Serial.print(photocellVal2);
  Serial.print(",");  
  Serial.print(photocellVal3);
  Serial.print(",");
  Serial.print(photocellVal4);
  Serial.println(",");
  
//   if(incomingByte == 1)  digitalWrite(dig13, LOW) ;
//    if(incomingByte == 2)  digitalWrite(dig12, LOW) ;
//     if(incomingByte == 3) digitalWrite(dig11, LOW) ;
//     if(incomingByte ==4) digitalWrite(dig10, LOW) ;
//     if(incomingByte == 5) digitalWrite(dig09, LOW) ;
    }

}

