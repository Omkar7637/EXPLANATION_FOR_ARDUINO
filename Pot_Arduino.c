int potenciometro = A0;
int valor;
int posicion;
int bocina = 2;

void setup()
{
  pinMode(bocina, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 valor = analogRead(potenciometro);
 posicion = map(valor, 0, 1023, 0, 100);
 Serial.begin(posicion); 
 delay(100);
 Serial.println(posicion);
 delay(1000);
  
  if (posicion >= 0 and posicion <14){
 tone(bocina,523.25,500);
 delay(500);
  }
    
  else if (posicion >= 14 and posicion <28){
 tone(bocina,587.33,500);
 delay(500);
  }
 
  else if (posicion >= 28 and posicion <42){
 tone(bocina,659.26,500);
 delay(500);
  }
  
  else if (posicion >= 42 and posicion <56){
 tone(bocina,698.46,500);
 delay(500);
  }
  
  else if (posicion >= 56 and posicion <70){
 tone(bocina,783.99,500);
 delay(500);
  }
    
  else if (posicion >= 70 and posicion <84){
 tone(bocina,880,500);
 delay(500);
  }
  
  else if (posicion > 84 and posicion <98){
 tone(bocina,987.77,500);
  delay(500);
  }
  
  else if (posicion >= 98 and posicion <101){
 noTone(bocina);
 delay(1000);
  }
}