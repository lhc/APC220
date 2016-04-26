//Variavel que armazena os caracteres recebidos
String buff;
 
//Definicoes das portas dos leds
int porta_led_verm = 8;
int porta_led_amar = 9;

//Variaveis para controle do estado dos leds
int estado_verm = 0;
int estado_amar = 0;
 
void setup(){
  pinMode(porta_led_verm, OUTPUT);
  pinMode(porta_led_amar, OUTPUT);
  digitalWrite(porta_led_amar, LOW);
  digitalWrite(porta_led_verm, LOW);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.print (" LHC TESTA ");
  digitalWrite(porta_led_verm, HIGH);
  delay (300);
  digitalWrite(porta_led_amar, HIGH);
  delay(300);
  digitalWrite(porta_led_amar, LOW);
  delay(300);
  digitalWrite(porta_led_verm, LOW);
}
 
void loop(){
  receber();
  Mandar();
}//voidloop
 
void Mandar(){
  delay(2000);
  Serial.print("ok#"); 
}

void receber(){
  while(Serial.available()> 0){
  for (int t=0; t < 3; t++)
  buff = Serial.read();  
  Serial.print (buff);
  }

  if (buf == 'LHC#'){
        digitalWrite(porta_led_amar, 1);
        delay(1000);
        digitalWrite(porta_led_verm, 0);
        delay(1000);
  }
      digitalWrite(porta_led_verm, 1);
    delay(500);
}
