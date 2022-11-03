// Definição das portas de entrada e saída do programa (Sensores e atuadores)
#define pinoLed1 21
#define pinoLed2 15
#define pinoLed3 37
#define pinoLed4 41
#define pinoBuzzer 2

#define pinoLdr 9
#define botao1 17
#define botao2 18

// Variável responsável por armazenar as leituras que o usuário fornecer
int leituras = 0;

// Vetor de quadro posições em valores deciais setados entre 1 a 15
int vetor[4] = {0,0,0,0};

// Configurandos quais dos pinos serão de entradas e saídas
void setup() {

  // Frequência da porta serial
  Serial.begin(9600);

  pinMode(pinoLed4, OUTPUT);
  pinMode(pinoLed3, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);

  pinMode(pinoLdr, INPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);

}

// Função responsável por padronizar os números recebidos de 0 a 4095 para o intervalo de 1 a 15
int padronizar(int valorRecebido){

  // Valor máximo e mínimo de leitura aceita pelo sensor LDR
  int pinoLDR_max = 4095;
  int pinoLDR_min = 300;

  // Variável responsável por armazenar o número de 1 a 15 setado anteriormente
  int valorPadronizado = 0;

  // Variável responsável por setar o valor atual como o valor máximo aceitável para a leiturado LDR
  int valorAtual = pinoLDR_max;


  while(valorAtual >= valorRecebido) {

    valorPadronizado++;
    valorAtual -= 273;

    // A condição analisa o menor valor que pode vir da leitura do sensor LDR
    if(valorAtual <= pinoLDR_min) {
      valorPadronizado = 16;
      break;
    }
  }
  
  // Retorna o valor do intervalo de 1 a 15
  return 16 - valorPadronizado;
  
}

 // A função converte o valor de binário (1 a 15) para binário (0 e 1), analisando as quatro posições recebidas 
void conversor(int aux, int vetorArmazenamento[4]){
  // Se o número recebido for menor que quatro, executa, uma vez que foi setado somente com quatro posições, iniciando de zero
	for(int x = 0; x < 4; x++) {
		vetorArmazenamento[x] = 0;
	}
 
  int x = 0;

  // Enquanto a variável auxiliar foi maior que zero, pega a posição do vetor de armazenamento, pega o "resto" da divisão de aux por 2
  while (aux > 0) {
  
    vetorArmazenamento[x] = aux % 2;
    aux = aux / 2;
    x++;
  }
}

// Função responsável por acender os leds se baseando nos valores binários recebidos
void ordemLeds(int vetorArmazenamento[4]){

  // Vetor responsável por receber o valor de entrada do led, da direita para a esquerda
  int vetorEntrada[4] = {pinoLed4, pinoLed3, pinoLed2, pinoLed1};

  for(int x = 0; x < 4; x++) {

    // Os casos abaixo são responsáveis por ascender ou apagar os leds de acordo com os números binários recebidos
    switch(vetorArmazenamento[x]) {
      // Acende os Led's
      case 1:
        digitalWrite(vetorEntrada[x], HIGH);
      break;
      // Apaga os Led's
      case 0:
        digitalWrite(vetorEntrada[x], LOW);
    }
  }
}

int frequenciaValor(int valorDecimal){
  // Retorna a frequência de som de acordo com o número decimal recebido
  return valorDecimal * 200;
}

// Função responsável por apresentar um feedback com um som 3 vezes seguidos, quando não for mais permitido armazenar valores
void som(){

  for(int x = 0; x < x; x++) {
    // Toca o som
    tone(pinoBuzzer, 3000);
    delay(500);
    // Para de tocar
    noTone(pinoBuzzer);
    delay(100);
  }
}

void loop(){

  // Leitura do sensor LDR.
  int leitura = analogRead(pinoLdr);
  Serial.println("Leitura LDR:");
  Serial.println(leitura);

  // Normalizando os valores de 0 a 4095 para 1 a 15 e um vetor que armazena quatro valores
  int valor_normalizado = padronizar(leitura);
  int vetorArmazenamento[4];

  // Conversor de número decimal para binário e leds acesos de acordo com o número
  conversor(valor_normalizado, vetorArmazenamento);
  ordemLeds(vetorArmazenamento);

  // A variável armazena o valor, caso o botão 1 esteja precionado ou não
  int botaoPressionado = digitalRead(botao1);

  if(botaoPressionado) {

    // Se o usuário apertar o botão menos que 4 vezes, ainda tem espaço no vetor, então pode-se fazer outra gravação
    if(leituras < 4) {

      vetor[leituras] = valor_normalizado;

      leituras++;
      ordemLeds(vetorArmazenamento);
      tone(pinoBuzzer, frequenciaValor(valor_normalizado));

      delay(1000);
      noTone(pinoBuzzer);

    } else {

      som();
    }

  }

  // A variável armazena o valor, caso o botão 2 esteja precionado ou não
  int botao2Pressionado = digitalRead(botao2);


  if(botao2Pressionado) {

    // Quando a leitura for maior que quatro, toca um som de ação não permitida.
    if(leituras != 4) {

      som();

    // Toca a sequência que o usuário realizou anteriormente
    } else {

      for(int x = 0; x < 4; x++) {

        // Vetor responsável por armazenar quatro valores
        int vetorArmazenamento[4];

        // Converte decimal em binário
        conversor(vetor[x], vetorArmazenamento);

        // Função responsável por acender os leds 
        ordemLeds(vetorArmazenamento);

        // Tocar o som na frequência correspondente ao led 
        tone(pinoBuzzer, frequenciaValor(vetor[x]));
        delay(500);
        noTone(pinoBuzzer);

      }

    }

  }

}