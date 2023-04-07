# Conversor de bases em C

Este trabalho foi desenvolvido como atividade avaliativa para a disciplina de Sistemas Lógicos do curso de Ciência da Computação da Universidade Federal do Amazonas (UFAM).

## Descrição do projeto
Um simples e divertido algoritmo em C para conversão de valores de qualquer base para qualquer base. 
Informe a base de origem, a base de destino e o valor a ser convertido. Receba o resultado da conversão e o seu equivalente valor na base 10.

## Limitações
Bases válidas: 2 a 62. Valor máximo possível (em base 10): 4.294.967.295.

## Pré-requisitos
* gcc

## Como rodar essa aplicação
```bash
# Clone este repositório
$ git clone https://github.com/juhanada/conversor-de-bases-c.git

# Acesse a pasta do projeto no terminal/cmd
$ cd conversor-de-bases-c

# Compile utilizando o gcc
$ gcc conversor.c -o conversor

# Execute
$ ./conversor
```

## Caracteres válidos e seus valores correspondentes
Foram utilizados 62 caracteres para codificação do valor (0-9, A-Z, a-z).
| Símbolo  | Valor em decimal | Símbolo  | Valor em decimal | Símbolo  | Valor em decimal |
| ------ | ------ | ------ | ------ | ------ | ------ |
| 0 | 0 | A | 10 | a | 36 |
| 1 | 1 | B | 11 | b | 37 |
| 2 | 2 | C | 12 | c | 38 |
| 3 | 3 | D | 13 | d | 39 |
| 4 | 4 | E | 14 | e | 40 |
| 5 | 5 | F | 15 | f | 41 |
| 6 | 6 | G | 16 | g | 42 |
| 7 | 7 | H | 17 | h | 43 |
| 8 | 8 | I | 18 | i | 44 |
| 9 | 9 | J | 19 | j | 45 |
| - | - | K | 20 | k | 46 |
| - | - | L | 21 | l | 47 |
| - | - | M | 22 | m | 48 |
| - | - | N | 23 | n | 49 |
| - | - | O | 24 | o | 50 |
| - | - | P | 25 | p | 51 |
| - | - | Q | 26 | q | 52 |
| - | - | R | 27 | r | 53 |
| - | - | S | 28 | s | 54 |
| - | - | T | 29 | t | 55 |
| - | - | U | 30 | u | 56 |
| - | - | V | 31 | v | 57 |
| - | - | W | 32 | w | 58 |
| - | - | X | 33 | x | 59 |
| - | - | Y | 34 | y | 60 |
| - | - | Z | 35 | z | 61 |
