/******************************************************
*  Gabriel Cardoso dos Santos Herculino               *
*  Trabalho de Algoritmos e Programação II (2020/2)   *
*  Professora: Graziela Santos de Araújo (Turma P05)  *
******************************************************/

// Bibliotecas utilizadas
#include "TAD1.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função que insere um termo n ordenadamente na lista
void inserir_ordenado(int coef, int exp, termo* &lst) 
{
    // Variáveis utilizadas
    termo *novo, *p, *aux;
    
    // Alocação e definição de novo nó da lista
    novo = (termo *) malloc (sizeof(termo));
    novo -> ant = NULL;
    novo -> coeficiente = coef;
    novo -> expoente = exp;
    novo -> prox = NULL;

    // Verifica se o nó vai inicializar a lista
    if(lst == NULL) {
        lst = novo;
    }
    // Verifica se o novo nó vai passar a ser o primeiro da lista
    else if(novo->expoente < lst->expoente){
        novo->prox = lst;
        lst->ant = novo;
        lst = novo;
    }
    // Ou caso o nó não fique na primeira posição
    else {
        // Percorrer a lista para verificar a posição do novo nó
        p = lst; 
        while(1) {
            // Caso o expoente já exista, soma-se o novo termo com o já existente
            if(novo->expoente == p->expoente) {
                p->coeficiente += novo->coeficiente;
                break;
            }

            // Ou então, se chegar ao final da lista, o novo se torna o último nó
            else if(p->prox == NULL) {
                p->prox = novo;
                novo->ant = p;
                break;
            }

            // Ou então ele entra ordenado na posição correta
            else if(novo -> expoente < p->prox->expoente) {
                aux = p->prox;
                p->prox = novo;
                novo->prox = aux;
                novo->ant = p;
                novo->prox->ant = novo;
                break;
            } 
            p = p->prox; // Passa variável para o próximo nó
        }
    }
}

// // Função que remove um elemento x da lista
void remover_termo(int exp, termo* &lst) 
{    
    // Percorrer a lista até encontrar elemento igual a x
    termo *p;
    for(p = lst; p != NULL; p = p->prox) {
        if(p->expoente == exp) {
            // Se o nó removido for o primeiro, atualiza lst
            if(p->ant == NULL)
                lst = p->prox;

            // Ou se o nó não for o primeiro, atualiza o prox do nó anterior
            else if(p->ant != NULL)
                p->ant->prox = p->prox;

            // Se o nó não for o último, atualiza o ant do nó posterior
            if(p->prox != NULL)
                p->prox->ant = p->ant;

            free(p);
            break;
        }
    }
}

// // Função que remove todas ocorrências de um elemento x na lista
void remover_ocorrencias(int x, termo* &lst) 
{    
    // Percorrer a lista enquanto houver nós e remover os iguais a x
    termo *p;
    for(p = lst; p != NULL; p = p->prox) {
        if(p->expoente == x) {
            // Se o nó removido for o primeiro, atualiza lst
            if(p->ant == NULL)
                lst = p->prox;

            // Ou se o nó não for o primeiro, atualiza o prox do nó anterior
            else if(p->ant != NULL)
                p->ant->prox = p->prox;

            // Se o nó não for o último, atualiza o ant do nó posterior
            if(p->prox != NULL)
                p->prox->ant = p->ant;
            free(p);
        }
    }
}

// Função que realiza a impressão dos nós de uma lista
void imprimir_polinomio(termo *lst) 
{    
    // Percorrer e enquanto houver nós na lista, imprimir o campo expoente
    termo *p;
    for(p = lst; p != NULL; p = p->prox){
        // Se o termo for o primeiro
        if(p == lst) {
            // Se o expoente for maior ou igual a 1
            if(p->expoente >= 1)
                printf("%dx^%d ", p->coeficiente, p->expoente);
            // Se o expoente for 0, não imprimi-lo
            else
                printf("%+d ", p->coeficiente);
        }
        // Se não for o primeiro
        else {
            // Se o expoente for maior ou igual a 1
            if(p->expoente >= 1)
                printf("%+dx^%d ", p->coeficiente, p->expoente);
            // Se o expoente for 0, não imprimi-lo
            else
                printf("%+d ", p->coeficiente);
        }
    } printf("\n");
}

// Função que realiza a reinicialização do polinômio
void reinicializar_polinomio(termo* &lst)
{
    // Remove todos os nós até chegar no último
    termo *p;
    while(lst->prox != NULL) {
        p = lst;
        lst = lst->prox;
        free(p);
    }
    // Reseta coeficiente e expoente do único nó restante
    lst->coeficiente = 0;
    lst->expoente = 0;
}

// Função que calcula o valor de P(x)
int resolver_polinomio(int x, termo* &lst) 
{   
    // Variáveis utilizadas
    int resultado = 0;
    termo *p = lst;

    // Calcula o valor de cada termo
    while (p != NULL) {
        resultado += x * pow(p->coeficiente, p-> expoente);
        p = p->prox;
    }
    // Retorna o resultado de todo o polinômio
    return resultado;
}