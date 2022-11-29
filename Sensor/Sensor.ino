#define echoPin 2 // συνδέστε την ακίδα D2 Arduino στην ακίδα Echo του HC-SR04
#define trigPin 3 // συνδέστε την ακίδα D3 Arduino στην ακίδα Trig του HC-SR04
long duration;
int distance=100;
int led1 =5;
int led2 =6;
int led3 =7;
int led4 =8;
int led5 =9;
int led6 =10;
int led7 =11;
int led8 =12;
const int buzzer = 4; //buzzer στο pin 9

void setup()

{
 pinMode(buzzer, OUTPUT); // buzzer - pin 9 ως output
 pinMode(trigPin, OUTPUT); // Ορίζει το trigPin ως OUTPUT
 pinMode(echoPin, INPUT); // Ορίζει το echoPin ως INPUT
 Serial.begin(9600);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(led5, OUTPUT);
 pinMode(led6, OUTPUT);
 pinMode(led7, OUTPUT);
 pinMode(led8, OUTPUT);
 Serial.println("Ultrasonic Sensor HC-SR04"); 

 }


void loop()

{ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

   
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Ταχύτητα ηχητικού κύματος διαιρούμενη με 2 (πηγαινει και πίσω)


  if(distance >=1 && distance <= 5 )
 {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  delay(4000);
  tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  delay(1000);        // για 1sec
  noTone(buzzer);     // Σταματάμε τον ήχο
  delay(1000);        // για 1sec
 }

 if(distance > 6 && distance <= 7 )
 {
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  delay(4000);
  tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  delay(1500);        // για 1sec
  noTone(buzzer);     // Σταματάμε τον ήχο
  delay(1500);        // για 1sec
 }

 if(distance > 7 && distance <= 8 )
 {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  delay(4000);
  tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  delay(2000);        // για 1sec
  noTone(buzzer);     // Σταματάμε τον ήχο
  delay(2000);        // για 1sec
 }


if(distance > 8 && distance <= 10 )
 {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  delay(4000);
  tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  delay(2500);        // για 1sec
  noTone(buzzer);     // Σταματάμε τον ήχο
  delay(2500);        // για 1sec
 }


if(distance > 10 && distance <= 11 )
 {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  delay(4000);
  tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  delay(3000);        // για 1sec
  noTone(buzzer);     // Σταματάμε τον ήχο
  delay(3000);        // για 1sec
 }

if(distance > 11 &&  distance <= 15 )
 {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, LOW);
  delay(4000);
  tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  delay(3500);        // για 1sec
  noTone(buzzer);     // Σταματάμε τον ήχο
  delay(3500);        // για 1sec
 }
   
 if(distance > 15 && distance <= 20 )
 {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, HIGH);
  delay(4000);
  tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  delay(4000);        // για 1sec
  noTone(buzzer);     // Σταματάμε τον ήχο
  delay(4000);        // για 1sec
 }

 if(distance > 20)
 {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, HIGH);
  delay(4000);
  tone(buzzer, 1000);  // Αποστολή 1KHz ηχητικού σήματος...
  delay(4500);        // για 1sec
  noTone(buzzer);     // Σταματάμε τον ήχο
  delay(4500);        // για 1sec
 }

   return;
 }

