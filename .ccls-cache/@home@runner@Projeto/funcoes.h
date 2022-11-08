#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTALFUNC 1500
#define MEGABYTE 1048576
#define VAZIO ' '

int opcao = 0, entrada = 0;
double totalOcupado = 0;


  struct adicionar{
    char nomeFuncionario[60];
    double espacoOcupado;
    float porcentagemEspaco;
  }funcionario[TOTALFUNC];

void inicializarVetores(){

  for (int i = 0; i < TOTALFUNC; i++){
    for(int n = 0; n < 1; n++){
      funcionario[i].nomeFuncionario[n] = VAZIO;
      funcionario[i].porcentagemEspaco = 0;
      funcionario[i].espacoOcupado = 0;
    }
  }
}

int menu(){
  
  printf("\n1. Cadastrar um funcionario");
  printf("\n2. Ver o relatorio do espaço usado");
  printf("\n3. Sair\n\n");
  scanf("%i", &opcao);
 return opcao;
}
void cadastro(){
  
  int i,tamanho = 0;
  char desejo[10], sair[5] = "sair";
  int retorno;
  system("clear");

  for(i = 0; i < TOTALFUNC; i++){

    for (int b = i; b < TOTALFUNC; b++){
      
      tamanho = strlen(funcionario[b].nomeFuncionario);
      if(tamanho > 3 && funcionario[b].espacoOcupado > 0){
        i++;
      }
      else
        break;
    }
    printf("Digite o nome do funcionario:\n");
    scanf(" %[^\n]c", funcionario[i].nomeFuncionario);
    printf("\nDigite o valor em bytes ocupado por ele:\n");
    scanf(" %lf", &funcionario[i].espacoOcupado);
    totalOcupado = funcionario[i].espacoOcupado + totalOcupado;
    printf("\nPara terminar digite 'sair' ou digite qualquer coisa para continuar\n");
    scanf(" %s", desejo); 
    retorno = strncmp(desejo, sair, 5);
    system("clear");
    if(retorno == 0){
      printf("CADASTRO FINALIZADO!!!");
      break;
    }
    else
     continue;
  }
}

void converterByte(){

  for(int i = 0 ; i < TOTALFUNC; i++){
    
    funcionario[i].espacoOcupado = funcionario[i].espacoOcupado / MEGABYTE;
  }
  totalOcupado = totalOcupado / MEGABYTE;
  
}
void calcularPorcentagem(){
  
 for(int i = 0; i < TOTALFUNC; i++){
   
    funcionario[i].porcentagemEspaco = (funcionario[i].espacoOcupado * 100) / totalOcupado;
  }
}

void relatorio(){
  
  system("clear");
  int aux = 0;
  double media;
  converterByte();
  calcularPorcentagem();
  
  printf("\n\t\t\t\tUso do espaço em disco pelos usuários\n");
  printf("------------------------------------------------------------------------\n");
  printf("N\t\tUsuario\t\t\tEspaço utilizado\t\t%% de uso");
  for(int i = 0; i < TOTALFUNC; i++){

    if (funcionario[i].espacoOcupado != 0){
      aux++;
      media = totalOcupado / aux;
      printf("\n%i\t\t%s\t\t\t%.2fMB \t\t\t%.2f%%\n", i + 1, funcionario[i].nomeFuncionario, funcionario[i].espacoOcupado, funcionario[i].porcentagemEspaco);
    }
    else
      break;
  } 
  printf("\nEspaço total ocupado: %.2fMB", totalOcupado);
  printf("\nEspaço medio ocupado: %.2fMB", media);
}