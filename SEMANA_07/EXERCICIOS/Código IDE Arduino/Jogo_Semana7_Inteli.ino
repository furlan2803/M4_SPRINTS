#include "EspMQTTClient.h"
#include <string.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>
#define I2C_SDA 47
#define I2C_SCL 48

LiquidCrystal_I2C lcd(0x27, 16, 2);

EspMQTTClient client(

  "Inteli-COLLEGE",
  "QazWsx@123",
  // "SHARE-RESIDENTE 2",
  // "Share@residente",
  "broker.hivemq.com",
  "giovannaJogoDaVelhaSemana7"

);

void onConnectionEstablished() {

  client.subscribe("INTELI/Semana7/JogoDaVelha", [] (const String &payload)  {

    if(payload == "acenderX") {
      lcd.clear();
      lcd.print("Jogador X ganhou");
      lcd.setCursor(0, 1);
      lcd.print("Parabens!");
      digitalWrite(8, HIGH);
      delay(3000);
      tone(40,440,500);
      tone(40,294,300); 
      tone(40,349,250);
      tone(40,392,250);
      tone(40,440,250); 
      tone(40,294,300);
      tone(40,349,200);
      tone(40,392,200);
      tone(40,330,700);
      tone(40,392,500); 
      tone(40,262,500); 
      tone(40,349,200);
      tone(40,330,200); 
      tone(40,392,200);
      noTone(40);
      digitalWrite(8, LOW);
      delay(3000);
      lcd.clear();
    }

    if(payload == "acenderEmpate"){
      lcd.clear();
      lcd.print("O jogo Empatou");
      lcd.setCursor(0, 1);
      lcd.print("Tente Novamente");
      digitalWrite(16, HIGH);
      delay(3000);
      tone(40,500,200);
      tone(40,500,200);
      tone(40,500,200);
      tone(40,800,150);
      tone(40,500,500);
      tone(40,600,1000);
      tone(40,392,200);
      tone(40,330,700);
      tone(40,392,500); 
      noTone(40);
      digitalWrite(16, LOW);
      delay(1000);   
      lcd.clear();
    }

    if(payload == "acenderO"){
      lcd.clear();
      lcd.print("Jogador O ganhou");
      lcd.setCursor(0, 1);
      lcd.print("Parabens!");
      digitalWrite(3, HIGH);
      delay(3000);
      tone(40,500,200);
      tone(40,800,150);
      tone(40,800,150);
      tone(40,500,200);
      tone(40,500,200);
      tone(40,500,500);
      tone(40,500,500);
      tone(40,600,1000);
      noTone(40);
      digitalWrite(3, LOW);
      delay(3000);   
      lcd.clear();
    }

    lcd.print("Novo Jogo");
    lcd.setCursor(0, 1);
    lcd.print("Boa Sorte");
    Serial.println(payload);

  });

  client.publish("INTELI/Semana7/JogoDaVelha", "Acabei de conectar!");

}

void setup() {

  Serial.begin(115200);

  pinMode(8, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(40, OUTPUT);

  Wire.begin(I2C_SDA, I2C_SCL);
  lcd.init();
  lcd.backlight();
  lcd.print("Bom Jogo");

}

void loop() {

  client.loop();
  delay(1000);

}