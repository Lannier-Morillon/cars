const int laser=6; 
const int bouton=7;
int val=0;
              
void setup() {
  Serial.begin(9600);
  pinMode(laser,OUTPUT);         //on configure le laser en sortie
  pinMode(bouton,INPUT);         //on configure le bouton en entrée
  digitalWrite(laser,HIGH);       //on configure le laser en mode éteind
}

void loop() {
 val=digitalRead(bouton);        //val prend les valeurs du bouton (HIGH ou LOW)  
 if (val==HIGH) {                // si on appuie sur le bouton 
  digitalWrite(laser,LOW);      //on allume le laser
 }
 else {                          //sinon
  digitalWrite(laser,HIGH);      //il reste éteind
 }
}
