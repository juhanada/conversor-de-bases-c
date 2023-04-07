/*
  Universidade Federal do Amazonas
  Instituto de Computação
  ICC060 - Sistemas Lógicos
  Acadêmica: Juíle Hanada
  Atividade Prática 01 - Conversor de Bases

  Instruções: O seguinte código corresponde ao algoritmo em C para conversão de bases entre 2 a 61, com o valor em decimal limitado a 4.294.967.295 (unsigned int)

  Observação: Foi implementado para o usuário especificar sempre a base de origem e destino. Sem essa especificação, não seria possível estabelecer se o valor lido é corresponde a base de origem ou destino. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// validar bases de entrada e saída (2-61)
bool isBaseValid(unsigned char base) {
  if (base >= 2 && base <= 61)
    return true;
  else {
    printf("Base inválida.\n");
    return false;
  }
}

// caracteres válidos: 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz)
bool isCharValid(char c) {
  return !(c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c >122);
}

// converter caracter alfanumerico em valor decimal
int parseCharToValue(char c) {
  // valor caso char seja numero (char 48-57)
  if (c < 58) 
    return c-48;
  // valor caso char seja letra maiuscula (char 65-90)
  if (c < 91)
    return c-55;
  // valor caso char seja letra minuscula (char 97-122)
  return c-62;
}

// converter valor decimal em caracter alfanumerico
char parseValueToChar(unsigned char value) {
  if (value < 10)
    return value + 48;
  if (value < 36)
    return value + 55;
  return value + 62;
}

// validar valor do caracter lido válido (valor <  base)
bool isValueValid(unsigned char value, unsigned int base) {
  return value < base;
}

int main () {
  unsigned char value; // valor atribuído a cada caracter (0-60)
  unsigned char *values = NULL; // vetor para armazenar valores na base de origem e caracteres na saída
  unsigned int base_origem, base_destino;
  unsigned int quociente = 0; // variavel utilizada no metodo de divisoes sucessivas
  unsigned int decimal; // max valor possível de conversão = 4.294.967.295
  bool valida; // variavel para controlar loop de entrada de base
  char c; // caracter utilizado para leitura e escrita da cadeia
  unsigned int length = 0; // tamanho da cadeia de entrada e saída

  // lendo e validando base de entrada
  valida = false;
  while (!valida) {
    printf("Informe a base de entrada (2 a 61): ");
    scanf("%u", &base_origem);
    valida = isBaseValid(base_origem);
  }

  // lendo e validando base de destino
  valida = false;
  while (!valida) {
    printf("Informe a base de destino (2 a 61): ");
    scanf("%u%*c", &base_destino);  
    valida = isBaseValid(base_destino);
  }

  // lendo cadeia a ser convertida
  printf("Informe a cadeia a ser convertida: ");
  while((c = getchar()) != 10) {

    // validando caracter: 
    if (!isCharValid(c)) {
      printf("Caracter inválido: \"%c\". São válidos somente números e letras.\n", c);
      break;
    }

    // atribuindo e validando valor ao caracter digitado
    value = parseCharToValue(c);
    if (!isValueValid(value, base_origem)) {
      printf("Caracter inválido: \"%c\". Esse caracter é inválido para a base de origem selecionada.\n", c);
      break;
    }

    // salvando valor em vetor alocado de forma dinâmica
    if (values == NULL) {
      values = (unsigned char *) malloc(sizeof(char) * (length+1));
      values[0] = value;
    } else {
      values = (unsigned char *) realloc(values, sizeof(char) * (length+1));
      values[length] = value;
    }
    length++;
  }

    // conversao para decimal
    decimal = 0;
    for (unsigned int i = length; i >0; i--){
      unsigned int valorConvertido = values[i-1] * pow(base_origem, (length-i));
      decimal += valorConvertido; 
    }

    // conversao para base de destino
    length = 0;
    quociente = decimal;
    free(values);
    values = NULL;
    while (quociente > 0) {
      value = quociente % base_destino;
      quociente = quociente/base_destino;
      c = parseValueToChar(value);
 
      // armazenando vetor de caracteres
      if (values == NULL) {
        values = (unsigned char *) malloc(sizeof(char) * (length+1));
        values[0] = c;   
      } else {
        values = (unsigned char *) realloc(values, sizeof(char) * (length+1));
        values[length] = c;
      }
      length++;
    }

    // impressao da cadeia na base de destino reversa
    printf("Resultado: ");
    for (unsigned int i = length; i >0; i--){
      printf("%c",values[i-1]);
    }
    
    printf(" na base %d. Em decimal: %d\n", base_destino, decimal);
    free(values);

  return 0;
}