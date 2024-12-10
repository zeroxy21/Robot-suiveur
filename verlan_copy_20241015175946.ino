int rotasens1 = 12;
int brake1 = 9;
int speed1 = 3;

int rotasens2 = 13;
int brake2 = 8;
int speed2 = 11;

int sensorPin1 = 7;  // line detection sensor interface
int sensorPin2 = 6;

int val1;            // variable to store sensor reading
int val2;

void setup() {
  pinMode(sensorPin1,INPUT);  // define sensor as input  
  pinMode(sensorPin2,INPUT);
  Serial.begin(9600);     // initialize serial communication with PC

 pinMode(rotasens1, OUTPUT); // Broche Arduino réservée pour le sens de rotation du moteur A
 pinMode(brake1, OUTPUT); // Broche Arduino réservée pour le freinage du moteur A

  pinMode(rotasens2, OUTPUT); // Broche Arduino réservée pour le sens de rotation du moteur A
 pinMode(brake2, OUTPUT); // Broche Arduino réservée pour le freinage du moteur A

  digitalWrite(rotasens1, HIGH);
  digitalWrite(rotasens2, LOW);
}

void loop() {
  val1 = digitalRead(sensorPin1); // read value from sensor
  val2 = digitalRead(sensorPin2);

  if(val1 == LOW) { 
    analogWrite(speed2,0);
    analogWrite(speed1,0);
    digitalWrite(brake1, HIGH); 
    digitalWrite(brake2, HIGH); 
    delay(350);
    digitalWrite(brake1, LOW);
    digitalWrite(brake2,HIGH);
    analogWrite(speed1,70); 
    delay(350);
  } 
 
  else { 
    //Serial.println("Line NOT detected on 1"); 
    //digitalWrite(rotasens1, LOW);
   digitalWrite(brake2, LOW);
   digitalWrite(brake1, LOW);
  analogWrite(speed1, 70); 
  analogWrite(speed2,70); 
 digitalWrite(rotasens1, HIGH);
  digitalWrite(rotasens2, LOW);


  }
 if (val2 == LOW) { 
    analogWrite(speed2,0);
    analogWrite(speed1,0);
    digitalWrite(brake2,HIGH);
    digitalWrite(brake1,HIGH);
    delay(350);
    digitalWrite(brake1,HIGH); 
    digitalWrite(brake2,LOW);
     analogWrite(speed2,70); 

    delay(350);
  } 
  else { 
    //Serial.println("Line NOT detected on 1"); 
    //digitalWrite(rotasens1, LOW);
   digitalWrite(brake2, LOW);
   digitalWrite(brake1, LOW);
  analogWrite(speed1, 70); 
  analogWrite(speed2,70); 
  digitalWrite(rotasens1, HIGH);
  digitalWrite(rotasens2, LOW);
}
}