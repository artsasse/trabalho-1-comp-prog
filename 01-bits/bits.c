/*
 * Primeiro laboratório de Computadores e Programação
 *
 * A ideia do laboratório é mostrar ao aluno outras formas de fazer as operações
 * que ele já está acostumado a fazer, mas de formas diferentes.
 * Criamos esse desafio com o objetivo de fazê-lo pensar em diferentes formas de se
 * atingir o mesmo resultado. Num cenário real, saber quais instruções são melhor
 * otimizadas pelo compilador pode ajudar muito a perfomance de um programa.
 *
 * O aluno deverá usar apenas um subset de operações de C para realizar o que
 * for pedido no enunciado.
 *
 * Todas as operações permitidas serão especificadas em cada questão.
 * Não está permitido o uso de if-else, for, while, switch, etc.
 *
 * Forma de avaliação:
 *      - Quantas operações o aluno utilizou para realizar a tarefa (se está dentro da quantidade aceitável)
 *      - Explicação do código -- deverá ser o mais claro possível,
 *          imaginando que qualquer pessoa sem conhecimento prévio da
 *          matéria consiga entender o que foi feito, em detalhes.
 *      - As resoluções com menos operações do que a do monitor terão bonificação.
 *
 * Assinatura:
 *      Alunos: Arthur Mendonça Sasse - Gabriel Bitencourt
 *      DRE: 117206692 - XXXXXXXX
 *      versão do GCC utilizada: 10.2.0
 *
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdint.h>

/* Número não é zero
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x é diferente 0, retorna 0 caso contrário
 *
 *      Exemplo:
 *          naoEhZero(0) -> 0
 *          naoEhZero(7) -> 1
 */
int32_t naoEhZero(int32_t x) {
    //O operador ! converte um operando diferente de zero em 0 e um operando zero em 1.
    //Se x for diferente de zero, primeiro é convertido para 0 e depois para 1.
    //Se x for zero, primeiro é convertido para 1 e depois para 0.
    return !!x;
}

/* Número é par ou não
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x é par, retorna 0 caso contrário
 *
 *      Exemplo:
 *          ehPar(0) -> 1
 *          ehPar(2) -> 1
 *          ehPar(7) -> 0
 */
int32_t ehPar(int32_t x) {
    //do segundo bit até o bit mais significativo, todos representam valores divisíveis por 2.
    //O bit que determina se o número é par ou ímpar é o menos significativo.
    //Ele representa adicionar ou não + 1 a um número que sabemos que é par.
    //Se adicionamos, o número fica ímpar. Se não adicionamos, o número se mantém par.
    //Por isso, fazemos uma mascara com o número 1 usando o operador &, para obter apenas o bit menos significativo.
    //Se o bit menos significativo de x for 1, o resultado da primeira operação será 1, o número é impar.
    //Se o bit menos significativo de x for 0, o resultado da primeira operação será 0, o número é par.
    //Usamos o operador ! apenas para inverter o resultado.
    return !(x & 1);
}

/*
 * Módulo 8
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 1
 *
 *      Retorna x % 8
 *
 *      Exemplo:
 *          mod8(1) -> 1
 *          mod8(7) -> 7
 *          mod8(10) -> 2
 */
int32_t mod8(int32_t x) {
    //Do 4° bit até o bit mais significativo, todos os valores representados por esses bits sao divisiveis por 8.
    //O que vai determinar o modulo da divisao sao os valores nos 3 bits menos significativos
    //Esses 3 bits representam todos os valores menores que 8, até zero. Logo, representam todos os valores de modulo de 8.
    //A representacao dos negativos em complemento a 2 garante que o modulo também funcione para os negativos.
    return x & 7;
}

/* Número positivo ou não
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 5
 *      Monitor: 2
 *
 *      Retorna 1 se número é positivo, 0 caso contrário
 *
 *      Exemplo:
 *          ehPositivo(878) -> 1
 *          ehPositivo(-343) -> 0
 */
int32_t ehPositivo(int32_t x) {
    //Se x for positivo, seu bit mais significativo sera 0. 
    //Fazendo o shift aritmético para direita 31 vezes, repetiremos o zero em todos os bits, obtendo o valor 0.
    //O operador ! converte zero para 1.
    //Se x for negativo, seu bit mais significativo sera 1.
    //Fazendo o shift aritmético para direita 31 vezes, repetiremos o 1 em todos os bits, obtendo um valor diferente de zero.
    //O operador ! converte esse numero diferente de zero para 0.
    return !(x>>31);
}

/* Negativo sem -
 *      Permitido:
 *          Operações: ~ & ^ | ! << >> +
 *
 *      Número máximo de operações: 5
 *      Monitor: 2
 *
 *      Retorna -x
 *
 *      Exemplo:
 *          negativo(1) -> -1
 *          negativo(42) -> -42
 */
int32_t negativo(int32_t x) {
    //complemento a 2 é o principal padrao de representacao de numeros negativos em computadores
    //fazemos o complemento de x e depois somamos 1 unidade
    return (~x)+1;
}

/* Implementação do & usando bitwise
 *      Permitido:
 *          Operações: ~ ^ | ! << >>
 *
 *      Número máximo de operações: 7
 *      Monitor: 4
 *
 *      Retorna x & y
 *
 *      Exemplo:
 *          bitwiseAnd(1, 2) -> 0
 *              01 & 10 -> 00
 *          bitwiseAnd(3, 11) -> 3
 *              11 & 1011 -> 0011
 */
int32_t bitwiseAnd(int32_t x, int32_t y) {
    //Usando os operadores ~ e | conseguimos emular a tabela de algebra booleana do operador &

    // TABELA x & y       
    //   0|1
    // 0|0|0|
    // 1|0|1|

    // TABELA x | y     
    //   0|1
    // 0|0|1|
    // 1|1|1|

    // TABELA ~x | ~y     
    //   0|1
    // 0|1|1|
    // 1|1|0|

    // TABELA ~(~x | ~y)     
    //   0|1
    // 0|0|0|
    // 1|0|1|

    return ~(~x | ~y);
}

/* Igual sem ==
 *      Permitido:
 *          Operações: ~ & ^ | << >> ! +
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x == y, 0 caso contrário
 *
 *      Exemplo:
 *          ehIgual(10, 10) -> 1
 *          ehIgual(16, 8) -> 0
 */
int32_t ehIgual(int32_t x, int32_t y) {
    //x^y so vai retornar zero se x e y forem iguais. Em qualquer outro caso retorna um valor diferente de zero.
    //O operador ! usa o resultado da operacao anterior, tranformando zero em 1 e qualquer numero diferente de zero em 0.
    return !(x^y);
}

/*
 * Multiplicação por 7
 *      Permitido:
 *          Operações: << >> | ! & + -
 *
 *      Número máximo de operações: 4
 *      Monitor: 2
 *
 *      Retorna x multiplicado por 7
 *
 *      Exemplo:
 *          mult7(7) -> 49
 */
int32_t mult7(int32_t x) {
    //8x - x = 7x
    //primeiro fazemos um shift de 3 bits para esquerda, equivalente a multiplicar por 8
    //depois subtraimos x, para obter 7x
    return (x<<3) - x;
}

/*
 * Bit na posição p do inteiro x
 *      Permitido:
 *          Operações bitwise: << >> | & + -
 *
 *      Número máximo de operações: 6
 *      Monitor: 2
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser apenas 0 ou 1
 *
 *      p será um valor entre 0 e 31
 *
 *      Exemplo:
 *          23 em binário: 0   0 ... 0 1 0 1 1 1
 *               posições: 31 30 ... 5 4 3 2 1 0
 *
 *          bitEmP(23, 31) -> 0
 *          bitEmP(23, 5) -> 0
 *          bitEmP(23, 4) -> 1
 *          bitEmP(23, 3) -> 0
 *          bitEmP(23, 2) -> 1
 *          bitEmP(23, 1) -> 1
 *          bitEmP(23, 0) -> 1
 *
 */
int32_t bitEmP(int32_t x, uint8_t p) {
    //fazendo o shift para direita p vezes, trazemos o valor que estava no bit de posicao 'p' para o bit de posicao 0
    //Depois aplicamos uma mascara com o valor 1 para descobrir o valor que esta nesse bit menos significativo.
    //O numero 1 só possui o valor 1 no bit 0, logo, quando usamos o operador &, se o bit 0 em x for 0, o resultado será 0.
    //Se o bit 0 em x for 1, o resultado será 1.
    return (x>>p) & 1;
}

/*
 * Byte na posição p do inteiro x
 *      Permitido:
 *          Operações: << >> | ! &
 *
 *      Número máximo de operações: 6
 *      Monitor: 3
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser entre 0 e 0xFF
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          byteEmP(0x12345678, 0) -> 0x78
 *          byteEmP(0x12345678, 1) -> 0x56
 *          byteEmP(0x12345678, 2) -> 0x34
 *          byteEmP(0x12345678, 3) -> 0x12
 *
 */
int32_t byteEmP(int32_t x, uint8_t p) {
    //p é um valor em bytes, por isso multiplicamos por 8 para obter o valor P em bits
    //essa multiplicação é feita com o shift para a esquerda 3 vezes
    //depois fazemos um shift para direita P vezes em x
    //fazemos isso para trazer o valor que estava no byte p para o byte menos significativo
    //ao final usamos a mascara 0xFF para descobrir os valores presentes nesse byte menos significativo
    return (x>>(p<<3)) & 0xFF;
}

/*
 * Negação lógica sem !
 *      Permitido:
 *          Operações: << >> | & +
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna 1 se x == 0, retorna 0 caso contrário
 *
 *      Exemplo:
 *          negacaoLogica(0) -> 1
 *          negacaoLogica(37) -> 0
 *
 */
int32_t negacaoLogica(int32_t x) {
    return -1;
}

void teste(int32_t saida, int32_t esperado) {
    static uint8_t test_number = 0;
    test_number++;
    if(saida == esperado)
        printf(ANSI_COLOR_GREEN "PASSOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            saida, esperado);

    else
        printf(ANSI_COLOR_RED "%d: FALHOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            test_number, saida, esperado);
}

int main() {
    puts(ANSI_COLOR_BLUE "Primeiro lab - bits" ANSI_COLOR_RESET);
    puts("");

    puts("Teste: naoEhZero");
    teste(naoEhZero(0), 0);
    teste(naoEhZero(1), 1);
    teste(naoEhZero(1024), 1);
    teste(naoEhZero(-1), 1);
    teste(naoEhZero(-2), 1);
    teste(naoEhZero(-2147483648), 1);
    teste(naoEhZero(2147483647), 1);
    puts("");

    puts("Teste: ehPar");
    teste(ehPar(2), 1);
    teste(ehPar(1), 0);
    teste(ehPar(3), 0);
    teste(ehPar(13), 0);
    teste(ehPar(100), 1);
    teste(ehPar(125), 0);
    teste(ehPar(1024), 1);
    teste(ehPar(2019), 0);
    teste(ehPar(2020), 1);
    teste(ehPar(-1), 0);
    teste(ehPar(-27), 0);
    teste(ehPar(-1073741825), 0);
    teste(ehPar(1073741824), 1);
    teste(ehPar(2147483647), 0);
    teste(ehPar(-2147483648), 1);
    teste(ehPar(0), 1);
    puts("");

    puts("Teste: mod8");
    teste(mod8(0), 0);
    teste(mod8(4), 4);
    teste(mod8(7), 7);
    teste(mod8(8), 0);
    teste(mod8(-1), 7);
    teste(mod8(-8), 0);
    teste(mod8(2147483647), 7);
    teste(mod8(-2147483648), 0);
    puts("");

    puts("Teste: ehPositivo");
    teste(ehPositivo(-1), 0);
    teste(ehPositivo(1), 1);
    teste(ehPositivo(2037), 1);
    teste(ehPositivo(-2037), 0);
    teste(ehPositivo(-2147483648), 0);
    teste(ehPositivo(-2147483648/2), 0);
    teste(ehPositivo(2147483647), 1);
    puts("");

    puts("Teste: negativo");
    teste(negativo(0), 0);
    teste(negativo(1), -1);
    teste(negativo(-1), 1);
    teste(negativo(2147483647), -2147483647);
    teste(negativo(-2147483647), 2147483647);
    teste(negativo(-2147483648), 2147483648);
    puts("");

    puts("Teste: bitwiseAnd");
    teste(bitwiseAnd(1, 3), 1);
    teste(bitwiseAnd(-1, 0), 0);
    teste(bitwiseAnd(-1, 0x7FFFFFFF), 0x7FFFFFFF);
    teste(bitwiseAnd(0b0100, 0b1100), 0b0100);
    puts("");

    puts("Teste: ehIgual");
    teste(ehIgual(1,1), 1);
    teste(ehIgual(1,0), 0);
    teste(ehIgual(0,1), 0);
    teste(ehIgual(-1,1), 0);
    teste(ehIgual(-1,-1), 1);
    teste(ehIgual(2147483647,-1), 0);
    teste(ehIgual(2147483647,-2147483647), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    puts("");

    puts("Teste: mult7");
    teste(mult7(1), 7);
    teste(mult7(7), 49);
    teste(mult7(3), 21);
    teste(mult7(-1), -7);
    teste(mult7(-306783378), -2147483646);
    teste(mult7(306783378), 2147483646);
    puts("");

    puts("Teste: bitEmP");
    teste(bitEmP(1, 0), 1);   //    b01 => retorna 1
    teste(bitEmP(1, 1), 0);   //    b01 => retorna 0
    teste(bitEmP(2, 0), 0);   //    b10 => retorna 0
    teste(bitEmP(2, 1), 1);   //    b10 => retorna 1
    teste(bitEmP(9, 2), 0);   //  b1001 => retorna 0
    teste(bitEmP(-4194305, 22), 0);
    teste(bitEmP(9, 3), 1);
    teste(bitEmP(16, 3), 0);
    teste(bitEmP(0x1 << 5, 4), 0);
    teste(bitEmP(0x1 << 31, 31), 1);
    teste(bitEmP(-1073741825, 30), 0);
    teste(bitEmP(-1073741825, 31), 1);
    puts("");

    puts("Teste: byteEmP");
    teste(byteEmP(0x766B, 1), 0x76);
    teste(byteEmP(0x766B, 0), 0x6B);
    teste(byteEmP(0x8420, 0), 0x20);
    teste(byteEmP(0x12345678, 3), 0x12);   // retorna 0x12
    teste(byteEmP(0x12345678, 2), 0x34);   // retorna 0x34
    teste(byteEmP(0x12345678, 1), 0x56);   // retorna 0x56
    teste(byteEmP(0x12345678, 0), 0x78);   // retorna 0x78
    teste(byteEmP(0x321, 1), 0x03);        // retorna 0x03
    teste(byteEmP(0x321, 0), 0x21);        // retorna 0x21
    puts("");

    puts("Teste: negacaoLogica");
    teste(negacaoLogica(0), 1);
    teste(negacaoLogica(1), 0);
    teste(negacaoLogica(-1), 0);
    teste(negacaoLogica(64), 0);
    teste(negacaoLogica(-64), 0);
    teste(negacaoLogica(2147483647), 0);
    teste(negacaoLogica(-2147483648), 0);
    puts("");
}
