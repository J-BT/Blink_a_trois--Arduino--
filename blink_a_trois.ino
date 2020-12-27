const int CONNEXION1 = 11;
const int CONNEXION2 = 12;
const int CONNEXION3 = 13;
int delai ;
int tour;
int i;

/*
NB : Serial.print();--> Ne fait pas revenir à la ligne 
      Serial.println();--> Fait revenir à la ligne 
  
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(CONNEXION1, OUTPUT);
  pinMode(CONNEXION2, OUTPUT);
  pinMode(CONNEXION3, OUTPUT);
  delai = 1000;
  tour = 1;

  // On eteint toutes les LED
  digitalWrite(CONNEXION1, LOW);
  digitalWrite(CONNEXION2, LOW);
  digitalWrite(CONNEXION3, LOW);
  
  Serial.begin(9600); //On initialise la communication
  Serial.println("***** START !!! *****");

}

void loop() {

  Serial.print("Tour n°");
  Serial.println(tour);
  Serial.print("Le délai ON/OFF = ");
  Serial.print(delai*0.001);
  Serial.println(" secondes");
  Serial.println();
  
  digitalWrite(CONNEXION1, HIGH);
  digitalWrite(CONNEXION2, HIGH);
  digitalWrite(CONNEXION3, HIGH);
  delay(delai);

  
  digitalWrite(CONNEXION1, LOW);
  digitalWrite(CONNEXION2, LOW);
  digitalWrite(CONNEXION3, LOW);
  delay(delai);


  digitalWrite(CONNEXION1, HIGH);
  digitalWrite(CONNEXION2, HIGH);
  digitalWrite(CONNEXION3, HIGH);
  delay(100);
  
  for (i = CONNEXION3 ; i >= CONNEXION1 ; i --){
    // on eteint toutes les LED
    digitalWrite(CONNEXION1, HIGH);
    digitalWrite(CONNEXION2, HIGH);
    digitalWrite(CONNEXION3, HIGH); 
    // on allume la LED i  (si i = 13, on allume la LED n°13)
    digitalWrite(i , LOW);
    delay(delai);
    digitalWrite(i , HIGH);
    delay(100);
    
  }

  // on decremente de 200 delai pour raccourcir le
  // delai d'allumage
  delai -= 200;
  tour ++;
  
  // On remet delai à 1s quand delai == 0s
  if (delai == 0){
    delai = 1000; 
  }
  
}
