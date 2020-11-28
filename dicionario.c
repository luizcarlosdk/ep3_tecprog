/*
  AO PREENCHER(MOS) ESTE CABEÇALHO COM O(S) MEU(NOSSOS) NOME(S) E
  O(S) MEU(NOSSOS) NÚMERO(S) USP, DECLARO(AMOS) QUE SOU(SOMOS) O(S)
  ÚNICO(S) AUTOR(ES) E RESPONSÁVEL(IS) POR ESTE ARQUIVO. TODAS AS
  PARTES ORIGINAIS DO EXERCÍCIO PROGRAMA (EP) FORAM DESENVOLVIDAS
  E IMPLEMENTADAS POR MIM(NÓS) SEGUINDO AS INSTRUÇÕES DO EP E, 
  PORTANTO, NÃO CONSTITUEM DESONESTIDADE ACADÊMICA OU PLÁGIO.  
  DECLARO TAMBÉM QUE SOU(SOMOS) RESPONSÁVEL(IS) POR TODAS AS CÓPIAS
  DESTE ARQUIVO E QUE EU(NÓS) NÃO DISTRIBUÍ(MOS) OU FACILITEI(AMOS)
  A SUA DISTRIBUIÇÃO. ESTOU(AMOS) CIENTE(S) DE QUE OS CASOS DE PLÁGIO 
  E DESONESTIDADE ACADÊMICA SERÃO TRATADOS CONFORME SUA GRAVIDADE.
  ENTENDO(EMOS) QUE EPS SEM ASSINATURA NÃO SERÃO CORRIGIDOS E, 
  AINDA ASSIM, PODERÃO SER PUNIDOS POR DESONESTIDADE ACADÊMICA.

  Nome(s) :
  NUSP(s) :

  Referências: Com exceção das rotinas fornecidas no enunciado e em
  sala de aula, caso você(s) tenha(m) utilizado alguma referência,
  liste(m) abaixo para que o programa não seja considerado plágio ou
  irregular.
 
  Exemplo:
  - O algoritmo Quicksort foi baseado em
  http://www.ime.usp.br/~pf/algoritmos/aulas/quick.html
*/

#include "dicionario.h"
#include <string.h>

/*
 * Função: criaDicionario
 * ---------------------------------
 * Aloca dinamicamente um dicionário com a capacidade passada no parâmetro
 * qtde_maxima_entradas. 
 * Na estrutura interna do dicionário, a função aloca espaço para 
 * qtde_maxima_entradas strings de tamanho máximo TAM_MAX_ENTRADA.
 * A função devolve um ponteiro para o dicionário alocado.
 */

tDicionario* criaDicionario (short qtde_maxima_entradas){
  tDicionario* dicionario = malloc(sizeof(tDicionario));
  dicionario.capacidade = qtde_maxima_entradas;
  dicionario.tamanho = 0; 
  dicionario.entradas = malloc(TAM_MAX_ENTRADA * sizeof(char*)); 
  
  int i;
  for(i = 0; i < TAM_MAX_ENTRADA; i++){
    dicionario->entradas[i] = malloc(qtde_maxima_entradas *sizeof(char));
  }

  return dicionario; 

}

/*
 * Função: destroiDicionario
 * ---------------------------------
 * Desaloca um dicionario alocado dinamicamente (desalocando, inclusive
 * os espaços alocados paras as strings das entradas que mantém). 
 */
void destroiDicionario (tDicionario* dicionario){
  int i;
  for(i = 0; i < TAM_MAX_ENTRADA; i++){
    free(dicionario->entradas[i]);
  }

  free(dicionario->entradas);
  free(dicionario); 
}

/*
 * Função: adicionaEntrada
 * ---------------------------------
 * Se o dicionário não está cheio, a função adiciona a entrada nele.
 * Nesse caso, a entrada é incluída na posição seguinte à última posição 
 * atualmente ocupada no vetor de entradas. 
 * A função devolve o código da entrada no dicionário (ou seja, o número
 * da posição onde a entrada foi incluída) ou devolve -1 quando o 
 * dicionário está cheio.
 */
short adicionaEntrada(tDicionario *dicionario, char *entrada){
  if(dicionario->capacidade >= dicionario->tamanho){
    strcpy(dicionario->entradas[dicionario->tamanho], entrada);
    dicionario->tamanho++;
    return (dicionario->tamanho - 1); 
  }

  else {
    return -1; 
  }
}

/*
 * Função: obtemEntrada
 * ---------------------------------
 * A função devolve a entrada que corresponde ao código no dicionário.
 * O código indica a posição em que a entrada está armazenada.
 * A função devolve NULL quando o código passado no parâmetro é inválido.
 */
char* obtemEntrada(tDicionario *dicionario, short codigo){
  
}