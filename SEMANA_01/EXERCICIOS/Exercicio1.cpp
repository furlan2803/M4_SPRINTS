#include <iostream>
#include <string>

int vMax, vMin;

int main(){

   printf("Digite o valor Maximo do intervalor: ");
   scanf("%d", &vMax);

   int vetorMov[vMax*4];
   int posAtualVet = 0;

   printf("\nDigite o valor Minimo do intervalo: ");
   scanf("%d", &vMin);

   posAtualVet = dirige(vetorMov,vMax);
   percorre(vetorMov,posAtualVet);
}

int dirige(int *v,int maxv){

    int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;

    while(dirigindo){	

        int medida = leitura();

        medida = converteSensor(medida, vMin, vMax);

        posAtualVetor = armazenaVetor(vetorMov, medida, posAtualVetor);

        dirigindo = leComando();		
    }
    return posAtualVetor;
    
}

int leitura(){
    
    int vSensor;

   printf("\nDigite o valor da leitura do sensor: ");
   scanf("%d", &vSensor);

}

int converteSensor(int medida, int vMin, int vMax){

    int vSensor = medida;
    int vMinimo = vMin;
    int vMaximo = vMax;

    int vConvertido = (vSensor - vMinimo) * 100 / (vMaximo - vMinimo);

    return vConvertido;
}

int armazenaVetor(int *v, int posicaoAtual, int medida){

    int *vetorMov = v;
    int posAtualVetor = posicaoAtual;
    int vConvertido = medida;

    vetorMov[posAtualVetor] = vConvertido;
    posAtualVetor++;

    return posAtualVetor;
}

int leComando(){

    int continuar;

    printf("\nVoce deseja continuar? (1 - Sim / 0 - Nao): ");
    scanf("%d", &continuar);

    if(continuar == 1){
        return 1;
    }
    else if(continuar == 0){
        return 0;
    }
}

int direcaoMenorCaminho(){



}

void percorre(int *v,int tamPercorrido){	

	// int *vetorMov = v;
	// int maiorDir = 0;
	
	// for(int i = 0; i< tamPercorrido; i+=4){

	// 	char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
	// 	printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	// }
}
