const int pinoLed1 = 5;
const int pinoLed2 = 7;
const int pinoLed3 = 10;
const int pinoLed4 = 11;
const int button1 = 13;
const int button2 = 15;

const int pinoBuzzer = 9;
const int pinoLDR = 4;

int leituraLDR;
int porcentagem;
int leituraB1; 
int leituraB2; 
int armazenaRepeticao;

int vetorElemento[400];
int ultimoValor = 0; 
int leituiraValor;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");

  pinMode(pinoBuzzer,OUTPUT);
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoLed3, OUTPUT);
  pinMode(pinoLed4, OUTPUT);
  pinMode(pinoLDR, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}
// Varia de 64 a 8126 (Leitura do LDR)

void loop() {

  leituraB1 = digitalRead(button1);
  leituraB2 = digitalRead(button2);
  leituraLDR = analogRead(pinoLDR); 

  porcentagem = (leituraLDR - 32) / ((4000 - 32) / 15);
  Serial.println(porcentagem); // Quantidade de partes que o escopo pode ser dividido

  if(leituraB2 == HIGH){
    
    for(int i = 0; i < ultimoValor; i++){

      armazenaRepeticao = vetorElemento[i];
      habilitarLed(armazenaRepeticao);

    }

  }

  if(leituraB1 == HIGH){

    habilitarLed(porcentagem);
    vetorElemento[ultimoValor] = porcentagem;
    ultimoValor++;

  }

}

int habilitarLed(int valorTotal){

  if(valorTotal == 0){
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, LOW);
      digitalWrite(pinoLed3, LOW);
      digitalWrite(pinoLed4, LOW);
    }
    else if(valorTotal == 1){
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, LOW);
      digitalWrite(pinoLed3, LOW);
      digitalWrite(pinoLed4, LOW);
      tone(pinoBuzzer,440,500); 
      
    }
    else if(valorTotal == 2){
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, HIGH);
      digitalWrite(pinoLed3, LOW);
      digitalWrite(pinoLed4, LOW);
      tone(pinoBuzzer,294,300); 
    }
    else if(valorTotal == 3){
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, HIGH);
      digitalWrite(pinoLed3, LOW);
      digitalWrite(pinoLed4, LOW);
      tone(pinoBuzzer,349,250);
    }
    else if(valorTotal == 4){
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, LOW);
      digitalWrite(pinoLed3, HIGH);
      digitalWrite(pinoLed4, LOW);
      tone(pinoBuzzer,392,250);
    }
    else if(valorTotal == 5){
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, LOW);
      digitalWrite(pinoLed3, HIGH);
      digitalWrite(pinoLed4, LOW);
      tone(pinoBuzzer,440,250); 
    }
    else if(valorTotal == 6){
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, HIGH);
      digitalWrite(pinoLed3, HIGH);
      digitalWrite(pinoLed4, LOW);
      tone(pinoBuzzer,294,300);
    }
    else if(valorTotal == 7){
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, HIGH);
      digitalWrite(pinoLed3, HIGH);
      digitalWrite(pinoLed4, LOW);
      tone(pinoBuzzer,349,200);
    }
    else if(valorTotal == 8){
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, LOW);
      digitalWrite(pinoLed3, LOW);
      digitalWrite(pinoLed4, HIGH);
      tone(pinoBuzzer,392,200);
    }
    else if(valorTotal == 9){
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, LOW);
      digitalWrite(pinoLed3, LOW);
      digitalWrite(pinoLed4, HIGH);
      tone(pinoBuzzer,330,700);
    }
    else if(valorTotal == 10){
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, HIGH);
      digitalWrite(pinoLed3, LOW);
      digitalWrite(pinoLed4, HIGH);
      tone(pinoBuzzer,0,200); 
    }
    else if(valorTotal == 11){
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, HIGH);
      digitalWrite(pinoLed3, LOW);
      digitalWrite(pinoLed4, HIGH);
      tone(pinoBuzzer,392,500); 
    }
    else if(valorTotal == 12){
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, LOW);
      digitalWrite(pinoLed3, HIGH);
      digitalWrite(pinoLed4, HIGH);
      tone(pinoBuzzer,262,500); 
    }
    else if(valorTotal == 13){
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, LOW);
      digitalWrite(pinoLed3, HIGH);
      digitalWrite(pinoLed4, HIGH);
      tone(pinoBuzzer,349,200);
    }
    else if(valorTotal == 14){
      digitalWrite(pinoLed1, LOW);
      digitalWrite(pinoLed2, HIGH);
      digitalWrite(pinoLed3, HIGH);
      digitalWrite(pinoLed4, HIGH);
      tone(pinoBuzzer,330,200); 
    }
    else if(valorTotal == 15){
      digitalWrite(pinoLed1, HIGH);
      digitalWrite(pinoLed2, HIGH);
      digitalWrite(pinoLed3, HIGH);
      digitalWrite(pinoLed4, HIGH);
      tone(pinoBuzzer,392,200);
    }
    delay(700);
    digitalWrite(pinoLed1, LOW);
    digitalWrite(pinoLed2, LOW);
    digitalWrite(pinoLed3, LOW);
    digitalWrite(pinoLed4, LOW);
}