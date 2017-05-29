
#include <Servo.h> 

Servo myservo; 
int pos = 0; 

const int stepPin3 = 3; 
const int dirPin3 = 2; 


// axa 2 

const int stepPin2 = 5;
const int dirPin2 = 4;
// axa 1
const int stepPin1 = 6;
const int dirPin1 = 7;
// definire pini butoane 

int  start = 28;
int cooler = 30;

// definire pini senzori capete de cursa

const int axa1 = 22;
const int axa2 = 24;
const int axa3 = 26;
static int xy = 1;
static int a =1;
static int b = 1;


void setup() {

  myservo.attach(8);
  
  // initialize serial communication:
  
  Serial.begin(9600);
  
  // initialize the LED pins:

  
  pinMode(stepPin3,OUTPUT); 
  pinMode(dirPin3,OUTPUT);

  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);

  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(start, OUTPUT);
  pinMode(cooler, OUTPUT);

  pinMode(axa1,INPUT);
  pinMode(axa2,INPUT);
  pinMode(axa3,INPUT);
  pinMode(13,OUTPUT);

  
   digitalWrite(start , HIGH);
   digitalWrite(cooler , HIGH);
}

void loop() {





 
  // read the sensor:
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    // do something different depending on the character received.
    // The switch statement expects single number values for each case;
    // in this exmaple, though, you're using single quotes to tell
    // the controller to get the ASCII value for the character.  For
    // example 'a' = 97, 'b' = 98, and so forth:

    switch (inByte) {
      case 'A':
         for(int x =0 ; x<500; x++){
    digitalWrite(dirPin1,LOW);
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin1,LOW);
    delayMicroseconds(1000);
    }
        break;
      case 'B':
       for(int x =0 ; x<500; x++){
    digitalWrite(dirPin1,HIGH);
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin1,LOW);
    delayMicroseconds(1000);}
        break;
      case 'C':
          for(int x =0 ; x<500; x++){
    digitalWrite(dirPin2,LOW);
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin2,LOW);
    delayMicroseconds(1000);
    }
        break;
     
      case 'D':
      
          for(int y =0 ; y < 500; y++)
    
 {
    digitalWrite(dirPin2,HIGH);
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin2,LOW);
    delayMicroseconds(1000);
   
    }
        break;
      case 'E':
        for(int x =0 ; x<500; x++){
    digitalWrite(dirPin3,HIGH);
    digitalWrite(stepPin3,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin3,LOW);
    delayMicroseconds(1000);
    }
        break;

            case 'F':
        for(int x =0 ; x<500; x++){
    digitalWrite(dirPin3,LOW);
    digitalWrite(stepPin3,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin3,LOW);
    delayMicroseconds(1000);
    }
        break;

             case 'G':
   
    for(pos = 0; pos <= 10; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
        break;

             case 'H':
 
    for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
        break;
        case 'P' :
{
    digitalWrite(start , LOW);
}
   break;

    case 'S' :
{
    digitalWrite(start , HIGH);
}
   break;
   case 'X' :
{
    digitalWrite(cooler , LOW);
}
   break;
   case 'Y' :
{
    digitalWrite(cooler , HIGH);
}
   break;
    

        
      default:
        // turn all the LEDs off:
        for (int thisPin = 2; thisPin < 7; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}
