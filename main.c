#include <stdio.h>

/* Código por: Guilherme Cordeiro Peixoto
 * Estudante de Engenharia de Computação
 * Centro Universitário SENAC
 */



/* Estrutura Item que recebe(em ordem) nome, unidade de medida,
 * unidade de moeda, quantidade do item, valor unitário e o seu 
 * total.
 */ 
typedef struct{
  char Nome_Item[16];
  char Uni_Med[4], Uni_Mon[3];
  double Qtd, Val_Unit;
  double Total_Item;

}Item;

/* Estrutura Categorias que recebe(em ordem) nome, número de
 * itens e o total.
 */ 
typedef struct{
  char Nome_Cat[26];
  int Num_Itens;
  double Total_Cat;
}Categoria;


int main(void) {
  
// Definindo o número de categorias contadores auxiliares.  
  int Num_Cat, x, i, y, z, Total_Itens = 0;

// Variáveis para pagamento, incluindo desconto e parcelas.
  char Tipo_Pag, Moeda[4];
  double Desc, Tot_Desc, Total = 0,  Tot_Pag, Min_Parc, Val_Parc;
  int Num_Par;

// Recebe o número de categorias e cria as estrturas Itens e Cat_Totais.
  scanf("%d", &Num_Cat);
  Item Itens[20];
  Categoria Cat_Totais[Num_Cat];
  
// Loop que repete até todas as categorias desejadas sejam lidas.  
  for(i = 0; i < Num_Cat; i++){

// Recebe o nome da categoria e quantidade de itens nela.
    scanf("%s", Cat_Totais[i].Nome_Cat);
    scanf("%d", &Cat_Totais[i].Num_Itens);

// Recebe as informações sobre os itens.
    for(x = 0; x < Cat_Totais[i].Num_Itens; x++ ) {
      scanf("%s %lf %s %s %lf", Itens[Total_Itens].Nome_Item, &Itens[Total_Itens].Qtd, Itens[Total_Itens].Uni_Med, Itens[Total_Itens].Uni_Mon, &Itens[Total_Itens].Val_Unit);

/* Multiplica o valor unitário do item x pela quantidade
 * do mesmo e atribui ao total da categoria e total a pagar.
 */    
      Itens[Total_Itens].Total_Item = Itens[Total_Itens].Qtd * Itens[Total_Itens].Val_Unit;
      Cat_Totais[i].Total_Cat += Itens[Total_Itens].Total_Item;
      
      Total += Itens[Total_Itens].Total_Item; 

 // Armazena as informações de um item e vai para o próximo. 
      ++Total_Itens;
    }
  }

// Recebe o desconto e forma de pagamento.
  scanf("%lf %c", &Desc, &Tipo_Pag);

// Cálculo do valor total do desconto e total a pagar.
  Tot_Desc = ((Total * Desc) / 100);
  Tot_Pag = Total - Tot_Desc;

// Disponibiliza o pagamento parcelado.
  if(Tipo_Pag == 'P' || Tipo_Pag == 'p'){
    scanf("%s %lf", Moeda, &Min_Parc);
    if(Total < Min_Parc){
      Tipo_Pag = 'A';
    }
    Num_Par = Tot_Pag / Min_Parc;
    Val_Parc = Tot_Pag / Num_Par;
  }


// Printa os valores finais.
  printf("\n\nGuilherme Cordeiro Peixoto\n");
  printf("guilherme.cordeiro3@hotmail.com\n\n");
  z = 0;
  while(z < Total_Itens){
  for(int i = 0; i < Num_Cat; i++){
      printf("%s\n", Cat_Totais[i].Nome_Cat);
      for(x = 0; x <  Cat_Totais[i].Num_Itens; x++){
        printf("* %s: %s %.2lf (%.1lf %s)\n", Itens[z].Nome_Item, Itens[z].Uni_Mon, Itens[z].Total_Item, Itens[z].Qtd, Itens[z].Uni_Med);   
        ++z; 
      }  
      printf("** TOTAL %s: R$ %.2lf\n\n",Cat_Totais[i].Nome_Cat, Cat_Totais[i].Total_Cat);
  }
  }
  printf("TOTAL DE ITENS: %d \n", Total_Itens);
  printf("VALOR TOTAL: R$ %.2lf\n", Total);
  printf("DESCONTO: %.2lf %%\n", Desc);
  printf("VALOR DO DESCONTO: R$ %.2lf\n",Tot_Desc);
  printf("VALOR A PAGAR: R$ %.2lf", Tot_Pag);
  
  // Aplica os dados extras para caso de pagamento parcelado.
  if( Tipo_Pag == 'P' || Tipo_Pag == 'p'){
    printf("\nPARCELAS: %d\n", Num_Par);
    printf("VALOR DA PARCELA: R$ %.2lf\n", Val_Parc);
  }

  return 0;
}