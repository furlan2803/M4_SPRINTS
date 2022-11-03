#include <iostream>

int main(){

   int vMax, vMin, valor, continuar;

   printf("\nDigite o valor Maximo do intervalor: ");
   scanf("%d", &vMax);

   printf("\nDigite o valor Minimo do intervalo: ");
   scanf("%d", &vMin);
   
   printf("\nDigite o valor do intervalor que deseja calcular: ");
   scanf("%d", &valor);

   if(valor > vMax){

       printf("\n\nO valor escolhido esta fora do intervalo!");
       printf("\nDeseja calcular o valor novamente? (1 - Sim / 0 - Nao)");
       scanf("%d", &continuar);

       if(continuar == 1){
           main();
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
           main();
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
           main();
       }
       else{
           printf("\nFim do programa!");
       }

   }

}