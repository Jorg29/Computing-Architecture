/*
Αυτός ο κωδικός σχεδιάστηκε από τον Γιώργο Κεφάλα.
Προορίζεται για ακαδημαϊκή χρήση στο Τμήμα Πληροφορικής και Τηλεπικοινωνιών του Πανεπιστημίου
Ιωαννίνων
*/
/*
Αυτός ο κώδικας σχεδιάστηκε και εκτελέστηκε στο πρόγραμμα Arduino έκδοσης 1.8.17
Σχεδιάστηκε για χρήση με το Arduino UNO R3
*/
String stop;
int green = 2;//leds
int yellow = 3;//leds
int red = 4;//leds
int redpedestrian= 5;//leds
int greenpedestrian= 6;//leds
void setup(){Serial.begin(9600);
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(redpedestrian,OUTPUT);
  pinMode(greenpedestrian,OUTPUT);
  }
  void loop(){
  digitalWrite(green,HIGH);//ΠΡΑΣΙΝΟ ΦΩΣ ΑΝΟΙΧΤΟ
  Serial.print ("Green Light\n");//ΕΜΦΑΝΙΣΕ ΠΡΑΣΙΝΟ ΦΩΣ
  digitalWrite(redpedestrian,HIGH);//ΚΟΚΚΙΝΟ ΦΩΣ ΠΕΖΩΝ ΑΝΟΙΧΤΟ
  delay(4000);//ΚΑΘΥΣΤΕΡΗΣΗ 4 SEC ΓΙΑ ΠΡΑΣΙΝΟ ΦΩΣ
  digitalWrite(green,LOW);//ΠΡΑΣΙΝΟ ΦΩΣ ΚΛΕΙΣΤΟ
  digitalWrite(yellow,HIGH);//ΚΙΤΡΙΝΟ ΦΩΣ ΑΝΟΙΧΤΟ
  Serial.print ("Yellow Light\n");//ΕΜΦΑΝΙΣΕ ΚΙΤΡΙΝΟ ΦΩΣ
  delay(1000);//ΚΑΘΥΣΤΕΡΗΣΗ 1 SEC ΓΙΑ ΚΙΤΡΙΝΟ ΦΩΣ
  digitalWrite(yellow,LOW);//ΚΙΤΡΙΝΟ ΦΩΣ ΚΛΕΙΣΤΟ
  digitalWrite(redpedestrian,LOW);//ΚΟΚΚΙΝΟ ΦΩΣ ΠΕΖΩΝ ΚΛΕΙΣΤΟ
  digitalWrite(red,HIGH);//ΚΟΚΚΙΝΟ ΦΩΣ ΑΝΟΙΧΤΟ
  Serial.print ("Red Light\n");//ΕΜΦΑΝΙΣΕ ΚΟΚΚΙΝΟ ΦΩΣ
  digitalWrite(greenpedestrian,HIGH);//ΠΡΑΣΙΝΟ ΦΩΣ ΠΕΖΩΝ ΑΝΟΙΧΤΟ
  delay(3000);//ΚΑΘΥΣΤΕΡΗΣΗ 3 SEC ΓΙΑ ΚΟΚΚΙΝΟ ΦΩΣ
  digitalWrite(red,LOW);//ΚΟΚΚΙΝΟ ΦΩΣ ΚΛΕΙΣΤΟ
  digitalWrite(greenpedestrian,LOW);//ΠΡΑΣΙΝΟ ΦΩΣ ΠΕΖΩΝ ΚΛΕΙΣΤΟ
    
  if (Serial.available() >0){//ΓΙΑ ΣΤΟΠ
  
  Serial.println("Stop");
  stop = Serial.readString();
  
  if(stop == "Stop")//ΟΤΑΝ ΣΤΟΠ
  {
   digitalWrite(green, LOW);//ΠΡΑΣΙΝΟ ΦΩΣ ΚΛΕΙΣΤΟ
   digitalWrite(greenpedestrian, HIGH);//ΠΡΑΣΙΝΟ ΦΩΣ ΠΕΖΩΝ ΑΝΟΙΧΤΟ
   digitalWrite(yellow, LOW);//ΚΙΤΡΙΝΟ ΦΩΣ ΚΛΕΙΣΤΟ
   digitalWrite(red, HIGH);//ΚΟΚΚΙΝΟ ΦΩΣ ΑΝΟΙΧΤΟ
   digitalWrite(redpedestrian, LOW);//ΚΟΚΚΙΝΟ ΦΩΣ ΠΕΖΩΝ ΚΛΕΙΣΤΟ
  }}
  }
