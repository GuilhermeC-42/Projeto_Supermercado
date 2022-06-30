#include <stdio.h>

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
  if(toupper(tipoPagamento) == 'P'){
    scanf("%s %lf", moeda, &minimoParcela);
    if(totalCompra < minimoParcela){
      tipoPagamento = 'A';
    }
    numeroParcelas = totalPagamento / minimoParcela;
    valorParcela = totalPagamento / numeroParcelas;
  }

// Saídas
  int contItem = 0;
  while(contItem < totalItens){
  for(int i = 0; i < numCategoria; i++){
      printf("%s\n", CatTotais[i].nomeCat);
      for(int x = 0; x <  CatTotais[i].numItens; x++){
        printf("* %s: %s %.2lf (%.1lf %s)\n", Itens[contItem].nomeItem, Itens[contItem].unimoeda, Itens[contItem].totalItem, Itens[contItem].qtdItems, Itens[contItem].uniMedida);   
        ++contItem; 
      }  
      printf("** TOTAL %s: R$ %.2lf\n\n",CatTotais[i].nomeCat, CatTotais[i].totalCat);
  }
  }
  printf("TOTAL DE ITENS: %d \n", totalItens);
  printf("VALOR TOTAL: R$ %.2lf\n", totalCompra);
  printf("DESCONTO: %.2lf %%\n", valorDesconto);
  printf("VALOR DO DESCONTO: R$ %.2lf\n",totalDesconto);
  printf("VALOR A PAGAR: R$ %.2lf", totalPagamento);
  
  // Aplica os dados extras para caso de pagamento parcelado.
  if(toupper(tipoPagamento) == 'P'){
    printf("\nPARCELAS: %d\n", numeroParcelas);
    printf("VALOR DA PARCELA: R$ %.2lf\n", valorParcela);
  }

  return 0;
}