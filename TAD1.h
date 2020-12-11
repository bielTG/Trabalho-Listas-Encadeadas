/******************************************************
*  Gabriel Cardoso dos Santos Herculino               *
*  Trabalho de Algoritmos e Programação II (2020/2)   *
*  Professora: Graziela Santos de Araújo (Turma P05)  *
******************************************************/

// Estrutura usada para resolver o problema do polinômio
struct termo {
    termo *ant;
    int coeficiente;
    int expoente;
    termo *prox;
};

// Protótipo das funções utilizadas
void inserir_ordenado(int c, int e, termo* &lst);
void remover_termo(int exp, termo* &lst);
void remover_ocorrencias(int x, termo* &lst);
void imprimir_polinomio(termo *lst);
void reinicializar_polinomio(termo* &lst);
int resolver_polinomio(int x, termo* &lst);