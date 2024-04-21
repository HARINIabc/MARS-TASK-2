const int trigPIN=10;
const int echoPIN=2;
const int dirPIN=6;
const int pwmPIN=3;
int dist;
int time;
void setup()
{
  pinMode(dirPIN ,OUTPUT);
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
  pinMode(pwmPIN,OUTPUT);
  Serial.begin(9600);
  Serial.println("ULTRASONIC SENSOR DISTANCE WITH MOTOR");
}
void loop()
{
  
  digitalWrite(trigPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPIN, HIGH);//increasing the pulse
  delayMicroseconds(10);
  digitalWrite(trigPIN, LOW);//reducing the pulse again to LOW 
  time = pulseIn(echoPIN, HIGH);//calculating the time taken to go from high to low 
  dist = time * 0.034 / 2; //finding the distance from the pulse recieved
 
 
  Serial.println("Distance:");
  Serial.println(dist);
 
 
 
 if(dist>100)
 {
    digitalWrite(dirPIN,LOW);
    analogWrite(pwmPIN,150);
    delay(100);
  }
   else if( dist>75 && dist<100)
   {
     digitalWrite(dirPIN,LOW);
    analogWrite(pwmPIN,75);
    delay(100);
     }
   else if(dist>50 && dist<75)
   {
     analogWrite(pwmPIN,0);
     delay(100);
   }
   else if(dist>25 && dist<50)
   {
     digitalWrite(dirPIN,HIGH);
    analogWrite(pwmPIN,75);
    delay(100);
   }
   else if(dist<25)
  {
    digitalWrite(dirPIN,HIGH);
    analogWrite(pwmPIN,150);
    delay(100);
   }
  delay(900);
}

