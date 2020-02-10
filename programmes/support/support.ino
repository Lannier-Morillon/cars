//cibles
const int cible0=A0;
const int cible1=A1;
const int cible2=A2;

int valeur0=0;
int valeur1=1;
int valeur2=2;

//bluetooth
char Data;

//servos
#include <Servo.h>
Servo servoG;
Servo servoM;
Servo servoD;

//ecran
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,9,10,11,12);

int compteur=-1;
int avant=90;
int apres=180;
 
void setup() {
  //bluetooth
  Serial.begin(9600);

  //cible
  pinMode(cible0,INPUT);
  pinMode(cible1,INPUT);
  pinMode(cible2,INPUT);
  
  //ecran
  lcd.begin(16,2);
  analogWrite(4,25);
  lcd.setCursor(8,0);
  
  //servo
  servoG.attach(6);
  servoM.attach(7);
  servoD.attach(8);
  servoG.write(90); //première position à 90°
  servoM.write(90);
  servoD.write(90);
}

void loop() {
  if(Serial.available()){
    Data=Serial.read();
    if (Data=='G'){
      servoG.write(180);
      apres=180;}
    if (Data=='M'){
      servoM.write(180);
      apres=180;}
    if (Data=='D'){
      servoD.write(180);
      apres=180;}
  }
  valeur0=analogRead(cible0);
  valeur1=analogRead(cible1);
  valeur2=analogRead(cible2);
  
  if (valeur0>900) {
    servoG.write(90);
    avant=90;}
  if (valeur1>900) {
    servoM.write(90);
    avant=90;}
  if (valeur2>900) {
    servoD.write(90);
    avant=90;}

  //affichage score 
  if (avant==90){
    if (apres==180){
      compteur=compteur+1;}
      avant=180;
      apres=90;}
  lcd.setCursor(3,0);
  lcd.print("Score :");
  lcd.setCursor(11,0);
  lcd.print(compteur);
  Serial.println(compteur);
}
