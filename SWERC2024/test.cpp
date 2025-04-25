// initialisation des sorties en fonction de la led quels allume

const int vert_f = 8; // feu vert

const int orange_f = 10; //feu orange

const int rouge_f = 12; // feu rouoge

const int rouge_p = 6; // feu rouge pieton

const int vert_p = 4; // feu vert pieton

const int bouton = 2; // touon pressoir

int etat_bouton = 0; // varaible qui contient l'état du bouton

int temps_rouge = 3000; // le temps du feu frouge peu varie entre 3 et 5 secondes



void setup() { // On initialise les différentes sorties et entree

  pinMode(vert_f, OUTPUT); // feu vert

  pinMode(orange_f, OUTPUT); // feu orange

  pinMode(rouge_f, OUTPUT); // feu rouge

  pinMode(rouge_p, OUTPUT); // feu rouge pieton

  pinMode(vert_p, OUTPUT); // feu vert pieton

  pinMode(bouton, INPUT); // bouton

}



void loop() {

  digitalWrite(rouge_p, HIGH); // on allume le rouge pieton et

  digitalWrite(vert_f, HIGH); // on allume le feu vert pour 3 secondes

  delay(3000); 

  etat_bouton = digitalRead(bouton) ; // on regarde si le bouton est pressé

  digitalWrite(vert_f, LOW); // on éteint le vert et 

  digitalWrite(orange_f, HIGH); // allume le orange pour 1 secondes

  delay(1000);

    if(etat_bouton==HIGH){ // si le bouton était presser a la fin du feu vert 

    temps_rouge = 5000; //on passe le delai su rouge a 5 seoncdes

    digitalWrite(rouge_p, LOW); // on éteint le feu rouge pieton

    digitalWrite(vert_p, HIGH); //on allume le feu pieton vert

  }

  digitalWrite(orange_f, LOW); // on éteint le orange 

  digitalWrite(rouge_f, HIGH); // et allume le rouge pour 3 ou 5 seconde

  delay(temps_rouge); // on attemps le temps actuel du rouge

  if(etat_bouton==HIGH){ // si le bouton a été pressé avant 

    temps_rouge = 3000; // on remet la variable a 3 seconde

    digitalWrite(vert_p, LOW); // éteint le vert pieton

    digitalWrite(rouge_p, HIGH); // allume le rouge pieton

    etat_bouton=LOW; // on remet le bouton a non pressé

  }

  digitalWrite(rouge_f, LOW); //on éteint le rouge 

}