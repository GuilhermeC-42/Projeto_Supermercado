# Projeto_Supermercado <img src="https://user-images.githubusercontent.com/63323023/176590543-eb7c7939-1852-4d1a-a1c6-431451c47573.png" alt="drawing" width="35"/>
## Descrição
Projeto de simulação de sistema de supermercado utilizando paradigma procedural em C. 

## Dependências
São compiladas junto ao código, não sendo necessária a instalação das mesmas.
- [stdio](https://www.ibm.com/docs/en/zos/2.3.0?topic=files-stdioh-standard-input-output)
- [stdbool](https://www.ibm.com/docs/en/zos/2.3.0?topic=files-stdboolh-macros-bool-type)

## Execução
O projeto pode ser executado diretamente pela prompt de comando.
<br/><br/>
O preenchimento deve possuir a seguinte ordem:
 1. Número total de categorias a serem cadastrados (podendo ser separada em frutas, carnes, etc.);
 2. Nome da categoria;
 3. Número de itens em cada categoria;
<br/><br/>
###
Para cada item, preencher em uma linha no seguinte formato (separando cada campo por espaço ' '):
  - Nome do item, Quantidade, Unidade de medida (Kg, L, etc.), Moeda, Valor unitário. 
<br/><br/>
###
Ao finalizar o preenchimento de todos os itens e categorias, as informações de desconto são inseridas no formato percentual e o tipo de pagamento (A prazo / Parcelado) em caractere:
  - Percentual (0.X), Tipo de pagamento('A'||'P').
<br/><br/>
###
Por fim, caso o pagamento seja parcelado definir a moeda e valor da parcela desejada:
  - Moeda, Valor da parcela.
<br/><br/>
<br/><br/>
###
## Limitações e melhorias
Por questões de síntaxe, o código exige padrões de entrada fixos. 
Pode ser aprimorado com funções para postagem de informações no terminal, evitando a poluição do código.
