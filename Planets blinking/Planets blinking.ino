/*
Αυτός ο κωδικός σχεδιάστηκε από τον Γιώργο Κεφάλα.
Προορίζεται για ακαδημαϊκή χρήση στο Τμήμα Πληροφορικής και Τηλεπικοινωνιών του Πανεπιστημίου
Ιωαννίνων
*/
/*
Αυτός ο κώδικας σχεδιάστηκε και εκτελέστηκε στο πρόγραμμα Arduino έκδοσης 1.8.17
Σχεδιάστηκε για χρήση με το Arduino UNO R3
*/
#include <TimeLib.h>
int planet1 = 10;//leds
int planet2 = 9;//leds
int planet3 = 8;//leds
char moon;
int stars;
void setup() {
  Serial.begin(9600);
  pinMode(planet1,OUTPUT);
  pinMode(planet2,OUTPUT);
  pinMode(planet3,OUTPUT);}
 
void loop(){
  if (hour()<6 && hour()>17){
    digitalWrite(planet1 , HIGH);// ΠΛΑΝΗΤΗΣ1 ΑΝΟΙΧΤΟΣ
    digitalWrite(planet2 , HIGH);// ΠΛΑΝΗΤΗΣ2 ΑΝΟΙΧΤΟΣ
    digitalWrite(planet3 , HIGH);}// ΠΛΑΝΗΤΗΣ3 ΑΝΟΙΧΤΟΣ
  else {
    digitalWrite(planet1, LOW);// ΠΛΑΝΗΤΗΣ1 ΚΛΕΙΣΤΟΣ
    digitalWrite(planet2, LOW);// ΠΛΑΝΗΤΗΣ2 ΚΛΕΙΣΤΟΣ
    digitalWrite(planet3, LOW);// ΠΛΑΝΗΤΗΣ3 ΚΛΕΙΣΤΟΣ
  }
  Serial.println("L=LOWBLINK, M=MEDIUMBLINK, Q=QUICK");//ΛΕΙΤΟΥΡΓΙΕΣ BLINK
  stars = Serial.read();//ΛΕΙΤΟΥΡΓΙΕΣ BLINK L,M,Q
  if(moon == 'L') {
    stars = 0;}else if(moon == 'M'){
    stars = 1;}else if(moon == 'Q'){
    stars = 2;}
     switch (stars){
     case 0:  // LOWBLINK=1.5SEC           
      digitalWrite(planet1 , HIGH);// ΠΛΑΝΗΤΗΣ1 ΑΝΟΙΧΤΟΣ
      digitalWrite(planet2 , HIGH);// ΠΛΑΝΗΤΗΣ2 ΑΝΟΙΧΤΟΣ
      digitalWrite(planet3 , HIGH);// ΠΛΑΝΗΤΗΣ3 ΑΝΟΙΧΤΟΣ
      Serial.println("Low Feature");
      delay(1500);  //ΚΑΘΥΣΤΕΡΗΣΗ 1.5 SEC    
      digitalWrite(planet1, LOW);// ΠΛΑΝΗΤΗΣ1 ΚΛΕΙΣΤΟΣ
      digitalWrite(planet2, LOW);// ΠΛΑΝΗΤΗΣ2 ΚΛΕΙΣΤΟΣ
      digitalWrite(planet3, LOW);// ΠΛΑΝΗΤΗΣ3 ΚΛΕΙΣΤΟΣ
      delay(1500); //ΚΑΘΥΣΤΕΡΗΣΗ 1.5 SEC
      break; 
      case 1:  // MEDIUMBLINK=1SEC                        
      digitalWrite(planet1 , HIGH);// ΠΛΑΝΗΤΗΣ1 ΑΝΟΙΧΤΟΣ
      digitalWrite(planet2 , HIGH);// ΠΛΑΝΗΤΗΣ2 ΑΝΟΙΧΤΟΣ
      digitalWrite(planet3 , HIGH);// ΠΛΑΝΗΤΗΣ3 ΑΝΟΙΧΤΟΣ
      Serial.println("Medium Feature");
      delay(1000);//ΚΑΘΥΣΤΕΡΗΣΗ 1 SEC
      digitalWrite(planet1, LOW);// ΠΛΑΝΗΤΗΣ1 ΚΛΕΙΣΤΟΣ
      digitalWrite(planet2, LOW);// ΠΛΑΝΗΤΗΣ2 ΚΛΕΙΣΤΟΣ
      digitalWrite(planet3, LOW);// ΠΛΑΝΗΤΗΣ3 ΚΛΕΙΣΤΟΣ
      delay(1000); //ΚΑΘΥΣΤΕΡΗΣΗ 1 SEC
      break;   
      case 2:  // QUICK=0.5 SEC                       
      digitalWrite(planet1 , HIGH);// ΠΛΑΝΗΤΗΣ1 ΑΝΟΙΧΤΟΣ
      digitalWrite(planet2 , HIGH);// ΠΛΑΝΗΤΗΣ2 ΑΝΟΙΧΤΟΣ
      digitalWrite(planet3 , HIGH);// ΠΛΑΝΗΤΗΣ3 ΑΝΟΙΧΤΟΣ
      Serial.println("Quick Feature");
      delay(500);//ΚΑΘΥΣΤΕΡΗΣΗ 0.5 SEC
      digitalWrite(planet1, LOW);// ΠΛΑΝΗΤΗΣ1 ΚΛΕΙΣΤΟΣ
      digitalWrite(planet2, LOW);// ΠΛΑΝΗΤΗΣ2 ΚΛΕΙΣΤΟΣ
      digitalWrite(planet3, LOW);// ΠΛΑΝΗΤΗΣ3 ΚΛΕΙΣΤΟΣ
      delay(500);//ΚΑΘΥΣΤΕΡΗΣΗ 0.5 SEC
      break;}}
