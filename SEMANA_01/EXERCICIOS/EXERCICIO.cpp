#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

// Exercício 1 - Recebe uma certa medida e ajusta ela percentualmente entre um intervalo de valor máximo e mínimo

int converteSensor(int valor, int vMax, int vMin){

    int vSensor = valor;
    int vMinimo = vMin;
    int vMaximo = vMax;

    int vConvertido = (vSensor - vMinimo) * 100 / (vMaximo - vMinimo);

    return vConvertido;
}

// Exercício 2 - Faça uma função que simule a leitura do sensor

int leituraSensor(){

    int lSensor;

    printf("\nDigite o valor da leitura do sensor: ");
    scanf("%d", &lSensor);

    return lSensor;
}

// Exercício 3 - Faça uma função que armazene uma medida inteira em um vetor fornecido

int armazenaVetor(int valorNovo, int ultimaPosicao, int *vetor){

    vetor[ultimaPosicao] = valorNovo;
    return ultimaPosicao ++;
}

/* Exercício 4 - Faça uma função que receba um vetor com 4 posições
string maiorValor(int *vetorNovo, int *valorMax){

     printf("aqui");

    string direcao[4] = {"Direita", "Esquerda", "Frente", "Tras"};

    int valorIndice = -1; 

    for(int aux2 = 0; aux2 < 4; aux2++){

        if(vetorNovo[aux2] > *valorMax){

            *valorMax = vetorNovo[aux2];
            valorIndice = aux2;
        }
    }

    return direcao[valorIndice];
} */

int maiorVetor4(int *vetor, int inicial){

     printf("aqui");

    int iMaior = inicial;

    for(int aux = inicial+1; aux < 4; aux++){
        if(vetor[aux] > vetor[iMaior]){
            iMaior = vetor[aux];
        }
    }
    return iMaior;
}

// Exercício 5 - Faça uma função que leia o vetor

bool leComando(){

    char comandoChar;

    cout << "\nDeseja calcular outro valor? ( S / N): ";
    cin >> comandoChar;
    if(comandoChar == 'N'){
        return false;
    }
    
    return true;
}

// Exercício 6 - Faça uma função que verifica a distancia dos quatro sensores

int dirige(int *vetor){

    int posAtualVetor = 0;
    bool direcionamento = true;

    //while(direcionamento){	

    for(int aux = posAtualVetor, direcionamento=true; aux < 4*(posAtualVetor+1); aux++){

        int medidaValorSensor = leituraSensor();
        int medidaConv = converteSensor(medidaValorSensor, 0, 380);
        //posAtualVetor = armazenaVetor(medidaConv, posAtualVetor, vetor);
        vetor[posAtualVetor] = medidaConv;
        posAtualVetor++;
            
        printf("posAtualVetor = %i", posAtualVetor);
        		
    }
    direcionamento = leComando();

    return posAtualVetor;
}

// Exercício 7 - Faça uma função que percorre os vetores e mostra o movimento

void movimento(int *vetor, int n){	
    printf("HHHHHHHHHHHHH");
    char direcao[] = "";
	for(int aux = 0; aux < n; aux += 4){
        
		//string direcao = maiorValor(&(vetorMov[aux3]),&maiorDir);
        int iMaior = maiorVetor4(vetor,aux);
        printf("Posição maior: %d", iMaior);
        switch (iMaior)
        {
        case 0:
            strcpy (direcao,"Direita");
            break;
        case 1:
            strcpy (direcao,"Esquerda");
            break;
        case 2: 
            strcpy (direcao,"Frente");
            break;
        case 3:
            strcpy (direcao,"Tras");
        }

		printf("O robo esta com a motivementacao para %s com uma distancia de %i\n",direcao, vetor[iMaior]);
	}
}


// Exercício 8 - 

int MAX = 100;

int main(){

    int vetorMov[MAX * 4];
    int vMax, vMin;

    printf("Digite o valor Maximo do intervalo: ");
    scanf("%d", &vMax);

    printf("\nDigite o valor Minimo do intervalo: ");
    scanf("%d", &vMin);

   int posAtualVet = dirige(vetorMov);
   printf("%i", posAtualVet);

   //movimento(vetorMov,posAtualVet);

   return 0;
}