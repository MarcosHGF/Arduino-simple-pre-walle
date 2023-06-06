#include<Servo.h>
Servo servo;

int trig = 13;
int echo = 12;

//cc
const int enableBridge1 = 2;
const int MotorForward1 = 3;
const int MotorReverse1 = 4;
const int enableBridge2 = 5;
const int MotorForward2 = 6;
const int MotorReverse2 = 7;
int Power = 80;

long ultrassom();

void setup()
{
Serial.begin(9600);
 pinMode(13,OUTPUT);
 pinMode(12, INPUT);
 servo.attach(11);
  //cc
  pinMode(MotorForward1,OUTPUT);
  pinMode(MotorReverse1,OUTPUT);
  pinMode(enableBridge1,OUTPUT);
  pinMode(MotorForward2,OUTPUT);
  pinMode(MotorReverse2,OUTPUT);
  pinMode(enableBridge2,OUTPUT);
  
}
void loop()
{
//bot working:
  
  long duracao;
  long distancia;

  servo.write(90);
  
  digitalWrite(13, 0);
  delayMicroseconds(2);
  digitalWrite(13,1);
  delayMicroseconds(10);
  digitalWrite(13,0);
  duracao=pulseIn(12,1);
  distancia = duracao/58;
  Serial.println(distancia);
  delay(250);
  
  
  if(distancia>25 && distancia<150){
	delay(1000);
    //cc1
  	digitalWrite(enableBridge1,HIGH);
	analogWrite(MotorReverse1,0);
	analogWrite(MotorForward1,Power);
    //c2
    digitalWrite(enableBridge2,HIGH);
    analogWrite(MotorReverse2,0);
	analogWrite(MotorForward2,Power);
    
    servo.write(90);  
  }
 if(distancia<=25){
   
    long distancia3;
  	long distancia4;
   
     //cc1
      delay(100);
      digitalWrite(enableBridge1,LOW);
      analogWrite(MotorReverse1,0);
      analogWrite(MotorForward1,0);
      //c2
      digitalWrite(enableBridge2,LOW);
      analogWrite(MotorReverse2,0);
      analogWrite(MotorForward2,0);
   		delay(5000);
   
       servo.write(90);
        delay(3000);
        servo.write(120);
        distancia3 = ultrassom();
        delay(3000);
        servo.write(60);
        distancia4 = ultrassom();
        delay(3000);


		if(distancia4 > distancia3){
            //cc1
            delay(1000);
            digitalWrite(enableBridge1,LOW);
            analogWrite(MotorReverse1,0);
            analogWrite(MotorForward1,0);
            //c2
            digitalWrite(enableBridge2,HIGH);
            analogWrite(MotorReverse2,0);
            analogWrite(MotorForward2,Power);
            }
            if(distancia3 > distancia4){
            //cc1
            delay(1000);
            digitalWrite(enableBridge1,HIGH);
            analogWrite(MotorReverse1,0);
            analogWrite(MotorForward1,Power);
            //c2
            digitalWrite(enableBridge2,LOW);
            analogWrite(MotorReverse2,0);
            analogWrite(MotorForward2,0);
            }
   
   
  }
  if(distancia>=150){
  long distancia1;
  long distancia2;
    
    //servo
    servo.write(90);
    delay(3000);
    servo.write(120);
    distancia1 = ultrassom();
    delay(3000);
    servo.write(60);
    distancia2 = ultrassom();
    delay(3000);
    
    if(distancia1 > distancia2){
   	 //cc1
      delay(1000);
      digitalWrite(enableBridge1,LOW);
      analogWrite(MotorReverse1,0);
      analogWrite(MotorForward1,0);
      //c2
      digitalWrite(enableBridge2,HIGH);
      analogWrite(MotorReverse2,0);
      analogWrite(MotorForward2,Power);
    }
    if(distancia2 > distancia1){
      //cc1
      delay(1000);
      digitalWrite(enableBridge1,HIGH);
      analogWrite(MotorReverse1,0);
      analogWrite(MotorForward1,Power);
      //c2
      digitalWrite(enableBridge2,LOW);
      analogWrite(MotorReverse2,0);
      analogWrite(MotorForward2,0);
    }
  }
}

long ultrassom(){
  long x, y;
  
  digitalWrite(13, 0);
  delayMicroseconds(2);
  digitalWrite(13,1);
  delayMicroseconds(10);
  digitalWrite(13,0);
  y=pulseIn(12,1);
  x = y/58;
  Serial.println(x);
  delay(250);
  return x;
}

