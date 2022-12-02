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
      tone(38,1898,150);
      delay(75);
      tone(38,1690,150);
      delay(75);
      tone(38,1500,150);
      delay(75);
      tone(38,1420,150);
      delay(75);
      tone(38,1265,150);
      delay(75);
      tone(38,1194,150);
      delay(75);
      tone(38,1126,150);
      delay(75);
      tone(38,1063,150);
      delay(75);
      tone(38,1001,150); 
      delay(75);
      noTone(38);
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
      tone(38,494,100);
      tone(38,988,100);
      tone(38,740,100);
      tone(38,622,100);
      tone(38,740,100);
      tone(38,622,100);
      tone(38,523,100);
      tone(38,1047,100);
      tone(38,784,100); 
      tone(38,659,100);
      tone(38,1047,100);
      tone(38,784,100); 
      noTone(38);
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
      tone(38,660,150);
      delay(200);
      tone(38,660,150);
      delay(200);
      tone(38,660,300);
      delay(200);
      tone(38,510,150);
      delay(100);
      tone(38,660,150);
      delay(400);
      tone(38,770,150);
      delay(200);
      tone(38,380,150);
      delay(200);
      tone(38,510,150);
      delay(200);
      tone(38,380,150); 
      delay(200);
      noTone(38);
      digitalWrite(3, LOW);
      delay(3000);   
      lcd.clear();
    }
    lcd.clear();
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
  pinMode(38, OUTPUT);

  Wire.begin(I2C_SDA, I2C_SCL);
  lcd.init();
  lcd.backlight();
  lcd.print("Bem-Vindo");
  lcd.setCursor(0, 1);
  lcd.print("Bom Jogo");

}

void loop() {

  client.loop();
  delay(1000);

}
