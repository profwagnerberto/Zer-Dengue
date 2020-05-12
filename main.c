#include <stdio.h>
#include <stdlib.h>

struct Fila{
  int posicaoInicial;
  int posicaoFinal;
  int capacidade;
  int *dados;
};

void criarFila(struct Fila *endFila, int capacidadeDesejada) {
  endFila -> posicaoInicial = 0;
  endFila -> posicaoFinal = -1;
  endFila -> capacidade = capacidadeDesejada;
  endFila -> dados = malloc (capacidadeDesejada * sizeof(int));
}

void inserirItem(struct Fila *endFila, int numSolic) {
  endFila -> posicaoFinal++;
  endFila -> dados[endFila -> posicaoFinal] = numSolic;
}

int removerItem(struct Fila *endFila) {
  int valorАSerDesenfileirado;
  valorАSerDesenfileirado = endFila -> dados [endFila -> posicaoInicial];
  endFila -> posicaoInicial++;
  return valorАSerDesenfileirado;
}

int filaVazia(struct Fila *endFila) {
  if(endFila -> posicaoInicial > endFila -> posicaoFinal )
    return 1;
  else
    return 0;
}

int tamanhoDaFila(struct Fila *endFila) {
  return endFila -> capacidade;
}

int main(void) {
  int numSolic;
  int i;
  struct Fila solicitacoes;
  struct Fila aux;
  int opcao;

  do{
    for(i=1;i<30;i++)
      printf("\n");
    printf("MENU \n");
    printf("---- \n");

    printf("1-Criar fila \n");
    printf("2-Inserir item \n");
    printf("3-Remover item \n");
    printf("4-Sequencia armazenada \n");
    printf("5-Tamanho da fila \n");
    printf("6-Fila Vazia \n");
    printf("9-Encerrar \n");
    printf("---- \n");
    printf("Informe a opção desejada: ");
    scanf("%d",&opcao);

    if( opcao == 1 ){
      criarFila(&solicitacoes,5);
      criarFila(&aux,5);
      printf("Fila criada.");
    }

    if( opcao == 2 ){
      printf("Falaí o número da Solicitação: ");
      scanf("%d",&numSolic);
      inserirItem(&solicitacoes, numSolic);
      printf("Item inserido.");
    }

    if( opcao == 3 ){
      removerItem(&solicitacoes);
      printf("Item removido.");
    }

    if( opcao == 4 ){
      while( filaVazia(&solicitacoes) == 0 ){
        numSolic = removerItem(&solicitacoes);
        inserirItem(&aux, numSolic);
        printf(" %d |", numSolic);
      }
      while( filaVazia(&aux) == 0 ){
        numSolic = removerItem(&aux);
        inserirItem(&solicitacoes, numSolic);
      }
    }

    if( opcao == 5 )
      printf("Capacidade da fila: %d \n", tamanhoDaFila(&solicitacoes) );

    if( opcao == 6 )
      if( filaVazia(&solicitacoes) == 0 )
        printf("A fila não está vazia. \n");
      else
        printf("A fila está vazia. \n");

    printf("\n\n*** Tecla 0 para continuar...", tamanhoDaFila(&solicitacoes) );
    scanf("%d",&opcao);

  }while( opcao != 9 );

  return 0;
}