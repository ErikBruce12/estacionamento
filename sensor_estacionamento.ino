  // Biblioteca incluída

 #include <HCSR04.h>

// Definição dos pinos a ser ultilizado no arduíno
 #define p_trigger 4
 #define p_echo 5
 #define led_vermelho 3
 #define led_verde 8
 #define buzzer 9

 UltraSonicDistanceSensor distanceSensor(p_trigger, p_echo);

 float dist_cm, dist_m;

 void setup() {
  
  Serial.begin(9600);

  // Dispositivos de saída
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

// Frequência
int freq;
float seno;

void tocaBuzzer(){
 for(int x=0;x<180;x++){
  seno = (sin(x*3.1416/180));
  freq = 2000+(int(seno*1000));
  tone(buzzer,freq);
  delay(2);
  }
}

void loop() {

  // Comando a ser executado

  dist_cm = distanceSensor.measureDistanceCm(); 
  dist_m = dist_cm/100; 
  Serial.print("Distancia: "); 
  Serial.print(dist_cm);
  Serial.print("cm/ ");
  Serial.print (dist_m);
  Serial.println("m");
  Serial.println("--");
  
   if(dist_cm <= 10.0){
        digitalWrite(led_verde, LOW); // Desliga led verde
        digitalWrite(led_vermelho, HIGH); // Liga led vermelho
        delay(100);
        digitalWrite(led_vermelho, LOW); // Desliga led vermelho
        delay(100);
        tocaBuzzer();  // Toca buzzer (sirene)
        
   }else{

       digitalWrite(led_verde, HIGH); // Liga led verde
       noTone(buzzer); // Desliga buzzer(sirene)
         
 }
  
}

  
