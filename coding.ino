#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "yLOjjZt7HeVCBVx0DTXDKQzKnLPvwgA1";
char ssid[] = "Redmi Note 9";
char pass[] = "p324n9k4t";
#define sensor A0
#define LED 16

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(sensor,INPUT);
  pinMode(LED,OUTPUT);
}

void loop(){
  int nilai=(analogRead(sensor));
  Serial.print("Nilai analog sensor:");
  Serial.println(nilai);
  delay(1000);
  if(nilai>450){
    Blynk.notify ("TERJADI KEBOCORAN GAS!");
    digitalWrite(LED,HIGH);
    delay(2000);
  }
  else{
      digitalWrite(LED,LOW);
      delay(2000);
  }
 Blynk.run();
}
