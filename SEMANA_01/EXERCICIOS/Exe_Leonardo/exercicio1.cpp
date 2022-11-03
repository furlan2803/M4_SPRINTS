#include <iostream>

int valor;
int vMax, vMin, continuar;

int leituraSensor(){
    
    printf("\nDigite o valor do intervalor que deseja calcular: ");
    scanf("%d", &valor);

    return valor;
}

int converteSensor(){

   int valor = leituraSensor();

   printf("\nDigite o valor Maximo do intervalor: ");
   scanf("%d", &vMax);

   printf("\nDigite o valor Minimo do intervalo: ");
   scanf("%d", &vMin);

   if(valor > vMax){

       printf("\n\nO valor escolhido esta fora do intervalo!");
       printf("\nDeseja calcular o valor novamente? (1 - Sim / 0 - Nao)");
       scanf("%d", &continuar);

       if(continuar == 1){
           return converteSensor();
       }
       else{
           printf("\nFim do programa");
       }
       
   }
   else if(valor < vMin){

       printf("\n\nO valor escolhido esta fora do intervalo!");
       printf("\nDeseja calcular o valor novamente? (1 - Sim / 0 - Nao)");
       scanf("%d", &continuar);

       if(continuar == 1){
           return converteSensor();
       }
       else{
           printf("\nFim do programa!");
       }

   }
   else{

        int vConvertido = (valor - vMin) * 100 / (vMax - vMin);
       printf("\nO valor escolhido corresponde a %d porcento do intervalo.", vConvertido);
       printf("\nDeseja calcular outro valor? (1 - Sim / 0 - Nao)");
       scanf("%d", &continuar);

       if(continuar == 1){
           return converteSensor();
       }
       else{
           printf("\nFim do programa!\n");
           return armazenaVetor();

       }

   }

}

int digire(){

    int vetor[vMax*4];

}

int main(){


}

int armazenaVetor(){

    int vetor[10], valor, capacidade, ultimaPosicao, continuarPrograma;

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &valor);

    printf("Digite a capacidade de armazenamento do vetor: ");
    scanf("%d", &capacidade);

    printf("Digite a ultima posicao preenchida: ");
    scanf("%d", &ultimaPosicao);

    printf("Deseja inserir outro valor? (1 - Sim / 0 - Nao)");
    scanf("%d", &continuarPrograma);

    if(continuarPrograma == 1){
        return armazenaVetor();
    }
    else{
        printf("Fim do programa!");
    }

}



