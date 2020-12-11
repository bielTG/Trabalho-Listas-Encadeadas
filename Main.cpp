/******************************************************
*  Gabriel Cardoso dos Santos Herculino               *
*  Trabalho de Algoritmos e Programação II (2020/2)   *
*  Professora: Graziela Santos de Araújo (Turma P05)  *
******************************************************/

// Bibliotecas utilizadas
#include "TAD1.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Declaração das variáveis
    int op, inicializado = 0;
    int coeficiente, expoente, x, resultado;
    termo *P1 = NULL;

    // Execução do programa
    do {
        // Menu de opções
        printf("\n  # 1 - Inicializar polinômio.");
        printf("\n  # 2 - Inserir termo ordenado.");
        printf("\n  # 3 - Imprimir polinômio.");
        printf("\n  # 4 - Remover termo.");
        printf("\n  # 5 - Reinicializar polinômio.");
        printf("\n  # 6 - Resolver polinômio.");
        printf("\n  # 7 - Finalizar programa.");
        printf("\nOpcao: ");
        scanf("%d", &op);
        
        // Opção 1: Inicialização de polinômio
        if(op == 1) {
            if(!inicializado) {
                inserir_ordenado(0, 0, P1);
                printf("Polinômio inicializado!\n");
                inicializado = 1;
            } else
                printf("O polinômio já está inicializado!\n");
        }
        // Opção 2: Inserção de termo no polinômio
        else if(op == 2) {
            if(inicializado){
                printf("Informe o coeficiente e o expoente: ");
                scanf("%d %d", &coeficiente, &expoente);
                inserir_ordenado(coeficiente, expoente, P1);
                printf("O termo foi inserido!\n");
            } else
                printf("Inicialize o polinômio para inserir termos!\n");
        }
        // Opção 3: Impressão de polinômio atual
        else if(op == 3) {
            if(inicializado) {
                printf("Polinômio atual: ");
                imprimir_polinomio(P1);
            } else
                printf("O polinômio está vazio!\n");
        }
        // Opção 4: Remoção de termo conforme expoente excolhido
        else if(op == 4) {
            if(inicializado) {
                printf("Informe o expoente do termo a ser removido: ");
                scanf("%d", &expoente);
                remover_termo(expoente, P1);
                printf("Termo removido!\n");
            } else
                printf("Não há termos para remover!\n");
        }
        // Opção 5: Reinicialização do polinômio
        else if(op == 5) {
            if(inicializado) {
                reinicializar_polinomio(P1);
                printf("\nPolinômio reinicializado!\n");
            }
            else
                printf("O polinômio ainda não foi inicializado!\n");
        }
        // Opção 6: Cálculo do polinômio para o valor de x
        else if(op == 6) {
            if(inicializado) {
                printf("Determine o valor de x: ");
                scanf("%d", &x);
                resultado = resolver_polinomio(x, P1);
                printf("Resultado: %d\n", resultado);
            } else
                printf("O polinômio ainda não foi inicializado!\n");
        }
        else
            printf("Opção não encontrada!\n");
    } while(op != 7);
    printf("Programa Finalizado!\n");
    return 0;
}