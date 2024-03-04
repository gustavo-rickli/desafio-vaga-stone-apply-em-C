#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
  int totalDeEmails;
  char *listaDeEmails;
  float quantiaPorPessoa;
} Pagamento;

typedef struct {
  char *nomeItem;
  int quantidadeItem;
  float precoUnidade;
} Carrinho_de_compras;

// Parâmetros:  um ponteiro constante dados constante da struct Carrinho_de_compras
//              um ponteiro constante para dados constates do array listaDeEmails
// Retorno:     um ponteiro da struct Pagamento
Pagamento desafio_calcula(const Carrinho_de_compras *listaDeCompra, const char *listaDeEmails[]);
// const struct Carrinho_de_compras* listaDeCompra
// const char* const listaDeEmails[] 

// imprime os emails com seus devidos valores
void imprimir_resultado(Pagamento resultado);

int main(void) {

  // GERA SEUS ITENS AQUI
  // FORMATO GENÉRICO PARA GERAR CADA ITEM:
  // NOME DO ITEM (string)  |  QUANTIDADE DE ITENS (int)  |  PREÇO POR UNID. (float)
  Carrinho_de_compras listaDeCompra[] = {
    {"Banana", 4, 8},
    {"Milho", 5, 3.5}
  };

  // GERE SEUS EMAILS AQUI
  // COLOQUE COMO ÚLTIMA STRING O CARACTER NULO '\0', POIS ELE INDICA DA LISTA DE EMAILS 
  char *listaDeEmails[] = {
    "stone@gmail.com",
    "maria@hotmail.com",
    "joao@yahoo.com",
    '\0'
  };

  Pagamento resultado = desafio_calcula(&listaDeCompra, listaDeEmails);

  imprimir_resultado(resultado);

  return 0;
}

Pagamento desafio_calcula(const Carrinho_de_compras* listaDeCompra, const char *listaDeEmails[]) {

  // Pegar o tamanho da lista de emails
  int TAMANHO_LISTA_DE_EMAILS = -1;
  while(listaDeEmails[++TAMANHO_LISTA_DE_EMAILS]!='\0');

  Pagamento pagamento = {TAMANHO_LISTA_DE_EMAILS};

  float valorTotalDosItens = 0;

  // Calcular a soma dos valores
  for (int counter = 0; counter <= sizeof(listaDeCompra[0]) / sizeof(listaDeCompra);  counter = counter + 1) {
    valorTotalDosItens += listaDeCompra[counter].quantidadeItem * listaDeCompra[counter].precoUnidade;
  }

  // Definição da structure que será retornada
  // Dividir o valor de forma igual entre a quantidade de e-mails
  pagamento.quantiaPorPessoa = valorTotalDosItens / pagamento.totalDeEmails;
  pagamento.listaDeEmails = *listaDeEmails;

  //Retornar uma struct do Pagamento
  return pagamento;
}

void imprimir_resultado(Pagamento pagamento) {
  
  int counter = 0;
  int localDoPtr = pagamento.quantiaPorPessoa;

  printf("\n\n\t ----------------------------------\n");
  printf("\t  %s%d%s\n", "Possuimos ", pagamento.totalDeEmails, " emails no total");
  printf("\t ----------------------------------\n");
  printf("\t  %s%.2f\n", "Cada pessoa vai pagar R$", pagamento.quantiaPorPessoa);
  printf("\t ----------------------------------\n");

  for (counter = 0; counter <= pagamento.totalDeEmails - 1; counter = counter + 1) {

    printf("\t  %d %s", counter + 1, "email -> ");

    while (*pagamento.listaDeEmails != '\0') {
      printf("%c", *pagamento.listaDeEmails);
      pagamento.listaDeEmails = pagamento.listaDeEmails + 1;
    }

    pagamento.listaDeEmails = pagamento.listaDeEmails + 1;
    printf("\n");
  }

  printf("\t ----------------------------------\n\n\n");

  //printf("\n\t-> End Testing\t\n");
}
