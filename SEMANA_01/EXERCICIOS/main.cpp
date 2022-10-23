// Declaração das bibliotecas utilizadas
#include <iostream>
#include <string>

// Declaração das funções utilizadas
using namespace std;

//A função abaixo é responsável por realizar a conversão do número digitado pelo usuário, para porcentagem

int converteSensor(int medida,int vMin,int vMax){

    float conversao = 0;

    conversao = (medida-vMin) / (vMax-vMin) * 100;

    return conversao;

}

//A função abaixo é responsável por realizar a simulação da leitura do sensor utilizado pelo usuário

int leSensor() {

    int lSensor;

    printf("O sensor está lendo: %d", lSensor);

    return lSensor;

}

// A função abaixo é responsável por receber uma medida inteira recebida pelo usuário e guardar em um vetor

int armazenaMedida(int valorN, int ValorU, int *vetor, int quant){

    int *vetorValor = vetor;

    vetorValor[ValorU] = valorN;

    return ValorU ++;
    
}

// A função abaixo é responsável por receber quatro medidas do usuário e retornar qual a maior distância e sua direção
// OBS: Utilizou-se o comando "const char*" pois o comando estava dando problema em tipagem

const char* direcaoMenorCaminho(int *vetorValor, int *vMax){

    const char* sentido[] = {"Direita", "Esquerda", "Frente", "Tras"};

    int inicio = -1;

    for(int x = 0; x < 4; x++){

        if (vetorValor[x] > *vMax){

            *vMax = vetorValor[x];
            inicio = x;

        }

    }

    return sentido[inicio];

}

// A função abaixo é responsável por perguntar ao usuário se ele deseja continuar utilizando o programa

bool leComando(){

    char rMapeamento;
    
    cout << "Deseja prosseguir com o andamento do mapeamento? (S/N)" << endl;
    cin >> rMapeamento;

    if(rMapeamento == 'N'){

        return false;
    }

    return true;

}

// A função abaixo é responsável por verifica as distâncias do robo para com os objetos e mapear o local para uma movimentação futura.

int dirige(int *vetor,int vMax){

    int posicaoAtual = 0;
    int verificacao = 1;

    while(verificacao){

        for (size_t x = 0; x < 4; x++){

            int valor = leSensor();
            valor = converteSensor(valor,0,830);
            posicaoAtual = armazenaMedida(valor, posicaoAtual, vetor, vMax);

        }

        verificacao = leComando();

    }

    return posicaoAtual;

}

// A função abaixo é responsável por ler e comparar os sensores, visando devolver qual a maior distância

void percorre(int *vetor, int totalDistancia){

    int distanciaMaior = 0;

    for(int x = 0; x < totalDistancia; x += 4){

        const char *sentido = direcaoMenorCaminho(&(vetor[x]), &distanciaMaior);

        printf("\nA maior movimentacao do robo foi para a %s com valor de %i\n", sentido, distanciaMaior);
        
    }

}

// Função principal

int main() {

    int vetorMax = 100;
    int movimentacao[vetorMax * 4];
    int posicaoAtual = 0;

    posicaoAtual = dirige(movimentacao, vetorMax);
    percorre(movimentacao, posicaoAtual);

    return 0;

}