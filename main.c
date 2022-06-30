#include <stdio.h>
#include <stdbool.h>

/* Estrutura Item que recebe(em ordem) nome, unidade de medida,
 * unidade de moeda, quantidade do item, valor unitário e o seu 
 * total.
 */ 
typedef struct{
  char nomeItem[16];
  char uniMedida[4], unimoeda[3];
  double qtdItems, valUnitario;
  double totalItem;
}Item;

/* Estrutura Categorias que recebe(em ordem) nome, número de
 * itens e o total.
 */ 
typedef struct{
  char nomeCat[26];
  int numItens;
  double totalCat;
}Categoria;

/* Função que verifica se pagamento é parcelado ou não */
bool verifica_pagamento_parcelado(char pagamento){
  if(toupper(pagamento) == 'P'){
    return true;
  }
  else{
    return false;
  }
}

int main(void) { 
  int numCategoria, numeroParcelas, totalItens = 0;
  char tipoPagamento, moeda[4];
  double valorDesconto, totalDesconto, totalCompra = 0, totalPagamento, minimoParcela, valorParcela;

// Criação de estruturas
  scanf("%d", &numCategoria);
  Item Itens[20];
  Categoria CatTotais[numCategoria];

// Preenchimento das categorias
  for(int contCategoria = 0; contCategoria < numCategoria; contCategoria++){
    scanf("%s", CatTotais[contCategoria].nomeCat);
    scanf("%d", &CatTotais[contCategoria].numItens);

    for(int x = 0; x < CatTotais[contCategoria].numItens; x++ ) {
      scanf("%s %lf %s %s %lf", 
        Itens[totalItens].nomeItem,  
        &Itens[totalItens].qtdItems, 
        Itens[totalItens].uniMedida, 
        Itens[totalItens].unimoeda, 
        &Itens[totalItens].valUnitario);
    
      Itens[totalItens].totalItem = Itens[totalItens].qtdItems * Itens[totalItens].valUnitario;
      CatTotais[contCategoria].totalCat += Itens[totalItens].totalItem;
      
      totalCompra += Itens[totalItens].totalItem; 

      ++totalItens;
    }
  }

// Preenchimento dos descontos
  scanf("%lf %c", &valorDesconto, &tipoPagamento);

  totalDesconto = ((totalCompra * valorDesconto) / 100);
  totalPagamento = totalCompra - totalDesconto;

// Disponibiliza o pagamento parcelado.
  if(verifica_pagamento_parcelado(tipoPagamento)){
    scanf("%s %lf", moeda, &minimoParcela);
    if(totalCompra < minimoParcela){
      tipoPagamento = 'A';
    }
    numeroParcelas = totalPagamento / minimoParcela;
    valorParcela = totalPagamento / numeroParcelas;
  }

// Saídas
  int contItens = 0;
  while(contItens < totalItens){
    for(int contItem = 0; contItem < numCategoria; contItem++){
        printf("%s\n", CatTotais[contItem].nomeCat);

        for(int contItemMostrado = 0; contItemMostrado < CatTotais[contItem].numItens; contItemMostrado++){
          printf("* %s: %s %.2lf (%.1lf %s)\n", 
          Itens[contItens].nomeItem, 
          Itens[contItens].unimoeda, 
          Itens[contItens].totalItem, 
          Itens[contItens].qtdItems, 
          Itens[contItens].uniMedida);   
          
          ++contItens; 
        }  
        
        printf("** TOTAL %s: R$ %.2lf\n\n",
        CatTotais[contItem].nomeCat, 
        CatTotais[contItem].totalCat);
    }
  }
  printf("TOTAL DE ITENS: %d \n", totalItens);
  printf("VALOR TOTAL: R$ %.2lf\n", totalCompra);
  printf("DESCONTO: %.2lf %%\n", valorDesconto);
  printf("VALOR DO DESCONTO: R$ %.2lf\n",totalDesconto);
  printf("VALOR A PAGAR: R$ %.2lf", totalPagamento);
  
  // Aplica os dados extras para caso de pagamento parcelado.
  if(verifica_pagamento_parcelado(tipoPagamento)){
    printf("\nPARCELAS: %d\n", numeroParcelas);
    printf("VALOR DA PARCELA: R$ %.2lf\n", valorParcela);
  }

  return 0;
}