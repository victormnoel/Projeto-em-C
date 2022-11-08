#include "funcoes.h"

int main(void) {
  
  
  inicializarVetores();
  do{
    printf("\n\nDigite o numero opçao desejada :\n");
    entrada = menu();
    switch(entrada){
    case 1 :
      cadastro();
      break;
    case 2 :
      relatorio();
      break;
    default:
      system("clear");
      printf("EXECUÇÃO FINALIZADA!!!");
      break;
    }
  }while(entrada != 3);

  return 0;
}