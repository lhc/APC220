// Base TX Arduino Mega
//Variavel que armazena os caracteres recebidos
char buf;

//Definicoes das portas dos leds
int porta_led_verm = 8;
int porta_led_amar = 9;

//Variaveis para controle do estado dos leds
int estado_verm = 0;
int estado_amar = 0;
 
void setup(){
  pinMode(porta_led_verm, OUTPUT);
  pinMode(porta_led_amar, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
    Serial.println (" LHC TESTA " );
}
 
void loop(){
  //Aguarda os dados na serial
  while(Serial.available() > 0)  {
    buf = Serial.read();
    if (buf == 'LHC#'){
     digitalWrite(porta_led_amar, HIGH);
     digitalWrite(porta_led_verm, LOW);
     delay(1000);
    } 
  }
  digitalWrite(porta_led_verm, 1);
  delay(500);
  Mandar();
}
 
void Mandar(){
  Serial.print("LHC#"); 
  digitalWrite(porta_led_amar, 0);
  delay(500);
  digitalWrite(porta_led_amar, 1);
  digitalWrite(porta_led_amar, 0);
}
