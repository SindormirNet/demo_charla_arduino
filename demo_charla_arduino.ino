/*
   Demostracion del uso de la consola remota con Arduino Yun
   Jorge Gomez / Sindormir.net 
    jorge@sindormir.net 2014
    
   Codigo de demostracion para la presentacion de Arduino de
   Sindormir.net

   Dependiendo de la funcion llamada en el loop se carga el 
   codigo para una demostracion u otra.

   Licencia GPLv3

*/


#include <Bridge.h>
#include <Servo.h>
#include <YunServer.h>
#include <YunClient.h>

#define DIST_ECHO 7
#define DIST_TRIG 8

#define SERVO 9

#define SENSOR_SONIDO 2

#define LED_AZUL 13
#define LED_VERDE 12
#define LED_ROJO 11

YunServer server; 

Servo miservo;

void setup() {                
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(DIST_ECHO, INPUT);
  pinMode(DIST_TRIG, OUTPUT);

  Bridge.begin();
  miservo.attach(SERVO);
  server.listenOnLocalhost();
  server.begin();

}


void loop() {
  //color_servo();
  //servo_distancia();
  control_rest();
  

}

void control_rest(){
  YunClient client = server.accept();

  if (client) {
    // Process request
    process(client);

    // Close connection and free resources.
    client.stop();
  }

  delay(50); // Poll every 50ms
}

void servo_distancia(){
  int dist;
  
  dist=mide_distancia_servo();
  
  miservo.write(map(dist,0,100,0,179));
  delay(100); 
}


void color_servo(){
  miservo.write(0);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE,LOW);
  digitalWrite(LED_AZUL, HIGH);
  delay(2000);         

  miservo.write(60);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE,HIGH);
  digitalWrite(LED_AZUL, LOW);
  delay(2000);

  miservo.write(120);
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE,LOW);
  digitalWrite(LED_AZUL, HIGH);
  delay(2000);  

  miservo.write(179);
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE,LOW);
  digitalWrite(LED_AZUL, LOW);
  delay(2000);
}
